# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 16:47:24 by marvin            #+#    #+#              #
#    Updated: 2025/09/15 16:47:24 by marvin           ###   ########.fr        #
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

LIBFT_DIR = libft
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

$(LIBFT):
	@echo "Compilando libft..."
	@make -C $(LIBFT_DIR)
	@echo "libft compilada ✔️"

norminette:
	norminette $(CLIENT_SRC) $(SERVER_SRC) -R CheckForbiddenSourceHeader

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@make clean -C $(LIBFT_DIR)
	@echo "Arquivos .o limpos 🧴"

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(CLIENT), $(SERVER) e libft limpos 🧽🧼"

re: fclean all

.PHONY: all clean fclean re norminette