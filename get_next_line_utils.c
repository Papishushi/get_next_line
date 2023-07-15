/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:31:53 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/14 20:34:39 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i] != '\0'){
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *memory, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!memory)
	{
		memory = malloc(1);
		memory[0] = '\0';
	}
	if (!memory || !buff)
		return (NULL);
	str = malloc((ft_strlen(memory) + ft_strlen(buff)) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (memory)
		while (memory[++i] != '\0')
			str[i] = memory[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(memory) + ft_strlen(buff)] = '\0';
	free(memory);
	return (str);
}

char	*ft_get_line(char *memory)
{
	int		i;
	char	*line;

	i = 0;
	//If the first char is NULL return NULL
	if (!memory[0])
		return (NULL);
	//Count the number of chars in the line
	while (memory[i] && memory[i] != '\n')
		i++;
	//Alloc space for the number of chars in the line + 2 bytes
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	//Increase i and assign to line the current char while is not NULL nor nl
	while (memory[i] && memory[i] != '\n'){
		line[i] = memory[i];
		i++;
	}
	//If the last char is nl asign nl to line[i] and increase i
	if (memory[i] == '\n')
		line[i++] = '\n';
	//Assign NULL char to last char and return the line
	line[i] = '\0';
	return (line);
}

char	*ft_chop_memory(char *memory)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	//Count the first number of chars in the buffer up until nl
	while (memory[i] && memory[i] != '\n')
		i++;
	//If last character is NULL free buffer and return NULL
	if (!memory[i]){
		free(memory);
		return (NULL);
	}
	//Alloc the lenght of the full buffer minus the chars until nl
	str = malloc(ft_strlen(memory) - i++ + 1);
	if (!str)
		return (NULL);
	j = 0;
	//Copy the contents of memory to str up to NULL byte
	while (memory[i])
		str[j++] = memory[i++];
	//Finalize the string and return the buffer with the start chopped
	str[j] = '\0';
	free(memory);
	return (str);
}
