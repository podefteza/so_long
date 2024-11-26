/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:58:46 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/26 13:58:18 by carlos-j         ###   ########.fr       */
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

int validate_map_characters(t_game *game)
{
	int row;
	int col;

	row = 0;
	while (game->map.map[row])
	{
		col = 0;
		while (game->map.map[row][col])
		{
			char cell = game->map.map[row][col];
			// Check for invalid characters
			if (cell != 'E' && cell != 'C' && cell != 'P' &&
				cell != '1' && cell != '0' && cell != '\n')
				{
					printf("Validating character: %c\n", game->map.map[row][col]);
					return (0);
				}

			// Check for invalid spaces
			if (cell == ' ')
				return (0);
			// Check for consecutive '\n' or a '\n' at the end
			if (cell == '\n' && (!game->map.map[row + 1] || game->map.map[row + 1][0] == '\n'))
				return (0);
			col++;
		}
		row++;
	}
	return (1); // Valid map
}

void scan_map(t_game *game)
{
	int		row;
	int		col;
	int		nr_collectibles = 0;
	int		nr_walls = 0;

	if (!validate_map_characters(game))
		cleanup_and_exit(game, "Error\nInvalid map format.\n", 1);

	row = -1;
	while (game->map.map[++row])
	{
		col = -1;
		while (game->map.map[row][++col])
		{
			char cell = game->map.map[row][col];
			if (cell == 'P')
				process_player(game, col, row);
			else if (cell == 'E')
				process_exit(game, col, row);
			else if (cell == 'C')
				process_collectible(game, col, row, &nr_collectibles);
			else if (cell == '1')
				process_wall(game, col, row, &nr_walls);
		}
	}
}


