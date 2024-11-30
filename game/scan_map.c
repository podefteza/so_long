/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:58:46 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 17:14:37 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validate_map_characters(t_game *game)
{
	int		row;
	int		col;
	int		first_line_length;
	char	cell;

	row = 0;
	first_line_length = game->map.columns;
	while (game->map.map[row])
	{
		col = 0;
		while (game->map.map[row][col])
		{
			cell = game->map.map[row][col];
			if (cell != 'E' && cell != 'C' && cell != 'P' && cell != '1'
				&& cell != '0' && cell != 'X')
				return (0);
			col++;
		}
		if (col != first_line_length)
			return (0);
		row++;
	}
	return (1);
}

void	scan_map(t_game *game)
{
	int	nr_collectibles;
	int	nr_walls;
	int	nr_enemies;

	nr_collectibles = 0;
	nr_walls = 0;
	nr_enemies = 0;
	if (validate_map_characters(game) != 1)
		cleanup_and_exit(game, "Error\nInvalid map format.\n", 1);
	process_map(game, nr_collectibles, nr_walls, nr_enemies);
}
