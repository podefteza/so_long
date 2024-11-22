/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:28:21 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/22 22:14:23 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_collectibles(t_game *game)
{
	if (game->collectible_x)
	{
		free(game->collectible_x);
		game->collectible_x = NULL;
	}
	if (game->collectible_y)
	{
		free(game->collectible_y);
		game->collectible_y = NULL;
	}
}

void	free_walls(t_game *game)
{
	if (game->wall_x)
	{
		free(game->wall_x);
		game->wall_x = NULL;
	}
	if (game->wall_y)
	{
		free(game->wall_y);
		game->wall_y = NULL;
	}
}

void	free_map(t_game *game)
{
	int i;

	if (game->map.map)
	{
		for (i = 0; i < game->map.lines; i++)
		{
			if (game->map.map[i])
				free(game->map.map[i]);
		}
		free(game->map.map);
		game->map.map = NULL;
	}
}

void free_sprites(t_game *game)
{
	if (game->sprites.player)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.player);
		game->sprites.player = NULL;
	}

	if (game->sprites.win1)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.win1);
		game->sprites.win1 = NULL;
	}
	if (game->sprites.win2)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.win2);
		game->sprites.win2 = NULL;
	}
	if (game->sprites.win3)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.win3);
		game->sprites.win3 = NULL;
	}

	if (game->sprites.p_l_c_door)
	{
        mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_l_c_door);
		game->sprites.p_l_c_door = NULL;
	}
	if (game->sprites.p_r_c_door)
	{
        mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_r_c_door);
		game->sprites.p_r_c_door = NULL;
	}
	if (game->sprites.p_l_o_door)
	{
        mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_l_o_door);
		game->sprites.p_l_o_door = NULL;
	}
    if (game->sprites.p_r_o_door)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_r_o_door);
		game->sprites.p_r_o_door = NULL;
	}

	if (game->sprites.background)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.background);
		game->sprites.background = NULL;
	}

	if (game->sprites.collect)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.collect);
		game->sprites.collect = NULL;
	}

	if (game->sprites.exit_closed)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit_closed);



	if (game->sprites.p_right)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_right);
		game->sprites.p_right = NULL;
	}
	/*if (game->sprites.p_left)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_left);
		game->sprites.p_left = NULL;
	}*/

/*
	if (game->sprites.wall)
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.wall);
*/
}


void	cleanup_and_exit(t_game *game, int exit_code)
{
	// Free dynamically allocated game objects

	free_collectibles(game);
	free_walls(game);
	free_map(game);
	free_sprites(game);
	// Free MinilibX resources
	mlx_destroy_image(game->minilibx.connect_mlx, game->image);
	if (game->minilibx.window_mlx)
		mlx_destroy_window(game->minilibx.connect_mlx, game->minilibx.window_mlx);
	if (game->minilibx.connect_mlx)
	{
		mlx_destroy_display(game->minilibx.connect_mlx);
		free(game->minilibx.connect_mlx);
	}
	game->minilibx.window_mlx = NULL;
	game->minilibx.connect_mlx = NULL;
	exit(exit_code);
}



