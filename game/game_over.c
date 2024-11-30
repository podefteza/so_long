/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:15:56 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 14:34:31 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_over_message(t_game *game)
{
	game->center.center_x = (game->map.columns * SPRITE_SIZE) / 2 - 32;
	game->center.center_y = (game->map.lines * SPRITE_SIZE) / 2;
	game->center.sprite1_x = game->center.center_x - SPRITE_SIZE;
	game->center.sprite2_x = game->center.center_x;
	game->center.sprite3_x = game->center.center_x + SPRITE_SIZE;
	game->center.sprite_y = game->center.center_y - SPRITE_SIZE / 2;
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.game_over1,
		game->center.sprite1_x, game->center.sprite_y);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.game_over2,
		game->center.sprite2_x, game->center.sprite_y);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.game_over3,
		game->center.sprite3_x, game->center.sprite_y);
	game->center.message_x = game->center.center_x - 40;
	game->center.message_y = game->center.sprite_y + SPRITE_SIZE + 15;
}

int	game_over(t_game *game, int new_x, int new_y)
{
	int	img_size;

	img_size = SPRITE_SIZE;
	if (game->map.map[new_y][new_x] != 'X')
		return (0);
	if (game->sprites.player)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.player);
	if (game->last_direction == 'L')
		game->sprites.player = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
				E_R_P_L_SPRITE, &img_size, &img_size);
	else if (game->last_direction == 'R')
		game->sprites.player = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
				E_R_P_R_SPRITE, &img_size, &img_size);
	draw_background(game);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.player, SPRITE_SIZE
		* game->position_x, SPRITE_SIZE * game->position_y);
	return (1);
}
