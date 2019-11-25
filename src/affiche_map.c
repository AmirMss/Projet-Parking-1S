#include "../inc/parking.h"
#include <fcntl.h>

char	**parse_map(char *path_to_file)
{
	int		fd;
	int		size_i;
	int		size_j;
	int		i;
	char	*buff;
	char	**map;
    if ((fd = open_files(path_to_file)) == -1)
        return (NULL);
    get_next_line(fd, &buff);       //  info size map;
	size_i = ft_atoi(buff);         //  01.map :
    free(buff);                     //  12
    get_next_line(fd, &buff);       //  10
	size_j = ft_atoi(buff);         //  *************
    free(buff);                     //  ...
    map = (char **)ft_memalloc(sizeof(char *) * size_i + 1);
    i = 0;
	while (get_next_line(fd, &buff) == 1)
	{
        map[i] = (char *)ft_memalloc(sizeof(char ) * size_j + 1);
        ft_strcpy(map[i], buff);
        free(buff);
		i++;
	}
    return (map);
}

void affiche_map(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
		{
			if (map[i][j] == 'U')
			{
				printf("\033[10;36;2m");
				printf("╔"); // On l'affimap[i][j]he
				printf("\033[0m");
			}
			else if (map[i][j] == 'B')
			{
				printf("\033[10;36;2m");
				printf("═");
				printf("\033[0m");
			}
			else if (map[i][j] == 'A')
			{
				printf("\033[10;36;2m");
				printf("║");
				printf("\033[0m");
			}
			else if (map[i][j] == 'x')
			{
				printf("\033[10;36;2m");
				printf("▀");
				printf("\033[0m");
			}
			else if (map[i][j] == 'K')
			{
				printf("\033[10;36;2m");
				printf("╚");
				printf("\033[0m");
			}
			else if (map[i][j] == 'M')
			{
				printf("\033[10;36;2m");
				printf("╗");
				printf("\033[0m");
			}
			else if (map[i][j] == 'L')
			{
				printf("\033[10;36;2m");
				printf("╝");
				printf("\033[0m");
			}
			else if (map[i][j] == '6')
			{
				printf("\033[10;36;2m");
				printf("╬");
				printf("\033[0m");
			}
			else if (map[i][j] == 'R')
			{
				printf("\033[10;36;2m");
				printf("╩");
				printf("\033[0m");
			}
			else if (map[i][j] == '9')
			{
				printf("\033[10;36;2m");
				printf("╦");
				printf("\033[0m");
			}
			else if (map[i][j] == '0')
			{
				printf("\033[10;36;2m");
				printf(" ");
				printf("\033[0m");
			}
			else if (map[i][j] == 's')
			{
				printf("\033[10;36;2m");
				printf("▌");
				printf("\033[0m");
			}
			else if (map[i][j] == '3')
			{
				printf("\033[10;36;2m");
				printf("╣");
				printf("\033[0m");
			}
			else if (map[i][j] == 'G')
			{
				printf("\033[10;36;2m");
				printf("╠");
				printf("\033[0m");
			}
            else
            {
				printf("\033[10;36;2m");
				printf("%c", map[i][j]);
				printf("\033[0m");
            }
            j++;
		}
        ft_putchar('\n');
        i++;
	}
}
