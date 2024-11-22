/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:41:56 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/22 17:41:16 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_message(t_game *game)
{
	int	center_x;
	int	center_y;
	int	sprite1_x;
	int	sprite2_x;
	int	sprite3_x;
	int	sprite_y;
	int	message_x;
	int	message_y;

	center_x = (game->map.columns * SPRITE_SIZE) / 2 - 32;
	center_y = (game->map.lines * SPRITE_SIZE) / 2;
	sprite1_x = center_x - SPRITE_SIZE;
	sprite2_x = center_x;
	sprite3_x = center_x + SPRITE_SIZE;
	sprite_y = center_y - SPRITE_SIZE / 2;
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.win1, sprite1_x, sprite_y);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.win2, sprite2_x, sprite_y);
	mlx_put_image_to_window(game->minilibx.connect_mlx,
		game->minilibx.window_mlx, game->sprites.win3, sprite3_x, sprite_y);
	message_x = center_x - 40;
	message_y = sprite_y + SPRITE_SIZE + 15;
	mlx_string_put(game->minilibx.connect_mlx, game->minilibx.window_mlx,
		message_x, message_y, 0xFFFFFF, "Press any key to exit.");
}

void	check_win(t_game *game)
{
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
		win_message(game);
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
	{
		ft_putstr_fd("Congratulations, you won!\n", 1);
		cleanup_and_exit(game, 0);
	}
	new_x = game->position_x;
	new_y = game->position_y;
	if (key == 65307)
		cleanup_and_exit(game, 1);
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
	else
		return (0);
	move_player(game, new_x, new_y);
	return (0);
}
