/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:11:20 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:11:21 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

size_t	len_convert(double nbr, int len)
{
	size_t	i;

	i = 0;
	while (nbr > len)
	{
		i++;
		nbr /= len;
	}
	if (nbr == len)
		i++;
	return (i);
}

char	*ft_convet_base(CINT nbr, char *base)
{
	char	*str;
	int		len;
	int		nbcar;

	len = ft_strlen_ptf(base);
	nbcar = len_convert(nbr, (double)len);
	str = malloc(sizeof(char) * (nbcar + 2));
	str[nbcar + 1] = '\0';
	while (nbr >= len)
	{
		str[nbcar--] = base[nbr % len];
		nbr /= len;
	}
	str[nbcar] = base[nbr % len];
	return (str);
}
