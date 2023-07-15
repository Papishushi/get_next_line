/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:32:09 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/14 20:34:42 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_till_nl(int fd, char *memory);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *memory, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *memory);
char	*ft_chop_memory(char *memory);

#endif
