/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 03:11:25 by nbedouan          #+#    #+#             */
/*   Updated: 2024/12/18 04:15:08 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	cleaner(char *str)
{
	if (ft_strchr(str, '\n') && str[0] != '\0')
		ft_strlcpy(str, ft_strchr(str, '\n') + 1, \
		ft_strlen(ft_strchr(str, '\n')));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*join_read(char *to_read, char *n_line, int *bytes_read, int fd)
{
	n_line = ft_strjoin(n_line, to_read);
	if (!n_line)
		return (free(n_line), NULL);
	if (ft_strchr(n_line, '\n'))
		return (n_line);
	*bytes_read = read(fd, to_read, BUFFER_SIZE);
	if (*bytes_read < 0)
	{
		to_read[0] = '\0';
		return (free(n_line), NULL);
	}
	to_read[*bytes_read] = '\0';
	return (n_line);
}

char	*get_next_line(int fd)
{
	static char	to_read[fd][BUFFER_SIZE + 1];
	char		*n_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n_line = ft_strdup("");
	if (!n_line)
		return (free(n_line), NULL);
	bytes_read = 1;
	while (bytes_read)
	{
		n_line = join_read(to_read[fd], n_line, &bytes_read, fd);
		if (!n_line)
			return (NULL);
		if (ft_strchr(n_line, '\n'))
			break ;
	}
	cleaner(to_read[fd]);
	if (n_line && n_line[0] == 0)
		return (free(n_line), NULL);
	return (n_line);
}
