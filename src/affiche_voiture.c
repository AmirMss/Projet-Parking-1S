#include "../inc/parking.h"
#include <fcntl.h>

static int  get_value(int fd)
{
    char *buff;
    int nb;

    get_next_line(fd, &buff);
    nb = ft_atoi(buff);
    free(buff);
    return (nb);
}

static t_car *get_car(char *path_to_files)
{
    t_car       *car;
    int			fd;
    int         size_i, size_j;
    char		*buff;
    int			i;
    int         horizontal;

    car = (t_car *)malloc(sizeof(t_car));
    if ((fd = open_files(path_to_files)) == -1 )
        return (NULL);
    size_i = get_value(fd);
    size_j = get_value(fd);
    car->horizontal = (char **)ft_memalloc(sizeof(char *) * size_i + 1);
    i = 0;
    horizontal = 1;
    while (get_next_line(fd, &buff ) == 1)
    {
        if (buff[0] == '\0')
        {
            size_i = get_value(fd);
            size_j = get_value(fd);
            car->vertical = (char **)ft_memalloc(sizeof(char *) * size_i + 1);
            horizontal = 0;
        }
        if (horizontal == 1)
            car->horizontal[i] = (char *)ft_memalloc(sizeof(char) * size_j + 1);
        else 
            car->vertical[i] = (char *)ft_memalloc(sizeof(char) * size_j + 1);
        if (horizontal == 1)
        {
            ft_strcpy(car->horizontal[i], buff);
            car->horizontal[i][size_j] = '\0';
        }
        else if (horizontal == 0)
        {
            ft_strcpy(car->vertical[i], buff);
            car->vertical[i][size_j] = '\0';
        }
        i++;
        free(buff);
    }
    return (car);
}

t_car **parse_car(char **path_to_files, int argc)
{
    t_car	**all_car;
    int			i;
    int			j;

    i = 2;
    all_car = (t_car **)malloc(sizeof(t_car*) * (argc - i) + 1);
    j = 0;
    while (i < argc)
    {
        all_car[j] = get_car(path_to_files[i]);
        j++;
        i++;
    }
    all_car[j] = NULL;
    return (all_car);
}

void affiche_voiture(t_car *car, int x, int y, int d)
{
    int i;
    int j;
    char c;

    j = 0;
    c = '\0';
    i = 0;
    while (car->horizontal[i] != NULL)
    {
        j = 0;
        while (car->horizontal[i][j] != '\0' || car->horizontal[i][j] != '\n')
        {
            printf("\033[%d;%dH", x, y);
            x++;
            c = car->horizontal[i][j];
            while (c != '\0')
            {
                c = car->horizontal[i][j];
                if (d == 1)
                {
                    printf("\033[10;36;2m");
                    printf(" "); // On l'affiche
                    printf("\033[0m");
                }
                else if (c == 'A')
                {
                    printf("\033[10;36;2m");
                    printf("┌"); // On l'affiche
                    printf("\033[0m");
                }
                else if (c == 'B')
                {
                    printf("\033[10;36;2m");
                    printf("─");
                    printf("\033[0m");
                }
                else if (c == 'C')
                {
                    printf("\033[10;36;2m");
                    printf("┬");
                    printf("\033[0m");
                }
                else if (c == 'P')
                {
                    printf("\033[10;36;2m");
                    printf("┐");
                    printf("\033[0m");
                }
                else if (c == 'M')
                {
                    printf("\033[10;36;2m");
                    printf("└");
                    printf("\033[0m");
                }
                else if (c == 'G')
                {
                    printf("\033[10;36;2m");
                    printf("┴");
                    printf("\033[0m");
                }
                else if (c == 'N')
                {
                    printf("\033[10;36;2m");
                    printf("┘");
                    printf("\033[0m");
                }
                else if (c == 'E')
                {
                    printf("\033[10;36;2m");
                    printf("│");
                    printf("\033[0m");
                }
                else if (c == 'D')
                {
                    printf("\033[10;36;2m");
                    printf("├");
                    printf("\033[0m");
                }
                else if (c == 'H')
                {
                    printf("\033[10;36;2m");
                    printf("┤");
                    printf("\033[0m");
                }

                else
                    printf("%c", c);
                j++;
            }
        }
        i++;
    }
}
