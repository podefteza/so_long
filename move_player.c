/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:41:56 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/16 12:42:19 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
    if (game->map.map[new_y][new_x] != '1')
    {
        if (new_x < game->position_x)
            game->last_direction = 'L'; // Moving left
        else if (new_x > game->position_x)
            game->last_direction = 'R'; // Moving right

        if (game->map.map[new_y][new_x] == 'C')
        {
            game->nr_collectibles--;
            game->map.map[new_y][new_x] = '0';
        }

        mlx_put_image_to_window(game->minilibx.connect_mlx,
            game->minilibx.window_mlx, game->sprites.background,
            SPRITE_SIZE * game->position_x, SPRITE_SIZE * game->position_y);

        game->position_x = new_x;
        game->position_y = new_y;
        game->movements++;

        refresh_dynamic_elements(game);
        draw_exit(game);

        // Check win condition
        if (game->nr_collectibles == 0
            && game->map.map[game->position_y][game->position_x] == 'E')
        {
            game->win_state = 1; // Set win state
			mlx_string_put(game->minilibx.connect_mlx, game->minilibx.window_mlx, 50, 50, 1, "Congratulations, you won!\nPress any key to exit.");
        }
    }
}



int	handle_key(int key, t_game *game)
{
	int new_x = game->position_x;
	int new_y = game->position_y;


	if (game->win_state == 1)
    {

		mlx_destroy_window(game->minilibx.connect_mlx, game->minilibx.window_mlx);
        ft_putstr_fd("Congratulations, you won!\n", 1);
        exit(0);
    }

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
