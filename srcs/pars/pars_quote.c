/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:16:44 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:16:47 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_in_quote(t_data *dta)
{
	int	i;
	int	in1;
	int	in2;

	in1 = -1;
	in2 = -1;
	i = -1;
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '"' && in2 == -1)
			in1 *= -1;
		if (dta->prompt_t[i] == '\'' && in1 == -1)
			in2 *= -1;
		if (in1 == 1 && (dta->prompt_t[i] == '\'' || is_sep(dta->prompt_t[i])))
			dta->prompt_t[i] *= -1;
		if (in2 == 1 && (dta->prompt_t[i] == '"' || dta->prompt_t[i] == '$'
				|| is_sep(dta->prompt_t[i])))
			dta->prompt_t[i] *= -1;
	}
}

void	remove_quote(t_data *dta)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = 0;
	new = malloc(sizeof(char) * ft_strlen(dta->prompt_t));
	ft_bzero(new, ft_strlen(dta->prompt_t));
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '\'' || dta->prompt_t[i] == '"')
			;
		else
		{
			new[j] = dta->prompt_t[i];
			j++;
		}
	}
	new[j] = '\0';
	free(dta->prompt_t);
	dta->prompt_t = new;
}
