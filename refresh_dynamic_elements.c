/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_dynamic_elements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:05:18 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/13 10:08:33 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to refresh dynamic elements like player and collectible
void	refresh_dynamic_elements(t_game *game)
{
	static int	prev_x = -1;
	static int	prev_y = -1;

	// Clear the previous player position by drawing the background
	if (prev_x != -1 && prev_y != -1)
	{
		mlx_put_image_to_window(game->minilibx.connect_mlx,
			game->minilibx.window_mlx, game->sprites.background, SPRITE_SIZE
			* prev_x, SPRITE_SIZE * prev_y);
	}
	// Update previous position to the current one before moving player
	prev_x = game->position_x;
	prev_y = game->position_y;
	// Redraw the player at the new position
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.player, SPRITE_SIZE
		* game->position_x, SPRITE_SIZE * game->position_y);
	// Print movement count in the terminal for debugging
	ft_putstr_fd("Movements: ", 2);
	ft_putnbr_fd(game->movements, 2);
	ft_putstr_fd("\n", 2);
}
