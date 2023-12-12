CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = push_swap_errors.c push_swap_lists.c push_swap_utils.c \
	push_swap.c ft_p_stack.c ft_r_stack.c ft_rr_stack.c \
	ft_s_stack.c push_swap_sorter.c push_swap_s_utils_mover.c \
	push_swap_s_utils.c push_swap_s_utils_2.c \
	push_swap_s_utils_3.c
	
BONUS_SRCS = checker.c push_swap_errors_bonus.c push_swap_lists_bonus.c \
	push_swap_utils_bonus.c push_swap_sorter_bonus.c\
	ft_p_stack_bonus.c ft_r_stack_bonus.c ft_rr_stack_bonus.c ft_s_stack_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)
LIBFT = ./libft/libft.a

NAME = push_swap 

PUSH_SWAP_BONUS = checker

all: $(NAME)

bonus: $(PUSH_SWAP_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap
	
#%.o: %.c
#	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT): 
	make -C ./libft


$(PUSH_SWAP_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(PUSH_SWAP_BONUS)

fclean: clean
	rm -f push_swap
	rm -f checker
	make fclean -C ./libft
clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make clean -C ./libft

re: fclean all

.PHONY: all fclean clean re