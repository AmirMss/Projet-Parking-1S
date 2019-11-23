#include "../inc/parking.h"

static int	usage(char *name)
{
	printf("Usage : %s <map_file> <car_files ...>\nLes fichiers doivent être valide !\n", name);
	return (0);
}

int		main(int argc, char **argv)
{
	char		**map;
	t_car	**all_car;

	if (argc < 3)
		return (usage(argv[0]));
	if ((map = parse_map(argv[1])) == NULL)
		return (usage(argv[0]));
	if ((all_car = parse_car(argv, argc)) == NULL)
		return (usage(argv[0]));

    //affiche_map(map);
    
    int i = 0;
    printf("\n");
    while (all_car[0]->horizontal[i] != NULL)
    {
        printf("%s", all_car[0]->horizontal[i]);
        i++;
    }
	return (0);
}
