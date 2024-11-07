/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:13:52 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/06 18:04:33 by carlos-j         ###   ########.fr       */
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
#  define BUFFER_SIZE 10000
# endif

# define WIDTH 720
# define HEIGHT 720

# define SPRITE_SIZE 64
# define BACKGROUND_SPRITE "sprites/background.xpm"
# define PLAYER_RIGHT_SPRITE  "sprites/michael_background.xpm"
# define PLAYER_LEFT_SPRITE "sprites/michael_left.xpm"
# define EXIT_SPRITE "sprites/door.xpm"
/*# define WALL_SPRITE
# define COLLECTABLE_SPRITE
# define EXIT_SPRITE*/

typedef struct s_minilibx
{
	void				*connect_mlx;
	void				*window_mlx;
}						t_minilibx;

typedef struct s_map
{
	char				**map;
	char				*buffer;
	int					lines;
	int					columns;
	int					count;
	char				exit;
}						t_map;

typedef struct s_sprites
{
	int					player_position;
	char				side;

	void				*background;
	void				*wall;
	void				*player;
	void				*player_left;
	void				*player_right;
	void				*collectable;
	void				*exit;
}						t_sprites;

typedef struct s_game
{
	struct s_minilibx	minilibx;
	struct s_sprites	sprites;
	t_map				map;

	int					steps;
	int					position_x;
	int					position_y;
	int					exit_x;
	int					exit_y;

	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}						t_game;


// LIBFT
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char *s, int fd);
size_t					ft_strlen(const char *s);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

char	**ft_split(t_game *game, char c);

#endif
