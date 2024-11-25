/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:30:25 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/25 12:15:22 by carlos-j         ###   ########.fr       */
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
	{
		ft_putstr_fd("Error\nInvalid map. ", 1);
		cleanup_and_exit(game, "Impossible to reach the exit.\n", 42);
	}
	if (state.collected < game->nr_collectibles)
	{
		ft_putstr_fd("Error\nInvalid map. ", 1);
		cleanup_and_exit(game, "Not all collectibles can be reached.\n", 42);
	}
	reset_collectibles(game);
	return (state.collected == game->nr_collectibles && state.exit_reached);
}
