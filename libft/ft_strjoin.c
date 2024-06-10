/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:07:40 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:07:42 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dup;

	if (!s1 || !s2)
		return (NULL);
	dup = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dup)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dup[i] = s1[i];
	i--;
	while (s2[++j])
		dup[++i] = s2[j];
	dup[i + 1] = '\0';
	return (dup);
}
