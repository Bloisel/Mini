/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:07:24 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:07:26 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (!dst || size < 1)
		return (ft_strlen((char *)src));
	if (size)
		while (++i < size - 1 && src[i])
			dst[i] = src[i];
	dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}
