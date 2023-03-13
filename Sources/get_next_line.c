/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:37:49 by lreille           #+#    #+#             */
/*   Updated: 2023/03/09 23:55:22 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		re;

	buffer = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	line = NULL;
	re = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	if (re > 0)
		line = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	while (re > 0 && buffer[0] != '\n')
	{
		line = ft_strjoin(line, buffer);
		re = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	}
	if (buffer[0] == '\n')
		line = ft_strjoin(line, "\n");
	free(buffer);
	return (line);
}
