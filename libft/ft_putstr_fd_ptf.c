/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_ptf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:08:31 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:08:32 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

size_t	ft_strlen_ptf(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_putstr_fd_ptf(char *s, int fd)
{
	if (!s)
		return (0);
	write(fd, s, ft_strlen_ptf(s));
	return (ft_strlen_ptf(s));
}
