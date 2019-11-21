#ifndef PARKING_H
# define PARKING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_car
{
	char		*horizontal;
	char		*vertical;
}				t_list_car;

/*
**			affiche_map.c
*/
char	**parse_map(char *path_to_file);
void	affiche_map(char *fichier);
/*
**			affiche_map.c
*/
void	affiche_voiture(char *fichier, int x, int y, int d);
/*
**			efface_map.c
*/
void	efface_voiture(int x, int y);

#endif
