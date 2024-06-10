/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:17:15 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:17:17 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	takeintpath(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if ((env[i][0] == 'P' && env[i][1] == 'A')
			&& (env[i][2] == 'T' && env[i][3] == 'H'))
			return (i);
		i++;
	}
	return (-1);
}

int	take_env(t_data *dta, char *env)
{
	char	*temp;
	char	**r;
	int		i;

	i = 0;
	temp = ft_strtrim(env, "PATH=");
	r = ft_split(temp, ':');
	free(temp);
	while (r[i])
	{
		temp = r[i];
		r[i] = ft_strjoin(r[i], "/");
		free(temp);
		i++;
	}
	dta->env = r;
	return (0);
}

int	hub_env(t_data *dta, char **env_brut)
{
	int		i;
	char	*env_l;

	i = takeintpath(env_brut);
	if (i == -1)
	{
		printf("Error: No PATH in environnement\n");
		return (-1);
	}
	env_l = env_brut[i];
	take_env(dta, env_l);
	return (0);
}
