/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:14:08 by gabriela          #+#    #+#             */
/*   Updated: 2023/06/06 14:02:49 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_extract(char *s)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (s[i] == '\0')
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (s[j] && s[j] != '\n')
		line[i++] = s[j++];
	if (s[i] == '\n')
		line[i++] = s[j++];
	line[i] = '\0';
	return (line);
}

char	*ft_remainder(char *s)
{
	int		i;
	int		j;
	char	*tail;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	tail = (char *)malloc(ft_strlen(s) - i + 1);
	if (tail == NULL)
		return (NULL);
	i++;
	while (s[i] != '\0')
		tail[j++] = s[i++];
	tail[j] = '\0';
	free(s);
	return (tail);
}

char	*ft_reading(int fd, char *s)
{
	int		rd;
	char	*buf;

	rd = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (rd > 0 && !ft_strchr(s, '\n'))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s[2048];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = ft_reading(fd, s[fd]);
	if (s[fd] == NULL)
		return (NULL);
	line = ft_extract(s[fd]);
	s[fd] = ft_remainder(s[fd]);
	return (line);
}