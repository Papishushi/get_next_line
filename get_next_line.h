/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:16:05 by dmoliner          #+#    #+#             */
/*   Updated: 2023/01/13 20:50:46 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
///Debug
#include<fcntl.h>
#include<errno.h>
extern int errno;

char *get_next_line(int fd);

#endif
