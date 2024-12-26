/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:40:55 by pitran            #+#    #+#             */
/*   Updated: 2024/12/24 12:33:54 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int is_valid_move(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (0);
	
	if (map->grid[y][x] == '1')
		return(0);
	
	if (map->grid[y][x] =='E')
		handle_exit(map, x, y);
	return (1);
}

void	handle_exit(t_map *map, int x, int y)
{
	
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (0);
	if (map->grid[y][x] != 'E')
		return(0);
	if (map->collectibles == 0)
	{
		open_door(map, x, y);
		//printf succes message
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
