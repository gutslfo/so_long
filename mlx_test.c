#include "solong.h"

void    my_mlx_pixel_put(t_data *data, int  x, int  y, int  color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main(void)
{
    t_data  data;
    int     y;
    int     x;
    int     color;

    data.mlx = mlx_init();
    if (data.mlx == NULL)
        return (1);

    data.win = mlx_new_window(data.mlx, 1080, 1920, "Image Creation Test");
    if (data.win == NULL)
        return (1);

    data.img = mlx_new_image(data.mlx, 1080, 1920);
    if (data.img == NULL)
        return (1);
    
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    x = 20;
    y = 356;
    color = 0x00FF00FF;

    while (x < 1020)
    {
        y = 356;
        while (y < 1356)
        {
            my_mlx_pixel_put(&data, x, y, color);
            y++;
        }
        x++;
        color--;
    }

    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_loop(data.mlx);
    return (0);
}