/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:14:00 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/06 18:29:36 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
External functs.: open, close, read, write, malloc, free, perror, strerror, exit
• All functions of the math library (-lm compiler option, man man 3 math)
• All functions of the MiniLibX
• ft_printf and any equivalent YOU coded
Libft authorized: Yes
*/

#include "so_long.h"

int handle_key(int keycode)
{
    if (keycode == 65307)
    {
        exit(0);
    }
    return (0);
}


int initial_check(int argc, char **argv)
{
	size_t	len;

	// verify arguments
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long map.ber\n", 2);
		return (1);
	}

	// verify extention
	len = ft_strlen(argv[1]);
	if ((len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0))
	{
		ft_putstr_fd("Usage: ./so_long map.ber\n", 2);
		return (1);
	}

	// function to validade map

	return (0);
}

int	map_checker(char *argv, t_game *game)
{
	int	count;
	int	fd;

	game->map.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!game->map.buffer)
		return (0);
	fd = open (argv, O_RDONLY);
	count = read(fd, game->map.buffer, BUFFER_SIZE);
	if (count == -1)
	{
		free(game->map.buffer);
		return (-1);
	}
	game->map.buffer[count] = '\0';
	game->map.map = ft_split(game, '\n');
	// free...
	return (1);
}

void	load_background(t_game *game)
{
	int	l;
	int	c;

	l = -1;
	while (++l < game->map.lines)
	{
		c = -1;
		while (++c < game->map.columns)
		{
			mlx_put_image_to_window(game->minilibx.connect_mlx, game->minilibx.window_mlx, game->sprites.background, SPRITE_SIZE * c, SPRITE_SIZE * l);
		}
	}
}


int	main(int argc, char **argv)
{
	t_game game;

	int		img_size = 64;
	int read_map;

	if (initial_check(argc, argv) == 1)
		exit(0);

	// handle errors reading map...
	read_map = map_checker(argv[1], &game);
	if (read_map == 0 || read_map == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}


	// the size of the window will depend on the map
	game.minilibx.connect_mlx = mlx_init();
	game.minilibx.window_mlx = mlx_new_window(game.minilibx.connect_mlx, img_size * game.map.columns, img_size * game.map.lines, "so_long");
	game.image = mlx_new_image(game.minilibx.connect_mlx, WIDTH, HEIGHT);

	// load sprites
	game.sprites.background = mlx_xpm_file_to_image(game.minilibx.connect_mlx, BACKGROUND_SPRITE, &img_size, &img_size);
	game.sprites.player = mlx_xpm_file_to_image(game.minilibx.connect_mlx, PLAYER_RIGHT_SPRITE, &img_size, &img_size);
	game.sprites.exit = mlx_xpm_file_to_image(game.minilibx.connect_mlx, EXIT_SPRITE, &img_size, &img_size);

	// fill background
	load_background(&game);

	// player
	int l = -1;
	int c;
	while (game.map.map[++l])
	{
		c = -1;
		while (game.map.map[l][++c])
		{
			if (game.map.map[l][c] == 'P')
			{
				game.position_x = l;
				game.position_y = c;
			}

			if (game.map.map[l][c] == 'E')
			{
				game.exit_x = l;
				game.exit_y = c;
			}
		}

	}
	printf("%d %d", game.position_x, game.position_y);
	mlx_put_image_to_window(game.minilibx.connect_mlx, game.minilibx.window_mlx, game.sprites.player, img_size * game.position_y, img_size * game.position_x);




	mlx_put_image_to_window(game.minilibx.connect_mlx, game.minilibx.window_mlx, game.sprites.exit, 0, 300);


	mlx_key_hook(game.minilibx.window_mlx, handle_key, NULL);
	mlx_loop(game.minilibx.connect_mlx);
}
