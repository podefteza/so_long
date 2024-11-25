/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:13:52 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/25 10:04:09 by carlos-j         ###   ########.fr       */
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
#  define BUFFER_SIZE 2048
# endif

# define WIDTH 1024
# define HEIGHT 768

# define SPRITE_SIZE 64
# define BG_SPRITE "sprites/background.xpm"
# define WALL_SPRITE "sprites/wall.xpm"
# define COLLECT_SPRITE "sprites/collectible.xpm"
# define P_L_SPRITE "sprites/player_left.xpm"
# define P_R_SPRITE "sprites/player_right.xpm"

# define WIN1 "sprites/win1.xpm"
# define WIN2 "sprites/win2.xpm"
# define WIN3 "sprites/win3.xpm"

# define C_DOOR_SPRITE "sprites/closed_door.xpm"
# define O_DOOR_SPRITE "sprites/open_door.xpm"
# define P_L_C_DOOR_SPRITE "sprites/player_left_closed_door.xpm"
# define P_R_C_DOOR_SPRITE "sprites/player_right_closed_door.xpm"
# define P_L_O_DOOR_SPRITE "sprites/player_left_win.xpm"
# define P_R_O_DOOR_SPRITE "sprites/player_right_win.xpm"

typedef struct s_flood_fill
{
	int			directions[4][2];
	int			collected;
	int			exit_reached;
}				t_flood_fill;

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
	void		*p_left;
	void		*p_right;
	void		*p_l_c_door;
	void		*p_r_c_door;
	void		*p_l_o_door;
	void		*p_r_o_door;
	void		*collect;
	void		*win1;
	void		*win2;
	void		*win3;
	void		*exit;
	void		*exit_closed;
	void		*exit_open;
}				t_sprites;

typedef struct s_game
{
	t_minilibx	minilibx;
	t_sprites	sprites;
	t_map		map;

	int			movements;
	int			position_x;
	int			position_y;
	int			player_count;
	int			exit_x;
	int			exit_y;
	int			exit_count;
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

// EXIT
void			free_collectibles(t_game *game);
void			free_walls(t_game *game);
void			free_map(t_game *game);
int	cleanup_and_exit(t_game *game, char *error, int exit_code);
void			free_sprites(t_game *game, int exit_code);

// MAP OBJECTS COUNT
int				player_count(t_game *game);
void			count_collectibles(t_game *game);
void			count_walls(t_game *game);

// FLOOD FILL HELPER FUNCTIONS
void			reset_collectibles(t_game *game);
void			init_directions(int directions[4][2]);
void			process_cell(t_game *game, int x, int y, t_flood_fill *state);
void			explore_neighbors(t_game *game, int x, int y,
					t_flood_fill *state);

// VALIDATION
void			flood_fill(t_game *game, int x, int y, t_flood_fill *state);

int				extension_check(int argc, char **argv, t_game *game);
int				map_checker(char *argv, t_game *game);
void			count_collectibles(t_game *game);
void			count_walls(t_game *game);
void			scan_map(t_game *game);
int				player_count(t_game *game);
int				check_rectangular(t_game *game);
int				check_walls(t_game *game);
int				check_valid_path(t_game *game);

// MAP CONTENT CHECKER
int				check_rectangular(t_game *game);
void			count_collectibles(t_game *game);
void			count_walls(t_game *game);

// SCAN MAP
void			scan_map(t_game *game);

// ERROR
//int				error_output(char *error, t_game *game);
void			free_map(t_game *game);

// LOAD AND REFRESH SPRITES
void			player_sprites(t_game *game, int img_size);
void			load_sprites(t_game *game, int img_size);
void			refresh_dynamic_elements(t_game *game);
void			draw_exit(t_game *game);
void			draw_background(t_game *game);
void			load_static_elements(t_game *game);
void			free_player_sprites(t_game *game);
void			free_load_sprites(t_game *game);

// GAME_SETUP
void			game_setup(t_game *game, int img_size);

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
