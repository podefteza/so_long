/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_dynamic_elements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:35:50 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 15:21:54 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	refresh_score_left(t_game *game)
{
	if (game->movements < 100)
		game->score.score_left = game->score.left_0;
	if (game->movements >= 100 && game->movements < 200)
		game->score.score_left = game->score.left_1;
	if (game->movements >= 200 && game->movements < 300)
		game->score.score_left = game->score.left_2;
	if (game->movements >= 300 && game->movements < 400)
		game->score.score_left = game->score.left_3;
	if (game->movements >= 400 && game->movements < 500)
		game->score.score_left = game->score.left_4;
	if (game->movements >= 500 && game->movements < 600)
		game->score.score_left = game->score.left_5;
	if (game->movements >= 600 && game->movements < 700)
		game->score.score_left = game->score.left_6;
	if (game->movements >= 700 && game->movements < 800)
		game->score.score_left = game->score.left_7;
	if (game->movements >= 800 && game->movements < 900)
		game->score.score_left = game->score.left_8;
	if (game->movements >= 900 && game->movements <= 999)
		game->score.score_left = game->score.left_9;
	if (game->movements > 5)
		cleanup_and_exit(game, "Error\nNo more moves allowed.\n", 1);
}

void	refresh_score_center(t_game *game)
{
	int	temp;

	temp = (game->movements / 10) % 10;
	if (temp == 0)
		game->score.score_center = game->score.center_0;
	if (temp == 1)
		game->score.score_center = game->score.center_1;
	if (temp == 2)
		game->score.score_center = game->score.center_2;
	if (temp == 3)
		game->score.score_center = game->score.center_3;
	if (temp == 4)
		game->score.score_center = game->score.center_4;
	if (temp == 5)
		game->score.score_center = game->score.center_5;
	if (temp == 6)
		game->score.score_center = game->score.center_6;
	if (temp == 7)
		game->score.score_center = game->score.center_7;
	if (temp == 8)
		game->score.score_center = game->score.center_8;
	if (temp == 9)
		game->score.score_center = game->score.center_9;
}

void	refresh_score_right(t_game *game)
{
	if (game->movements % 10 == 0)
		game->score.score_right = game->score.right_0;
	if (game->movements % 10 == 1)
		game->score.score_right = game->score.right_1;
	if (game->movements % 10 == 2)
		game->score.score_right = game->score.right_2;
	if (game->movements % 10 == 3)
		game->score.score_right = game->score.right_3;
	if (game->movements % 10 == 4)
		game->score.score_right = game->score.right_4;
	if (game->movements % 10 == 5)
		game->score.score_right = game->score.right_5;
	if (game->movements % 10 == 6)
		game->score.score_right = game->score.right_6;
	if (game->movements % 10 == 7)
		game->score.score_right = game->score.right_7;
	if (game->movements % 10 == 8)
		game->score.score_right = game->score.right_8;
	if (game->movements % 10 == 9)
		game->score.score_right = game->score.right_9;
}

void	refresh_dynamic_elements(t_game *game)
{
	static int	prev_x = -1;
	static int	prev_y = -1;

	if (prev_x != -1 && prev_y != -1)
	{
		mlx_put_image_to_window(game->minilibx.connect_mlx,
			game->minilibx.window_mlx, game->sprites.background, SPRITE_SIZE
			* prev_x, SPRITE_SIZE * prev_y);
	}
	prev_x = game->position_x;
	prev_y = game->position_y;
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.player, SPRITE_SIZE
		* game->position_x, SPRITE_SIZE * game->position_y);
	if (game->movements >= 100)
		refresh_score_left(game);
	if (game->movements > 9)
		refresh_score_center(game);
	refresh_score_right(game);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->score.score_left, 0, 0);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->score.score_center, SPRITE_SIZE, 0);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->score.score_right, SPRITE_SIZE * 2, 0);
}
