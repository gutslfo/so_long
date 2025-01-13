#include "solong.h"

int	check_structure(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		if (i == 0 || i == map->height - 1)
		{
			j = 0;
			while (j < map->width - 1)
			{
				if (map->grid[i][j] != '1')
				{
					printf("Map must be surrounded by walls");
					return(0);
				}
				j++;
			}
		}
		else if(map->grid[i][0]!= '1' || map->grid[i][map->width - 1] == '1')
		{
			printf("Map must be surrounded by walls\n");
			return(0);
		}
		i++;	
	}
	return(1);
}

int	validate_elements(t_map *map)
{
	int	i;
	int	j;
	int	player_count;
	int	exit_count;
	
	player_count = 0;
	exit_count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!ft_strchr("01CEP", map->grid[i][j]))
			{
				printf("Invalid element");
				return(0);
			}
			if (map->grid[i][j] == 'P')
			{
				player_count++;
				printf("Player count: %d\n", player_count);
				map->player_x = j;
				map->player_y = i;
			}
			else if (map->grid[i][j] == 'E')
			{
				exit_count++;
				printf("Exit count: %d\n", exit_count);
				map->exit_x = j;
				map->exit_y = i;
			}
			else if (map->grid[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		printf("You must have one player position (P)\n");
		return (0);
	}
	if (exit_count != 1)
	{
		printf("You must have one exit position (E)\n");
		return (0);
	}
	if (map->collectibles <= 0)
	{
		printf("You must have at least one collectible on the map\n");
		return (0);
	}
	return (1);
}

void	floodfill(char **map_copy, int height, int width, int y, int x, int *collectibles)
{
	if( x < 0 || x >= width || y < 0 || y >= height )
		return;
	
	if (map_copy[y][x] == '1'|| map_copy[y][x] == 'V')
		return;
	
	if (map_copy[y][x] == 'C')
		(*collectibles)++;
	
	map_copy[y][x] = 'V';

	floodfill(map_copy, height, width, y + 1, x, collectibles);
	floodfill(map_copy, height, width, y - 1, x, collectibles);
	floodfill(map_copy, height, width, y, x + 1, collectibles);
	floodfill(map_copy, height, width, y, x - 1, collectibles);
	
}

int	floodtest(t_map *map)
{
	char	**map_copy;
	int		test_collectibles;
	int		i;

	map_copy = malloc(sizeof(char *) * (map->height + 1));
	if (!map_copy)
	{
		printf("Floodtest: map grid copy allocation error");
		return(0);
	}
	i = 0;
	while (i < map->height)
	{
		map_copy[i] = ft_strdup(map->grid[i]);
		if (!map_copy[i])
		{
			free_map(map_copy, i);
			printf("Floodtest: string allocation error (ft_strdup)");
			return (0);
		}
		i++;
	}
	map_copy[i] = NULL;

	test_collectibles = 0;
	
	floodfill(map_copy, map->height, map->width, map->player_y, map->player_x, &test_collectibles);

	if ((map_copy[map->exit_y][map->exit_x] == 'V') && (test_collectibles == map->collectibles))
	{
		free_map(map_copy, map->height);
		return(1);
	}
	free_map(map_copy, map->height);
	printf("Invalid access path\n");
	return(0);
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}
