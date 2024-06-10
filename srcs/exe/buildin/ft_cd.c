/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:14:16 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:14:19 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../include/minishell.h"

void	update_env_var(t_data *dta, char *var, char *value)
{
	char	**actual_in;
	char	*tempo;

	actual_in = NULL;
	if (dta->actual)
		actual_in = dta->actual;
	tempo = ft_strjoin(var, value);
	dta->actual = malloc(sizeof(char *) * 3);
	dta->actual[0] = ft_strdup("export");
	dta->actual[1] = tempo;
	dta->actual[2] = NULL;
	export(dta);
	free_tab(dta->actual);
	dta->actual = NULL;
	dta->actual = actual_in;
}

void	cd_actual(t_data *dta, char **pwd)
{
	if (*pwd)
		update_env_var(dta, "OLDPWD=", *pwd);
	else
	{
		update_env_var(dta, "OLDPWD=", "");
		if (errno)
		{	
			chdir("/");
			*pwd = getcwd(NULL, 0);
		}	
	}
	free(*pwd);
	*pwd = getcwd(NULL, 0);
	update_env_var(dta, "PWD=", *pwd);
}

void	old_print_pwd(t_data *dta)
{
	char	*pwd;
	t_list	*aux;
	int		i;

	aux = *dta->env_list;
	i = -1;
	while (aux)
	{
		if (!(ft_strncmp("OLDPWD=", aux->content, ft_strlen("OLDPWD="))))
		{
			pwd = aux->content;
			while (pwd[++i] != '=')
				;
			i += 1;
			ft_printf("%s\n", &pwd[i]);
			return ;
		}
		aux = aux->next;
	}
}

void	cd(t_data *dta)
{
	char	*home_path;
	char	*pwd;

	home_path = ft_getenv("HOME", dta);
	pwd = getcwd(NULL, 0);
	if (!dta->actual[1] || !(ft_strncmp(dta->actual[1], "~", 2)))
	{
		if (chdir(home_path) == -1)
			mess_error(dta, -1, "HOME not set", "");
	}
	else if (!ft_strncmp(dta->actual[1], "-", 2))
		old_print_pwd(dta);
	else if (chdir(dta->actual[1]) == -1)
	{
		if (errno == EACCES)
			mess_error(dta, 1, "Permission denied", "");
		else if (errno == ENAMETOOLONG)
			mess_error(dta, -1, "File name too long", "");
		else
			mess_error(dta, 1, "No such file or directory", "");
	}
	if (!dta->actual[1] || ft_strncmp(dta->actual[1], "-", 2))
		cd_actual(dta, &pwd);
	free(home_path);
	free(pwd);
}
