/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd_ptf.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:08:37 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:08:38 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

size_t	ft_putnbr_fd_size2_ptf(unsigned int n)
{
	size_t	i;
	size_t	nb;

	nb = 10;
	i = 1;
	while (nb <= (size_t)n)
	{
		nb *= 10;
		i++;
	}
	return (i);
}

void	ft_ptnbr_fd_write2_ptf(unsigned int n, int fd)
{
	size_t	nb;
	char	c;
	size_t	size;
	size_t	i;

	nb = 0;
	size = ft_putnbr_fd_size2_ptf(n);
	i = 0;
	while (++i <= size)
	{
		nb *= 10;
		nb += n % 10;
		n /= 10;
	}
	i = 0;
	while (++i <= size)
	{
		c = (nb % 10) + 48;
		write(fd, &c, 1);
		nb /= 10;
	}
}

void	ft_putnbr_unsigned_fd_ptf(unsigned int n, int fd)
{
	if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	ft_ptnbr_fd_write2_ptf(n, fd);
}
