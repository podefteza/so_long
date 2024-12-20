/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:33:01 by carlos-j          #+#    #+#             */
/*   Updated: 2024/12/04 15:13:10 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	screen_check(t_game *game)
{
	int	screen_width;
	int	screen_height;
	int	window_width;
	int	window_height;

	screen_width = 0;
	screen_height = 0;
	game->minilibx.connect_mlx = mlx_init();
	mlx_get_screen_size(game->minilibx.connect_mlx, &screen_width,
		&screen_height);
	window_width = SPRITE_SIZE * game->map.columns;
	window_height = SPRITE_SIZE * game->map.lines;
	if (window_width > screen_width || window_height > screen_height)
		cleanup_and_exit(game, "Error\nMap too large to fit the screen.\n", 13);
	game->minilibx.window_mlx = mlx_new_window(game->minilibx.connect_mlx,
			window_width, window_height, "so_long");
	game->image = mlx_new_image(game->minilibx.connect_mlx, window_width,
			window_height);
}

void	game_setup(t_game *game, int img_size)
{
	screen_check(game);
	load_sprites(game, img_size);
	load_score_left(game, img_size);
	load_score_center(game, img_size);
	load_score_right(game, img_size);
	player_sprites(game, img_size);
	count_enemies(game);
	count_walls(game);
	scan_map(game);
	load_static_elements(game);
	if (game->movements == 0)
		game->last_direction = 'R';
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.player, SPRITE_SIZE
		* game->position_x, SPRITE_SIZE * game->position_y);
}
