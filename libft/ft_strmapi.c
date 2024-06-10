/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:07:12 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:07:14 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = -1;
	c = malloc((ft_strlen(s) + 1));
	if (!c)
		return (NULL);
	while (++i < ft_strlen(s))
		c[i] = f(i, s[i]);
	c[i] = '\0';
	return (c);
}
