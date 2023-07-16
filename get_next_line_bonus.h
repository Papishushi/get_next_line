/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:32:09 by dmoliner          #+#    #+#             */
/*   Updated: 2023/07/16 17:29:46 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# ifndef FD_MAX
#  define FD_MAX 4096
# endif

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *memory, char *buff);
size_t	ft_strlen(const char *s);
char	*ft_read_till_nl(int fd, char *memory);
char	*ft_get_line(char *memory);
char	*ft_chop_memory(char *memory);
char	*get_next_line(int fd);

#endif
