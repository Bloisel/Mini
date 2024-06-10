/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:10:12 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:10:13 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;

	if (!del || !lst)
		return ;
	while (*lst != NULL)
	{
		del((*lst)->content);
		cur = *lst;
		*lst = cur->next;
		free(cur);
	}
	*lst = NULL;
}
