/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamrani <mlamrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:58:26 by mlamrani          #+#    #+#             */
/*   Updated: 2024/02/01 15:42:16 by mlamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;
	size_t	len_s;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
	{
		return (ft_strdup(""));
	}
	if (len > len_s - start)
	{
		len = len_s - start;
	}
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	len += start;
	while (start < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *s)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(sizeof(char) * ((ft_strlen(s)) + 1));
	if (!p)
		return (NULL);
	while (*s)
		p[i++] = *s++;
	p[i] = '\0';
	return (p);
}

static char	*setup(int fd, char *str, ssize_t i)
{
	char	*tab;
	char	*temp_str;

	if (!str)
		return (NULL);
	tab = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!tab)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, tab, BUFFER_SIZE);
		if (i == -1)
			return (free(tab), free(str), NULL);
		tab[i] = '\0';
		temp_str = ft_strjoin(str, tab);
		free(str);
		str = temp_str;
		if (ft_strchr(tab, '\n'))
			break ;
	}
	free(tab);
	if (i == 0 && (str[0] == '\0'))
		return (free(str), NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*tmp[MAX_FD];
	char		*line;
	int			j;
	char		*tmp_copy;

	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if (tmp[fd] == NULL)
	{
		tmp[fd] = ft_strdup("");
		if (!tmp[fd])
			return (NULL);
	}
	tmp[fd] = setup(fd, tmp[fd], 1);
	if (tmp[fd] == NULL)
		return (NULL);
	while (tmp[fd][j] && tmp[fd][j] != '\n')
		j++;
	line = ft_substr(tmp[fd], 0, j += 1);
	tmp_copy = tmp[fd];
	tmp[fd] = ft_substr(tmp[fd], j, ft_strlen(tmp[fd]));
	if (tmp_copy)
		free(tmp_copy);
	return (line);
}
