/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:54:32 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/29 14:10:25 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_message(t_game *game, t_center *center)
{
	center->center_x = (game->map.columns * SPRITE_SIZE) / 2 - 32;
	center->center_y = (game->map.lines * SPRITE_SIZE) / 2;
	center->sprite1_x = center->center_x - SPRITE_SIZE;
	center->sprite2_x = center->center_x;
	center->sprite3_x = center->center_x + SPRITE_SIZE;
	center->sprite_y = center->center_y - SPRITE_SIZE / 2;
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.win1, center->sprite1_x,
		center->sprite_y);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.win2, center->sprite2_x,
		center->sprite_y);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.win3, center->sprite3_x,
		center->sprite_y);
	center->message_x = center->center_x - 40;
	center->message_y = center->sprite_y + SPRITE_SIZE + 15;
	mlx_string_put(game->minilibx.connect_mlx, game->minilibx.window_mlx,
		center->message_x, center->message_y, 0xFFFFFF,
		"Press any key to exit.");
}

void	check_win(t_game *game)
{
	t_center	center;

	if (game->nr_collectibles == 0
		&& game->map.map[game->position_y][game->position_x] == 'E')
		game->win_state = 1;
	if (game->win_state == 1)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.background);
		game->sprites.background = game->sprites.wall;
		draw_background(game);
		mlx_put_image_to_window(game->minilibx.connect_mlx,
			game->minilibx.window_mlx, game->sprites.exit, SPRITE_SIZE
			* game->position_x, SPRITE_SIZE * game->position_y);
		win_message(game, &center);
	}
}
