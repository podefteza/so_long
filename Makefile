# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 09:29:40 by carlos-j          #+#    #+#              #
#    Updated: 2024/11/13 10:45:51 by carlos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror

MINILIBXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

SRCS = so_long.c \
		validation.c \
		load_sprites.c \
		load_static_elements.c \
		refresh_dynamic_elements.c \
		game_setup.c \
		move_player.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_strlen.c \
		libft/ft_strncmp.c \
		libft/ft_substr.c \
		libft/ft_strdup.c \
		libft/ft_split.c \
		libft/ft_itoa.c

OBJS = ${SRCS:.c=.o}

NAME = so_long

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C ./minilibx-linux
	$(CC) $(OBJS) $(MINILIBXFLAGS) -o $(NAME)
	@echo "Compilation successful."

clean:
	@rm -f ${OBJS}
	@echo "Object files removed."

fclean: clean
	@rm -f ${NAME}
	@echo "Executable removed."

re: fclean all
	@echo "Recompiled all files."

.PHONY: all clean fclean re
