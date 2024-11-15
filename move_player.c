/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:41:56 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/13 10:58:30 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map.map[new_y][new_x] != '1'
		&& !(game->map.map[new_y][new_x] == 'E' && game->nr_collectibles > 0))
	{
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
		if (game->nr_collectibles == 0
			&& game->map.map[game->position_y][game->position_x] == 'E')
		{
			mlx_destroy_window(game->minilibx.connect_mlx,
				game->minilibx.window_mlx);
			ft_putstr_fd("Congratulations, you won!\n", 2);
			exit(0);
		}
	}
}

int	handle_key(int key, t_game *game)
{
	int new_x = game->position_x;
	int new_y = game->position_y;

	new_x = game->position_x;
	new_y = game->position_y;
	if (key == 65307) // free...
		exit(0);
	else if (key == 119 || key == 65362)
		new_y -= 1;
	else if (key == 97 || key == 65361)
	{
		new_x -= 1;
		game->sprites.player = game->sprites.player_left;
	}
	else if (key == 115 || key == 65364)
		new_y += 1;
	else if (key == 100 || key == 65363)
	{
		new_x += 1;
		game->sprites.player = game->sprites.player_right;
	}
	else
		return (0);
	move_player(game, new_x, new_y);
	return (0);
}
