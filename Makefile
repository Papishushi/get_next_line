# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 08:45:32 by dmoliner          #+#    #+#              #
#    Updated: 2023/07/11 08:45:32 by dmoliner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=128
NAME = gnl
RM = rm -rf
COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m
################################################################################
##								MANDATORY									  ##
################################################################################
CFILES = \
		get_next_line.c \
		get_next_line_utils.c
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
################################################################################
##									BONUS									  ##
################################################################################
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
OBJS = $(CFILES:.c=.o)
################################################################################

################################################################################
.PHONY: all re fclean clean
################################################################################
all:        $(NAME)
	make &> /tmp/make.log

$(NAME): $(OBJS)
	@echo "😈 $(COLOR_BLUE)Compilando ejecutable final: $(NAME)$(COLOR_END) 😈"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[A✅ $(COLOR_BLUE)¡Hecho!$(COLOR_END) ✅"

%.o:%.c
			@echo "😈 $(COLOR_BLUE)Compilando archivo obj: $(@)$(COLOR_END) 😈"
			@$(CC) $(CFLAGS) -c $^ -o $@
			@echo "\r\033[A✅ $(COLOR_BLUE)¡Hecho!$(COLOR_END) ✅"

re:     	fclean all

fclean: clean
			@$(RM) $(NAME)

clean:
			@$(RM) $(OBJS)

# $<: rule target file (input)
# $@: rule source file (output)
