/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pars_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:15:22 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:15:25 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	check_first_pipe(t_data *dta)
{
	int	i;

	i = -1;
	if (dta->prompt_t[0] == '\0')
		return (1);
	while (dta->prompt[0][++i] && is_sep(dta->prompt[0][i]))
		;
	if (dta->prompt[0][i] == '|' && dta->exit_actual == 0)
	{
		mess_error(dta, 258, "syntax error near", "|");
		dta->exit_actual = 1;
		return (1);
	}
	return (0);
}

void	check_err_pipe(t_data *dta)
{
	int	arg;
	int	i;

	arg = -1;
	if (check_first_pipe(dta) == 1 || dta->prompt_t[0] == '\0')
		return ;
	while (dta->prompt[++arg])
	{
		i = -1;
		while (dta->prompt[arg][++i] && is_sep(dta->prompt[arg][i]))
			;
		if (dta->prompt[arg][i] == '|')
		{
			i = -1;
			arg++;
			while (dta->prompt[arg][++i] && is_sep(dta->prompt[arg][i]))
				;
			if (dta->prompt[arg][i] == '|' && dta->exit_actual == 0)
			{
				mess_error(dta, 258, "syntax error near", "|");
				dta->exit_actual = 1;
			}
		}
	}
}

void	check_err_before_pipe(t_data *dta)
{
	int	arg;

	arg = -1;
	if (is_to_space(dta->prompt[0][0]))
		arg++;
	while (dta->prompt[++arg] && dta->exit_actual == 0)
	{
		if (is_to_space(dta->prompt[arg][0]) && (is_to_space(dta->
				prompt[arg + 1][0]) || is_to_space(dta->prompt[arg - 1][0])))
		{
			mess_error(dta, 258, "syntax error near", dta->prompt[arg]);
			dta->exit_actual = 1;
		}
	}
}

void	check_err(t_data *dta)
{
	check_err_pipe(dta);
	check_err_before_pipe(dta);
}
