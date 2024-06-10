/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_triple_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:15:38 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:15:41 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	is_background(char **str)
{
	size_t	i;
	size_t	ret;

	i = -1;
	ret = 0;
	while (str[++i])
		if (str[i][0] == '|' && str[i][1] != '|')
			ret++;
	return (ret);
}

int	len_tab_bg(char **str)
{
	size_t	i;
	size_t	ret;

	i = -1;
	ret = 0;
	while (str[++i][0] != '|' && str[i])
		if (str[i][0] != ('E' * -1))
			ret++;
	return (ret);
}

char	**dup_tab(t_data *dta)
{
	size_t	i;
	size_t	j;
	char	**new;

	new = malloc(sizeof(char *) * (len_tab_bg(dta->prompt) + 2));
	i = -1;
	j = 0;
	while (dta->prompt[++i] && dta->prompt[i][0] != '|')
	{
		if (dta->prompt[i][0] != ('E' * -1))
		{
			new[j] = ft_strdup(dta->prompt[i]);
			free(dta->prompt[i]);
			dta->prompt[i] = ft_strdup(dta->empty);
			j++;
		}
	}
	new[j] = ft_strdup(dta->prompt[i]);
	free(dta->prompt[i]);
	dta->prompt[i] = ft_strdup(dta->empty);
	new[j + 1] = NULL;
	return (new);
}

char	**no_fork(t_data	*dta, int i)
{
	size_t	j;
	char	**new;

	j = 0;
	while (dta->prompt[++i])
		if (dta->prompt[i][0] != ('E' * -1))
			j++;
	if (j == 0)
		return (NULL);
	dta->nb_cmd_p++;
	new = malloc(sizeof(char *) * (j + 2));
	i = -1;
	j = 0;
	while (dta->prompt[++i])
	{
		if (dta->prompt[i][0] != ('E' * -1))
		{
			new[j++] = ft_strdup(dta->prompt[i]);
			free(dta->prompt[i]);
			dta->prompt[i] = ft_strdup(dta->empty);
		}
	}
	new[j] = NULL;
	return (new);
}

void	init_triple(t_data *dta)
{
	size_t	i;

	i = 0;
	if (dta->prompt == NULL)
		return ;
	dta->nb_cmd_p = 0;
	dta->p = malloc(sizeof(char **) * (is_background(dta->prompt) + 2));
	while (is_background(dta->prompt))
	{
		dta->p[i] = dup_tab(dta);
		i++;
		dta->nb_cmd_p++;
	}
	dta->p[i] = no_fork(dta, -1);
	dta->p[i + 1] = NULL;
}
