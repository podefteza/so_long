/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:13:52 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/27 12:08:55 by carlos-j         ###   ########.fr       */
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

# define LEFT_0 "sprites/score/left/0.xpm"
# define LEFT_1 "sprites/score/left/1.xpm"
# define LEFT_2 "sprites/score/left/2.xpm"
# define LEFT_3 "sprites/score/left/3.xpm"
# define LEFT_4 "sprites/score/left/4.xpm"
# define LEFT_5 "sprites/score/left/5.xpm"
# define LEFT_6 "sprites/score/left/6.xpm"
# define LEFT_7 "sprites/score/left/7.xpm"
# define LEFT_8 "sprites/score/left/8.xpm"
# define LEFT_9 "sprites/score/left/9.xpm"
# define CENTER_0 "sprites/score/center/0.xpm"
# define CENTER_1 "sprites/score/center/1.xpm"
# define CENTER_2 "sprites/score/center/2.xpm"
# define CENTER_3 "sprites/score/center/3.xpm"
# define CENTER_4 "sprites/score/center/4.xpm"
# define CENTER_5 "sprites/score/center/5.xpm"
# define CENTER_6 "sprites/score/center/6.xpm"
# define CENTER_7 "sprites/score/center/7.xpm"
# define CENTER_8 "sprites/score/center/8.xpm"
# define CENTER_9 "sprites/score/center/9.xpm"
# define RIGHT_0 "sprites/score/right/0.xpm"
# define RIGHT_1 "sprites/score/right/1.xpm"
# define RIGHT_2 "sprites/score/right/2.xpm"
# define RIGHT_3 "sprites/score/right/3.xpm"
# define RIGHT_4 "sprites/score/right/4.xpm"
# define RIGHT_5 "sprites/score/right/5.xpm"
# define RIGHT_6 "sprites/score/right/6.xpm"
# define RIGHT_7 "sprites/score/right/7.xpm"
# define RIGHT_8 "sprites/score/right/8.xpm"
# define RIGHT_9 "sprites/score/right/9.xpm"

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
	int			map_read_fd;
	int			lines;
	int			columns;
	char		exit;
}				t_map;

typedef struct s_score
{
	void		*left_0;
	void		*left_1;
	void		*left_2;
	void		*left_3;
	void		*left_4;
	void		*left_5;
	void		*left_6;
	void		*left_7;
	void		*left_8;
	void		*left_9;
	void		*center_0;
	void		*center_1;
	void		*center_2;
	void		*center_3;
	void		*center_4;
	void		*center_5;
	void		*center_6;
	void		*center_7;
	void		*center_8;
	void		*center_9;
	void		*right_0;
	void		*right_1;
	void		*right_2;
	void		*right_3;
	void		*right_4;
	void		*right_5;
	void		*right_6;
	void		*right_7;
	void		*right_8;
	void		*right_9;
	void		*score_left;
	void		*score_center;
	void		*score_right;
}				t_score;

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
	void		*ex_closed;
	void		*exit_open;
}				t_sprites;

typedef struct s_center
{
	int			center_x;
	int			center_y;
	int			sprite1_x;
	int			sprite2_x;
	int			sprite3_x;
	int			sprite_y;
	int			message_x;
	int			message_y;
}				t_center;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_game
{
	t_minilibx	minilibx;
	t_sprites	sprites;
	t_map		map;
	t_score		score;

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

// PROCESS MAP
void			process_player(t_game *game, int x, int y);
void			process_exit(t_game *game, int x, int y);
void			process_collectible(t_game *game, int x, int y,
					int *nr_collectibles);
void			process_wall(t_game *game, int x, int y, int *nr_walls);
void			process_map(t_game *game, int nr_collectibles, int nr_walls);

// END GAME
void			win_message(t_game *game, t_center *center);
void			check_win(t_game *game);

// EXIT
void			free_collectibles(t_game *game);
void			free_walls(t_game *game);
void			free_map(t_game *game);
int				cleanup_and_exit(t_game *game, char *error, int exit_code);
void			free_player_sprites(t_game *game, int exit_code);
void			free_map_sprites(t_game *game, int exit_code);
void			free_score_left(t_game *game);
void			free_score_center(t_game *game);
void			free_score_right(t_game *game);

// MAP OBJECTS COUNT
int				player_count(t_game *game);
void			count_collectibles(t_game *game);
void			count_walls(t_game *game);

// FLOOD FILL HELPER FUNCTIONS
void			reset_map(t_game *game);
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
void			free_map(t_game *game);

// LOAD AND REFRESH SPRITES
void			refresh_score_left(t_game *game);
void			refresh_score_center(t_game *game);
void			refresh_score_right(t_game *game);
void			load_score_left(t_game *game, int img_size);
void			load_score_center(t_game *game, int img_size);
void			load_score_right(t_game *game, int img_size);
void			player_sprites(t_game *game, int img_size);
void			load_sprites(t_game *game, int img_size);
void			refresh_dynamic_elements(t_game *game);
void			draw_exit(t_game *game);
void			draw_background(t_game *game);
void			load_static_elements(t_game *game);

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
