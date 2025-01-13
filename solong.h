#ifndef SOLONG_H
#define SOLONG_H

#include "minilibx-linux/mlx.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>


#define IMG_WIDTH  48
#define IMG_HEIGHT 48

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

typedef struct s_data{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    char    *wall_image;
    char    *path_image;
    char    *random_plant_image;
    char    *player_image;
    char    *exit_image;
    char    *collectible_image;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    t_map   map;
    
}   t_data;

// get_next_line utils

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif 

char        *ft_strchr(const char *s, int c);
void        *ft_memset(void *s, int c, size_t n);
size_t      ft_strlen(char *str);
char        *ft_strdup(char *s);
char        *ft_substr(char *str, unsigned int start, size_t len);
char        *ft_strjoin(char *base, char *append);
//get_next_line
char        *get_next_line(int fd);
char        *subline(int fd, char *line, char *buffer, char **line_left);
//parsing
int         line_count(char	*filename);
int			parse_map(char *filename, t_map *map);
//init
int			init_map(t_data *data, char *filename);
//checkmap
int         check_structure(t_map *map);
int         validate_elements(t_map *map);
void        floodfill(char **map_copy, int height, int width, int y, int x, int *collectibles);
int         floodtest(t_map *map);
void        free_map(char **map, int height);
//map render
int         init_images(t_data *data);
void        draw_wall(int x, int y, t_data *data);
void        draw_path(int x, int y, t_data *data);
void        draw_player(int x, int y, t_data *data);
void        draw_collectible(int x, int y, t_data *data);
int         free_images(t_data *data, int rank);
int         init_data(t_data *data);


#endif