/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_lst_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:16:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:16:28 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

char	**list_to_tab(t_list *lst)
{
	int		i;
	char	**tab;
	t_list	*aux;

	i = 0;
	aux = lst;
	tab = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	while (aux)
	{
		tab[i] = ft_strdup(aux->content);
		aux = aux->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
