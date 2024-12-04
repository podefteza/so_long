/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:14:00 by carlos-j          #+#    #+#             */
/*   Updated: 2024/12/04 15:13:03 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	if (game->win_state == 1)
		cleanup_and_exit(game, "Congratulations, you won!\n", 0);
	cleanup_and_exit(game, "Error\nYou quit the game.\n", 1);
	return (0);
}

void	hooks(t_game *game)
{
	mlx_hook(game->minilibx.window_mlx, 2, 1, handle_key, game);
	mlx_hook(game->minilibx.window_mlx, 17, 0, &exit_game, game);
	mlx_loop(game->minilibx.connect_mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		img_size;
	int		read_map;

	defaults(&game);
	img_size = SPRITE_SIZE;
	if (extension_check(argc, argv, &game) != 1)
		cleanup_and_exit(&game, "Error\nFailed to open map file.\n", 5);
	read_map = map_checker(argv[1], &game);
	if (read_map == 0 || read_map == -1)
		exit(1);
	game_setup(&game, img_size);
	hooks(&game);
	return (0);
}
