/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:14:27 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/28 14:10:13 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_player(t_game *game, int x, int y)
{
	game->position_x = x;
	game->position_y = y;
}

void	process_exit(t_game *game, int x, int y)
{
	game->exit_x = x;
	game->exit_y = y;
}

void	process_collectible(t_game *game, int x, int y, int *nr_collectibles)
{
	game->collectible_x[*nr_collectibles] = x;
	game->collectible_y[*nr_collectibles] = y;
	(*nr_collectibles)++;
}

void	process_wall(t_game *game, int x, int y, int *nr_walls)
{
	game->wall_x[*nr_walls] = x;
	game->wall_y[*nr_walls] = y;
	(*nr_walls)++;
}

void	process_enemy(t_game *game, int x, int y, int *nr_enemies)
{
	game->enemy_x[*nr_enemies] = x;
	game->enemy_y[*nr_enemies] = y;
	(*nr_enemies)++;
}

void	process_map(t_game *game, int nr_collectibles, int nr_walls, int nr_enemies)
{
	int		row;
	int		col;
	char	cell;

	row = -1;
	while (game->map.map[++row])
	{
		col = -1;
		while (game->map.map[row][++col])
		{
			cell = game->map.map[row][col];
			if (cell == 'P')
				process_player(game, col, row);
			else if (cell == 'E')
				process_exit(game, col, row);
			else if (cell == 'C')
				process_collectible(game, col, row, &nr_collectibles);
			else if (cell == '1')
				process_wall(game, col, row, &nr_walls);
			else if (cell == 'X')
				process_enemy(game, col, row, &nr_enemies);
		}
	}
}
