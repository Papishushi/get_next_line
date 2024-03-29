/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:23:07 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/15 18:44:24 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_till_nl(const int fd, char *memory)
{
	char	*chunk;
	int		rd_bytes;

	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(memory, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, chunk, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(memory);
			free(chunk);
			return (NULL);
		}
		chunk[rd_bytes] = '\0';
		memory = ft_strjoin(memory, chunk);
	}
	free(chunk);
	return (memory);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memory;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	memory = ft_read_till_nl(fd, memory);
	if (!memory)
		return (NULL);
	line = ft_get_line(memory);
	memory = ft_chop_memory(memory);
	return (line);
}
