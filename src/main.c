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

    SET_UTF/*Set local char*/ 
    
    system("@cls||clear");
	if (argc != 2)
		return (usage(argv[0]));
	if ((map = parse_map(argv[1])) == NULL)
		return (usage(argv[0]));
    affiche_map(map);
    if (NULL == (player = new_player(find_start(map, 0), find_start(map, 1), map)))
        return (end("Error first player malloc\n"));


    while (1)
    {
        move_all(player, map);
        sleep(1);
    }
	return (EXIT_SUCCESS);
}
