# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:05:17 by mzhitnik          #+#    #+#              #
#    Updated: 2024/12/22 13:09:59 by mzhitnik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = push_swap
CC = cc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	CC $< -o $@




.PHONY all clean fclean re








# gcc -o my_program main.c -I./includes -L./libs -lft (-lft tells the linker to look for libft.a (note that -l removes the lib prefix and .a extension, so libft.a becomes -lft).)