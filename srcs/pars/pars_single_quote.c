/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_single_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:16:56 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:16:58 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_in_simple_quote(t_data *dta)
{
	int	nbquote;
	int	i;

	nbquote = 0;
	i = 0;
	while (dta->prompt_t[++i])
		if (dta->prompt_t[i] == '\'')
			nbquote++;
	i = 0;
	while (nbquote > 1)
	{
		while (dta->prompt_t[i] != '\'' && dta->prompt_t[i])
			i++;
		while (dta->prompt_t[++i] != '\'' && dta->prompt_t[i])
			if (is_sep(dta->prompt_t[i]) || dta->prompt_t[i] == '\"'
				|| dta->prompt_t[i] == '$')
				dta->prompt_t[i] = dta->prompt_t[i] * -1;
		nbquote -= 2;
		i++;
	}
}

void	replace_special_char_in_arg(t_data *dta)
{
	size_t	i;
	size_t	arg;

	arg = -1;
	while (++arg < dta->nb_arg)
	{
		i = -1;
		while (dta->d_arg[arg]->data[++i])
			if (dta->d_arg[arg]->data[i] < 0)
				dta->d_arg[arg]->data[i] = dta->d_arg[arg]->data[i] * -1;
	}
}

void	replace_special_char(t_data *dta)
{
	size_t	i;
	size_t	arg;

	arg = -1;
	while (dta->prompt[++arg] != NULL)
	{
		i = -1;
		while (dta->prompt[arg][++i])
			if (dta->prompt[arg][i] < 0 && is_to_space(dta->prompt[arg][i]))
				dta->prompt[arg][i] = dta->prompt[arg][i] * -1;
	}
}

void	replace_special_char_ac(t_data *dta)
{
	size_t	i;
	size_t	arg;

	arg = -1;
	while (dta->prompt[++arg] != NULL)
	{
		i = -1;
		while (dta->prompt[arg][++i])
			if (dta->prompt[arg][i] < 0)
				dta->prompt[arg][i] = dta->prompt[arg][i] * -1;
	}
}

	// if (!ft_strnstr(dta->prompt[0], "echo", 5))
	// {