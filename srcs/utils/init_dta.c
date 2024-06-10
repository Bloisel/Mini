/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:17:35 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:17:36 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	init_dta(t_data *dta, char **env)
{
	dta->exit = 0;
	dta->nb_arg = 0;
	dta->st = 1;
	dta->status = 0;
	dta->actual = NULL;
	dta->nb_arg_hist = 0;
	dta->path_ok = 0;
	dta->nb_arg = 0;
	dta->pipe_str = ft_strdup("init");
	dta->empty = ft_strdup("E");
	dta->empty[0] = dta->empty[0] * -1;
	if (hub_env(dta, env) == -1)
		exit(1);
	get_nickname(dta, env);
	g_exit_status = 0;
	dta->prompt_t = ft_strdup("defaultminishell=defaultminishell");
	free(dta->prompt_t);
}

void	init_basic_env(t_data *dta, char **pwd)
{
	dta->dup_env = malloc(sizeof(char *) * 5);
	dta->dup_env[0]
		= ft_strdup("PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	dta->dup_env[1] = ft_strjoin("PWD=", (*pwd));
	dta->dup_env[2] = ft_strdup("SHLVL=0");
	dta->dup_env[3] = ft_strdup("_=./minishell");
	dta->dup_env[4] = NULL;
}

void	dup_env(t_data *dta, char **env)
{
	int		i;
	char	*pwd;

	i = 0;
	dta->dup_env = NULL;
	pwd = getcwd(NULL, 0);
	if (!(*env))
		init_basic_env(dta, &pwd);
	else
	{
		while (env[i] != NULL)
			i++;
		dta->dup_env = malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (env[i])
		{
			dta->dup_env[i] = ft_strdup(env[i]);
			i++;
		}
		dta->dup_env[i] = NULL;
	}
	free(pwd);
}

int	size_to_char(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i] != c && str[i])
		;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

void	replace_existing_arg_for_env(t_data *dta, t_lst *lst)
{
	int	i;

	i = -1;
	i = dta->nb_arg ;
	while (--i >= 0)
	{
		if (ft_memcmp(dta->d_arg[i]->flag,
				lst->flag, ft_strlen(dta->d_arg[i]->flag) + 1) == 0)
		{
			free(dta->d_arg[i]->data);
			free(dta->d_arg[i]->flag);
			free(dta->d_arg[i]);
			dta->d_arg[i] = lst;
			return ;
		}
	}
	addtab_arg(dta, lst);
}
