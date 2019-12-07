#include "../inc/parking.h"
#include <fcntl.h>

static int     is_paterne(char c)
{
    if (ft_isalnum(c) || c == ' ' || c == '\\' || c == '/' || c == '_' || c == '(' || c == ')' || c == '<' || c == '>')
        return (0);
    return (-1);
}

char	**parse_map(char *path_to_file)
{
	int		fd;
	int		size_i;
	int		size_j;
	int		i, j;
	char	*buff;
	char	**map;

    if ((fd = open_files(path_to_file)) == -1)
        return (NULL);
   
    size_i = get_value(fd);
    size_j = get_value(fd);
    map = (char **)ft_memalloc(sizeof(char *) * size_i + 1);
    i = 0;
	while (get_next_line(fd, &buff) == 1)
	{
        map[i] = ft_memalloc(sizeof(char ) * size_j + 1);
        j = 0;
        while (is_paterne(buff[j]) == 0)
        {
            map[i][j] = buff[j];
            j++;
        }
        map[i][j] = '\n';
        free(buff);
		i++;
	}
    close(fd);
    return (map);
}

int  find_start(char **map, int d)
{
    int i;
    int j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 's' && d == 0)
                return (i);
            if (map[i][j] == 's' && d == 1)
                return (j);
            j++;
        }
        i++;
    }
    return (-1);
}

void affiche_map(char **map)
{
    int i;
    int j;
    char c;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
		{
            c = map[i][j];
            j++;
            if (c == 'U')
             {
                 printf("\033[10;36;2m");
                 printf("╔"); // On l'affiche
                 printf("\033[0m");
             }
             else if (c == 'B')
             {
                 printf("\033[10;36;2m");
                 printf("═");
                 printf("\033[0m");
             }
             else if (c == 'A')
             {
                 printf("\033[10;36;2m");
                 printf("║");
                 printf("\033[0m");
             }
             else if (c == 'x')
             {
                 printf("\033[10;36;2m");
                 printf("▀");
                 printf("\033[0m");
             }
             else if (c == 'K')
             {
                 printf("\033[10;36;2m");
                 printf("╚");
                 printf("\033[0m");
             }
             else if (c == 'M')
             {
                 printf("\033[10;36;2m");
                 printf("╗");
                 printf("\033[0m");
             }
             else if (c == 'L')
             {
                 printf("\033[10;36;2m");
                 printf("╝");
                 printf("\033[0m");
             }
            else if (c == '1' || c == 'd' || c == 'l' || c == 'h' || c == 'e' || c == '2')
             {
                 printf("\033[10;36;2m");
                 printf(" ");
                 printf("\033[0m");
             }
             else if (c == '6')
             {
                 printf("\033[10;36;2m");
                 printf("╬");
                 printf("\033[0m");
             }
             else if (c == 'R')
             {
                 printf("\033[10;36;2m");
                 printf("╩");
                 printf("\033[0m");
             }
             else if (c == '9')
             {
                 printf("\033[10;36;2m");
                 printf("╦");
                 printf("\033[0m");
             }
             else if (c == '0')
             {
                 printf("\033[10;36;2m");
                 printf(" ");
                 printf("\033[0m");
             }
             else if (c == 's')
             {
                 printf("\033[10;36;2m");
                 printf("▌");
                 printf("\033[0m");
             }
             else if (c == '3')
             {
                 printf("\033[10;36;2m");
                 printf("╣");
                 printf("\033[0m");
             }
             else if (c == 'G')
             {
                 printf("\033[10;36;2m");
                 printf("╠");
                 printf("\033[0m");
             }
            else 
                printf("%c", c);
		}
        i++;
	}
}
