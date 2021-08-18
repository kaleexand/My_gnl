/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalexand <kalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:36:42 by kalexand          #+#    #+#             */
/*   Updated: 2021/01/06 14:28:55 by kalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_static_reminder(char **static_reminder)
{
	if (*static_reminder)
		free(*static_reminder);
	*static_reminder = NULL;
	return (0);
}

int		ft_null(char *str)
{
	while (*str)
	{
		*str = '\0';
		str++;
	}
	return (1);
}

char	*str_remainder(char *static_reminder, char **line)
{
	char *str;

	str = NULL;
	if (static_reminder)
	{
		if ((str = ft_strchr(static_reminder, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(static_reminder);
			ft_strcpy(static_reminder, ++str);
		}
		else
		{
			*line = ft_strdup(static_reminder);
			ft_null(static_reminder);
		}
	}
	else
		*line = ft_strdup("");
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*pointer;
	static char	*static_reminder;
	int			i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	pointer = str_remainder(static_reminder, line);
	while (!pointer && ((i = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[i] = '\0';
		if ((pointer = ft_strchr(buf, '\n')))
		{
			*pointer = '\0';
			if (static_reminder)
				free(static_reminder);
			if (!(static_reminder = ft_strdup(++pointer)))
				return (-1);
		}
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
	}
	return ((i || ft_strlen(static_reminder)) ? 1 :
		free_static_reminder(&static_reminder));
}
