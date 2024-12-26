#ifndef SOLONG_H
#define SOLONG_H

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct s_data{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    char    *wall_image;
    char    *path_image;
    char    *random_plant_image;
    char    *player_image;
    char    *collectible_image;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    t_map   map
    
}   t_data;

typedef struct s_map{
	char    **grid;
	int     width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectibles;
}	t_map;

IMG_WIDTH 48;
IMG_HEIGHT 48;



#endif