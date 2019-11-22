#include "../inc/parking.h"

static t_list_car *get_car(char * patpath_to_files)
{
	t_list_car	*car;
	int			fd;
	char		buff;
	int			i;
	int			j;


	fd = open(path_to_file, O_RDONLY);
	if (fd < 0 || read(fd, &buff, 0) < 0)
	{
		printf("Le fichier %s n'est pas valide !\n", path_to_file);
		return (NULL);
	}
	i = 0;
	j = 0
	while (read(fd, &buff, 1) < 0)
	{
		if (buff = '\n' && j == 0)
		{
			car->horizontal[i] = NULL;
			break ;
		}
		if (buff == '\n')
		{
			car->horizontal[i][j] = '\0';
			j = 0;
			i++;
		}
		car->horizontal[i][j] = buff;
		j++;
	}
	while (read(fd, &buff, 1) < 0)
	{
		if (buff = '\0')
		{
			car->vertical[i] = NULL;
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

t_list_car **parse_car(char **path_to_files, int argc)
{
	t_list_car	**all_car;
	int			i;
	int			j;

	i = 2;
	all_car = (t_list_car **)malloc(sizeof(t_list_car*) * (argc - i) + 1);
	j = 0;
	while (i < argc)
	{
		if ((all_car[j] = get_car(path_to_files[i]) != NULL));
			j++;
		i++;
	}
	all_car[j] = NULL;
	return (all_car);
}

void affiche_voiture(char **car, int x, int y, int d)
{
	int i;
	int j;
	j = 0;
	while (car[i] != NULL)
	{
		j = 0;
		printf("\033[%d;%dH", x, y);
		x++;
		while (car[i][j] != '\0')
		{
			if (d == 1)
			{
				printf("\033[10;36;2m");
				printf(" "); // On l'affiche
				printf("\033[0m");
			}
			else if (car[i][j] == 'A')
			{
				printf("\033[10;36;2m");
				printf("┌"); // On l'affiche
				printf("\033[0m");
			}
			else if (car[i][j] == 'B')
			{
				printf("\033[10;36;2m");
				printf("─");
				printf("\033[0m");
			}
			else if (car[i][j] == 'C')
			{
				printf("\033[10;36;2m");
				printf("┬");
				printf("\033[0m");
			}
			else if (car[i][j] == 'P')
			{
				printf("\033[10;36;2m");
				printf("┐");
				printf("\033[0m");
			}
			else if (car[i][j] == 'M')
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
			else if (car[i][j] == 'N')
			{
				printf("\033[10;36;2m");
				printf("┘");
				printf("\033[0m");
			}
			else if (car[i][j] == 'E')
			{
				printf("\033[10;36;2m");
				printf("│");
				printf("\033[0m");
			}
			else if (car[i][j] == 'D')
			{
				printf("\033[10;36;2m");
				printf("├");
				printf("\033[0m");
			}
			else if (car[i][j] == 'H')
			{
				printf("\033[10;36;2m");
				printf("┤");
				printf("\033[0m");
			}
			
				else
					printf("%c", c);
			j++;
		}
		i++;
	}
}
