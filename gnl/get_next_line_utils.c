/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalexand <kalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:37:06 by kalexand          #+#    #+#             */
/*   Updated: 2020/12/23 16:11:02 by kalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
{
	char *s;

	s = (char*)str;
	while (*s != '\0')
	{
		if (*s == (char)ch)
			return (s);
		s++;
	}
	if (ch == '\0')
		return (s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*str1;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[len] != '\0')
		len++;
	str1 = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str1)
		return (NULL);
	while (i < len)
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*s3;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	s3 = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		s3[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2 && s2[j] != '\0')
	{
		s3[i] = s2[j];
		++i;
		++j;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}
