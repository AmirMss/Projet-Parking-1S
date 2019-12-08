#include "../inc/parking.h"

static int     is_paterne(char c)
{
    if (ms_isalnum(c) || c == ' ' || c == '\\' || c == '/' || c == '_' || c == '(' || c == ')' || c == '<' || c == '>')
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
    map = (char **)ms_memalloc(sizeof(char *) * size_i + 1);
    i = 0;
	while (get_next_line(fd, &buff) == 1)
	{
        map[i] = ms_memalloc(sizeof(char ) * size_j + 1);
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

int  find_char(char **map, int d, char c)
{
    int i;
    int j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == c && d == 0)
                return (i);
            if (map[i][j] == c && d == 1)
                return (j);
            j++;
        }
        i++;
    }
    return (-1);
}

void affiche_map(char **map)
{
    int     i, j;
    char    c;

    i = 0;
    printf("\033[%d;%dH", 0, 0);

    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
		{
            c = map[i][j];
            j++;
            printf("\033[10;36;2m");
            if (c == 'U')
                printf("╔"); // On l'affiche
            else if (c == 'B')
                printf("═");
            else if (c == 'A')
                printf("║");
            else if (c == 'x')
                printf("▀");
            else if (c == 'K')
                printf("╚");
            else if (c == 'M')
                printf("╗");
            else if (c == 'L')
                printf("╝");
            else if (c == '1' || c == 'd' || c == 'l' || c == 'h' || c == 'e'\
                            || c == '2' || c == 'p' || c == 'b' || c == 'n' ||\
                            c == 'k' || c == 'c' || c == 'v' || c == 'a' || c == 'u' ||\
                            c == 'Z')
                printf(" ");
            else if (c == '6')
                printf("╬");
            else if (c == 'R')
                printf("╩");
            else if (c == '9')
                printf("╦");
            else if (c == '0')
                printf(" ");
            else if (c == 's')
                printf("▌");
            else if (c == '3')
                printf("╣");
            else if (c == 'G')
                printf("╠");
            else if (c == 'f')
                printf("%lc", 0x1F6A7);
            else if (c == 'y')
                printf("%lc", 0x1F6A6);
            else if (c == 'z')
                printf("\033[0m%lc", 0x1F3ED);
            else 
                printf("%c", c);
            printf("\033[0m");
		}
        i++;
	}
    fflush(stdout);
}
