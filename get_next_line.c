/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:55:44 by nbedouan          #+#    #+#             */
/*   Updated: 2024/12/14 19:25:59 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	cleaner(char *str)
{
	if (ft_strchr(str, '\n') && str[0] != '\0')
		ft_strlcpy(str, ft_strchr(str, '\n') + 1, ft_strlen(ft_strchr(str, '\n')));
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

char	*get_next_line(int fd)
{
	static char	to_read[BUFFER_SIZE + 1] = "\0";
	char		*n_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n_line = ft_strdup("");
	if (!n_line)
		return (NULL);
	bytes_read = 1;
	while (bytes_read)
	{
		n_line = ft_strjoin(n_line, to_read);
		if (!n_line)
			return (NULL);
		if (ft_strchr(n_line, '\n'))
			break ;
		bytes_read = read(fd, to_read, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			to_read[0] = '\0';
			return (free(n_line), NULL);
		}
		to_read[bytes_read] = '\0';
	}
	cleaner(to_read);
	if (n_line[0] == 0)
		return (free(n_line), NULL);
	return (n_line);
}
