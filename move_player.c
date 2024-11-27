/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:41:56 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/27 11:24:09 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_putstr_fd("Movements: ", 2);
		ft_putnbr_fd(game->movements, 2);
		ft_putstr_fd("\n", 2);
		refresh_dynamic_elements(game);
		draw_exit(game);
		check_win(game);
	}
}

int	player_between_walls(t_game *game, int new_x, int new_y)
{
	if (game->map.map[new_y][new_x] == '1' && game->position_x == game->exit_x
		&& game->position_y == game->exit_y)
	{
		if (game->last_direction == 'L')
			game->sprites.player = game->sprites.p_l_c_door;
		else
			game->sprites.player = game->sprites.p_r_c_door;
		refresh_dynamic_elements(game);
		return (0);
	}
	else
		return (1);
}

void	player_on_exit(t_game *game)
{
	if (game->position_x == game->exit_x && game->position_y == game->exit_y)
	{
		if (game->nr_collectibles == 0)
		{
			if (game->last_direction == 'L')
				game->sprites.player = game->sprites.p_l_c_door;
			else
				game->sprites.player = game->sprites.p_r_c_door;
		}
		else
		{
			if (game->last_direction == 'L')
				game->sprites.player = game->sprites.p_left;
			else
				game->sprites.player = game->sprites.p_right;
		}
	}
}

int	process_key_input(int key, t_game *game, int *new_x, int *new_y)
{
	if (key == 65307)
		cleanup_and_exit(game, "Error\nYou quit the game.\n", 1);
	else if (key == 119 || key == 65362)
		*new_y -= 1;
	else if (key == 115 || key == 65364)
		*new_y += 1;
	else if (key == 97 || key == 65361)
	{
		*new_x -= 1;
		game->last_direction = 'L';
		game->sprites.player = game->sprites.p_left;
	}
	else if (key == 100 || key == 65363)
	{
		*new_x += 1;
		game->last_direction = 'R';
		game->sprites.player = game->sprites.p_right;
	}
	return (0);
}

int	handle_key(int key, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->position_x;
	new_y = game->position_y;
	process_key_input(key, game, &new_x, &new_y);
	if (game->win_state == 1)
		cleanup_and_exit(game, "Congratulations, you won!\n", 0);
	if (player_between_walls(game, new_x, new_y) == 0)
		return (0);
	player_on_exit(game);
	refresh_dynamic_elements(game);
	move_player(game, new_x, new_y);
	return (0);
}
