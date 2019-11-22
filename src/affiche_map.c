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
	int		size_j;
	char	buff[254];
	char	**map;

	fd = open(path_to_file, O_RDONLY);
	if (fd < 0 || read(fd, &buff, 0) < 0)
	{
		printf("Le fichier %s n'est pas valide !\n", path_to_file);
		return (NULL);
	}
	size_i = get_size(fd);
	size_j = get_size(fd);
	j = 0;
	while (buff[j] != '\n' || buff[j] != '\0')
		j++;
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
			printf("Error malloc \n");
			return (NULL);
		}
		read(fd, &(map[i]), size_j);
		printf("%s", map[i]);
		i++;
	}
	return (map);
}

void affiche_map(char *fichier){

	char c;
	FILE* fichierp;

	fichierp = NULL;
	fichierp = fopen(fichier , "r");

	if (fichierp != NULL)
	{
		while ((c=fgetc(fichierp)) != EOF)
		{
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
			else{printf("%c",c);
			}
		}
		fclose(fichierp);
	}
}
