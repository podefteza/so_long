/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_static_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:44:35 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/13 10:14:17 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_game *game)
{
	int l, c;
	l = 0;
	while (l < game->map.lines)
	{
		c = 0;
		while (c < game->map.columns)
		{
			mlx_put_image_to_window(game->minilibx.connect_mlx,
				game->minilibx.window_mlx, game->sprites.background, SPRITE_SIZE
				* c, SPRITE_SIZE * l);
			c++;
		}
		l++;
	}
}

void	draw_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nr_walls)
	{
		mlx_put_image_to_window(game->minilibx.connect_mlx,
			game->minilibx.window_mlx, game->sprites.wall, SPRITE_SIZE
			* game->wall_x[i], SPRITE_SIZE * game->wall_y[i]);
		i++;
	}
}

void	draw_collectibles(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nr_collectibles)
	{
		mlx_put_image_to_window(game->minilibx.connect_mlx,
			game->minilibx.window_mlx, game->sprites.collectible, SPRITE_SIZE
			* game->collectible_x[i], SPRITE_SIZE * game->collectible_y[i]);
		i++;
	}
}

void	draw_exit(t_game *game)
{
	int	img_size;

	img_size = SPRITE_SIZE;
	if (game->nr_collectibles > 0)
		game->sprites.exit = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
				CLOSED_DOOR_SPRITE, &img_size, &img_size);
	else
		game->sprites.exit = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
				OPEN_DOOR_SPRITE, &img_size, &img_size);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.exit, SPRITE_SIZE
		* game->exit_x, SPRITE_SIZE * game->exit_y);
}

void	load_static_elements(t_game *game)
{
	draw_background(game);
	draw_walls(game);
	draw_collectibles(game);
	draw_exit(game);
}
