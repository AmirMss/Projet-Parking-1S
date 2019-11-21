#include "../inc/parking.h"

void	efface_voiture(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	for(i = 0; i < 2; i++)
	{
		printf("\033[%d;%dH", x, y);
		x++;
		for(j = 0; j < 8; j++)
		{
			printf(" ");
			/*y++; tu as oublier ?*/
		}

	}
}
