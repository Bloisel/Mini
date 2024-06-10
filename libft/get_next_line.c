/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:05:27 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:05:31 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*read_line_fd(int fd, char *l)
{
	char	*buf;
	int		buf_len;

	buf_len = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (ft_strchr_gnl(l, '\n') == NULL && buf_len != 0)
	{
		buf_len = read(fd, buf, BUFFER_SIZE);
		if (buf_len == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[buf_len] = '\0';
		l = ft_strjoin_gnl(l, buf);
	}
	free(buf);
	return (l);
}

char	*write_line(char *l)
{
	int		i;
	char	*ret_st;

	if (!l[0])
		return (NULL);
	ret_st = (char *)malloc((ft_strlen_n_o(l) + 2) * sizeof(char));
	i = -1;
	while (l[++i] != '\n' && l[i])
		ret_st[i] = l[i];
	if (l[i] == '\n')
	{
		ret_st[i] = l[i];
		i++;
	}
	ret_st[i] = '\0';
	return (ret_st);
}

char	*next_line(char *l)
{
	int		i;
	char	*ret_st;

	if (l[ft_strlen_n_o(l)])
	{
		i = (ft_strlen_n_o(l)) + 1;
		ret_st = NULL;
		ret_st = ft_strjoin_gnl(ret_st, &l[i]);
		free(l);
		return (ret_st);
	}
	free(l);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*l = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	l = read_line_fd(fd, l);
	if (!l)
		return (NULL);
	line = write_line(l);
	l = next_line(l);
	return (line);
}
