# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masoares <masoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:50:35 by masoares          #+#    #+#              #
#    Updated: 2023/12/19 10:00:08 by masoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = pipex.c pipex_utils.c

SRCS_BONUS = pipex_bonus.c pipex_utils_bonus.c errors_bonus.c

CFLAGS = -Wall -Werror -Wextra -g

BONUS = pipex_bonus 

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = ./libft/libft.a

HEADER = pipex.h

NAME = pipex

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(LIBFT)
	cc $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS)

$(LIBFT):
	make -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
	rm -f $(BONUS)
	
clean:
	make clean -C ./libft
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

re: fclean all

.PHONY: all fclean clean re