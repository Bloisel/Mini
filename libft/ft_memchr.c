/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:09:35 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:09:36 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s1;

	i = -1;
	s1 = (char *)s;
	if (c >= 256)
		c -= 256;
	while (++i < n)
	{
		if ((unsigned char)s1[i] == (unsigned char)c)
			return (&s1[i]);
	}
	return (NULL);
}
