/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:09:00 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:09:01 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}