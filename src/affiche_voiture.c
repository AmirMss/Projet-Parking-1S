#include "../inc/parking.h"
#include <fcntl.h>

static t_car *get_car(char *path_to_files)
{
    t_car	*car;
    int			fd;
    char		buff;
    int			i;
    int			j;


    fd = open(path_to_files, O_RDONLY);
    if (fd < 0 || read(fd, &buff, 0) < 0)
    {
        printf("Le fichier %s n'est pas valide !\n", path_to_files);
        return (NULL);
    }
    i = 0;
    j = 0;
    car = (t_car *)malloc(sizeof(t_car));

    while (read(fd, &buff, 1) > 0)
    {
        car->horizontal[i][j] = buff;
        j++;
    }
    while (read(fd, &buff, 1) > 0)
    {
        if (buff == '\0')
        {
            car->vertical[i][0] = '\0';
            break;
        }
        if (buff == '\n')
        {
            car->vertical[i][j] = '\0';
            j = 0;
            i++;
        }
        car->vertical[i][j] = buff;
        j++;
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
