# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 09:29:40 by carlos-j          #+#    #+#              #
#    Updated: 2024/11/30 15:18:17 by carlos-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror

MINILIBXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

SRCS = so_long.c \
		game/check_win.c \
		game/file_checker.c \
		game/load_exit.c \
		game/map_objects_count.c \
		game/scan_map.c \
		game/default_variables.c \
		game/flood_fill.c \
		game/load_score_sprites.c \
		game/move_player.c \
		game/validation.c \
		game/destroy_score_sprites.c \
		game/free_map_characters.c \
		game/load_sprites.c \
		game/process_map.c \
		game/destroy_sprites.c \
		game/game_over.c \
		game/load_static_elements.c \
		game/process_map_objects.c \
		game/exit.c \
		game/game_setup.c \
		game/map_content_checker.c \
		game/refresh_dynamic_elements.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_strncmp.c \
		libft/ft_substr.c

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
