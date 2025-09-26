# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 16:47:24 by marvin            #+#    #+#              #
#    Updated: 2025/09/26 18:58:45 by rafaoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CLIENT_BONUS_SRC = client_bonus.c
SERVER_BONUS_SRC = server_bonus.c

CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR)

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$@ ✔️"

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT_FLAGS) -o $(CLIENT)
	@echo "$(CLIENT) compilado ✔️"

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT_FLAGS) -o $(SERVER)
	@echo "$(SERVER) compilado ✔️"

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT_FLAGS) -o $(CLIENT_BONUS)
	@echo "$(CLIENT_BONUS) compilado ✔️"

$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT_FLAGS) -o $(SERVER_BONUS)
	@echo "$(SERVER_BONUS) compilado ✔️"
	
$(LIBFT):
	@echo "Compilando libft..."
	@make -C $(LIBFT_DIR)
	@echo "libft compilada ✔️"

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)
		
norminette:
	norminette $(CLIENT_SRC) $(SERVER_SRC) $(CLIENT_BONUS_SRC) $(SERVER_BONUS_SRC) -R CheckForbiddenSourceHeader

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	@make clean -C $(LIBFT_DIR) --silent
	@echo "Arquivos .o limpos 🧴"

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@make fclean -C $(LIBFT_DIR) --silent
	@echo "Tudo limpo 🧽🧼"

re: fclean all

.PHONY: all clean fclean re norminette