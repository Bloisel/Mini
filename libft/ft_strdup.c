/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:07:53 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:07:56 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(char const *s)
{
	char	*dup;

	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, ft_strlen(s));
	dup[ft_strlen(s)] = '\0';
	return (dup);
}
