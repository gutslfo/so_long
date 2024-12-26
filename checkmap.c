/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:24:42 by pitran            #+#    #+#             */
/*   Updated: 2024/12/23 16:40:35 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




int	line_count(char	*filename)
{
	int	fd;
	int	line_count;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	line_count = 0;
	empty_line = 0;
	while((line = get_next_line(fd)))
	{
		if (ft_strlen(line) > 1 || line[0] != '\n')
			line_count++;
		else 
			empty_line = 1;
		free(line);
	}
	close (fd);
	if (empty_line)
		return(0);
	return(line_count);
}

t_map*	parse_map(char	*filename)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return(NULL);
	
	map->height = line_count(filename);
	if (map->height < 3)
	{
		free(map);
		return(NULL);
	}
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
	{
		free_map(map);
		return(NULL);
	}
	map->collectibles = 0;

	fd = open(filename, O_RDONLY);
	if(fd < 0)
	{
		free_map(map);
		return(NULL);
	}
	
	i = 0;
	while((line = get_next_line(fd)))
	{
		map->grid[i] = line;
		if (i == 0)
			map->width = ft_strlen(line);
		if (ft_strlen(line) != map->width || map->width < 3)
		{
			free_map(map);
			return(NULL);
		}
		i++;
	}
	
	map->grid[i] = NULL;
	close(fd);
	return(map);
}

int	check_structure(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->grid[i]) != map->width)
			return(0);
		
		if (i == 0 || i == map->height - 1)
		{
			j = 0;
			while (j < map->width)
			{
				if (map->grid[i][j] != '1')
					return(0);
				j++;
			}
		}
		else if(map->grid[i][0]!= '1' || map->grid[i][map->width - 1] != '1')
			return(0);
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
	
	map->collectibles = 0;
	player_count = 0;
	exit_count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!ft_strchr("01CEP", map->grid[i][j]))
				return(0);
			if (map->grid[i][j] == 'P')
			{
				player_count++;
				map->player_x = j;
				map->player_y = i;
			}
			else if (map->grid[i][j] == 'E')
			{
				exit_count++;
				map->exit_x = j;
				map->exit_y = i;
			}
			else if (map->grid[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1 || map->collectibles <= 0)
		return 0;
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
		return(0);

	i = 0;
	while (i < map->height)
	{
		map_copy[i] = ft_strdup(map->grid[i]);
		if (!map_copy[i])
		{
			free_map(map_copy, i);
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