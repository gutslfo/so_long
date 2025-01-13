/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:40:18 by pitran            #+#    #+#             */
/*   Updated: 2025/01/13 19:29:30 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*int main(void)
{
    t_data data;
    int i = 0;

    if (!init_map(&data, "map.ber"))
        return (0);
    while (i < data.map.height)
    {
        printf("Verification: %s\n", data.map.grid[i]);
        i++;
    }
    return (0);
}
*/
/* PARSING CHECK 
int main(void)
{
    t_data data;
    
    if (!init_map(&data, "map.ber"))
    {
        return (0);
        printf("Error parsing");
    }

    if (check_structure(&data.map))
    {
        printf("Structure check succesful\n");
    }
    if (validate_elements(&data.map))
    {
        printf("Element validation succesful\n");
        printf("Player coordinates: x= %d, y = %d\n", data.map.player_x, data.map.player_y);
        printf("Exit coordinates: x = %d, y = %d\n", data.map.exit_x, data.map.exit_y);
        printf("Number of collectibles counted: %d\n", data.map.collectibles);
    }
    if (floodtest(&data.map))
    {
        printf("Floodfill tests successful\n");
        return (0);
    }
    printf("Floodfill test failed\n");
    return (0); 
}
*/

//GRAPHIC DISPLAY

int main(void)
{
    t_data  data;

    if(init_data(&data))
    {
        printf("Data initialisation succesful");
        return (0);
    }
    printf("Data initialisation failed");

    if(!init_images(&data))
    {
        printf("Image initialisation failure");
    }
    printf("Image initialisation succes");
    return (0);
}

// GNL: OK 
// LINE_COUNT: OK
// PARSE_MAP: OK
// INIT_MAP: OK
// CHECK STRUCTURE: OK
// VALIDATE ELEMENTS: OK
// FLOODFILL: OK
//FLOODTEST : OK
//FREE MAP : OK