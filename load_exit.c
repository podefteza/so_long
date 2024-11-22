/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:22:08 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/22 17:48:47 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_game *game)
{
	if (game->nr_collectibles > 0) // Door is still closed
	{

		if (game->position_x == game->exit_x
			&& game->position_y == game->exit_y)
		{
			if (game->last_direction == 'L')
				game->sprites.exit = game->sprites.p_l_c_door;
			else
				game->sprites.exit = game->sprites.p_r_c_door;
		}
		else
		{

			game->sprites.exit = game->sprites.exit_closed;
		}
	}
	else // Door can open
	{
		if (game->position_x == game->exit_x
			&& game->position_y == game->exit_y)
		{
			if (game->sprites.exit)
				mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit);
			if (game->last_direction == 'L')
				game->sprites.exit = game->sprites.p_l_o_door;
			else
				game->sprites.exit = game->sprites.p_r_o_door;
		}
		else
		{
			//if (game->sprites.exit_closed)
			//	mlx_destroy_image(game->minilibx.connect_mlx,
			//		game->sprites.exit_closed); // Free old sprite
			game->sprites.exit = game->sprites.exit_open;
		}
	}
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.exit, SPRITE_SIZE
		* game->exit_x, SPRITE_SIZE * game->exit_y);
}
