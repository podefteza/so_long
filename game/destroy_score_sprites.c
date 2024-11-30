/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_score_sprites.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:58:29 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 13:59:38 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_score_left(t_game *game)
{
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
}

void	free_score_center(t_game *game)
{
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
}

void	free_score_right(t_game *game)
{
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
}
