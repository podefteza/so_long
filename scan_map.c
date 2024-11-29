/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:58:46 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/28 14:10:55 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_characters(t_game *game)
{
	int		row;
	int		col;
	char	cell;

	row = 0;
	while (game->map.map[row])
	{
		col = 0;
		while (game->map.map[row][col])
		{
			cell = game->map.map[row][col];
			if (cell != 'E' && cell != 'C' && cell != 'P' && cell != '1'
				&& cell != '0' && cell != 'X' && cell != '\n')
				return (0);
			if (cell == '\n' && (!game->map.map[row + 1]
					|| game->map.map[row + 1][0] == '\n'))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

void	scan_map(t_game *game)
{
	int		nr_collectibles;
	int		nr_walls;
	int		nr_enemies;

	nr_collectibles = 0;
	nr_walls = 0;
	nr_enemies = 0;
	if (!validate_map_characters(game))
		cleanup_and_exit(game, "Error\nInvalid map format.\n", 1);
	process_map(game, nr_collectibles, nr_walls, nr_enemies);
}
