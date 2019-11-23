/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:39:14 by tbeguin           #+#    #+#             */
/*   Updated: 2019/01/04 17:38:40 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_next_line(char **line_fd, char **line, const int fd,
		ssize_t ret)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line_fd[fd][i] != '\0' && line_fd[fd][i] != '\n')
		i++;
	if (line_fd[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(line_fd[fd]);
		ft_strdel(&line_fd[fd]);
	}
	else if (line_fd[fd][i] == '\n')
	{
		*line = ft_strsub(line_fd[fd], 0, i);
		tmp = ft_strdup(line_fd[fd] + 1 + i);
		free(line_fd[fd]);
		line_fd[fd] = tmp;
		if (line_fd[fd][0] == '\0')
			ft_strdel(&line_fd[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char			*line_fd[4096];
	char				buff[BUFF_SIZE + 1];
	char				*tmp;
	ssize_t				ret;

	if (fd < 0 || BUFF_SIZE <= 0 || BUFF_SIZE > 2147483647 ||
			read(fd, &tmp, 0) < 0 || line == NULL || fd > 4096 || fd < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (line_fd[fd] == NULL)
			line_fd[fd] = ft_strnew(1);
		tmp = ft_strjoin(line_fd[fd], buff);
		free(line_fd[fd]);
		line_fd[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if ((line_fd[fd] == NULL || line_fd[fd][0] == '\0') && ret == 0)
		return (0);
	return (ft_next_line(line_fd, line, fd, ret));
}
