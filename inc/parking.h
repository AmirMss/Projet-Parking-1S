#ifndef PARKING_H
# define PARKING_H


# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct      s_car
{
	char	    	**horizontal;
	char	    	**vertical;
}			    	t_car;

typedef struct             s_list_player
{
    int                    car;
    int                    pos_x;
    int                    pos_y;
    int                    dir_x;
    int                    dir_y;
    struct s_list_player   *next;
}                          t_list_player;

/*
**			affiche_map.c
*/
char	            **parse_map(char *path_to_file);
void            	affiche_map(char **map);
int                 find_start(char **map, int d);
/*
**			affiche_car.c
*/
t_car                **parse_car(char **path_to_files, int argc);
void	             affiche_voiture(t_car *car, int x, int y, int d);
/*
**			util.c
*/
int                 open_files(char *file);
int                 get_value(int fd);
/*
**                  player.c              
*/
t_list_player                 *voiture(t_list_player *player, char **map, t_car **car);
#endif
