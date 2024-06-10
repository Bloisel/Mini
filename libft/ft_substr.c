/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:06:17 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:06:20 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	lg;

	lg = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s) || *s == '\0')
	{
		dup = malloc(1 * sizeof(char));
		*dup = 0;
		return (dup);
	}
	else if (len > (size_t)ft_strlen(s))
		lg = ft_strlen(s);
	else
		while (s[lg + start] && lg < len)
			lg++;
	dup = malloc(lg + 1);
	if (!dup)
		return (NULL);
	lg = -1;
	while (++lg < len && s[lg + start])
		dup[lg] = s[start + lg];
	dup[lg] = '\0';
	return (dup);
}
