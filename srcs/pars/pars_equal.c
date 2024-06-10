/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:15:44 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:15:47 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	addin_env(t_data *dta, t_lst *lst)
{
	t_list	*actual;
	char	*str;
	char	*new;
	char	*tmp;

	actual = *dta->env_list;
	while (actual != NULL)
	{
		str = (char *)actual->content;
		if (ft_strnstr(str, lst->flag, ft_strlen(lst->flag) + 1))
		{
			new = ft_strjoin(lst->flag, "=");
			tmp = new;
			new = ft_strjoin(new, lst->data);
			free(tmp);
			free(actual->content);
			actual->content = new;
		}
		actual = actual->next;
	}
}

void	addtab_arg(t_data *dta, t_lst *lst)
{
	size_t	i;
	t_lst	**n_lst;

	i = dta->nb_arg;
	if (dta->nb_arg != 0)
	{
		n_lst = malloc(sizeof(t_lst *) * (i + 2));
		i = 0;
		while (i < dta->nb_arg)
		{
			n_lst[i] = dta->d_arg[i];
			i++;
		}
		n_lst[i] = lst;
		n_lst[i + 1] = NULL;
		free(dta->d_arg);
		dta->d_arg = n_lst;
		dta->nb_arg += 1;
	}
	else
	{
		dta->d_arg = malloc(sizeof(t_lst *) * 2);
		dta->d_arg[0] = lst;
		dta->nb_arg = 1;
	}
}

void	add_list(t_data *dta, int i)
{
	t_lst	*lst;
	int		j;

	i++;
	j = 0;
	lst = malloc(sizeof(t_lst) * 1);
	while (dta->prompt_t[i + j] != ' ' && dta->prompt_t[i + j])
		j++;
	lst->data = malloc(sizeof(char) * j + 1);
	ft_memcpy(lst->data, &dta->prompt_t[i], j);
	lst->data[j] = '\0';
	j = 0;
	i -= 2;
	while (dta->prompt_t[i - j] != ' ' && i - j >= 0 && dta->prompt_t[i - j])
		j++;
	lst->flag = malloc(sizeof(char) * j + 1);
	ft_strlcat(lst->flag, &dta->prompt_t[i - j + 1], j + 1);
	lst->flag[j + 1] = '\0';
	addtab_arg(dta, lst);
	addin_env(dta, lst);
	ft_memset(dta->prompt_t, ' ', ft_strlen(lst->data)
		+ ft_strlen(lst->flag) + 2);
}

int	is_not_arg(t_data *dta)
{
	int	i;

	i = 0;
	while (dta->prompt_t[i] == ' ' && dta->prompt_t[i])
		i++;
	while (dta->prompt_t[i] != ' ' && dta->prompt_t[i])
	{
		if (dta->prompt_t[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

t_lst	**pars_equal(t_data *dta)
{
	size_t	i;
	char	*tempo;

	i = 0;
	if (!is_not_arg(dta))
		return (dta->d_arg);
	while (dta->prompt_t[i] != '=')
		i++;
	if (ft_strlen(&dta->prompt_t[i]) > 0)
	{
		if (!is_sep(dta->prompt_t[i - 1]) && !is_sep(dta->prompt_t[i + 1]))
			add_list(dta, i);
		if ((is_sep(dta->prompt_t[i - 1]) && !is_sep(dta->prompt_t[i + 1]))
			|| (!is_sep(dta->prompt_t[i - 1]) && is_sep(dta->prompt_t[i + 1])))
		{
			i++;
			while (is_sep(dta->prompt_t[i]))
				i++;
			tempo = dta->prompt_t;
			dta->prompt_t = ft_strdup(&dta->prompt_t[i]);
			free(tempo);
		}
	}
	return (dta->d_arg);
}
