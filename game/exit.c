/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:28:21 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 14:05:01 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	cleanup_and_exit(t_game *game, char *message, int exit_code)
{
	ft_putstr_fd(message, 2);
	free_map_characters(game);
	if (game->image)
		mlx_destroy_image(game->minilibx.connect_mlx, game->image);
	if (game->minilibx.window_mlx)
		mlx_destroy_window(game->minilibx.connect_mlx,
			game->minilibx.window_mlx);
	if (exit_code != 5 && exit_code != 6)
		free_game_over_sprites(game, exit_code);
	if (exit_code != 42 && exit_code != 5 && exit_code != 6)
	{
		free_player_sprites(game, exit_code);
		free_map_sprites(game, exit_code);
		free_score_left(game);
		free_score_center(game);
		free_score_right(game);
	}
	if (game->minilibx.connect_mlx)
	{
		mlx_destroy_display(game->minilibx.connect_mlx);
		free(game->minilibx.connect_mlx);
	}
	exit(exit_code);
}
