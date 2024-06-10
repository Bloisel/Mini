/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:10:27 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:10:28 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

int	number_char(int n, int *neg, int *j)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
		*neg = 1;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
		*j = *j * 10;
	}
	i++;
	return (i);
}

char	*fill(int neg, int j, char *c, int n)
{
	int	i;

	i = 0;
	if (neg)
	{
		c[i++] = '-';
		n *= -1;
	}
	while (j > 9)
	{
		c[i++] = (n / j) + 48;
		n = n % j;
		j = j / 10;
	}
	c[i++] = n + 48;
	c[i] = '\0';
	return (c);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		neg;
	int		j;

	neg = 0;
	j = 1;
	if (n == -2147483648)
	{
		c = ft_strdup("-2147483648");
		return (c);
	}
	c = malloc(number_char(n, &neg, &j) + 1);
	if (!c)
		return (NULL);
	fill(neg, j, c, n);
	return (c);
}
