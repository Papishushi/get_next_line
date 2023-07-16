/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:15:25 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/16 17:15:25 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s++))
		count++;
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i] != '\0')
		if (s[i++] == (char) c)
			return (&s[i - 1]);
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
	if (!memory[0])
		return (NULL);
	while (memory[i] && memory[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_chop_memory(char *memory)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!memory[i])
	{
		free(memory);
		return (NULL);
	}
	str = malloc(ft_strlen(memory) - i++ + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (memory[i])
		str[j++] = memory[i++];
	str[j] = '\0';
	free(memory);
	return (str);
}
