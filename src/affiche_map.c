#include "../inc/parking.h"
#include <fcntl.h>

static int get_size(int fd)
{
	int		size;
	char	buff;

	size = 0;
	while (read(fd, &buff, 1) > 0)
	{
        if (buff > '9' || buff < '0')
            break ;
		size = size * 10 + buff - '0';
    }
	return (size);
}

char	**parse_map(char *path_to_file)
{
	int		fd;
	int		size_i;
	int		i;
    int     ret;
    int		size_j;
	char	buff[1024];
	char	**map;

	fd = open(path_to_file, O_RDONLY);
	if (fd < 0 || read(fd, &buff, 0) < 0)
	{
		printf("Le fichier %s n'est pas valide !\n", path_to_file);
		return (NULL);
	}
	size_i = get_size(fd);
	size_j = get_size(fd);
	if ((map = (char **)malloc(sizeof(char *) * size_i + 1)) == NULL)
	{
		printf("Error malloc \n");
		return (NULL);
	}
	i = 0;
	while (i < size_i + 1)
	{
		if ((map[i] = (char *)malloc(sizeof(char) * size_j + 1)) == NULL)
		{
			printf("Error malloc\n");
			return (NULL);
		}
        ret = read(fd, &buff, size_j);
        buff[ret] = '\0';
        ft_strcpy(map[i], buff);
		i++;
	}
    map[i] = NULL;
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
                printf("%c",map[i][j]);
            j++;
		}
        i++;
	}
}
