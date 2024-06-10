/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:15:06 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:15:09 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../../include/minishell.h"

void	exec_absolute(t_data *dta)
{
	DIR	*dir;

	if ((access(dta->actual[0], F_OK)) != 0)
		mess_error(dta, 1, "No such file or directory", "");
	else
	{		
		dir = opendir(dta->actual[0]);
		if (dir)
		{
			mess_error(dta, -1, "is a directory", "");
			closedir(dir);
		}
		else
		{
			if ((access(dta->actual[0], X_OK)) == 0)
				execve(dta->actual[0], dta->actual, dta->dup_env);
			else
				mess_error(dta, 1, "Permission denied", "");
		}
	}
}

void	execute_cmd(t_data *dta)
{
	if (!(ft_strncmp(dta->actual[0], "pwd", 4)))
		pwd(dta);
	else if (!(ft_strncmp(dta->actual[0], "cd", 3)))
		cd(dta);
	else if (!(ft_strncmp(dta->actual[0], "env", 4)))
		env(dta, 0);
	else if (!(ft_strncmp(dta->actual[0], "echo", 5)))
		echo(dta, 0);
	else if (!(ft_strncmp(dta->actual[0], "export", 7)))
		export(dta);
	else if (!(ft_strncmp(dta->actual[0], "unset", 6)))
		unset(dta, 1);
	else if (!(ft_strncmp(dta->actual[0], "exit", 5)))
		ft_exit(dta);
	else if (!(ft_strchr(dta->actual[0], '/')))
		exec_cmd(dta);
	else
		exec_absolute(dta);
}

int	is_builtin(t_data *dta)
{
	if (!(ft_strncmp(dta->actual[0], "pwd", 4)))
		return (1);
	else if (!(ft_strncmp(dta->actual[0], "env", 4)))
		return (1);
	else if (!(ft_strncmp(dta->actual[0], "cd", 3)))
		return (1);
	else if (!(ft_strncmp(dta->actual[0], "echo", 5)))
		return (1);
	else if (!(ft_strncmp(dta->actual[0], "export", 7)))
		return (1);
	else if (!(ft_strncmp(dta->actual[0], "unset", 6)))
		return (1);
	else if (!(ft_strncmp(dta->actual[0], "exit", 5)))
		return (1);
	return (0);
}

void	ft_lst_free(t_list *lst)
{
	t_list	*tempo;

	while (lst != NULL)
	{
		tempo = lst;
		lst = lst->next;
		free(tempo);
	}
}
