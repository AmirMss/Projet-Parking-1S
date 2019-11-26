#include "../inc/parking.h"
#include <time.h>

int     get_path(t_list_player *p, char **map)
{
    time_t t;
    int    r;

    srand((unsigned)time(&t));
    r = rand() % 100;
    //printf("r = %d\n", r);
    if (map[p->pos_x + 1][p->pos_y] == '1' && r <= 24 && p->dir_x != -1)
        return (1);
    else if (map[p->pos_x - 1][p->pos_y] == '1' && r <= 49 && p->dir_x != 1)
        return (2);
    else if (map[p->pos_x][p->pos_y + 1] == '1' && r <= 74 && p->dir_y != -1)
        return (3);
    else if (map[p->pos_x][p->pos_y - 1] == '1' && r <= 99 && p->dir_y != 1)
        return (4);
    return (0);
}

void    refresh_player(t_list_player *player, char **map, t_car **car)
{
    int path;

    path = get_path(player, map);
    affiche_voiture(car[player->car], player->pos_x, player->pos_y, 1);
    if (path == 1)
    {
        player->pos_x += 1;
        player->dir_x = 1;
        player->dir_y = 0;
    }
    if (path == 2)
    {
        player->pos_x -=1;
        player->dir_x = -1;
        player->dir_y = 0;
    }
    if (path == 3)
    {
        player->pos_y += 1;
        player->dir_y = 1;
        player->dir_x = 0;
    }
    if (path == 4)
    {
        player->pos_y -= 1;
        player->dir_y = -1;
        player->dir_x = 0;
    }
    affiche_voiture(car[player->car], player->pos_x, player->pos_y, 0);
}

t_list_player     *voiture(t_list_player *player, char **map, t_car **car)
{
    time_t t;
    t_list_player *new;
    t_list_player *tmp;

    srand((unsigned)time(&t));
    if (player == NULL)
    {
        new = ft_memalloc(sizeof(t_list_player));
        new->pos_x = find_start(map, 0);
        new->pos_y = find_start(map, 1);
        new->dir_x = 1;
        new->dir_y = 0;
        new->car = 0;
        player = new;
    }
    tmp = player;
    while (tmp != NULL)
    {
        refresh_player(tmp, map, car);
        tmp = tmp->next;
    }
    return (player);
}
