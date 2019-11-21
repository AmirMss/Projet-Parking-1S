#include "../inc/parking.h"

int	main(void)
{
	affiche_map("files/map.txt");
	sleep(1);
	//printf("\033[%d;%dH", 20, 20);
	affiche_voiture("files/test.txt",20,20);
	//printf("\033[%d;%dH", 700, 0);
	sleep(1);
	efface_voiture(20,20);
	affiche_map("files/map.txt");
	//printf("\033[%d;%dH", 700, 0);
	return 0;
}
