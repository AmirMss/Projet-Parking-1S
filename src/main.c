#include "../inc/parking.h"

static int running = EXIT_SUCCESS;
static int lock = EXIT_SUCCESS;

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

static void     handel_exit(int sig)
{
    char c;

    system("@cls||clear");
    signal(sig, handel_exit);
    printf("You press CTRL+C...\nDo you really want to exit? [y/n]\n");
    c = getchar();
    if (c == 'y' || c == 'Y')
    {
        system("@cls||clear");
        printf("A+ %lc\n", 0x1F37B);
        running = EXIT_FAILURE;
    }
    else 
    {
        lock = EXIT_FAILURE;
        printf("Press any key\n");
        //signal(SIGINT, handel_exit);
    }
}

int		main(int argc, char **argv)
{
	char	    	**map;
    t_list_player   *player;
    time_t          t;
    int             speed;
    char            c;
    int             clock_x, clock_y, cycle;
    int             score_x, score_y, score;

    signal(SIGINT, handel_exit);
    SET_UTF/*Set local char*/
    while (running == EXIT_SUCCESS)
    {
        system("@cls||clear");
        printf("                       \
Bienvenue dans le projet parking de Moussous Amir\n                       \
Pour le premier mode appuyer sur 1,\n                       \
Pour le deuxieme mode appuyer sur 2\n                       \
Pour le mode ULTRA RAPIDE FIRE appuyer sur 3\n                       \
Pour le mode SUPER RAPIDE DE LA MORT QUI TUE ++ appuyer sur 4\n                       \
Pour le mode Acceleration progressive appuyer sur 5\n");
            c = getchar();
            if (c == '1'|| c == '5')
            {
                speed = 1000000;
                break ;
            }
            else if (c == '2')
            {
                speed = 850000;
                break ;
            }
            else if (c == '3')
            {
                speed = 500000;
                break ;
            }
            else if (c == '4')
            {
                speed = 250000;
                break ;
            }
    }

	if (argc != 2)
		return (usage(argv[0]));
	if ((map = parse_map(argv[1])) == NULL)
		return (usage(argv[0]));
    srand((unsigned)time(&t));
    system("@cls||clear");
    affiche_map(map);
    clock_x = find_char(map, 0, 'u');
    clock_y = find_char(map, 1, 'u');
    score_x = find_char(map, 0, 'Z') + 1;
    score_y = find_char(map, 1, 'Z');
    score = 0;
    cycle = 1;
    while (running == EXIT_SUCCESS)
    {
        printf("\033[10;36;2m\033[%d;%dH Score: \033[%d;%dH %d\033[1000;0H\033[0m", score_x, score_y, score_x + 1, score_y, score);
        cycle = print_clock(clock_x + 1, clock_y + 7, cycle);
        if (lock == EXIT_FAILURE)
        {
            system("@cls||clear");
            affiche_map(map);
            lock = EXIT_SUCCESS;
        }
        if (player == NULL)
        {
            if (NULL == (player = new_player(find_char(map, 0, 'a'), find_char(map, 1, 'a'), map)))
                exit(end("Error first player malloc\n"));
        }
        move_all(player, map);
        player = check_dead(player, map, &score);
        if (c == '5'&& speed > 15000)
            speed -= 1000;
        cycle++;
        usleep(speed);
    }
    exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}