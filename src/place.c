#include "../inc/parking.h"

void                wake_up(t_list_player *player, char **map)
{
    if (map[player->pos_x][player->pos_y + 1] == '1')
    {
        player->dir_x = 0;
        player->dir_y = 1;
    }
    else if (map[player->pos_x][player->pos_y - 1] == '1')
    {
        player->dir_x = 0;
        player->dir_y = -1;
    }
    player->exit = 1;
}

int                 check_place(t_list_player *player, char **map, char ori)
{
    int i_incr;
    int i;

    i = 0; 
    if (ori == 'l')
        i_incr = -1;
    else
        i_incr = 1;
    i += i_incr;
    while (map[player->pos_x][player->pos_y + i] != ' ')
    {
        if (map[player->pos_x][player->pos_y + i] == 'v')
            return (EXIT_FAILURE);
        i += i_incr;
    }
    return (EXIT_SUCCESS);
}