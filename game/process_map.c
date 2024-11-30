/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:09:57 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 16:13:47 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	process_map(t_game *game, int nr_collectibles, int nr_walls,
		int nr_enemies)
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
