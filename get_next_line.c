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

char	*get_next_line(int fd)
{
	static char to_read[BUFFER_SIZE + 1]= '\0';
	char	*n_line;
	int	bytes_read;

bytes_read = 0;
if (!fd || BUFFER_SIZE <= 0)
	return (NULL);
	n_line = ft_strdup()
}
