/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:11:14 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:11:18 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_dup_lst(t_list *aux)
{
	t_list	*new_lst;
	t_list	*lst;
	t_list	*tempo;

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
