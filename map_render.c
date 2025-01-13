/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:22:42 by pitran            #+#    #+#             */
/*   Updated: 2025/01/13 19:21:57 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int map_render(t_data *data)
{
	int     i;
	int     j;
	int		init;
	
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return(1);
	
	data->win = mlx_new_window(data->mlx, data->map.width * 48, data->map.height * 48, "Potion Hunt");
	if (data->win == NULL)
		return (1);
	
	init = init_images(data);
	if (!init) 
		return (1);

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.grid[i][j] == '1')
				draw_wall(j, i, data);
			else if (data->map.grid[i][j] == '0')
				draw_path(j, i, data);
			else if (data->map.grid[i][j] == 'C')
				draw_collectible(j, i, data);
			else if (data->map.grid[i][j] == 'P')
				draw_player(j, i, data);
			else
				return (0);
			j++;
		}
		i++;
	}
	return (0);
	
}

void    draw_wall(int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->wall_image, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	draw_path(int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->path_image, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	draw_player(int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->player_image, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	draw_collectible(int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->collectible_image, x * IMG_WIDTH, y * IMG_HEIGHT);
}
int init_images(t_data *data)
{
	int width;
	int height;

	width = IMG_WIDTH;
	height = IMG_HEIGHT;
	
	data->wall_image = mlx_xpm_file_to_image(data->mlx, "assets/xpm/TX-Stone.xpm", &width, &height);
	if (!data->wall_image)
	{
		perror("Error: failed to load wall texture");
		return(free_images(data, 0));
	}
	data->path_image = mlx_xpm_file_to_image(data->mlx, "assets/xpm/TX-Grass.xpm", &width, &height);
	if (!data->path_image)
	{
		perror("Error: failed to load path texture");
		return(free_images(data, 1));
	}

	data->player_image = mlx_xpm_file_to_image(data->mlx, "assets/xpm/SAMURAI.xpm", &width, &height);
	if (!data->player_image)
	{
		perror("Error: failed to load wall image");
		return(free_images(data, 2));
	}
	
	data->exit_image = mlx_xpm_file_to_image(data->mlx, "assets/xpm/Door.xpm", &width, &height);
	if (!data->exit_image)
	{
		printf("Error: failed to load exit image");
		return (free_images(data, 3));
	}
	data->collectible_image = mlx_xpm_file_to_image(data->mlx, "assets/xpm/Collectible.xpm", &width, &height);//add image xpm to assets 
	if (!data->collectible_image)
	{
		perror("Error: failed to load collectible image");
		return(free_images(data, 4));
	}
	return (1);
}

int	free_images(t_data *data, int rank)
{
	if (rank > 4)
		mlx_destroy_image(data->mlx, data->collectible_image);
	if (rank > 3)
		mlx_destroy_image(data->mlx, data->exit_image);
	if (rank > 2)
		mlx_destroy_image(data->mlx, data->player_image);
	if (rank >= 1)
		mlx_destroy_image(data->mlx, data->path_image);
	if (rank > 0)
		mlx_destroy_image(data->mlx, data->wall_image);
	return (0);
}