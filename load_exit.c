/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:22:08 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/25 11:49:28 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player_on_exit(t_game *game, int img_size)
{
	if ((game->sprites.p_left) && (game->last_direction != 'L'))
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_left);
		game->sprites.p_left = NULL;
	}
	else if ((game->sprites.p_left) && (game->last_direction != 'R'))
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_right);
		game->sprites.p_right = NULL;
	}
	if (game->sprites.exit)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit);
	if (game->last_direction == 'L')
	{
		game->sprites.exit = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
				P_L_O_DOOR_SPRITE, &img_size, &img_size);
	}
	else
	{
		game->sprites.exit = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
				P_R_O_DOOR_SPRITE, &img_size, &img_size);
	}
}

void	draw_exit(t_game *game)
{
	int	img_size;

	img_size = 64;
	if (game->nr_collectibles > 0)
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
			game->sprites.exit = game->sprites.ex_closed;
	}
	else if (game->position_x == game->exit_x
		&& game->position_y == game->exit_y)
		draw_player_on_exit(game, img_size);
	else
		game->sprites.exit = game->sprites.exit_open;
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.exit, SPRITE_SIZE
		* game->exit_x, SPRITE_SIZE * game->exit_y);
}
