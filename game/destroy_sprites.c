/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:21:04 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 13:59:43 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_game_over_sprites(t_game *game, int exit_code)
{
	if (game->sprites.enemy)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.enemy);
	if (game->sprites.game_over1)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.game_over1);
	if (game->sprites.game_over2)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.game_over2);
	if (game->sprites.game_over3)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.game_over3);
	(void)exit_code;
}

void	free_player_sprites(t_game *game, int exit_code)
{
	if (game->sprites.player)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.player);
	if (game->sprites.p_l_c_door)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_l_c_door);
	if (game->sprites.p_r_c_door)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_r_c_door);
	if (game->sprites.p_left && ((game->last_direction == 'R')
			|| !game->last_direction))
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_left);
	if (game->sprites.p_right && (game->last_direction == 'L'))
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_right);
	(void)exit_code;
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
	if (game->sprites.exit && (exit_code == 0))
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit);
	if (game->sprites.wall && (exit_code == 1 || exit_code == 33))
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.wall);
	if (game->sprites.exit_open && (exit_code == 1 || exit_code == 33))
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit_open);
}
