/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:58:46 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/21 09:01:26 by carlos-j         ###   ########.fr       */
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

void	scan_map(t_game *game)
{
	int		l;
	int		c;
	int		nr_collectibles;
	int		nr_walls;
	char	cell;

	l = -1;
	nr_collectibles = 0;
	nr_walls = 0;
	while (game->map.map[++l])
	{
		c = -1;
		while (game->map.map[l][++c])
		{
			cell = game->map.map[l][c];
			if (cell == 'P')
				process_player(game, c, l);
			else if (cell == 'E')
				process_exit(game, c, l);
			else if (cell == 'C')
				process_collectible(game, c, l, &nr_collectibles);
			else if (cell == '1')
				process_wall(game, c, l, &nr_walls);
		}
	}
}
