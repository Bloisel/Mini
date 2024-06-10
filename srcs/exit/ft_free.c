/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:15:27 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:15:30 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	free_tab(char **str)
{
	size_t	i;

	i = -1;
	if (str)
	{
		while (str[++i] != NULL)
			if (str[i] != NULL)
				free(str[i]);
	}
	if (str != NULL)
		free(str);
}

void	free_tab_len(char **str, size_t nb_arg)
{
	size_t	i;

	i = -1;
	if (str)
	{
		while (++i < nb_arg)
			if (str[i] != NULL)
				free(str[i]);
	}
	if (str != NULL)
		free(str);
}

void	free_lst(t_lst **lst, t_data *dta)
{
	size_t	i;

	i = -1;
	if (dta->nb_arg != 0)
	{
		while (++i < dta->nb_arg)
		{
			if (lst[i]->data != NULL)
				free(lst[i]->data);
			if (lst[i]->flag != NULL)
				free(lst[i]->flag);
			if (lst[i] != NULL)
				free(lst[i]);
		}
		if (lst != NULL)
			free(lst);
	}
}

void	free_triple_tab(char ***tab)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (tab)
	{
		while (tab[++i])
		{
			j = -1;
			while (tab[i][++j])
			{
				if (tab[i][j] != NULL)
					free(tab[i][j]);
			}
			if (tab[i] != NULL)
				free(tab[i]);
		}
		if (tab != NULL)
			free(tab);
	}
}

void	free_keys(t_data *dta)
{
	int	i;

	i = -1;
	while (dta->keys[++i] != NULL)
	{
		if (dta->keys[i] != NULL)
		{
			unlink(dta->keys[i]);
			if (dta->keys[i] != NULL)
				free(dta->keys[i]);
		}
	}
	if (dta->keys != NULL)
		free(dta->keys);
}
