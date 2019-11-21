 #include "../inc/parking.h"



static int	usage(char *name)
{
	printf("Usage : ./%s <map_file> <car_files ...>\nLes fichiers doivent être valide !\n", name);
	return (0);
 }

int		main(int argc, char **argv)
{
	char		**map;
	t_list_car	**all_type;
	int			i;

	if (argc < 3)
		return (usage(argv[0]));
	if ((map = prase_map(argv[1])) == NULL)
		return (usage(arv[0]));
	all_type = parse_car(argv);


	return (0);
}
