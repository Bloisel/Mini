/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:15:01 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:22:26 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	child(t_data *dta, int i, int arg)
{
	check_redirs(dta);
	if (dta->p[arg + 1] != NULL)
	{
		if (!dta->is_out)
			dup2(dta->fd[i % 2][1], STDOUT_FILENO);
	}
	close(dta->fd[i % 2][1]);
	if (i > 0)
	{
		close(dta->fd[i % 2][1]);
		if (!dta->is_in)
			dup2(dta->fd[(i + 1) % 2][0], STDIN_FILENO);
		close(dta->fd[(i + 1) % 2][0]);
	}
	close(dta->fd[i % 2][0]);
	if (dta->is_out)
		close(dta->back2);
	if (dta->actual[0])
	{
		if (is_builtin(dta) && !dta->nb_cmd_p)
			exit (g_exit_status);
		else
			execute_cmd(dta);
	}
	exit (g_exit_status);
}

void	run_cmd_whith_pipe_2(t_data *dta, int i, int *flag, int arg)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		close(dta->fd[i % 2][1]);
		close(dta->fd[i % 2][0]);
		*flag = 1;
	}
	if (pid == 0)
		child(dta, i, arg);
	close(dta->fd[i % 2][1]);
	if (i > 0 && dta->p[arg + 1] != NULL)
		close(dta->fd[(i + 1) % 2][0]);
	if (i > 0 && dta->p[arg + 1] == NULL)
	{
		close(dta->fd[i % 2][0]);
		close(dta->fd[(i + 1) % 2][0]);
	}
	if (i == 0 && dta->p[arg + 1] == NULL)
		close(dta->fd[i % 2][0]);
}

void	wait_fork(t_data *dta, int flag)
{
	int	nb_pipe;

	nb_pipe = dta->nb_cmd_p - 1;
	if (flag)
		mess_error(dta, -1, "Fork error", "");
	while (nb_pipe >= 0)
	{
		waitpid(-1, &dta->status, 0);
		if (g_exit_status != 130 && g_exit_status != 131)
			g_exit_status = WEXITSTATUS(dta->status);
		nb_pipe--;
	}
	if (g_exit_status == 250)
		g_exit_status = 1;
}

void	run_cmd_whith_pipe(t_data *dta)
{
	int					i;
	int					arg;
	int					flag;
	struct sigaction	sa;

	i = 0;
	arg = -1;
	flag = 0;
	sa.sa_sigaction = handle_sig_alt;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	while (dta->p[++arg] && WIFEXITED(dta->status))
	{
		if (pipe(dta->fd[i % 2]) == -1)
			mess_error(dta, -1, "Pipe ", "error");
		dta->actual = dta->p[arg];
		run_cmd_whith_pipe_2(dta, i, &flag, arg);
		i++;
	}
	wait_fork(dta, flag);
	wait(&dta->status);
	dta->ready_next = g_exit_status;
	prepare_for_next(dta);
}
