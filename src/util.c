# include "../inc/parking.h"

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

t_list_player   *new_player(int x_start, int y_start, char **map)   //  Init new player;
{
    time_t          t;
    t_list_player *new;

    srand((unsigned)time(&t));
    if (x_start == -1)
        return (NULL);
    if ((new = (t_list_player *)ms_memalloc(sizeof(t_list_player) *1)) == NULL) // If malloc error, return (NULL);
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

int            print_clock(int x, int y, int cycle)
{
    wchar_t tab[] = {0x2601, 0x26C5, 0x26C8, 0x1F324, 0x1F325, 0x1F326, 0x1F327, 0x1F328, 0x1F329, 0x1F32A};
    time_t  t;
    int     i;

    srand((unsigned)time(&t));
    i = cycle  / 10;
    if (cycle == 1)
        printf("\033[%d;%dH%lc", x, y - 3, tab[rand() % 10]);
    if (i == 0)
        printf("\033[%d;%dH%lc %lc", x, y, 0x1F55B, 0x1F311);
    else if (i == 1)
        printf("\033[%d;%dH%lc", x, y, 0x1F567);
    else if (i == 2)
        printf("\033[%d;%dH%lc", x, y, 0x1F550);
    else if (i == 3)
        printf("\033[%d;%dH%lc %lc", x, y, 0x1F55C, 0x1F312);//
    else if (i == 4)
        printf("\033[%d;%dH%lc", x, y, 0x1F551);
    else if (i == 5)
        printf("\033[%d;%dH%lc", x, y, 0x1F55D);
    else if (i == 6)
        printf("\033[%d;%dH%lc %lc", x, y, 0x1F552, 0x1F313);//
    else if (i == 7)
        printf("\033[%d;%dH%lc", x, y, 0x1F55E);
    else if (i == 8)
        printf("\033[%d;%dH%lc", x, y, 0x1F553);
    else if (i == 9)
        printf("\033[%d;%dH%lc %lc", x, y, 0x1F55F, 0x1F314);//
    else if (i == 10)
        printf("\033[%d;%dH%lc", x, y, 0x1F554);
    else if (i == 11)
        printf("\033[%d;%dH%lc", x, y, 0x1F560);
    else if (i == 12)
        printf("\033[%d;%dH%lc %lc", x, y, 0x1F555, 0x1F315);//
    else if (i == 13)
        printf("\033[%d;%dH%lc", x, y, 0x1F561);
    else if (i == 14)
        printf("\033[%d;%dH%lc", x, y, 0x1F556);
    else if (i == 15)
        printf("\033[%d;%dH%lc %lc", x, y, 0x1F562, 0x1F316);//
    else if (i == 16)
        printf("\033[%d;%dH%lc", x, y, 0x1F557);
    else if (i == 17)
        printf("\033[%d;%dH%lc", x, y, 0x1F563);
    else if (i == 18)
        printf("\033[%d;%dH%lc %lc", x, y, 0x1F558, 0x1F317);//
    else if (i == 19)
        printf("\033[%d;%dH%lc", x, y, 0x1F564);
    else if (i == 20)
        printf("\033[%d;%dH%lc", x, y, 0x1F559);
    else if (i == 21)
        printf("\033[%d;%dH%lc %lc", x, y, 0x1F565, 0x1F318);//
    else if (i == 22)
        printf("\033[%d;%dH%lc", x, y, 0x1F55A);
    else if (i == 23)
        printf("\033[%d;%dH%lc", x, y, 0x1F566);
    else if (i == 24)
        return (0);
    printf("\033[0m");
    fflush(stdout);
    return (cycle);
}