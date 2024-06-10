/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:10:04 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:10:05 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

t_list	*ft_lstdup(t_list *aux)
{
	t_list	*new_lst;
	t_list	*tempo;
	t_list	*lst;

	new_lst = 0;
	lst = aux;
	while (lst)
	{
		tempo = ft_lstnew(lst->content);
		if (!tempo)
			return (0);
		ft_lstadd_back(&new_lst, tempo);
		lst = lst->next;
	}
	return (new_lst);
}
