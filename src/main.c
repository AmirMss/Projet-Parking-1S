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
    t_car           *car;
//    t_lis_player    *player;

	if (argc < 3)
		return (usage(argv[0]));
	if ((map = parse_map(argv[1])) == NULL)
		return (usage(argv[0]));
	if ((all_car = parse_car(argv, argc)) == NULL)
		return (usage(argv[0]));
    affiche_map(map);
    car = all_car[0];
    affiche_voiture(car, 23, 20, 0);
	return (0);
}
