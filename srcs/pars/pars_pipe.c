/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:16:38 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:16:39 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

int	check_first_c_pipe(char *str)
{
	size_t	i;

	i = -1;
	if (!str)
		return (1);
	while (is_sep(str[++i]))
		;
	if (str[i] == '|')
		return (0);
	return (1);
}

char	*pipe_prompt(t_data *dta)
{
	char	*old;

	old = dta->pipe_str;
	if (dta->nb_pipe == 0)
		dta->pipe_str = ft_strdup("\033[0;32mpipe>\033[0;37m");
	else if (dta->nb_pipe == 1)
		dta->pipe_str = ft_strdup("\033[0;32mpipe pipe>\033[0;37m");
	else
		dta->pipe_str = ft_strdup("\033[0;32mpipe pipe quote>\033[0;37m");
	free(old);
	return (dta->pipe_str);
}

void	add_after_pipe(t_data *dta, char *str, char *temp)
{
	size_t	i;

	while (dta->exit_multi_pipe != 2)
	{
		str = readline(pipe_prompt(dta));
		i = -1;
		if (str != NULL)
		{
			if (!check_first_c_pipe(str))
				dta->exit_multi_pipe = 2;
			while (str[++i])
			{
				dta->nb_pipe++;
				if (!is_sep(str[i]))
				{
					temp = ft_strjoin(dta->prompt_t, str);
					free(dta->prompt_t);
					dta->prompt_t = temp;
					free(str);
					return ;
				}
			}
		}
		free(str);
	}
}

void	replace_pipe(t_data *dta)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = 0;
	new = malloc(sizeof(char) * (nb_charinstr(dta
					->prompt_t, '|') * 2) + ft_strlen(dta->prompt_t));
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '|')
		{
			new[j] = ' ';
			new[j + 1] = '|';
			new[j + 2] = ' ';
			j += 2;
		}
		else
			new[j] = dta->prompt_t[i];
		j++;
	}
	new[j] = '\0';
	free(dta->prompt_t);
	dta->prompt_t = new;
}

void	check_end_pipe(t_data *dta)
{
	dta->nb_pipe = 0;
	dta->exit_multi_pipe = 0;
	if (dta->prompt_t[0] == '\0' || !check_first_c_pipe(dta->prompt_t)
		|| nb_charinstr(dta->prompt_t, '|') == 0)
		return ;
	while (check_last_char(dta->prompt_t, '|') && dta->exit_multi_pipe != 2)
		add_after_pipe(dta, NULL, NULL);
}
