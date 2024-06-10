/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:15:16 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:15:19 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	get_cmd_path(t_data *dta)
{
	int		i;
	char	*actual;
	char	*path;

	i = -1;
	while (dta->path_split[++i])
	{
		actual = ft_strjoin(dta->path_split[i], "/");
		path = ft_strjoin(actual, dta->actual[0]);
		if ((access(path, F_OK)) == 0 && !ft_strncmp(path, "/", 1))
		{
			dta->cmd_path = ft_strdup(path);
			free(path);
			free(actual);
			return (1);
		}
		free(path);
		free(actual);
	}
	return (0);
}

int	get_path(t_data *dta)
{
	char	*actual;

	dta->path_ok = 0;
	actual = ft_getenv("PATH", dta);
	dta->path_split = ft_split(actual, ':');
	free(actual);
	if (!dta->path_split)
	{
		dta->path_ok = 1;
		dta->path_split = ft_split(" . ", '.');
	}
	return (dta->path_ok);
}
