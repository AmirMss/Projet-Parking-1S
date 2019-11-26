#include "../inc/parking.h"

static int	usage(char *name)
{
	printf("Usage : %s <map_file> <car_files ...>\nLes fichiers doivent etre valides !\n", name);
	return (0);
}

int		main(int argc, char **argv)
{
	char	    	**map;
	t_car           **all_car;
    t_list_player    *player;

	if (argc < 3)
		return (usage(argv[0]));
	if ((map = parse_map(argv[1])) == NULL)
		return (usage(argv[0]));
	if ((all_car = parse_car(argv, argc)) == NULL)
		return (usage(argv[0]));
    system("@cls||clear");
    affiche_map(map);
    player = NULL;
    while (1)
    {
        player = voiture(player, map, all_car);
        sleep(1);
    }
	return (0);
}
