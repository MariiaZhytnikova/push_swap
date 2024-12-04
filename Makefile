# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:05:17 by mzhitnik          #+#    #+#              #
#    Updated: 2024/12/04 15:08:38 by mzhitnik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = push_swap.exe
CC = cc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	CC $< -o $@




.PHONY all clean fclean re