/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:17:54 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/25 11:41:12 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_sprites(t_game *game, int img_size)
{
	game->sprites.player = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			P_R_SPRITE, &img_size, &img_size);
	game->sprites.p_right = game->sprites.player;
	game->sprites.p_left = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			P_L_SPRITE, &img_size, &img_size);
	game->sprites.p_l_c_door = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			P_L_C_DOOR_SPRITE, &img_size, &img_size);
	game->sprites.p_r_c_door = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			P_R_C_DOOR_SPRITE, &img_size, &img_size);
}

void	load_sprites(t_game *game, int img_size)
{
	game->sprites.background = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			BG_SPRITE, &img_size, &img_size);
	game->sprites.ex_closed = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			C_DOOR_SPRITE, &img_size, &img_size);
	game->sprites.exit = game->sprites.ex_closed;
	game->sprites.exit_open = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			O_DOOR_SPRITE, &img_size, &img_size);
	game->sprites.collect = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			COLLECT_SPRITE, &img_size, &img_size);
	game->sprites.wall = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			WALL_SPRITE, &img_size, &img_size);
	game->sprites.win1 = mlx_xpm_file_to_image(game->minilibx.connect_mlx, WIN1,
			&img_size, &img_size);
	game->sprites.win2 = mlx_xpm_file_to_image(game->minilibx.connect_mlx, WIN2,
			&img_size, &img_size);
	game->sprites.win3 = mlx_xpm_file_to_image(game->minilibx.connect_mlx, WIN3,
			&img_size, &img_size);
}
