#include "../inc/parking.h"


static int	usage(char *name)
{
	printf("Usage : %s <map_file>\nLes fichiers doivent etre valides !\n", name);
	return (EXIT_FAILURE);
}

int         end(char *s)
{
    printf("%s", s);
    return (EXIT_FAILURE);
}


int		main(int argc, char **argv)
{
	char	    	**map;
    t_list_player   *player;
    time_t          t;
    int             speed;
    char            c;

    SET_UTF/*Set local char*/
    system("@cls||clear");
    while (1)
    {
        printf("                       Bienvenue dans le projet parking de Moussous Amir\n                       \
Pour le premier mode appuyer sur 1,\n                       \
Pour le deuxieme mode appuyer sur 2\n                       \
Pour le mode ULTRA RAPIDE FIRE appuyer sur 3\n");
            c = getchar();
            if (c == '1')
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

    }

    system("@cls||clear");
	if (argc != 2)
		return (usage(argv[0]));
	if ((map = parse_map(argv[1])) == NULL)
		return (usage(argv[0]));
    affiche_map(map);
    srand((unsigned)time(&t));
    while (1)
    {
        if (player == NULL)
        {
            if (NULL == (player = new_player(find_start(map, 0), find_start(map, 1), map)))
                return (end("Error first player malloc\n"));
        }
        move_all(player, map);
        player = check_dead(player, map);
        usleep(speed);
    }
	return (EXIT_SUCCESS);
}