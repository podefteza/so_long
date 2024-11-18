/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:14:00 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/18 18:34:47 by carlos-j         ###   ########.fr       */
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

TEST:

*/

#include "so_long.h"

void	hooks(t_game *game)
{
	mlx_hook(game->minilibx.window_mlx, 2, 1, handle_key, game);
	mlx_loop(game->minilibx.connect_mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		img_size;
	int		read_map;

	img_size = SPRITE_SIZE;
	game.movements = 0;
	if (extension_check(argc, argv) == 1)
		exit(0);

	// handle errors reading map...
	read_map = map_checker(argv[1], &game);
	if (read_map == 0 || read_map == -1)
		exit(1);
	game_setup(&game, img_size);
	hooks(&game);
	return (0);
}
