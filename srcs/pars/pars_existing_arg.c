/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_existing_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:15:50 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:15:53 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	print_arg(t_data *dta)
{
	size_t	i;

	i = -1;
	while (++i < dta->nb_arg)
		ft_printf("ARG[%d] = FLAG=%s CONTENT=%s\n",
			i, dta->d_arg[i]->flag, dta->d_arg[i]->data);
}

void	replace_existing_arg(t_data *dta)
{
	int	i;
	int	j;

	i = -1;
	i = dta->nb_arg - 1;
	printf("%zu", dta->nb_arg);
	if (dta->nb_arg < 2)
		return ;
	while (i > 0)
	{
		j = i;
		while (--j >= 0)
		{
			if (ft_strncmp(dta->d_arg[i]->flag, dta->d_arg[j]->flag,
					ft_strlen(dta->d_arg[i]->flag) + 1) == 0)
			{
				if (dta->d_arg[j]->data)
					free(dta->d_arg[j]->data);
				dta->d_arg[j]->data = ft_strdup(dta->d_arg[i]->data);
			}
		}
		i--;
	}
}

int	check_arg(char *l, char *str)
{
	int	i;

	i = -1;
	if (ft_strlen(l) < ft_strlen(str))
		return (0);
	while (str[++i] != '\0')
	{
		if (l[i] != str[i])
			return (0);
	}
	if (ft_isalpha(l[i]) || l[i] == '_')
		return (0);
	return (1);
}
