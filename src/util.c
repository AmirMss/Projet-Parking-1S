# include "../inc/parking.h"
# include <fcntl.h>

int     open_files(char *file)
{
    int fd;
    char buff;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (-1);
    if (read(fd, &buff, 0) == -1)
        return (-1);
    return (fd);
}

int     get_value(int fd)
{
    char *buff;
    int nb;

    get_next_line(fd, &buff);
    nb = ms_atoi(buff);
    free(buff);
    return (nb);
}

t_list_player   *new_player(int x_start, int y_start, char **map)
{
    time_t          t;
    t_list_player *new;

    srand((unsigned)time(&t));
    if (x_start == -1)
        return (NULL);
    if ((new = (t_list_player *)ms_memalloc(sizeof(t_list_player) *1)) == NULL)
        return (NULL); 
    new->pos_x = x_start;
    new->pos_y = y_start;
    new->dir_x = 1;
    new->dir_y = 0;
    new->car = rand() % 4;
    new->exit = 0;
    new->wait = -42;
    new->dead = 0;
    new->next = NULL;
    new->map = map[new->pos_x][new->pos_y];
    map[new->pos_x][new->pos_y] = 'v';
    print_car(new, 0);
    return (new);
}