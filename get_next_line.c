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

	//Allocate buffer for reading and return NULL if an error ocurred.
	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	//Set rd_bytes to 1 so while loop works first time.
	rd_bytes = 1;
	//Loop while memory does not contain a '\n' and read() continues reading.
	while (!ft_strchr(memory, '\n') && rd_bytes != 0){
		//Read to buffer up to BUFFER_SIZE
		rd_bytes = read(fd, chunk, BUFFER_SIZE);
		//If EOF return NULL
		if (rd_bytes == -1)
		{
			free(memory);
			free(chunk);
			return (NULL);
		}
		//Ensure ending the string with null character
		chunk[rd_bytes] = '\0';
		//Join memory to buff
		memory = ft_strjoin(memory, chunk);
	}
	free(chunk);
	return (memory);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memory;

	//Check for invalid fd or invalid BUFFER_SIZE
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	//Read from fd using BUFFER_SIZE until the chunk contains a nl
	memory = ft_read_till_nl(fd, memory);
	if (!memory)
		return (NULL);
	//Get a line from memory or NULL if there is an error
	line = ft_get_line(memory);
	//Chop the line from the static memory
	if (memory)
		memory = ft_chop_memory(memory);
	return (line);
}
