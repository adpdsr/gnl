/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:28:18 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/13 17:10:48 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *ft_mem_concat(char *str, char *buff)
{
	char *tmp;

	tmp = ft_strjoin(str, buff);
	free(str);
	str = NULL;
	return (tmp);
}

static int	ft_get_line(char **line, char *buff, char *overf)
{
	char *tmp;

	if ((tmp = ft_strchr(buff, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(buff);
		ft_memmove(overf, tmp + 1, ft_strlen(tmp + 1) + 1);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char overf[BUFF_SIZE + 1];
	char		buff[BUFF_SIZE + 1];
	char 		*str;
	int 		ret;

	ft_bzero(buff, BUFF_SIZE);
	if (ft_get_line(line, overf, overf) == 1)
		return (1);
	str = ft_strdup(overf);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		str = ft_mem_concat(str, buff);
		if (ft_get_line(line, str, overf) == 1)
		{
			free(str);
			str = NULL;
			return (1);
		}
	}
	free(str);
	str = NULL;
	*line = NULL;
	return (0);
}

int		main(int ac, char **av)
{
	int fd;
	int i;
	char *line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 1;
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		printf("%d || %s\n", i, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}
