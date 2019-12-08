#ifndef PARKING_H
# define PARKING_H

#ifdef __APPLE__    // For Apple Unicode 
    #define SET_UTF setlocale (LC_ALL, "en_US.UTF-8");
#elif __linux       // For Linux Unicode
    #define SET_UTF setlocale(LC_ALL, "en_US.utf8");
#else               // else 
    #define SET_UTF setlocale(LC_ALL, "en_US.utf8");
#endif

#define BUFF_SIZE 128       //  Buff size for get_next_line;
#define WAITING_MAX 100     //  Max park cycle wait;
#define POPULATE 5          //  1 / N -> exemple 1/5 -> 1 of 5 cycle 1 more car;

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <locale.h>
# include <time.h>
# include <signal.h>
# include <fcntl.h>
 
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
int                         find_char(char **map, int d, char c);   //  Take a char ** & char and search this char, <if d == 0 return x> <else return y>; 
/*
**  			            util.c
*/
int                         open_files(char *file);                 //  Take a path file and return a file descriptor;
int                         get_value(int fd);                      //  Take a File descriptor and return sizeof files; 
t_list_player               *new_player(int x_start, int y_start, char **map);  //  Take x_start as in & y_start as int & map as char **, <Return : Malloc *t_list_player>;
int                         print_clock(int x, int y, int cycle);   //  Take a clock pos, and cycle, print Day, Night, Clock, Weather;
/*
**                          player.c              
*/
t_list_player               *move_all(t_list_player *player, char **map);   //  Take player list, and map.
t_list_player               *check_dead(t_list_player *player, char **map, int *nb);    //  Take a player, map and &score, every free score is increment;
void                        print_car(t_list_player *player, int d);    //  Take a player and print it if d == 0 print the car else print space;
/*
**                          place.c
*/
int                         check_place(t_list_player *player, char **map, char ori);   //  Take a player, map and orientation, check if the place is free <return : free = EXIT_SUCCES, not_free = EXIT_FAILURE>
void                        wake_up(t_list_player *player, char **map); //  Take a player and map.  Get the new path;
/*
**                          my_lib.c
*/
int		                    ms_atoi(const char *str);   //  man atoi;
int		                    ms_isdigit(int c);  //  man isdigit;
int	                    	ms_isalpha(int c);  //  man isalpha;
int	                    	ms_isalnum(int c);  //  man isalnum;
void                    	ms_bzero(void *s, size_t n);    //  man bzero;
void                    	*ms_memalloc(size_t size);  //  Allocates and returns a “fresh” memory area;
char                    	*ms_strjoin(char const *s1, char const *s2);    //  Allocates and returns a “fresh” string ending with ’\0’, result of the concatenation of s1 and s2;
char                    	*ms_strnew(size_t size);    //  Allocates and returns a “fresh” string ending with ’\0’;
char                       	*ms_strdup(const char *s);  //  man strdup;
void                    	ms_strdel(char **as);   //  Takes as a parameter the address of a string and free it, then sets its pointer to NULL;
char                    	*ms_strchr(const char *s, int c);   //  man strchr;
char	                    *ms_strcpy(char *dst, const char *src); //  man strcpy;
size_t	                    ms_strlen(const char *str); //  man strlen;
char	                    *ms_strcat(char *dest, const char *src);    //  man strcat;
char	                    *ms_strsub(char const *s, unsigned int start, size_t len);  //  Allocates  and returns a “fresh” substring from the string given as argument;
int		            		get_next_line(const int fd, char **line);   //  Return the next line form the file descriptor; 
#endif