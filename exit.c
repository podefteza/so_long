/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:28:21 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/27 11:52:48 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_collectibles(t_game *game)
{
	if (game->collectible_x)
	{
		free(game->collectible_x);
		game->collectible_x = NULL;
	}
	if (game->collectible_y)
	{
		free(game->collectible_y);
		game->collectible_y = NULL;
	}
}

void	free_walls(t_game *game)
{
	if (game->wall_x)
	{
		free(game->wall_x);
		game->wall_x = NULL;
	}
	if (game->wall_y)
	{
		free(game->wall_y);
		game->wall_y = NULL;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.map)
	{
		while (i < game->map.lines)
		{
			if (game->map.map[i])
				free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
		game->map.map = NULL;
	}
}

int	cleanup_and_exit(t_game *game, char *message, int exit_code)
{
	ft_putstr_fd(message, 2);
	free_collectibles(game);
	free_walls(game);
	free_map(game);
	if (game->image)
		mlx_destroy_image(game->minilibx.connect_mlx, game->image);
	if (game->minilibx.window_mlx)
		mlx_destroy_window(game->minilibx.connect_mlx,
			game->minilibx.window_mlx);
	if (exit_code != 42)
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
