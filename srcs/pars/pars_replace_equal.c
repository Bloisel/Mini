/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_replace_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:16:50 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:16:52 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	replace_not_in_db(t_data *dta, size_t len, size_t i, int exist)
{
	size_t	j;

	j = -1;
	while (dta->prompt_t[++j])
	{
		if (dta->prompt_t[j] == '$' && dta->prompt_t[j + 1] == '$')
			mess_error(dta, 1, "syntax error near :", "$");
		else if (dta->prompt_t[j] == '$' && dta->prompt_t[j + 1] == '?')
			return ;
		else if (dta->prompt_t[j] == '$')
		{
			i = 0;
			len = -1;
			j++;
			while (!is_sep(dta->prompt_t[j + ++len]) && !is_sep(dta->prompt_t
					[j + len] * -1) && dta->prompt_t[j + len]
				&& ft_isalpha(dta->prompt_t[j + len]));
			while (i < dta->nb_arg)
				if (check_arg(&dta->prompt_t[j],
						dta->d_arg[i++]->flag) == 1)
					exist = 1;
			if (!exist)
				dta->prompt_t[j - 1] = dta->prompt_t[j - 1] * -1;
		}
	}
}

size_t	get_len_replace(t_data *dta)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (dta->prompt_t[++i + j])
	{
		if (dta->prompt_t[i + j] == '$')
		{
			while (!is_sep(dta->prompt_t[i + j] * -1)
				&& dta->prompt_t[i + j] != '\0')
			{
				j++;
			}
		}
	}
	return (i);
}

size_t	replace_arg_2(t_data *dta, size_t i, size_t *m, char *tmp)
{
	size_t	k;
	size_t	l;
	int		j;

	k = dta->nb_arg;
	j = -1;
	while (!is_sep(dta->prompt_t[i + ++j + 1] * -1) && !is_sep(dta
			->prompt_t[i + j + 1]) && dta->prompt_t[i + j + 1] != '$'
		&& dta->prompt_t[i + j + 1] && dta->prompt_t[i + j + 1] > 0
		&& ft_isalpha(dta->prompt_t[i + j + 1]));
	while (--k >= 0)
	{
		l = -1;
		if (ft_strnstr(&dta->prompt_t[i + 1],
				dta->d_arg[k]->flag, j + 1) != NULL)
		{
			while (dta->d_arg[k]->data[++l])
			{
				tmp[*m] = dta->d_arg[k]->data[l];
				*m += 1;
			}
			return (j);
		}
	}
	return (j);
}

size_t	replace_arg_3(t_data *dta, size_t *m, char *tmp)
{
	char	*num;

	num = ft_itoa(g_exit_status);
	if (dta->status == 130)
	{
		free(num);
		num = ft_strdup("130");
	}
	ft_strlcat(tmp, num, 250000);
	*m = *m + ft_strlen(num);
	free(num);
	return (1);
}

char	*replace_arg(t_data *dta)
{
	size_t	i;
	size_t	m;
	char	*tmp;

	i = -1;
	m = 0;
	if (dta->nb_arg != 0)
	{
		tmp = malloc(sizeof(char)
				* ft_strlen(dta->prompt_t) + 300);
		ft_bzero(tmp, ft_strlen(dta->prompt_t) + 299);
		while (dta->prompt_t[++i])
		{
			if (dta->prompt_t[i] == '$' && dta->prompt_t[i + 1] != '?')
				i += replace_arg_2(dta, i, &m, tmp);
			else if (dta->prompt_t[i] == '$' && dta->prompt_t[i + 1] == '?')
				i += replace_arg_3(dta, &m, tmp);
			else
				tmp[m++] = dta->prompt_t[i];
		}
		return (tmp);
	}
	return (dta->prompt_t);
}

					// if (strstr_el(&dta->prompt_t[j], dta->d_arg[i]->flag,
					// 		ft_strlen(dta->d_arg[i]->flag), len - 1) != NULL
					// 	&& strstr_el(&dta->prompt_t[j], "$?", 1, len - 1) != NULL)