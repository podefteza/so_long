/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:28:21 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/25 10:47:06 by carlos-j         ###   ########.fr       */
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

void free_sprites(t_game *game, int exit_code)
{
	if (game->sprites.player)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.player);
		game->sprites.player = NULL;
		//printf("destroyed sprites.player\n");
	}

	if (game->sprites.win1)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.win1);
		game->sprites.win1 = NULL;
		//printf("destroyed sprites.win1\n");
	}
	if (game->sprites.win2)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.win2);
		game->sprites.win2 = NULL;
		//printf("destroyed sprites.win2\n");
	}
	if (game->sprites.win3)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.win3);
		game->sprites.win3 = NULL;
		//printf("destroyed sprites.win3\n");
	}
	if (game->sprites.p_l_c_door)
	{
        mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_l_c_door);
		game->sprites.p_l_c_door = NULL;
		//printf("destroyed sprites.p_l_c_door\n");
	}
	if (game->sprites.p_r_c_door)
	{
        mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_r_c_door);
		game->sprites.p_r_c_door = NULL;
		//printf("destroyed sprites.p_r_c_door\n");
	}
	/*if (game->sprites.p_l_o_door)
	{
        mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_l_o_door);
		game->sprites.p_l_o_door = NULL;
	}
    if (game->sprites.p_r_o_door)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_r_o_door);
		game->sprites.p_r_o_door = NULL;
	}*/
	if (game->sprites.background)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.background);
		game->sprites.background = NULL;
		//printf("destroyed sprites.background\n");
	}

	if (game->sprites.collect)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.collect);
		game->sprites.collect = NULL;
		//printf("destroyed sprites.collect\n");
	}
	// check this one...
	if (game->sprites.exit_closed)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit_closed);
		game->sprites.exit_closed = NULL;
		//printf("destroyed sprites.exit_closed\n");
	}

	if (game->sprites.exit && exit_code == 0)
	//(void)exit_code;
	//if (game->sprites.exit)
	{
		//printf("%p\n", game->sprites.exit);
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit);
		game->sprites.exit = NULL;
		//printf("destroyed sprites.exit\n");
	}

	if (game->sprites.wall && exit_code == 1)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.wall);
		game->sprites.wall = NULL;
		//printf("destroyed sprites.wall\n");
	}

	if (game->sprites.exit_open && exit_code == 1)
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.exit_open);
		game->sprites.exit_open = NULL;
		//printf("destroyed sprites.exit_open\n");
	}

	if (game->sprites.p_left && exit_code == 1 && game->last_direction == 'R')
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_left);
		game->sprites.p_left = NULL;
		//printf("destroyed sprites.p_left\n");
	}
	if (game->sprites.p_right && exit_code == 1 && game->last_direction == 'L')
	{
		mlx_destroy_image(game->minilibx.connect_mlx, game->sprites.p_right);
		game->sprites.p_right = NULL;
		//printf("destroyed sprites.p_right\n");
	}

}


int	cleanup_and_exit(t_game *game, char *message, int exit_code)
{

	ft_putstr_fd(message, 2);

	free_collectibles(game);
	free_walls(game);
	free_map(game);


	if (game->image)
		mlx_destroy_image(game->minilibx.connect_mlx, game->image);
	if (game->minilibx.window_mlx)
		mlx_destroy_window(game->minilibx.connect_mlx, game->minilibx.window_mlx);
	free_sprites(game, exit_code);
	if (game->minilibx.connect_mlx)
	{
		mlx_destroy_display(game->minilibx.connect_mlx);
		free(game->minilibx.connect_mlx);
	}
	exit(exit_code);
}



