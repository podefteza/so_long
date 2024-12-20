/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_score_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:06:50 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 15:21:19 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_score_left(t_game *game, int img_size)
{
	game->score.left_0 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			LEFT_0, &img_size, &img_size);
	game->score.left_1 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			LEFT_1, &img_size, &img_size);
	game->score.left_2 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			LEFT_2, &img_size, &img_size);
	game->score.left_3 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			LEFT_3, &img_size, &img_size);
	game->score.left_4 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			LEFT_4, &img_size, &img_size);
	game->score.left_5 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			LEFT_5, &img_size, &img_size);
	game->score.left_6 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			LEFT_6, &img_size, &img_size);
	game->score.left_7 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			LEFT_7, &img_size, &img_size);
	game->score.left_8 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			LEFT_8, &img_size, &img_size);
	game->score.left_9 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			LEFT_9, &img_size, &img_size);
}

void	load_score_center(t_game *game, int img_size)
{
	game->score.center_0 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CENTER_0, &img_size, &img_size);
	game->score.center_1 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CENTER_1, &img_size, &img_size);
	game->score.center_2 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CENTER_2, &img_size, &img_size);
	game->score.center_3 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CENTER_3, &img_size, &img_size);
	game->score.center_4 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CENTER_4, &img_size, &img_size);
	game->score.center_5 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CENTER_5, &img_size, &img_size);
	game->score.center_6 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CENTER_6, &img_size, &img_size);
	game->score.center_7 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CENTER_7, &img_size, &img_size);
	game->score.center_8 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CENTER_8, &img_size, &img_size);
	game->score.center_9 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CENTER_9, &img_size, &img_size);
}

void	load_score_right(t_game *game, int img_size)
{
	game->score.right_0 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			RIGHT_0, &img_size, &img_size);
	game->score.right_1 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			RIGHT_1, &img_size, &img_size);
	game->score.right_2 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			RIGHT_2, &img_size, &img_size);
	game->score.right_3 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			RIGHT_3, &img_size, &img_size);
	game->score.right_4 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			RIGHT_4, &img_size, &img_size);
	game->score.right_5 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			RIGHT_5, &img_size, &img_size);
	game->score.right_6 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			RIGHT_6, &img_size, &img_size);
	game->score.right_7 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			RIGHT_7, &img_size, &img_size);
	game->score.right_8 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			RIGHT_8, &img_size, &img_size);
	game->score.right_9 = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			RIGHT_9, &img_size, &img_size);
}
