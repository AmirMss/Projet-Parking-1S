#include "../inc/parking.h"

int	main(void)
{
	affiche_map("files/map.txt");
	sleep(1);
	affiche_voiture("files/test.txt",20,20, 0);
	fflush(stdout);
	sleep(5);
	affiche_voiture("files/test.txt",20,20, 1);
	affiche_voiture("files/test.txt", 20, 21, 0);
	fflush(stdout);
	sleep(10);

	return 0;
}
