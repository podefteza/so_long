/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:22:03 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/18 18:34:41 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extension_check(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long map.ber\n", 2);
		exit (1);
	}
	len = ft_strlen(argv[1]);
	if ((len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0))
	{
		ft_putstr_fd("Error\nInvalid file extension. Use .ber files only.\n",
			2);
		exit (1);
	}
	return (0);
}



int map_checker(char *argv, t_game *game)
{
	int count;
	int fd;

	game->map.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!game->map.buffer)
		return (error_output("Memory allocation failed for buffer.\n"));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (error_output("Failed to open map file.\n"));

	count = read(fd, game->map.buffer, BUFFER_SIZE);
	if (count == -1)
	{
		free(game->map.buffer);
		close(fd);
		return (error_output("Failed to read map file.\n"));
	}
	close(fd);

	game->map.buffer[count] = '\0';


	//printf("Map buffer after read:\n%s\n", game->map.buffer);
	game->map.map = ft_split(game, '\n');
	if (!game->map.map)
	{
		printf("ft_split failed.\n");
		exit(1);  // Or return an error code if necessary
	}

	free(game->map.buffer);  // Free buffer after parsing

	if (!game->map.map)
		return (error_output("Failed to split map into lines.\n"));
	if (!check_character_count(game) || !check_rectangular(game) ||
		!check_walls(game) || !check_valid_path(game))
	{
		// Free map if any checks fail
		for (int i = 0; game->map.map[i]; i++)
			free(game->map.map[i]);
		free(game->map.map);
		return (0);
	}
	return (1);
}
