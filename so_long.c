/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:14:00 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/22 11:58:15 by carlos-j         ###   ########.fr       */
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
X press on window to quit the game

make Exit walkable
swap Exit with X when player is on the exit but not all collectibles are collected and create sprite of player on top of closede door

sprite for player on open door at end of game; show that sprite when exit

use make to switch characters: https://www.youtube.com/watch?v=zaKGzGfHjAQ

implement function to read the screen size and resize the map if needed

use of sprites to display the digits of the score in the window

when the player is facing a wall and you press a key L/R to turn, the sprite change turn imediatly, even if the character is not moving, and not after the next move.

when the 'game over', the player is always facing right, no matter what the last key L/R was

TEST:

*/

#include "so_long.h"

void	hooks(t_game *game)
{
	mlx_hook(game->minilibx.window_mlx, 2, 1, handle_key, game);
	mlx_loop(game->minilibx.connect_mlx);
}

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
	game->last_direction = '\0';
	game->win_state = 0;

	// Initialize MinilibX connection and window pointers
	game->minilibx.connect_mlx = NULL;
	game->minilibx.window_mlx = NULL;
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

