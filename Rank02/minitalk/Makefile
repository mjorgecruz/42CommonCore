CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_BONUS_SRC = client_bonus.c
SERVER_BONUS_SRC = server_bonus.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ_BONUS = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_OBJ_BONUS = $(SERVER_BONUS_SRC:.c=.o)
LIBFT = ./libft/libft.a

all: client server
	
client: $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o client

server: $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o server 

#%.o: %.c
#	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT): 
	make -C ./libft

bonus: client_bonus server_bonus

client_bonus: $(CLIENT_OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ_BONUS) $(LIBFT) -o client_bonus

server_bonus: $(SERVER_OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ_BONUS) $(LIBFT) -o server_bonus

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	rm -f $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)
	make clean -C ./libft

fclean:
	rm -f client server $(CLIENT_OBJ) $(SERVER_OBJ)
	rm -f client_bonus server_bonus $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)
	make fclean -C ./libft

re: fclean all

.PHONY: all fclean clean re