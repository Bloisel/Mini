/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_ptf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:08:45 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:08:46 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

size_t	ft_putnbr_fd_size_ptf(int n)
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

void	ft_ptnbr_fd_write_ptf(int n, int fd)
{
	size_t	nb;
	char	c;
	size_t	size;
	size_t	i;

	nb = 0;
	size = ft_putnbr_fd_size_ptf(n);
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

void	ft_putnbr_fd_ptf(int n, int fd)
{
	char	c;

	if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		c = '-';
		write(fd, &c, 1);
	}
	ft_ptnbr_fd_write_ptf(n, fd);
}
