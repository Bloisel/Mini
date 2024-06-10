/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:17:40 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:17:42 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	check_path2(t_data *dta)
{
	char	*aux;

	aux = ft_getenv("PWD", dta);
	if (!aux)
	{
		aux = getcwd(NULL, 0);
		update_env_var(dta, "PWD=", aux);
		free(aux);
	}
	else
		free(aux);
	aux = ft_getenv("_", dta);
	if (!aux)
		update_env_var(dta, "_=", "env");
	else
		free(aux);
}

void	check_path(t_data *dta)
{
	char	*aux;

	aux = ft_getenv("PATH", dta);
	if (!aux)
		update_env_var(dta, "PATH=",
			"/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	else
		free(aux);
	aux = ft_getenv("SHLVL", dta);
	if (!aux)
		update_env_var(dta, "SHLVL=", "0");
	else
		free(aux);
	check_path2(dta);
}

void	update_shlvl(t_data *dta)
{
	int		lvl;
	char	*number;
	char	*aux;	

	aux = ft_getenv("SHLVL", dta);
	lvl = ft_atoi(aux);
	if (lvl < 0)
	{
		ft_putstr_fd("minishell:", 2);
		if (lvl == -1)
			lvl++;
		ft_putendl_fd("warning: shell lvl too high, resetting to 1", 2);
	}
	free(aux);
	lvl++;
	number = ft_itoa(lvl);
	update_env_var(dta, "SHLVL=", number);
	free(number);
}

void	put_env_in_arg_2(t_data *dta)
{
	t_lst	*new;
	t_list	*lst;

	lst = *dta->env_list;
	while (lst)
	{
		new = malloc(sizeof(t_lst) * 1);
		if (size_to_char(lst->content, '=') != -1)
			new->flag = malloc(sizeof(char)
					* (size_to_char(lst->content, '=') + 2));
		ft_strlcpy(new->flag, lst->content,
			size_to_char(lst->content, '=') + 1);
		new->flag[size_to_char(lst->content, '=')] = '\0';
		new->data = ft_strdup(&lst->content
			[size_to_char(lst->content, '=') + 1]);
		replace_existing_arg_for_env(dta, new);
		lst = lst->next;
	}
}

int	check_equal(t_data *dta)
{
	size_t	i;

	i = -1;
	while (dta->prompt_t[++i])
	{
		while (is_sep(dta->prompt_t[i]))
			i++;
		if (is_sep(dta->prompt_t[i]))
			return (0);
		if (dta->prompt_t[i] == '=')
			return (1);
	}
	return (0);
}
