/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:09:16 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:09:17 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_new_node(void *cont, size_t size)
{
	t_list	*stack;
	void	*aux;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	aux = malloc(size);
	if (!aux)
	{
		free(stack);
		stack = NULL;
	}
	ft_memcpy(aux, cont, size);
	stack->content = aux;
	stack->next = NULL;
	return (stack);
}
