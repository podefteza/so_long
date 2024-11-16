/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:33:01 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/16 12:43:24 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_setup(t_game *game, int img_size)
{
	game->minilibx.connect_mlx = mlx_init();
	game->minilibx.window_mlx = mlx_new_window(game->minilibx.connect_mlx,
			SPRITE_SIZE * game->map.columns, SPRITE_SIZE * game->map.lines,
			"so_long");
	game->image = mlx_new_image(game->minilibx.connect_mlx, WIDTH, HEIGHT);
	load_sprites(game, img_size);
	//count_collectibles(game);
	count_walls(game);
	scan_map(game);
	load_static_elements(game);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.player, SPRITE_SIZE
		* game->position_x, SPRITE_SIZE * game->position_y);
}
