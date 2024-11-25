/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:14:00 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/25 10:37:26 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
External functs.: open, close, read, write, malloc, free, perror, strerror, exit
• All functions of the math library (-lm compiler option, man man 3 math)
• All functions of the MiniLibX
• ft_printf and any equivalent YOU coded
Libft authorized: Yes
*/

/*TODO:

- fix when quitting game and facing left

use of sprites to display the digits of the score in the window

when the player is facing a wall and you press a key L/R to turn, the sprite change turn imediatly, even if the character is not moving, and not after the next move.


*/

#include "so_long.h"

void start_game(t_game *game)
{
	// Initialize sprites
	game->sprites.player_position = 0;
	game->sprites.background = NULL;
	game->sprites.wall = NULL;
	game->sprites.player = NULL;
	game->sprites.p_left = NULL;
	game->sprites.p_right = NULL;
	game->sprites.p_l_c_door = NULL;
	game->sprites.p_r_c_door = NULL;
	game->sprites.p_l_o_door = NULL;
	game->sprites.p_r_o_door = NULL;
	game->sprites.collect = NULL;
	game->sprites.win1 = NULL;
	game->sprites.win2 = NULL;
	game->sprites.win3 = NULL;
	game->sprites.exit = NULL;
	game->sprites.exit_closed = NULL;
	game->sprites.exit_open = NULL;

	// Initialize map-related variables
	game->map.map = NULL;
	game->map.buffer = NULL;
	game->map.lines = 0;
	game->map.columns = 0;
	game->map.exit = 0;

	// Initialize other game properties
	game->movements = 0;
	game->position_x = 0;
	game->position_y = 0;
	game->player_count = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->exit_count = 0;
	game->nr_collectibles = 0;
	game->collectible_x = NULL;
	game->collectible_y = NULL;
	game->nr_walls = 0;
	game->wall_x = NULL;
	game->wall_y = NULL;
	game->image = NULL;
	game->addr = NULL;
	game->last_direction = '\0'; // if player is on the left of the map, load R, otherwise, load L
	game->win_state = 0;

	game->minilibx.connect_mlx = NULL;
	game->minilibx.window_mlx = NULL;
}

int	exit_game(t_game *game)
{
    cleanup_and_exit(game, "Error\nYou quit the game.\n", 1);
    return 0;
}

void	hooks(t_game *game)
{
	mlx_hook(game->minilibx.window_mlx, 2, 1L << 0, handle_key, game);
	mlx_hook(game->minilibx.window_mlx, 17, 0, &exit_game, game);
	mlx_loop(game->minilibx.connect_mlx);
}


int	main(int argc, char **argv)
{
	t_game	game;
	int		img_size;
	int		read_map;

	start_game(&game);
	img_size = SPRITE_SIZE;
	if (extension_check(argc, argv, &game) == 1)
		exit(0);
	read_map = map_checker(argv[1], &game);
	if (read_map == 0 || read_map == -1)
		exit(1);
	game_setup(&game, img_size);
	hooks(&game);
	return (0);
}

