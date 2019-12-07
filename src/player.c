#include "../inc/parking.h"
#include <time.h>

static void     print_car(t_list_player *player, int d)
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

t_list_player   *new_player(int x_start, int y_start, char **map)
{
    time_t          t;
    t_list_player *new;

    srand((unsigned)time(&t));
    if (x_start == -1)
        return (NULL);
    if ((new = (t_list_player *)ft_memalloc(sizeof(t_list_player) *1)) == NULL)
        return (NULL);
    
    new->pos_x = x_start;
    new->pos_y = y_start;
    new->dir_x = 0;
    new->dir_y = 0;
    new->car = rand() % 4;
    new->next = NULL;
    new->exit = 0;
    new->map = map[new->pos_x][new->pos_y];
    map[new->pos_x][new->pos_y] = 'v';
    print_car(new, 0);
    return (new);
}

int                next_dir(t_list_player *player, char **map)
{
    if (player->map == 's' || player->map == 'l') /*Start and down*/
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
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);

    /*else if (player->map == '2')
    {
        if (check_place(map, x, y, 'l') == 0 && player->exit == 0)
        {

        }
        else 
    }*/
}

int               refresh_player(t_list_player *player, char **map)
{
    if (next_dir(player, map) == EXIT_FAILURE)
    {
        map[player->pos_x][player->pos_y] = player->map;
        return (EXIT_FAILURE);
    }
    if (map[player->pos_x + player->dir_x][player->pos_y + player->dir_y] != 'v')
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
    return (EXIT_SUCCESS);
}

t_list_player     *move_all(t_list_player *player, char **map)
{
    t_list_player *tmp;
    t_list_player *prev;
    time_t          t;
    int i; 

    srand((unsigned)time(&t));
    prev = NULL;
    tmp = player;
    while (tmp != NULL)
    {
        print_car(tmp, 1);
        i = refresh_player(tmp, map);
        print_car(tmp, 0);

        prev = tmp;
        tmp = tmp->next;

    }
    if (prev != NULL && rand() % 3 == 0)
        prev->next = new_player(find_start(map, 0), find_start(map, 1), map);
    return (player);
}
