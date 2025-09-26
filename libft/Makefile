# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 11:31:58 by rafaoliv          #+#    #+#              #
#    Updated: 2025/09/26 18:58:10 by rafaoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS_BASIC = 	src/basic/ft_isalnum.c \
				src/basic/ft_isalpha.c \
				src/basic/ft_isascii.c \
				src/basic/ft_isdigit.c \
				src/basic/ft_isprint.c \
				src/basic/ft_strlen.c \
				src/basic/ft_toupper.c \
				src/basic/ft_tolower.c \
				src/basic/ft_atoi.c \
				src/basic/ft_strncmp.c \
				src/basic/ft_strlcpy.c \
				src/basic/ft_strlcat.c \
				src/basic/ft_strnstr.c \
				src/basic/ft_strchr.c \
				src/basic/ft_strrchr.c \
				src/basic/ft_bzero.c \
				src/basic/ft_memset.c \
				src/basic/ft_memcmp.c \
				src/basic/ft_memchr.c \
				src/basic/ft_memmove.c \
				src/basic/ft_memcpy.c \
				src/basic/ft_strdup.c \
				src/basic/ft_calloc.c \
				src/basic/ft_putchar_fd.c \
				src/basic/ft_putstr_fd.c \
				src/basic/ft_putendl_fd.c \
				src/basic/ft_putnbr_fd.c \
				src/basic/ft_substr.c \
				src/basic/ft_strjoin.c \
				src/basic/ft_strmapi.c \
				src/basic/ft_striteri.c \
				src/basic/ft_itoa.c \
				src/basic/ft_strtrim.c \
				src/basic/ft_split.c \
				src/basic/ft_lstnew_bonus.c \
				src/basic/ft_lstadd_front_bonus.c \
				src/basic/ft_lstsize_bonus.c \
				src/basic/ft_lstlast_bonus.c \
				src/basic/ft_lstadd_back_bonus.c \
				src/basic/ft_lstdelone_bonus.c \
				src/basic/ft_lstclear_bonus.c \
				src/basic/ft_lstiter_bonus.c \
				src/basic/ft_lstmap_bonus.c

SRCS_PRINTF = 	src/printf/ft_printf.c \
				src/printf/ft_conversion_specifier.c \
				src/printf/ft_print_char.c \
				src/printf/ft_print_str.c \
				src/printf/ft_print_nbr.c \
				src/printf/ft_print_hexa.c \
				src/printf/ft_print_pointer.c

SRCS_GNL = 	src/gnl/get_next_line.c

SRCS = $(SRCS_BASIC) $(SRCS_PRINTF) $(SRCS_GNL)

OBJ = $(SRCS:.c=.o)

INCLUDES = -I.

%.o: %.c
	@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@
	@echo "$@ ✔️"

$(NAME): $(OBJ)
	@ar -crs $(NAME) $(OBJ)

all: $(NAME)

norminette:
	@norminette $(SRCS) -R CheckForbiddenSourceHeader

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all