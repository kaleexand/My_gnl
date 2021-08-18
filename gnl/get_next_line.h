/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalexand <kalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:37:32 by kalexand          #+#    #+#             */
/*   Updated: 2020/12/23 16:09:29 by kalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlen(const char *str);
#endif
