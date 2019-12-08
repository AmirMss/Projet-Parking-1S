#include "../inc/parking.h"

void     print_car(t_list_player *player, int d)
{   
    wchar_t car; 

    car = ' ';
    if (d == 1)
        car = ' ';
    else if (player->car == 0)
    {
        if (player->dir_x != 0)
            car = 0x1F694;
        else
            car = 0x1F693;
    }
    else if (player->car == 1)
    {
        if (player->dir_x != 0)
            car = 0x1F696;
        else
            car = 0x1F695;
    }
    else if (player->car == 2)
    {
        if (player->dir_x != 0)
            car = 0x1F68D;
        else
            car = 0x1F68C;
    }
    else if (player->car == 3)
    {
        if (player->dir_x != 0)
            car = 0x1F694;
        else
            car = 0x1F693;
    }
    printf("\033[%d;%dH%lc\n",player->pos_x + 1, player->pos_y, car);
    printf("\033[%d;%dH", 1000, 0);
    fflush(stdout);
}

int                next_dir(t_list_player *player, char **map)
{
    time_t  t;
    int     r;
    srand((unsigned)time(NULL));
    r = rand() % 6;

    if (player->map == 'a' || player->map == 'l') /*Start and down*/
    {
        player->dir_x = 1;
        player->dir_y = 0;
    }
    else if (player->map == 'd') /* left */
    {
        player->dir_x = 0;
        player->dir_y = 1;
    }
    else if (player->map == 'h') /* Up */
    {
        player->dir_x = -1;
        player->dir_y = 0;
    }
    else if (player->map == ' ') /* */
    {
        player->dir_x = 0;
        player->dir_y = 0;
    }
    else if (player->map == 'e')
    {
        player->dir_x = 0;
        player->dir_y = 0;
        player->dead = 1;
        return (EXIT_FAILURE);
    }
    else if (player->map == '2')
    {
        if (player->exit == 1)
        {
            player->dir_x = 1;
            player->dir_y = 0;
        }
        else if (check_place(player, map, 'l') == EXIT_SUCCESS && r == 0)
        {
            player->dir_x = 0;
            player->dir_y = -1;
        }
    }
    else if (player->map == 'p')
    {
        if (player->exit == 1)
        {
            player->dir_x = -1;
            player->dir_y = 0;
        }
        else if (check_place(player, map, 'r') == EXIT_SUCCESS && r == 1)
        {
            player->dir_x = 0;
            player->dir_y = 1;
        }
    }
    else if (player->map == 'n')
    {
        player->dir_x = 0;
        player->dir_y = 0;
        if (player->wait == -42)
            player->wait = rand() % 20;
        if (player->wait <= 0)
            wake_up(player, map); 
        player->wait = player->wait - 1;
    }
    if (player->map == 'k' && player->exit == 1)
    {
        if (map[player->pos_x][player->pos_y + 2] == 'v' \
            || map[player->pos_x - 1][player->pos_y + 2] == 'v' \
            || map[player->pos_x - 2][player->pos_y + 2] == 'v')
        {
            player->dir_x = 0;
            player->dir_y = 0;
        }
        else
        {
            player->dir_x = 0;
            player->dir_y = 1;
        }
    }
    else if (player->map == 'c' && player->exit == 1)
    {
        if (map[player->pos_x + 1][player->pos_y - 2] == 'v' \
            || map[player->pos_x + 2][player->pos_y - 2] == 'v' \
            || map[player->pos_x][player->pos_y - 2] == 'v')
        {
            player->dir_x = 0;
            player->dir_y = 0;
        }
        else
        {
            player->dir_x = 0;
            player->dir_y = -1;
        }
    }
    return (EXIT_SUCCESS);
}

int               refresh_player(t_list_player *player, char **map)
{
    next_dir(player, map);
    if (map[player->pos_x + player->dir_x][player->pos_y + player->dir_y] != 'v' \
        && map[player->pos_x + player->dir_x * 2][player->pos_y + player->dir_y * 2] != 'v')
    {
        map[player->pos_x][player->pos_y] = player->map;
        player->pos_x += player->dir_x;
        player->pos_y += player->dir_y;
        player->map = map[player->pos_x][player->pos_y];
        if (player->map == 'x')
            map[player->pos_x][player->pos_y] = 'p';
        else 
            map[player->pos_x][player->pos_y] = 'v';
    }
    print_car(player, 0);
    return (EXIT_SUCCESS);
}

t_list_player     *move_all(t_list_player *player, char **map)
{
    t_list_player *tmp;
    t_list_player *prev;
    int i; 

    prev = NULL;
    tmp = player;
    while (tmp != NULL)
    {
        print_car(tmp, 1);
        refresh_player(tmp, map);
        prev = tmp;
        tmp = tmp->next;
    }
    if (prev != NULL && rand() % 3 == 0)
        prev->next = new_player(find_start(map, 0), find_start(map, 1), map);
    return (player);
}

t_list_player    *check_dead(t_list_player *player, char **map)
{
    t_list_player *tmp;
    t_list_player *prev;

    if (player == NULL)
        return (player);
    prev = player;
    if (player->dead == 1)
    {
        player = prev->next;
        map[prev->pos_x][prev->pos_y] = prev->map;
        print_car(prev, 1);
        free(prev);
        return(player);
    }
    tmp = prev->next;
    while (tmp != NULL)
    {
        if (tmp->dead == 1)
        {
            prev->next = tmp->next;
            map[tmp->pos_x][tmp->pos_y] = tmp->map;
            print_car(tmp, 1);            
            free(tmp);
            return(player);
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return (player);
}