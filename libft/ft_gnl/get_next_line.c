/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:51 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/08 13:28:51 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_instruction(char *buffer, int fd)
{
	int	rd;

	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd == -1)
		return (free(buffer), NULL);
	buffer[rd] = 0;
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_instruction(buffer, fd);
	if (!line)
		return (NULL);
	return (line);
}
