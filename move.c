/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:40:55 by pitran            #+#    #+#             */
/*   Updated: 2024/12/29 23:46:09 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int is_valid_move(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return(perror("Invalid coordinates"), 0);
	
	if (map->grid[y][x] == '1')
		return(perror("Why are you running into walls, Samuraï-dono? Take ahold of yourself, the quest is not over!"), 0);

	if (map->grid[x][y] == 'E')
		handle_exit(map, x, y);
	return (1);
}

void	handle_exit(t_map *map, int x, int y)
{
	
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return(perror("Invalid exit coordinates"), 0);
	
	if (map->grid[y][x] != 'E')
		return(perror("Player coordinates and exit coordinates do not match"), 0);
	
	if (map->collectibles == 0)
	{
		open_door(map, x, y);
		printf("Congratulations samuraï-dono! The shogun will be pleased.");
		mlx_destroy_window(data->mlx, data->win);
	}
	return;
}

void	player_move(t_data *data, int new_x, int new_y)
{
	if (is_valid_move(data->map, new_x, new_y))
	{
		if (data->map->grid[new_y][new_x] == 'C')
		{
			data->map->	collectibles--;
			data->map->grid[new_y][new_x] = '0';
		}
		
		draw_path(x, y, data);
		
		data->map->player_x = new_x;
		data->map->player_y = new_y;
		
		draw_player(new_x, new_y, data);
	}
}

mlx_key_hook(data->win, handle_keypress, data) // Implement

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 53)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    
    if (keycode == 13 || keycode == 126)
        player_move(data, data->map->player_x, data->map->player_y - 1);
    
    if (keycode == 1 || keycode == 125)
        player_move(data, data->map->player_x, data->map->player_y + 1);
        
    if (keycode == 0 || keycode == 123)
        player_move(data, data->map->player_x - 1, data->map->player_y);
        
    if (keycode == 2 || keycode == 124)
        player_move(data, data->map->player_x + 1, data->map->player_y);
        
    return (0);
}

void	open_door(t_data *data, int x, int y)
{
	if (x != map->exit_x || y != map->exit_y)
		return(perror("Invalid exit coordinates"));
	draw_path(data, x, y);
}