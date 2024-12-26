/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:22:11 by pitran            #+#    #+#             */
/*   Updated: 2024/12/24 12:22:21 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int count_path(char *grid)
{
  int i;
  int path_len;

  i = 0;
  path_len =
  while (grid[i])
  {
    if (grid[i] == '0')
      path_len++;
    i++;
  }
  return(path_len);
}

int path_start(char *grid)
{
  int i;

  i = 0;
  while (grid[i])
  {
    if (grid[i] == '0')
      return (i);
    i++;
  }
  return(-1);
}

int algo_random(char *grid)
{
  static int  count;
  int         index;
  int         path_x;
  int         path_len;

  path_x = path_start(grid);
  path_len = count_path(grid);

  if(path_len <= 6)
    return 0;
  
  if (count % 3)
    index = (path_x + 2)
  if (count % 3 = 1)
    index = ((path_x + 10) % 3);
  else
    index = ((path_x * 2) -4);
  count++;
  return (index);
}

void  random_plant(t_map *map)
{
  int j;
  int path_x;
  int path_len;

  j = 0;
  while (grid[i])
  {
    if (count_path(map->grid[i]) >= 6)
    {
      j = algo_random(map->grid[i])
      while (map->grid[i][j] != 0)
        j++
      place_xpm_image(mlx, win, "path/to/plants.xpm", i, j, tile_size);
    }
    i++;
  }
}