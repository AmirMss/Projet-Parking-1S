#include "../inc/parking.h"

static int	usage(char *name)
{
	printf("Usage : %s <map_file> <car_files ...>\nLes fichiers doivent �tre valide !\n", name);
	return (0);
}

int		main(int argc, char **argv)
{
	char		**map;
	t_list_car	**all_type;

	if (argc < 3)
		return (usage(argv[0]));
	if ((map = parse_map(argv[1])) == NULL)
		return (usage(argv[0]));
	if ((t_list_car = parse_car(argv, argc)) == NULL)
		return (usage(argv[0]));

    affiche_map(map);
	return (0);
}
