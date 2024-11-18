/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:41:56 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/18 15:06:27 by carlos-j         ###   ########.fr       */
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
        }
		if (game->win_state == 1)
		{
			game->sprites.background = game->sprites.wall;
			draw_background(game);

			mlx_put_image_to_window(game->minilibx.connect_mlx,
            game->minilibx.window_mlx, game->sprites.exit,
            SPRITE_SIZE * game->position_x, SPRITE_SIZE * game->position_y);

			// Calculate the center of the window
			int center_x = (game->map.columns * SPRITE_SIZE) / 2 - 32;
			int center_y = (game->map.lines * SPRITE_SIZE) / 2;

			// Adjust to position sprites in a row
			int sprite1_x = center_x - SPRITE_SIZE; // Left sprite
			int sprite2_x = center_x;              // Center sprite
			int sprite3_x = center_x + SPRITE_SIZE; // Right sprite
			int sprite_y = center_y - SPRITE_SIZE / 2; // Center vertically


			// Put sprites on the window
			mlx_put_image_to_window(game->minilibx.connect_mlx, game->minilibx.window_mlx,
				game->sprites.win1, sprite1_x, sprite_y);
			mlx_put_image_to_window(game->minilibx.connect_mlx, game->minilibx.window_mlx,
				game->sprites.win2, sprite2_x, sprite_y);
			mlx_put_image_to_window(game->minilibx.connect_mlx, game->minilibx.window_mlx,
				game->sprites.win3, sprite3_x, sprite_y);

			// Position the message below the sprites
			int message_x = center_x - 40; // Estimate width of text (8 chars * 24px per char)
			int message_y = sprite_y + SPRITE_SIZE + 20; // 20 pixels below the sprites

			mlx_string_put(game->minilibx.connect_mlx, game->minilibx.window_mlx,
				message_x, message_y, 0xFFFFFF, "Press any key to exit.");

		}


    }
}

/*void	move_player(t_game *game, int new_x, int new_y)
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
		draw_exit(game);

        mlx_put_image_to_window(game->minilibx.connect_mlx,
            game->minilibx.window_mlx, game->sprites.background,
            SPRITE_SIZE * game->position_x, SPRITE_SIZE * game->position_y);

        game->position_x = new_x;
        game->position_y = new_y;
        game->movements++;

        refresh_dynamic_elements(game);


        // Check win condition
        if (game->nr_collectibles == 0
            && game->map.map[game->position_y][game->position_x] == 'E')
        {
            game->win_state = 1; // Set win state
        }
		if (game->win_state == 1)
		{
			game->sprites.background = game->sprites.wall;
			draw_background(game);

			// Calculate the center of the window
			int center_x = (game->map.columns * SPRITE_SIZE) / 2 - 32;
			int center_y = (game->map.lines * SPRITE_SIZE) / 2;

			// Adjust to position sprites in a row
			int sprite1_x = center_x - SPRITE_SIZE; // Left sprite
			int sprite2_x = center_x;              // Center sprite
			int sprite3_x = center_x + SPRITE_SIZE; // Right sprite
			int sprite_y = center_y - SPRITE_SIZE / 2; // Center vertically

			// Put sprites on the window
			mlx_put_image_to_window(game->minilibx.connect_mlx, game->minilibx.window_mlx,
				game->sprites.win1, sprite1_x, sprite_y);
			mlx_put_image_to_window(game->minilibx.connect_mlx, game->minilibx.window_mlx,
				game->sprites.win2, sprite2_x, sprite_y);
			mlx_put_image_to_window(game->minilibx.connect_mlx, game->minilibx.window_mlx,
				game->sprites.win3, sprite3_x, sprite_y);

			// Position the message below the sprites
			int message_x = center_x - 40; // Estimate width of text (8 chars * 24px per char)
			int message_y = sprite_y + SPRITE_SIZE + 20; // 20 pixels below the sprites



			mlx_string_put(game->minilibx.connect_mlx, game->minilibx.window_mlx,
				message_x, message_y, 0xFFFFFF, "Press any key to exit.");

			draw_exit(game);
		}

	}
}*/



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
