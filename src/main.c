#include "../inc/parking.h"

static int running = EXIT_SUCCESS;  //  While condition;
static int lock = EXIT_SUCCESS;     //  Re-print the maps;

static int	usage(char *name)
{
	printf("Usage : %s <map_file>\nLes fichiers doivent etre valides !\n", name);
	return (EXIT_FAILURE);
}

static int         end(char *s)
{
    printf("%s", s);
    return (EXIT_FAILURE);
}

static void     handel_exit(int sig)        //  Handel CTRL + C;
{
    char c;

    CLEAR
    signal(sig, handel_exit);
    printf("You press CTRL+C...\nDo you really want to exit? [y/n]\n");
    c = getchar();
    if (c == 'y' || c == 'Y')
    {
        CLEAR   //  Clear windows;
        printf("A+ %lc\n", 0x1F37B);
        running = EXIT_FAILURE;
    }
    else 
    {
        lock = EXIT_FAILURE;
        printf("Press any key\n");
    }
}

int		main(int argc, char **argv)
{
	char	    	**map;
    t_list_player   *player;
    time_t          t;
    int             speed;  //  Speed in Microseconde;
    char            c;
    int             clock_x, clock_y, cycle;    // Pos x and y for the clock;
    int             score_x, score_y, score;    // Pos x and y for the Score;

    signal(SIGINT, handel_exit);    //  Handel CTRL + C;
    SET_UTF //  Seting char type;
    if (argc != 2)
		return (usage(argv[0]));
	if ((map = parse_map(argv[1])) == NULL)
		return (usage(argv[0]));
    while (running == EXIT_SUCCESS)     // While menu, wait select value;
    {
        CLEAR   //  Clear windows;
        printf("%sBienvenue dans le projet parking de Moussous Amir\n\
%sPour le premier mode appuyer sur 1,\n\
%sPour le deuxieme mode appuyer sur 2\n\
%sPour le mode ULTRA RAPIDE FIRE appuyer sur 3\n\
%sPour le mode SUPER RAPIDE DE LA MORT QUI TUE ++ appuyer sur 4\n\
%sPour le mode Acceleration progressive appuyer sur 5\n\n%s", SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE);
            c = getchar();
            if (c == '1'|| c == '5')
            {
                speed = 300000;   // Speed of a cars
                break ;
            }
            else if (c == '2')
            {
                speed = 200000;    // Speed of a cars
                break ;
            }
            else if (c == '3')
            {
                speed = 100000;     // Speed of a cars
                break ;
            }
            else if (c == '4')
            {
                speed = 5000;      // Speed of a cars
                break ;
            }
    }


    srand((unsigned)time(&t));
    CLEAR   //  Clear windows;
    affiche_map(map);
    clock_x = find_char(map, 0, 'u');
    clock_y = find_char(map, 1, 'u');
    score_x = find_char(map, 0, 'Z') + 1;
    score_y = find_char(map, 1, 'Z');
    score = 0;
    cycle = 1;
    while (running == EXIT_SUCCESS)
    {
        printf("\033[10;36;2m\033[%d;%dH Score: \033[%d;%dH %d\033[1000;0H\033[0m", score_x, score_y, score_x + 1, score_y, score); //  Print Score;
        cycle = print_clock(clock_x + 1, clock_y + 7, cycle);   //  Print Clock;
        if (lock == EXIT_FAILURE)
        {
            CLEAR   //  Clear windows;
            affiche_map(map);
            lock = EXIT_SUCCESS;    //  Reset the refresh;
        }
        if (player == NULL)
        {
            if (NULL == (player = new_player(find_char(map, 0, 'a'), find_char(map, 1, 'a'), map)))
                exit(end("Error first player malloc\n"));
        }
        move_all(player, map);
        player = check_dead(player, map, &score);
        if (c == '5'&& speed > 15000)   //  if game mode = 5, decrement speed;
            speed -= 1000;
        cycle++;
        usleep(speed);  // man usleep;
    }
    exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}