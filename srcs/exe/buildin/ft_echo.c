/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:14:22 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:14:26 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../../include/minishell.h"

void	print_echo(t_data *dta, int i)
{
	int	j;

	while (dta->actual[i])
	{
		j = -1;
		while (dta->actual[i][++j])
			if (dta->actual[i][j] < 0)
				dta->actual[i][j] = (dta->actual[i][j] * -1);
		if (dta->actual[i + 1] != NULL)
		{
			write(1, dta->actual[i], ft_strlen(dta->actual[i]));
			if (ft_strncmp(dta->actual[i], "", 1))
				write(1, " ", 1);
		}
		else
			write(1, dta->actual[i], ft_strlen(dta->actual[i]));
		i++;
	}
}

int	is_n(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}	

void	is_multiple_n(t_data *dta, int i)
{
	i = 1;
	if (dta->actual[i + 1] == NULL)
		return ;
	while (dta->actual[i] && !(ft_strncmp(dta->actual[i], "-n", 2)))
	{
		if (!(ft_strncmp(dta->actual[i], "-n", 3)))
			i++;
		else
		{
			if (!is_n(dta->actual[i]))
				break ;
			else
				i++;
		}
	}	
	print_echo(dta, i);
}

void	echo(t_data *dta, int i)
{
	g_exit_status = 0;
	if (dta->actual[1] == NULL)
		write(1, "\n", 1);
	else if (!(ft_strncmp(dta->actual[1], "-n", 3)))
		is_multiple_n(dta, i);
	else if (!(ft_strncmp(dta->actual[1], "-n", 2)) && is_n(dta->actual[1]))
	{
		i = 1;
		if (dta->actual[i + 1] == NULL)
			return ;
		while (dta->actual[i])
		{	
			if (!is_n(dta->actual[i]))
				break ;
			i++;
		}
		print_echo(dta, i);
	}
	else
	{
		print_echo(dta, 1);
		write(1, "\n", 1);
	}
}
