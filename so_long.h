/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:13:52 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/16 12:47:45 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define WIDTH 1024
# define HEIGHT 768

# define SPRITE_SIZE 64
# define BACKGROUND_SPRITE "sprites/background.xpm"
# define WALL_SPRITE "sprites/wall.xpm"
# define COLLECTIBLE_SPRITE "sprites/collectible.xpm"
# define PLAYER_LEFT_SPRITE "sprites/player_left.xpm"
# define PLAYER_RIGHT_SPRITE "sprites/player_right.xpm"

# define CLOSED_DOOR_SPRITE "sprites/closed_door.xpm"
# define OPEN_DOOR_SPRITE "sprites/open_door.xpm"
# define PLAYER_LEFT_CLOSED_DOOR_SPRITE "sprites/closed_door_left.xpm"
# define PLAYER_RIGHT_CLOSED_DOOR_SPRITE "sprites/closed_door_right.xpm"
# define PLAYER_LEFT_OPEN_DOOR_SPRITE "sprites/open_door_left.xpm"
# define PLAYER_RIGHT_OPEN_DOOR_SPRITE "sprites/open_door_right.xpm"

typedef struct s_minilibx
{
	void		*connect_mlx;
	void		*window_mlx;
}				t_minilibx;

typedef struct s_map
{
	char		**map;
	char		*buffer;
	int			lines;
	int			columns;
	char		exit;
}				t_map;

typedef struct s_sprites
{
	int			player_position;

	void		*background;
	void		*wall;
	void		*player;
	void		*player_left;
	void		*player_right;
	void		*player_left_closed_door;
	void		*player_right_closed_door;
	void		*player_left_open_door;
	void		*player_right_open_door;
	void		*collectible;
	void		*exit;
}				t_sprites;

typedef struct s_game
{
	t_minilibx	minilibx;
	t_sprites	sprites;
	t_map		map;

	int			movements;
	int			position_x;
	int			position_y;
	int			exit_x;
	int			exit_y;
	int			nr_collectibles;
	int			*collectible_x;
	int			*collectible_y;
	int			nr_walls;
	int			*wall_x;
	int			*wall_y;
	void		*image;
	char		*addr;
	char		last_direction;
	int			win_state;
}				t_game;

// LOAD_SPRITES
void			load_sprites(t_game *game, int img_size);

// REFRESH_DYNAMIC_ELEMENTS
void			refresh_dynamic_elements(t_game *game);

// LOAD_STATIC_ELEMENTS
void			draw_exit(t_game *game);
void			load_static_elements(t_game *game);

// GAME_SETUP
void			game_setup(t_game *game, int img_size);

// VALIDATION
int				initial_check(int argc, char **argv);
int				map_checker(char *argv, t_game *game);
void			count_collectibles(t_game *game);
void			count_walls(t_game *game);
void			scan_map(t_game *game);

// MOVE_PLAYER
int				handle_key(int key, t_game *game);

// LIBFT
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s);

char			**ft_split(t_game *game, char c);
char			*ft_itoa(int n);

#endif
