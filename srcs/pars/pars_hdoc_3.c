/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_hdoc_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:16:06 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:16:09 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	set_arg(t_data *dta, int *arg)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	ret = 0;
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '.' && dta->keys)
		{
			j = -1;
			while (dta->keys[++j])
				if (!(ft_strncmp(&dta->prompt_t[i],
							dta->keys[j], ft_strlen(dta->keys[j]))))
						ret += 1;
		}
	}
	if (ret == dta->key_done)
		*arg = 0;
	else
	{
	*arg = ret - dta->key_done;
	dta->key_done += *arg;
	}
}

int	nb_key(t_data *dta)
{
	int	i;

	i = -1;
	while (dta->keys[++i])
		;
	return (i);
}

void	reconstruct_prompt_2(t_data *dta, int *i, int *j, char *new)
{
	int	k;
	int	arg;

	k = 0;
	arg = 0;
	while (!is_sep(dta->prompt_t[*i]) && dta->prompt_t[*i])
		*i += 1;
	if (dta->keys[arg] != NULL)
	{
		while (dta->keys[arg])
		{
			k = 0;
			while (dta->keys[arg][k])
			{
				new[*j] = dta->keys[arg][k++];
				*j += 1;
			}
			free(dta->keys[arg]);
			dta->keys[arg] = ft_strdup(" ");
			new[*j] = ' ';
			*j += 1;
			arg++;
		}
	}
}
