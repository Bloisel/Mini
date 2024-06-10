/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_hdoc_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:16:00 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:16:02 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../include/minishell.h"

void	reconstruct_prompt(t_data *dta, int i, int j)
{
	char	*new;
	char	*tmp;

	new = malloc(sizeof(char) * (ft_strlen(dta->prompt_t) + 3));
	ft_bzero(new, (ft_strlen(dta->prompt_t) + 3));
	while (dta->prompt_t[++i])
	{
		if (dta->prompt_t[i] == '<' && dta->prompt_t[i + 1] == '<')
		{
			i += 2;
			while (is_sep(dta->prompt_t[i]) && dta->prompt_t[i])
				i++;
			reconstruct_prompt_2(dta, &i, &j, new);
		}
		else
		{
			new[j] = dta->prompt_t[i];
			j++;
		}
	}
	new[j] = '\0';
	new[j + 1] = 0;
	tmp = dta->prompt_t;
	dta->prompt_t = new;
	free(tmp);
}

void	init_keys(t_data *dta, char *key)
{
	dta->keys = malloc(sizeof(char *) * 2);
	dta->keys[0] = key;
	dta->keys[1] = NULL;
}

void	store_key(t_data *dta, char *key)
{
	char	**tmp;
	int		i;

	i = -1;
	if (dta->keys == NULL)
		init_keys(dta, key);
	else
	{
		while (dta->keys[++i])
			if (!ft_strncmp(dta->keys[i], key, 1024))
				return ;
		tmp = malloc(sizeof(char *) * (i + 2));
		i = -1;
		while (dta->keys[++i])
			tmp[i] = dta->keys[i];
		tmp[i] = key;
		tmp[i + 1] = NULL;
		if (dta->keys)
			free(dta->keys);
		dta->keys = tmp;
	}
}

void	put_str_in_new_file(char *str, char *key, t_data *dta)
{
	int		fd;
	char	*key_dot;

	key_dot = ft_strjoin(".", key);
	if (open(key_dot, O_WRONLY, 0644) > 0)
		unlink(key_dot);
	fd = open(key_dot, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Error when opening the file");
		exit(EXIT_FAILURE);
	}
	if (str[0] != '\0' && str[0] != '\n')
		write(fd, str, ft_strlen(str));
	store_key(dta, key_dot);
	close(fd);
	if (str != NULL)
		free(str);
	free(key);
}
