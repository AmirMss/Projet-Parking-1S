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
    t_list_player   *new;
    time_t          t;

    SET_UTF/*Set local char*/
    system("@cls||clear");
	if (argc != 2)
		return (usage(argv[0]));
	if ((map = parse_map(argv[1])) == NULL)
		return (usage(argv[0]));
    affiche_map(map);
    srand((unsigned)time(&t));
    if (NULL == (player = new_player(find_start(map, 0), find_start(map, 1), map)))
        return (end("Error first player malloc\n"));
    while (1)
    {
        move_all(player, map);
        player = check_dead(player, map);
        if (find_start(map, 0) != -1)
        {
            if (NULL == (new = new_player(find_start(map, 0), find_start(map, 1), map)))
                return (end("Error first player malloc\n"));
            new->next = player;
            player = new;

        }
        sleep(1);
    }
	return (EXIT_SUCCESS);
}