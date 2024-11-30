/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_variables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:12:05 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 14:43:40 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	game->nr_enemies = 0;
	game->enemy_x = NULL;
	game->enemy_y = NULL;
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

void	default_score_right_default(t_game *game)
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

void	defaults(t_game *game)
{
	default_values(game);
	default_score_left_center(game);
	default_score_right_default(game);
	default_sprites(game);
}
