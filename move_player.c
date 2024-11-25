/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:41:56 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/25 11:32:39 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_message(t_game *game, t_center *center)
{
	center->center_x = (game->map.columns * SPRITE_SIZE) / 2 - 32;
	center->center_y = (game->map.lines * SPRITE_SIZE) / 2;
	center->sprite1_x = center->center_x - SPRITE_SIZE;
	center->sprite2_x = center->center_x;
	center->sprite3_x = center->center_x + SPRITE_SIZE;
	center->sprite_y = center->center_y - SPRITE_SIZE / 2;
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.win1, center->sprite1_x,
		center->sprite_y);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.win2, center->sprite2_x,
		center->sprite_y);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.win3, center->sprite3_x,
		center->sprite_y);
	center->message_x = center->center_x - 40;
	center->message_y = center->sprite_y + SPRITE_SIZE + 15;
	mlx_string_put(game->minilibx.connect_mlx, game->minilibx.window_mlx,
		center->message_x, center->message_y, 0xFFFFFF,
		"Press any key to exit.");
}

void	check_win(t_game *game)
{
	t_center	center;

	if (game->nr_collectibles == 0
		&& game->map.map[game->position_y][game->position_x] == 'E')
		game->win_state = 1;
	if (game->win_state == 1)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.background);
		game->sprites.background = game->sprites.wall;
		draw_background(game);
		mlx_put_image_to_window(game->minilibx.connect_mlx,
			game->minilibx.window_mlx, game->sprites.exit, SPRITE_SIZE
			* game->position_x, SPRITE_SIZE * game->position_y);
		win_message(game, &center);
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map.map[new_y][new_x] != '1')
	{
		if (new_x < game->position_x)
			game->last_direction = 'L';
		else if (new_x > game->position_x)
			game->last_direction = 'R';
		if (game->map.map[new_y][new_x] == 'C')
		{
			game->nr_collectibles--;
			game->map.map[new_y][new_x] = '0';
		}
		mlx_put_image_to_window(game->minilibx.connect_mlx,
			game->minilibx.window_mlx, game->sprites.background, SPRITE_SIZE
			* game->position_x, SPRITE_SIZE * game->position_y);
		game->position_x = new_x;
		game->position_y = new_y;
		game->movements++;
		refresh_dynamic_elements(game);
		draw_exit(game);
		check_win(game);
	}
}

int	handle_key(int key, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->position_x;
	new_y = game->position_y;
	if (game->win_state == 1)
		cleanup_and_exit(game, "Congratulations, you won!\n", 0);
	if (key == 65307)
		cleanup_and_exit(game, "Error\nYou quit the game.\n", 1);
	else if (key == 119 || key == 65362)
		new_y -= 1;
	else if (key == 97 || key == 65361)
	{
		new_x -= 1;
		game->sprites.player = game->sprites.p_left;
	}
	else if (key == 115 || key == 65364)
		new_y += 1;
	else if (key == 100 || key == 65363)
	{
		new_x += 1;
		game->sprites.player = game->sprites.p_right;
	}
	move_player(game, new_x, new_y);
	return (0);
}
