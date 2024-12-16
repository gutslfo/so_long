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
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

#endif