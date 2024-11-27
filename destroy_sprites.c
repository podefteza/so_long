/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:21:04 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/27 12:05:10 by carlos-j         ###   ########.fr       */
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

void	free_score_left(t_game *game)
{
	//if (game->score.score_left)
	//	mlx_destroy_image(game->minilibx.connect_mlx, game->score.score_left);
	if (game->score.left_0)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.left_0);
	if (game->score.left_1)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.left_1);
	if (game->score.left_2)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.left_2);
	if (game->score.left_3)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.left_3);
	if (game->score.left_4)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.left_4);
	if (game->score.left_5)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.left_5);
	if (game->score.left_6)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.left_6);
	if (game->score.left_7)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.left_7);
	if (game->score.left_8)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.left_8);
	if (game->score.left_9)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.left_9);
	//if (game->score.score_left)
	//	mlx_destroy_image(game->minilibx.connect_mlx, game->score.score_left);
}

void	free_score_center(t_game *game)
{
	//if (game->score.score_center)
	//	mlx_destroy_image(game->minilibx.connect_mlx, game->score.score_center);
	if (game->score.center_0)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.center_0);
	if (game->score.center_1)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.center_1);
	if (game->score.center_2)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.center_2);
	if (game->score.center_3)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.center_3);
	if (game->score.center_4)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.center_4);
	if (game->score.center_5)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.center_5);
	if (game->score.center_6)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.center_6);
	if (game->score.center_7)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.center_7);
	if (game->score.center_8)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.center_8);
	if (game->score.center_9)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.center_9);
	//if (game->score.score_center)
	//	mlx_destroy_image(game->minilibx.connect_mlx, game->score.score_center);
}

void	free_score_right(t_game *game)
{
	//if (game->score.score_right)
	//	mlx_destroy_image(game->minilibx.connect_mlx, game->score.score_right);
	if (game->score.right_0)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.right_0);
	if (game->score.right_1)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.right_1);
	if (game->score.right_2)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.right_2);
	if (game->score.right_3)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.right_3);
	if (game->score.right_4)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.right_4);
	if (game->score.right_5)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.right_5);
	if (game->score.right_6)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.right_6);
	if (game->score.right_7)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.right_7);
	if (game->score.right_8)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.right_8);
	if (game->score.right_9)
		mlx_destroy_image(game->minilibx.connect_mlx, game->score.right_9);
	//if (game->score.score_right)
	//	mlx_destroy_image(game->minilibx.connect_mlx, game->score.score_right);
}
