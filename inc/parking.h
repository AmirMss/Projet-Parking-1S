#ifndef PARKING_H
# define PARKING_H

#ifdef __APPLE__
    #define SET_UTF setlocale (LC_ALL, "en_US.UTF-8");
#elif __linux
    #define SET_UTF setlocale(LC_ALL, "en_US.utf8");
#else
    #define SET_UTF setlocale(LC_ALL, "en_US.utf8");
#endif


# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <locale.h>

typedef struct             s_list_player
{
    char                   map;
    int                    exit;
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
char	        **parse_map(char *path_to_file);
void            affiche_map(char **map);
int             find_start(char **map, int d);
/*
**			util.c
*/
int             open_files(char *file);
int             get_value(int fd);
/*
**              player.c              
*/
t_list_player  *new_player(int x_start, int y_start, char **map);
t_list_player           *move_all(t_list_player *player, char **map);
#endif
