#ifndef PARKING_H
# define PARKING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_car
{
	char		horizontal[10][10];
	char		vertical[10][10];
}				t_list_car;

/*
**			affiche_map.c
*/
char	**parse_map(char *path_to_file, int argc);
void	affiche_map(char **map);
/*
**			affiche_map.c
*/
t_list_car **parse_car(char **path_to_files);
void		affiche_voiture(char *fichier, int x, int y, int d);
/*
**			efface_map.c
*/
void	efface_voiture(int x, int y);

char    *strcpy(char *dest, char *src );
#endif
