/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_historic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:16:19 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:16:22 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	init_historic(t_data *dta, char *new)
{
	dta->historique = malloc(sizeof(char *) * 2);
	dta->historique[0] = new;
	dta->historique[1] = NULL;
	dta->nb_arg_hist = 1;
}

void	print_historic(t_data *dta)
{
	size_t	arg;
	size_t	i;

	arg = -1;
	i = 0;
	while (++arg < dta->nb_arg_hist)
		printf("[%04zu]: %s\n", i += 1, dta->historique[arg]);
}

void	add_historic(t_data *dta)
{
	size_t	i;
	char	*new;
	char	*new2;
	char	**n_lst;

	i = dta->nb_arg_hist;
	new = ft_strdup(dta->prompt_t);
	new2 = ft_strdup(dta->prompt_t);
	if (dta->nb_arg_hist != 0)
	{
		n_lst = malloc(sizeof(char *) * (i + 3));
		i = -1;
		while (++i < dta->nb_arg_hist)
			n_lst[i] = dta->historique[i];
		n_lst[i] = new;
		n_lst[i + 1] = NULL;
		free(dta->historique);
		dta->historique = n_lst;
		dta->nb_arg_hist += 1;
	}
	else
		init_historic(dta, new);
	free(dta->prompt_t);
	dta->prompt_t = new2;
}
