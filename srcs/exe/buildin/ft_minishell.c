/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:14:43 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:14:47 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../include/minishell.h"

char	**dup_new_env(char **tab, int size)
{
	char	**new_tab;
	int		i;
	int		j;

	i = 0;
	new_tab = malloc((size + 1) * sizeof(char *));
	if (!new_tab)
		return (NULL);
	i = 0;
	j = 0;
	while (tab[i])
	{
		if (ft_strchr(tab[i], '='))
		{
			new_tab[j] = ft_strdup(tab[i]);
			j++;
		}
		i++;
	}
	new_tab[j] = NULL;
	return (new_tab);
}

void	run_minishell(t_data *dta)
{
	char	**new_env;
	int		size;
	int		i;

	if (dta->nb_cmd_p)
		exit (0);
	size = 0;
	i = -1;
	while (dta->dup_env[++i])
	{
		if (ft_strchr(dta->dup_env[i], '='))
			size++;
	}
	new_env = dup_new_env(dta->dup_env, size);
	if (execve(dta->actual[0], dta->actual, new_env) == -1)
		mess_error(dta, 127, "command not found :", dta->actual[0]);
	free_tab(new_env);
}

void	exec_cmd(t_data *dta)
{
	get_path(dta);
	dta->cmd_path = NULL;
	if (get_cmd_path(dta))
		execve(dta->cmd_path, dta->actual, dta->dup_env);
	else
	{
		if (dta->path_ok == 0)
			mess_error(dta, 127, "command not found :", dta->actual[0]);
		else
			mess_error(dta, 1, "No such file or directory", "");
	}
}
