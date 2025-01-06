/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:51:31 by pitran            #+#    #+#             */
/*   Updated: 2024/12/30 00:23:00 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong."

int init_map(t_data *data)
{
    data->map = malloc(sizeof(map));
    if(!map)
        return(perror("Map structure allocation error"), 0);
    
    data->map->grid = NULL;
    data->map->width = 0;
    data->map->height = 0;
    data->map->player_x = 0;
    data->map->player_y = 0;
    data->map->exit_x = 0;
    data->map->exit_y = 0;
    data->map->collectibles = 0;

    return(1);
}

int init_data(t_data *data)
{
    data = malloc(sizeof(data));
    if (!data)
        return(perror("Data structure allocation error"), 0);
    
    data->mlx = NULL;
    data->win = NULL;
    data->img = NULL;
    data->adress = NULL;
    data->wall_image = "\0";
    data->path_image = "\0";
    data->random_plant_image = "\0";
    data->player_image = "\0";
    data->collectible_image = "\0";
    data->bits_per_pixel = 0;
    data->line_length = 0;
    data->endian = 0;

    return (1);
}

int init_all(t_data *data)
{
    
}