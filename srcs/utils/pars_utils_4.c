/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:17:59 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:18:00 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_tab(t_data *dta)
{
	size_t	i;
	char	*t;

	i = -1;
	while (dta->prompt_t[++i])
		if (dta->prompt_t[i] == '\t')
			dta->prompt_t[i] = ' ';
	t = dta->prompt_t;
	dta->prompt_t = ft_strjoin(dta->prompt_t, "     ");
	free(t);
	t = dta->prompt_t;
	dta->prompt_t = ft_strjoin(" ", dta->prompt_t);
	free(t);
}

void	stop_handle(t_data *dta, int i)
{
	while (dta->prompt_t[++i])
		if (is_to_space(dta->prompt_t[i] * -1))
			dta->prompt_t[i] = dta->prompt_t[i] * -1;
}

void	handle_in_quote(t_data *dta, int i)
{
	int	in;
	int	in2;

	in = -1;
	in2 = -1;
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '"' && in2 == -1)
			in *= -1;
		if (dta->prompt_t[i] == '\'' && in == -1)
			in2 *= -1;
		if (is_to_space(dta->prompt_t[i]) && (in == 1 || in2 == 1))
			dta->prompt_t[i] = dta->prompt_t[i] * -1;
	}
}

void	prepare_for_next(t_data*dta)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 2);
	tab[0] = ft_strdup("test");
	tab[1] = NULL;
	dta->actual = tab;
	run_cmd_no_pipe(dta);
	free(dta->actual[0]);
	free(dta->actual);
	g_exit_status = dta->ready_next;
}

void	remove_from_arglst(t_data *dta, char *str)
{
	int	i;

	i = -1;
	while (dta->d_arg[++i])
		;
	while (--i >= 0)
	{
		if (ft_memcmp(dta->d_arg[i]->flag,
				str, ft_strlen(dta->d_arg[i]->flag) + 1) == 0)
		{
			free(dta->d_arg[i]->data);
			dta->d_arg[i]->data = ft_strdup("  ");
			free(dta->d_arg[i]->flag);
			dta->d_arg[i]->flag = ft_strdup("*****");
			return ;
		}
	}
}
