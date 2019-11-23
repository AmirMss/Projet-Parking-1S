#ifndef PARKING_H
# define PARKING_H


# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_car
{
	char		horizontal[10][10];
	char		vertical[10][10];
}				t_car;

/*
**			affiche_map.c
*/
char	**parse_map(char *path_to_file);
void	affiche_map(char **map);
/*
**			affiche_map.c
*/
t_car **parse_car(char **path_to_files, int argc);
void		affiche_voiture(t_car *car, int x, int y, int d);
/*
**			efface_map.c
*/
void	efface_voiture(int x, int y);
#endif
