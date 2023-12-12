NAME = libftprintf.a

SRCS =  ft_putnbr_base.c ft_putnbr_base_sc.c \
	ft_strlen.c ft_count_num.c \
	ft_putchar_fd.c ft_putstr_fd.c \
	ft_putnbr_fd.c ft_putunbr_fd.c \
	ft_putadd_fd.c ft_printf.c\
	ft_count_num2.c

#BSRCS = 

OBJS = $(SRCS:.c=.o)

#BOBJS = $(BSRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

HEADERS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS) 
		ar rcs $(NAME) $(OBJS)

#bonus: $(NAME) $(BOBJS) $(OBJS)
#	ar rcs $(NAME) $(BOBJS)	

#$(BOBJS): $(BSRCS)
#	cc $(CFLAGS) -c $(BSRCS)

clean :
		rm -f $(OBJS) $(BOBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY = fclean clean all bonus re
