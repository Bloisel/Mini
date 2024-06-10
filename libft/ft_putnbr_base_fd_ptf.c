/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_ptf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:08:53 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:08:54 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

size_t	len_hex_2_ptf(double nbr, int len)
{
	size_t	i;

	i = 0;
	while (nbr > 16.000)
	{
		i++;
		nbr /= len;
	}
	if (nbr == 16)
		i++;
	return (i);
}

size_t	ft_putnbr_base_fd_ptf(CINT nbr, char *base, int fd)
{
	char	*str;
	int		len;
	int		nbcar;
	size_t	ret;

	len = 16;
	if (nbr < 0)
		nbr *= -1;
	nbcar = len_hex_2_ptf(nbr, (double)len);
	ret = 0;
	str = malloc(sizeof(char) * (nbcar + 2));
	str[nbcar + 1] = '\0';
	while (nbr >= len)
	{
		str[nbcar--] = base[nbr % len];
		nbr /= len;
	}
	str[nbcar] = base[nbr % len];
	ret += ft_strlen_ptf(str);
	ft_putstr_fd_ptf(str, fd);
	free(str);
	return (ret);
}
