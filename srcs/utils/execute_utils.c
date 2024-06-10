/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:17:29 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:22:26 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	outfile_actual(t_data *dta)
{
	if (!dta->is_out)
		dta->back2 = dup(STDOUT_FILENO);
	if (dup2(dta->fd_out, STDOUT_FILENO) == -1)
		mess_error(dta, -1, "Dup error", "");
	close(dta->fd_out);
	dta->is_out = 1;
}

void	infile_actual(t_data *dta)
{
	if (!is_builtin(dta))
	{
		if (dup2(dta->fd_in, STDIN_FILENO) == -1)
			mess_error(dta, -1, "Dup error", "");
	}
	close(dta->fd_in);
	dta->is_in = 1;
}

int	outfile(t_data *dta, int i)
{
	if (!(ft_strncmp(dta->actual[i], ">", 2)))
		dta->fd_out = open(dta->actual[i + 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (!(ft_strncmp(dta->actual[i], ">>", 3)))
		dta->fd_out = open(dta->actual[i + 1],
				O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (dta->fd_out != -1)
	{
		r_redirection(dta, i);
		if (!dta->actual[0])
		{
			close(dta->fd_out);
			return (1);
		}
		outfile_actual(dta);
	}
	else
	{
		if (errno == EACCES)
			mess_error(dta, 1, "Permission denied", "");
		else
			mess_error(dta, -1, "here_doc:", "could not find here_doc file");
		return (1);
	}
	return (0);
}

int	infile(t_data *dta, int i)
{
	if (!(ft_strncmp(dta->actual[i], "<", 2)))
		dta->fd_in = open(dta->actual[i + 1], O_RDONLY);
	if (dta->fd_in == -1)
	{
		if (errno == EACCES)
			mess_error(dta, 1, "Permission denied", "");
		else
			mess_error(dta, 1, "No such file or directory", "");
		return (1);
	}
	else
	{
		r_redirection(dta, i);
		if (!dta->actual[0])
		{
			close(dta->fd_in);
			return (1);
		}
		infile_actual(dta);
	}
	return (0);
}

void	check_redirs(t_data *dta)
{
	int	i;

	dta->is_out = 0;
	dta->is_in = 0;
	i = -1;
	while (dta->actual[++i])
	{
		if (!(ft_strncmp(dta->actual[i], "<", 1)))
		{
			if (infile(dta, i))
				return ;
			i--;
		}
		else if (!(ft_strncmp(dta->actual[i], ">", 1)))
		{
			if (outfile(dta, i))
				return ;
			i--;
		}
	}
}
