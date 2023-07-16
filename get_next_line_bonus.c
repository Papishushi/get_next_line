/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:15:50 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/16 17:15:50 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	static char	*memory[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	memory[fd] = ft_read_till_nl(fd, memory[fd]);
	if (!memory[fd])
		return (NULL);
	line = ft_get_line(memory[fd]);
	memory[fd] = ft_chop_memory(memory[fd]);
	return (line);
}
