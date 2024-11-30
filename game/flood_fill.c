/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:14:28 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/26 13:59:47 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_reachable(t_game *game, int x, int y)
{
	return (x >= 0 && x < game->map.lines && y >= 0 && y < game->map.columns
		&& (game->map.map[x][y] == '0' || game->map.map[x][y] == 'C'
			|| game->map.map[x][y] == 'E') && game->map.map[x] != NULL);
}

void	reset_map(t_game *game)
{
	int	l;
	int	c;

	l = -1;
	while (game->map.map[++l])
	{
		c = -1;
		while (game->map.map[l][++c])
		{
			if (game->map.map[l][c] == '#')
				game->map.map[l][c] = 'C';
			else if (game->map.map[l][c] == '*')
				game->map.map[l][c] = '0';
		}
	}
}

void	init_directions(int directions[4][2])
{
	directions[0][0] = 0;
	directions[0][1] = 1;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = -1;
	directions[3][1] = 0;
}

void	process_cell(t_game *game, int x, int y, t_flood_fill *state)
{
	if (game->map.map[x][y] == 'C')
	{
		state->collected++;
		game->map.map[x][y] = '#';
	}
	else if (game->map.map[x][y] == 'E')
		state->exit_reached = 1;
	else if (game->map.map[x][y] == '0')
		game->map.map[x][y] = '*';
}

void	explore_neighbors(t_game *game, int x, int y, t_flood_fill *state)
{
	int	i;
	int	new_x;
	int	new_y;

	i = 0;
	while (i < 4)
	{
		new_x = x + state->directions[i][0];
		new_y = y + state->directions[i][1];
		if (is_reachable(game, new_x, new_y))
			flood_fill(game, new_x, new_y, state);
		i++;
	}
}
