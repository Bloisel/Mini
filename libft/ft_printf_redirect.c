/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:09:11 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:09:12 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

void	ft_printf_redirect2(char c, CINT arg, size_t *ret)
{
	if (c == 's')
	{
		if (arg != 0)
			*ret += ft_putstr_fd_ptf((char *)arg, 1);
		else
			*ret += ft_putstr_fd_ptf("(null)", 1);
	}
	if (c == 'x')
		*ret += ft_putnbr_base_fd_ptf((unsigned int)arg, "0123456789abcdef", 1);
	if (c == 'X')
		*ret += ft_putnbr_base_fd_ptf((unsigned int)arg, "0123456789ABCDEF", 1);
	if (c == 'p' )
	{
		*ret += ft_putstr_fd_ptf("0x", 1);
		*ret += ft_putnbr_base_fd2_ptf((unsigned long long)arg,
				"0123456789abcdef", 1);
	}
}

void	ft_printf_redirect(char c, CINT arg, size_t *ret, size_t *i)
{
	*i += 2;
	if (c == 'd' || c == 'i')
	{
		if (c == 'd')
			ft_putnbr_fd_ptf((int)arg, 1);
		if (c == 'i')
			ft_putnbr_fd_ptf((int)arg, 1);
	*ret += number_char_ptf((int)arg);
	}
	if (c == 'u')
	{
		ft_putnbr_unsigned_fd_ptf((unsigned int)arg, 1);
		*ret += number_char_ptf((unsigned int)arg);
	}
	if (c == 'c')
		*ret += ft_putchar_fd_ptf((char)arg, 1);
	if (c == '%')
		*ret += ft_putchar_fd_ptf('%', 1);
	if (ft_strrchr_ptf("spxX", c) != 0)
		ft_printf_redirect2(c, arg, ret);
}
