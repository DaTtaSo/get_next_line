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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	final_size;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	final_size = nmemb * size;
	ptr = malloc(final_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, final_size);
	return (ptr);
}

void	ft_bzero(void *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		*str = 0;
		str++;
	}
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		s_len;

	s_len = ft_strlen(s);
	dup = malloc((s_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[s_len] = 0;
	while (s_len >= 0)
	{
		dup[s_len] = s[s_len];
		s_len--;
	}
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, (len1 + 1));
	ft_strlcpy(res + len1, s2, (len2 + 1));
	return (res);
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


void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_data;
	unsigned const char	*src_data;

	if (!dest && !src)
		return (NULL);
	if (src > dest)
		dest = ft_memcpy(dest, src, n);
	else
	{
		dest_data = (unsigned char *) dest;
		src_data = (unsigned const char *) src;
		while (n-- > 0)
			dest_data[n] = src_data[n];
	}
	return (dest);
}
