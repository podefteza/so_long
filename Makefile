# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 09:29:40 by carlos-j          #+#    #+#              #
#    Updated: 2024/11/25 15:55:00 by carlos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror

MINILIBXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

SRCS = so_long.c \
		validation.c \
		load_sprites.c \
        load_exit.c \
		load_static_elements.c \
		refresh_dynamic_elements.c \
		game_setup.c \
		move_player.c \
		file_checker.c \
		scan_map.c \
		flood_fill.c \
		exit.c \
		check_win.c \
		destroy_sprites.c \
		map_content_checker.c \
		map_objects_count.c \
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

character_dwight:
	@cp sprites/dwight/*.xpm sprites/
	@echo "You chose Dwight as your character."

character_kevin:
	@cp sprites/kevin/*.xpm sprites/
	@echo "You chose Kevin as your character."

character_stanley:
	@cp sprites/stanley/*.xpm sprites/
	@echo "You chose Stanley as your character."

.PHONY: all clean fclean re
