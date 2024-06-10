/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:11:24 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:11:25 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	c = malloc(nmemb * size);
	if (!c)
		return (NULL);
	ft_memset(c, 0, nmemb * size);
	return (c);
}
