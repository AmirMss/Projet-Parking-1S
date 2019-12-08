#ifndef PARKING_H
# define PARKING_H

#ifdef __APPLE__    // For Apple Unicode 
    #define SET_UTF setlocale (LC_ALL, "en_US.UTF-8");
#elif __linux       // For Linux Unicode
    #define SET_UTF setlocale(LC_ALL, "en_US.utf8");
#else               // else 
    #define SET_UTF setlocale(LC_ALL, "en_US.utf8");
#endif

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <locale.h>
# include <time.h>

typedef struct             s_list_player
{
    int                    car;     //  type wchar car; 
    int                    pos_x;   //  pos_x in map;
    int                    pos_y;   //  pos_y in map;
    int                    dir_x;   //  dir_x in map <value : -1 / 0 / 1>;
    int                    dir_y;   //  dir_y in map <value : -1 / 0 / 1>;
    char                   map;     //  char on the map <at self->pos_x self->pos_y;
    int                    exit;    //  Go to exit;
    int                    wait;    //  NB cycle stay in parking place;
    int                    dead;    //  Is in the parking;
    struct s_list_player   *next;   //  Next node;
}                          t_list_player;

/*
**              			map.c
*/
char	                    **parse_map(char *path_to_file);        //  Use for parse map files <Return : Malloc **char>;
void                        affiche_map(char **map);                //  Take a Char **, convert to extended ASCII & print it in term;
int                         find_start(char **map, int d);          //  Take a char ** and search 'a', <if d == 0 return x> <else return y>; 
/*
**  			            util.c
*/
int                         open_files(char *file);                 //  Take a path file and return a file descriptor;
int                         get_value(int fd);                      //  Take a File descriptor and return sizeof files; 
t_list_player               *new_player(int x_start, int y_start, char **map);  //  Take x_start as in & y_start as int & map as char **, <Return : Malloc *t_list_player>;
/*
**                          player.c              
*/
t_list_player               *move_all(t_list_player *player, char **map);
t_list_player               *check_dead(t_list_player *player, char **map);
void                        print_car(t_list_player *player, int d);
/*
**                          place.c
*/



#endif
