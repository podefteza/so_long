/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:30:25 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/13 16:59:08 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_output(char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
}

int	initial_check(int argc, char **argv)
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

int	check_walls(t_game *game)
{
	int		height;
	int		width;
	int		i;
	char	*wall_error;

	height = game->map.lines;
	width = ft_strlen(game->map.map[0]);
	i = 0;
	wall_error = "Error\nMap must be closed by walls.\n";
	while (i < width)
	{
		if (game->map.map[0][i] != '1' || game->map.map[height - 1][i] != '1')
			error_output(wall_error);
		i++;
	}
	i = 1;
	while (i < height - 1)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][width - 1] != '1')
			error_output(wall_error);
		i++;
	}
	return (1);
}

int	check_character_count(t_game *game)
{
	int	i;
	int	j;
	int	exit_count;
	int	start_count;
	int	collectible_count;

	i = 0;
	start_count = 0;
	exit_count = 0;
	collectible_count = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'P')
			{
				start_count++;
				game->position_x = i;
				game->position_y = j;
			}
			if (game->map.map[i][j] == 'E')
			{
				exit_count++;
				game->exit_x = i;
				game->exit_y = j;
			}
			if (game->map.map[i][j] == 'C')
				collectible_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1 || start_count != 1 || collectible_count < 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map must have 1 player start, 1 exit, ", 2);
		ft_putstr_fd("and at least 1 collectible.\n", 2);
		exit (1);
	}
	return (1);
}

int	check_rectangular(t_game *game)
{
	int	i;

	i = 1;
	while (game->map.map[i])
	{
		if ((int)ft_strlen(game->map.map[i]) != game->map.columns)
		{
			ft_putstr_fd("Error\nMap must be rectangular.\n", 2);
			exit (1);
		}
		i++;
	}
	return (1);
}

void	count_collectibles(t_game *game)
{
	int	l;
	int	c;

	l = -1;
	game->nr_collectibles = 0;
	while (game->map.map[++l])
	{
		c = -1;
		while (game->map.map[l][++c])
		{
			if (game->map.map[l][c] == 'C')
			{
				game->nr_collectibles++;
			}
		}
	}
	// Allocate memory for collectible coordinates based on count
	game->collectible_x = malloc(game->nr_collectibles * sizeof(int));
	game->collectible_y = malloc(game->nr_collectibles * sizeof(int));
	if (!game->collectible_x || !game->collectible_y)
	{
		perror("Memory allocation failed");
		exit(1);
	}
}

void	count_walls(t_game *game)
{
	int	l;
	int	c;

	l = -1;
	game->nr_walls = 0;
	while (game->map.map[++l])
	{
		c = -1;
		while (game->map.map[l][++c])
		{
			if (game->map.map[l][c] == '1')
				game->nr_walls++;
		}
	}
	// Allocate memory for collectible coordinates based on count
	game->wall_x = malloc(game->nr_walls * sizeof(int));
	game->wall_y = malloc(game->nr_walls * sizeof(int));
	if (!game->wall_x || !game->wall_y)
	{
		perror("Memory allocation failed");
		exit(1);
	}
}

int is_reachable(t_game *game, int x, int y)
{
    // Check boundaries and valid cells (either empty, collectible, or exit)
    return (x >= 0 && x < game->map.lines && y >= 0 && y < game->map.columns
            && (game->map.map[x][y] == '0' || game->map.map[x][y] == 'C'
            || game->map.map[x][y] == 'E') && game->map.map[x] != NULL);
}

void print_map(t_game *game)
{
    for (int i = 0; i < game->map.lines; i++)
    {
        for (int j = 0; j < game->map.columns; j++)
            printf("%c", game->map.map[i][j]);
        printf("\n");
    }
}

void	reset_collectibles(t_game *game)
{
	int	l;
	int	c;

	l = -1;
	while (game->map.map[++l])
	{
		c = -1;
		while (game->map.map[l][++c])
		{
			if (game->map.map[l][c] == '#')
			{
				game->map.map[l][c] = 'C';
			}
		}
	}
}


int flood_fill(t_game *game, int x, int y, int *collected, int *exit_reached)
{
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int new_x, new_y;
    int i = 0;

    // Check if the position is out of bounds
    if (x < 0 || x >= game->map.lines || y < 0 || y >= game->map.columns)
		return 0;

    // If we find a collectible, increment the counter
    if (game->map.map[x][y] == 'C')
	{
        (*collected)++;
		//printf("Was able to reach C at %d, %d\n", x, y);
	}
    // If we've reached the exit
    if (game->map.map[x][y] == 'E')
	{
        *exit_reached = 1;
	}

    // Mark the cell as visited if it contains '0' (empty space)
    //char temp = game->map.map[x][y];
    if (game->map.map[x][y] == '0')
	{
		game->map.map[x][y] = '*';  // Use '*' to mark as visited
	}
	if (game->map.map[x][y] == 'C')
	{
		game->map.map[x][y] = '#';  // Use '*' to mark as visited
	}

    // Explore all four directions using a while loop
    while (i < 4)
    {
        new_x = x + directions[i][0];
        new_y = y + directions[i][1];

        if (is_reachable(game, new_x, new_y))
            flood_fill(game, new_x, new_y, collected, exit_reached);
        i++;
    }
	//printf("After flood_fill\n");
	//print_map(game);

    // Restore the original state of the map cell
    //game->map.map[x][y] = temp;
	//printf("Restored to original\n");
	//print_map(game);

    return (*collected == game->nr_collectibles && *exit_reached);
}




int check_valid_path(t_game *game)
{
    int collected = 0;
    int exit_reached = 0;

	count_collectibles(game);

    //printf("Checking path from (%d, %d) to exit at (%d, %d)\n", game->position_x, game->position_y, game->exit_x, game->exit_y);
	flood_fill(game, game->position_x, game->position_y, &collected, &exit_reached);

    //printf("Collected: %d, Required: %d, Exit Reached: %d\n", collected, game->nr_collectibles, exit_reached);
	if (exit_reached == 0)
		ft_putstr_fd("Impossible to reach the exit, map invalid... bla bla bla, fix\n", 2);
	if (collected < game->nr_collectibles)
		ft_putstr_fd("Not all collectibles can be reached... bla bla bla, fix\n", 2);
	//print_map(game);
	reset_collectibles(game);
    return (collected == game->nr_collectibles && exit_reached);
}



void scan_map(t_game *game)
{
    int l, c;
    int nr_collectibles = 0;
    int nr_walls = 0;

    l = -1;
	while (game->map.map[++l])
	{
		c = -1;
		while (game->map.map[l][++c])
		{
			if (game->map.map[l][c] == 'P')
			{
				game->position_x = c;
				game->position_y = l;
			}
			if (game->map.map[l][c] == 'E')
			{
				game->exit_x = c;
				game->exit_y = l;
			}
			if (game->map.map[l][c] == 'C')
			{
				game->collectible_x[nr_collectibles] = c;
				game->collectible_y[nr_collectibles] = l;
				nr_collectibles++;
			}
			if (game->map.map[l][c] == '1')
			{
				game->wall_x[nr_walls] = c;
				game->wall_y[nr_walls] = l;
				nr_walls++;
			}
		}
	}

    // Ensure 'P' exists before proceeding
    if (game->position_x == -1 || game->position_y == -1)
    {
        printf("Player 'P' not found on the map.\n");
        exit(1);  // Exit or handle the error gracefully
    }
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
