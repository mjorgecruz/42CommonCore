# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masoares <masoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:50:35 by masoares          #+#    #+#              #
#    Updated: 2023/12/18 18:42:43 by masoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = pipex.c pipex_utils.c

CFLAGS = -Wall -Werror -Wextra -g

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

HEADER = pipex.h

NAME = pipex

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


$(LIBFT):
	make -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
	
clean:
	make clean -C ./libft
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re