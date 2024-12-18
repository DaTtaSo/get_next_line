/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:23:53 by nbedouan          #+#    #+#             */
/*   Updated: 2024/12/16 17:31:57 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	s_len;
	size_t	i;

	s_len = 0;
	while (str[s_len] != '\n' && str[s_len] != 0)
		s_len++;
	if (str[s_len] == '\n')
		s_len++;
	dup = malloc((s_len + 1) * sizeof(char));
	if (dup == NULL)
		return (dup);
	i = 0;
	while (i < s_len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s2[len2] != '\n' && s2[len2] != 0)
		len2++;
	if (s2[len2] == '\n')
		len2++;
	len1 = ft_strlen(s1);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, (len1 + 1));
	free(s1);
	ft_strlcpy(res + len1, s2, (len2 + 1));
	return (res);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
