#include "../inc/parking.h"

static int running = EXIT_SUCCESS;  //  While condition;
static int lock = EXIT_SUCCESS;     //  Re-print the maps;

__attribute__((destructor)) void finish(void);

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
    char    c;

    CLEAR
    signal(sig, handel_exit);
    printf("You press CTRL+C...\nDo you really want to exit? [y/n]\n");
    c = getchar();
    if (c == 'y' || c == 'Y')
    {
        CLEAR   //  Clear windows;
        printf("%lc Joyeux Noel , à bientôt. %lc\n", 0x1F332 , 0x1F332);
        running = EXIT_FAILURE;
        exit (0);
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
    system("screen -d -m play files/vive_le_vent.wav repeat 999");
    while (running == EXIT_SUCCESS)     // While menu, wait select value;
    {
        CLEAR   //  Clear windows;
        printf("%s%lc Bienvenue dans le projet parking de Moussous Amir et Abkari Mehdi %lc \n\
%s%lc Pour le premier mode appuyer sur 1\n\
%s%lc Pour le deuxieme mode appuyer sur 2\n\
%s%lc Pour le mode ULTRA RAPIDE FIRE appuyer sur 3\n\
%s%lc Pour le mode SUPER RAPIDE DE LA MORT QUI TUE ++ appuyer sur 4\n\
%s%lc Pour le mode Acceleration progressive appuyer sur 5\n\n%s", SPACE,0x2744, 0x1F385, SPACE, 0x2744, SPACE, 0x2744, SPACE, 0x2744, SPACE , 0x2744, SPACE, 0x2744,SPACE);
        c = getchar();
        if (c == '1'|| c == '5')
        {
            speed = 300000;   // Speed of a cars
            break ;
        }
        else if (c == '2')
        {
            speed = 200000;    // Speed of a cars
            system("screen -d -m pkill play");
            sleep(1);
            system("screen -d -m play files/vive_le_vent.wav speed 1.25 repeat 999");
            break ;
        }
        else if (c == '3')
        {
            speed = 100000;     // Speed of a cars
            system("screen -d -m pkill play");
            sleep(1);
            system("screen -d -m play files/vive_le_vent.wav speed 1.5 repeat 999");
            break ;
        }
        else if (c == '4')
        {
            speed = 5000;      // Speed of a cars
            system("screen -d -m pkill play");
            sleep(1);
            system("screen -d -m play files/vive_le_vent.wav speed 2 repeat 999");
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

void        finish()
{
    system("screen -d -m pkill play");
}