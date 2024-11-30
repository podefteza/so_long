/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:03:53 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 14:04:57 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	free_enemies(t_game *game)
{
	if (game->enemy_x)
	{
		free(game->enemy_x);
		game->enemy_x = NULL;
	}
	if (game->enemy_y)
	{
		free(game->enemy_y);
		game->enemy_y = NULL;
	}
}

void	free_map_characters(t_game *game)
{
	free_collectibles(game);
	free_walls(game);
	free_map(game);
	free_enemies(game);
}
