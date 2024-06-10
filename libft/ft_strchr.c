/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:08:09 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:08:11 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (c >= 256)
		c -= 256;
	while (s[++i])
		if (s[i] == c)
			return (&((char *)s)[i]);
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (NULL);
}
