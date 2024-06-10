/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:17:46 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:17:49 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	check_last_char(char *str, char c)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (is_sep(str[i]))
		i--;
	if (str[i] == c)
		return (1);
	return (0);
}

int	is_to_space(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	check_fst_c(char *str)
{
	size_t	i;

	i = -1;
	while (is_sep(str[++i]))
		;
	if (str[i] != '\0')
		return (str[i]);
	return (0);
}

void	print_t_tab(char ***tab)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			ft_printf("%s~", tab[i][j]);
		ft_printf("\n");
	}
}

void	rm_pipe_t_tab(char ***tab)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j][0] == '|' && tab[i][j][1] != '|')
			{
				free(tab[i][j]);
				tab[i][j] = NULL;
			}
		}
	}
}
