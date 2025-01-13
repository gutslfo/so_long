/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:24:42 by pitran            #+#    #+#             */
/*   Updated: 2025/01/13 16:18:36 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	line_count(char	*filename)
{
	int	fd;
	int	line_count;
	int	empty_line;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return(perror("Error opening file (fd negative)"), 0);
	//printf("Opening file: %s\n", filename);
	//printf("FD: %d\n", fd);
	line_count = 0;
	empty_line = 0;
	line = get_next_line(fd);
	while(line)
	{
		if (ft_strlen(line) > 1 || line[0] != '\n')
			line_count++;
		else 
			empty_line = 1;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	if (empty_line)
		return(perror("Empty line in map:"), 0);
	return(line_count);
}

int	parse_map(char	*filename, t_map *map)
{
	int        fd;
	char	*line;
	int			i;
	int		len;

	map->height = line_count(filename);
	printf("Line count returned: %d\n", map->height);
	if (map->height < 3)
	{
		printf("Map must have a minimum of 3 lines");
		return(0);
	}
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);

	map->collectibles = 0;
	//printf("%d\n", map->collectibles);
	fd = open(filename, O_RDONLY);
	if(fd < 0)
	{
		free(map->grid);
		map->grid = NULL;
		return(0);
	}
	i = 0;
	line = get_next_line(fd);
	while(line && i < map->height)
	{
		map->grid[i] = line;
		//printf("Starting line read at i=%d\n", i);
		//printf("%s\n", map->grid[i]);
		if (i == 0)
		{
			map->width = ft_strlen(line) - 2;
			//printf("Map width: %d\n", map->width);
			//printf("Ft_strlen: %d\n", (int)ft_strlen(line));
			//printf(ngth: %d\n", (int)ft_strlen(line));
		}
		len = (int)ft_strlen(line) - 2;
		if (i + 1 == map->height)
			len += 1;
		if (len != map->width || map->width < 3)
		{
			free(map->grid);
			//printf("Number: %d\n", i);
			//printf("Map width 2: %d\n", map->width);
			//printf("Map heigt 2: %d\n", map->height);
			//printf("Length: %d\n", (int)ft_strlen(line));
			map->grid = NULL;
			return (0);
		}
		line = get_next_line(fd);
		//printf("Line read: %s\n", line);
		i++;
	}
	map->grid[i] = 0;
	close(fd);
	//printf("Final grid state:\n");
	return(1);
}    

