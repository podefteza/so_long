/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:14:00 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/27 12:00:15 by carlos-j         ###   ########.fr       */
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
create sprites for score up to 999


*/

#include "so_long.h"

void	default_values(t_game *game)
{
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
	game->minilibx.connect_mlx = NULL;
	game->minilibx.window_mlx = NULL;
}

void	default_score_left_center(t_game *game)
{
	game->score.left_0 = NULL;
	game->score.left_1 = NULL;
	game->score.left_2 = NULL;
	game->score.left_3 = NULL;
	game->score.left_4 = NULL;
	game->score.left_5 = NULL;
	game->score.left_6 = NULL;
	game->score.left_7 = NULL;
	game->score.left_8 = NULL;
	game->score.left_9 = NULL;
	game->score.center_0 = NULL;
	game->score.center_1 = NULL;
	game->score.center_2 = NULL;
	game->score.center_3 = NULL;
	game->score.center_4 = NULL;
	game->score.center_5 = NULL;
	game->score.center_6 = NULL;
	game->score.center_7 = NULL;
	game->score.center_8 = NULL;
	game->score.center_9 = NULL;
}

void	default_score_left_default(t_game *game)
{
	game->score.right_0 = NULL;
	game->score.right_1 = NULL;
	game->score.right_2 = NULL;
	game->score.right_3 = NULL;
	game->score.right_4 = NULL;
	game->score.right_5 = NULL;
	game->score.right_6 = NULL;
	game->score.right_7 = NULL;
	game->score.right_8 = NULL;
	game->score.right_9 = NULL;
	game->score.score_left = NULL;
	game->score.score_center = NULL;
	game->score.score_right = NULL;
}

void	default_sprites(t_game *game)
{
	game->sprites.player_position = 0;
	game->sprites.background = NULL;
	game->sprites.wall = NULL;
	game->sprites.player = NULL;
	game->sprites.p_right = NULL;
	game->sprites.p_left = NULL;
	game->sprites.collect = NULL;
	game->sprites.win1 = NULL;
	game->sprites.win2 = NULL;
	game->sprites.win3 = NULL;
	game->sprites.exit = NULL;
	game->sprites.ex_closed = NULL;
	game->sprites.exit_open = NULL;
	game->map.map = NULL;
	game->map.buffer = NULL;
	game->map.lines = 0;
	game->map.columns = 0;
	game->map.exit = 0;
	game->map.map_read_fd = 0;
}

int	exit_game(t_game *game)
{
	cleanup_and_exit(game, "Error\nYou quit the game.\n", 1);
	return (0);
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

	default_values(&game);
	default_sprites(&game);
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
