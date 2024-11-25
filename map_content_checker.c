/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:50:33 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/25 13:06:35 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *game)
{
	int		height;
	int		width;
	int		i;
	char	*wall_error;

	height = game->map.lines;
	width = ft_strlen(game->map.map[0]);
	i = 0;
	wall_error = "Error\nMap must be closed by walls.\n";
	while (i < width)
	{
		if (game->map.map[0][i] != '1' || game->map.map[height - 1][i] != '1')
			cleanup_and_exit(game, wall_error, 42);
		i++;
	}
	i = 1;
	while (i < height - 1)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][width - 1] != '1')
			cleanup_and_exit(game, wall_error, 42);
		i++;
	}
	return (1);
}

int	check_rectangular(t_game *game)
{
	int	i;

	i = 1;
	while (game->map.map[i])
	{
		if ((int)ft_strlen(game->map.map[i]) != game->map.columns)
			cleanup_and_exit(game, "Error\nMap must be rectangular.\n", 42);
		i++;
	}
	return (1);
}
