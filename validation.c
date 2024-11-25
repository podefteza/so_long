/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:30:25 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/23 11:58:18 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y, t_flood_fill *state)
{
	init_directions(state->directions);
	process_cell(game, x, y, state);
	explore_neighbors(game, x, y, state);
}

int	check_valid_path(t_game *game)
{
	t_flood_fill	state;

	state.collected = 0;
	state.exit_reached = 0;
	count_collectibles(game);
	flood_fill(game, game->position_x, game->position_y, &state);
	if (state.exit_reached == 0)
		cleanup_and_exit(game, "Error\n Invalid map. Impossible to reach the exit.\n", 0);
	if (state.collected < game->nr_collectibles)
	{
		ft_putstr_fd("Error\n", 2);
		cleanup_and_exit(game, "Invalid map. Not all collectibles can be reached.\n", 0);
	}
	reset_collectibles(game);
	return (state.collected == game->nr_collectibles && state.exit_reached);
}
