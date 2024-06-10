/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_redirection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:15:11 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:15:14 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	r_redirection(t_data *dta, int i)
{
	char	**actual;
	int		j;

	j = -1;
	actual = malloc(sizeof(char *) * (tab_len(dta->actual) - 1));
	while (dta->actual[++j] && j < i)
		actual[j] = ft_strdup(dta->actual[j]);
	i += 2;
	while (dta->actual[i])
		actual[j++] = ft_strdup(dta->actual[i++]);
	actual[j] = NULL;
	dta->actual = NULL;
	dta->actual = actual;
}
