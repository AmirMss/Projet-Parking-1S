#include "../inc/parking.h"

static int get_size(int fd)
{
	int		size;
	char	buff[2];

	size = 0;
	while (read(fd, &buff, 1) > 0)
	{
		if (!(buff[0] < '0' && c <= '9'))
			break ;
		size = size * 10 + buff[0] - '0';
	}
	return (size);
}

char	**parse_map(char *path_to_file)
{
	int		fd;
	int		size_i;
	int		size_j;
	char	buff[254];

	fd = open(path_to_file, O_RDONLY);
	if (fd < 0 || read(fd, &buff, 0) < 0)
	{
		printf("Le fichier %s n'est pas valide !\n", path_to_file);
		return (NULL);
	}
	size_i = get_size(fd);
	size_j = get_size(fd);
	printf("size_i = %d, size_j = %d\n", size_i, size_j);
	return (NULL);
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
