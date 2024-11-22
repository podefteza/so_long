/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:22:08 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/22 11:53:32 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_continue(t_game *game)
{
	if (game->position_x == game->exit_x && game->position_y == game->exit_y)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit);
		if (game->last_direction == 'L')
			game->sprites.exit = game->sprites.p_l_c_door;
		else
			game->sprites.exit = game->sprites.p_r_c_door;
	}
	else
	{
		//mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit);
		game->sprites.exit = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
				C_DOOR_SPRITE, &(int){SPRITE_SIZE}, &(int){SPRITE_SIZE});
	}
}

void	exit_final(t_game *game)
{
	if (game->position_x == game->exit_x && game->position_y == game->exit_y)
	{
		if (game->last_direction == 'L')
		{
			mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit);
			game->sprites.exit = game->sprites.p_l_o_door;
		}
		else
		{
			mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit);
			game->sprites.exit = game->sprites.p_r_o_door;
		}
	}
	else
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit);
		game->sprites.exit = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
				O_DOOR_SPRITE, &(int){SPRITE_SIZE}, &(int){SPRITE_SIZE});
	}
}

void	draw_exit(t_game *game)
{
	if (game->nr_collectibles > 0)
		exit_continue(game);
	else
		exit_final(game);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.exit, SPRITE_SIZE
		* game->exit_x, SPRITE_SIZE * game->exit_y);
}
