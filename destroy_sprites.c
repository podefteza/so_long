/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:21:04 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/25 13:24:01 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// if anything breaks, make them NULL pointers after destroy
void	free_player_sprites(t_game *game, int exit_code)
{
	if (game->sprites.player)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.player);
	if (game->sprites.p_l_c_door)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_l_c_door);
	if (game->sprites.p_r_c_door)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_r_c_door);
	if (game->sprites.p_left && exit_code == 1 && ((game->last_direction == 'R')
			|| !game->last_direction))
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_left);
	if (game->sprites.p_right && exit_code == 1
		&& (game->last_direction == 'L'))
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_right);
}

void	free_map_sprites(t_game *game, int exit_code)
{
	if (game->sprites.win1)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.win1);
	if (game->sprites.win2)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.win2);
	if (game->sprites.win3)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.win3);
	if (game->sprites.background)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.background);
	if (game->sprites.collect)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.collect);
	if (game->sprites.ex_closed)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.ex_closed);
	if (game->sprites.exit && exit_code == 0)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit);
	if (game->sprites.wall && exit_code == 1)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.wall);
	if (game->sprites.exit_open && exit_code == 1)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit_open);
}
