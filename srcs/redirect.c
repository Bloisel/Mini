/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:18:22 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:22:26 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	run_cmd_no_pipe(t_data *dta)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = handle_sig_alt;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	pid = fork();
	if (!pid)
	{
		check_redirs(dta);
		execute_cmd(dta);
		if (dta->is_out)
			dup2(dta->back2, STDOUT_FILENO);
		if (dta->is_out)
			close(dta->back2);
		exit(g_exit_status);
	}
	else
	{
		waitpid(pid, &dta->status, 0);
		if (g_exit_status != 130 && g_exit_status != 131)
			g_exit_status = WEXITSTATUS(dta->status);
	}
}

void	triger_exit(t_data *dta, long long number)
{
	int			i;

	i = -1;
	dta->exit = 1;
	if (dta->p[0][1])
	{
		if (dta->p[0][1][0] == '+' || dta->p[0][1][0] == '-')
			i++;
		while (dta->p[0][1][++i])
		{
			if (!ft_isdigit(dta->p[0][1][i]))
			{
				mess_error(dta, 255, "numeric argument required", "");
				g_exit_status = 255;
				return ;
			}
		}
		number = ft_atoi_long(dta->p[0][1]);
		while (number > 256)
			number -= 256;
		g_exit_status = number;
		return ;
	}
	g_exit_status = 0;
}

void	redirect(t_data *dta)
{
	if (g_exit_status == 130 || g_exit_status == 131)
		g_exit_status = 0;
	if (dta->prompt_t[0] != '\0' && dta->exit_actual == 0)
	{
		dta->actual = dta->p[0];
		if (!(ft_strncmp(dta->actual[0], "exit", 5)))
			triger_exit(dta, 0);
		else if (!(ft_strncmp(dta->actual[0], "export", 7)))
			export(dta);
		else if (!(ft_strncmp(dta->actual[0], "unset", 5)))
			unset(dta, 1);
		else if (!(ft_strncmp(dta->actual[0], "cd", 3)))
		{
			g_exit_status = 0;
			cd(dta);
		}
		else if (dta->nb_cmd_p == 1)
			run_cmd_no_pipe(dta);
		else if (dta->nb_cmd_p > 1)
			run_cmd_whith_pipe(dta);
	}
}

		// else if (!(ft_strncmp(dta->actual[0], "history", 8)))
		// 	print_historic(dta);
		// else if (!(ft_strncmp(dta->actual[0], "parg", 5)))
		// 	print_arg(dta);