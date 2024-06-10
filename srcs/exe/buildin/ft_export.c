/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:14:38 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:14:40 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../include/minishell.h"

int	valid_id(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isalnum(str[i])) && str[i] != '=' && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	export_actual(t_data *dta, char **actual, int j)
{
	char	*env_value;
	char	*var;

	if (!valid_id(actual[0]))
		mess_error(dta, -1, "not a valid identifier", "");
	else
	{
		env_value = ft_getenv(actual[0], dta);
		if (env_value)
		{
			var = ft_strdup(actual[0]);
			unset_from_list(dta, &var, ft_strlen(var));
			ft_lstadd_back(dta->env_list,
				ft_new_node((void *) dta->actual[j],
					ft_strlen(dta->actual[j]) + 1));
			free(env_value);
			free(var);
		}
		else
		{
			ft_lstadd_back(dta->env_list,
				ft_new_node((void *) dta->actual[j],
					ft_strlen(dta->actual[j]) + 1));
		}
	}
}

int	check_eq_export(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			return (1);
	}
	return (0);
}

void	export(t_data *dta)
{
	char	**actual;
	int		j;

	g_exit_status = 0;
	if (dta->actual[1] == NULL)
	{
		env(dta, 1);
		return ;
	}
	j = 1;
	while (dta->actual[j])
	{
		if (ft_strlen(dta->actual[j]) != 0 && check_eq_export(dta->actual[1]))
		{	
			actual = ft_split(dta->actual[j], '=');
			if (actual)
				export_actual(dta, actual, j);
			free_tab(actual);
		}
		else
			mess_error(dta, -1, "not a valid identifier", "");
		j++;
	}
	free_tab(dta->dup_env);
	dta->dup_env = list_to_tab(*dta->env_list);
}
