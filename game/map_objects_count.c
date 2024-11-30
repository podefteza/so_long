/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_objects_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:50:19 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 16:01:06 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_counts(t_game *game, char c, t_position position, int *counts)
{
	if (c == 'P')
	{
		counts[0]++;
		game->position_x = position.x;
		game->position_y = position.y;
	}
	else if (c == 'E')
	{
		counts[1]++;
		game->exit_x = position.x;
		game->exit_y = position.y;
	}
	else if (c == 'C')
		counts[2]++;
}

int	player_count(t_game *game)
{
	t_position	position;
	int			counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	position.x = -1;
	while (game->map.map[++position.x])
	{
		position.y = -1;
		while (game->map.map[position.x][++position.y])
			update_counts(game, game->map.map[position.x][position.y], position,
				counts);
	}
	if (counts[0] != 1 || counts[1] != 1 || counts[2] < 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map must have only 1 player and 1 exit, ", 2);
		cleanup_and_exit(game, "and at least 1 collectible.\n", 6);
	}
	return (1);
}

void	count_collectibles(t_game *game)
{
	int	l;
	int	c;

	l = -1;
	game->nr_collectibles = 0;
	while (game->map.map[++l])
	{
		c = -1;
		while (game->map.map[l][++c])
			if (game->map.map[l][c] == 'C')
				game->nr_collectibles++;
	}
	game->collectible_x = malloc(game->nr_collectibles * sizeof(int));
	game->collectible_y = malloc(game->nr_collectibles * sizeof(int));
	if (!game->collectible_x || !game->collectible_y)
	{
		perror("Memory allocation failed");
		exit(1);
	}
}

void	count_walls(t_game *game)
{
	int	l;
	int	c;

	l = -1;
	game->nr_walls = 0;
	while (game->map.map[++l])
	{
		c = -1;
		while (game->map.map[l][++c])
			if (game->map.map[l][c] == '1')
				game->nr_walls++;
	}
	game->wall_x = malloc(game->nr_walls * sizeof(int));
	game->wall_y = malloc(game->nr_walls * sizeof(int));
	if (!game->wall_x || !game->wall_y)
	{
		perror("Memory allocation failed");
		exit(1);
	}
}

void	count_enemies(t_game *game)
{
	int	l;
	int	c;

	l = -1;
	game->nr_enemies = 0;
	while (game->map.map[++l])
	{
		c = -1;
		while (game->map.map[l][++c])
			if (game->map.map[l][c] == 'X')
				game->nr_enemies++;
	}
	game->enemy_x = malloc(game->nr_enemies * sizeof(int));
	game->enemy_y = malloc(game->nr_enemies * sizeof(int));
	if (!game->enemy_x || !game->enemy_y)
	{
		perror("Memory allocation failed");
		exit(1);
	}
}
