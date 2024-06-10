/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:58:22 by tsorabel          #+#    #+#             */
/*   Updated: 2022/11/17 17:49:27 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strlen_n_o(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = -1;
	while (c > 256)
		c -= 256;
	if (!s)
		return (NULL);
	while (s[++i])
		if (s[i] == c)
			return (&((char *)s)[i]);
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dup;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dup = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			dup[i] = s1[i];
	while (s2[j])
		dup[i++] = s2[j++];
	dup[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
	free(s1);
	return (dup);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (dst[0] == '\0' || src[0] == '\0')
	{
		dst[0] = 0;
		return (0);
	}
	if (size)
	{
		while (++i < size - 1 && src[i])
		{
			dst[i] = src[i];
		}
	}
	dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}
