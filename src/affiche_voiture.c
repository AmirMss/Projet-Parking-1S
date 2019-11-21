#include "../inc/parking.h"

void affiche_voiture(char *fichier,int x, int y)
{
	char	c;
	int	i;
	int	j;
	FILE*	fichierp;

	i = 0;
	j = 0;
	fichierp = NULL;
	fichierp = fopen(fichier , "r");
	if (fichierp != NULL)
	{           
		for(i=0; i<2 ; i++){
			printf("\033[%d;%dH", x, y);
			x++;
			for(j=0; j<8; j++){
				c=fgetc(fichierp);
				if(c != EOF){
					if (c == 'A')
					{
						printf("\033[10;36;2m");
						printf("┌"); // On l'affiche
						printf("\033[0m");
					}
					else if (c == 'B')
					{
						printf("\033[10;36;2m");
						printf("─");
						printf("\033[0m");
					}
					else if (c == 'C')
					{
						printf("\033[10;36;2m");
						printf("┬");
						printf("\033[0m");
					}
					else if (c == 'P')
					{
						printf("\033[10;36;2m");
						printf("┐");
						printf("\033[0m");
					}
					else if (c == 'M')
					{
						printf("\033[10;36;2m");
						printf("└");
						printf("\033[0m");
					}
					else if (c == 'G')
					{
						printf("\033[10;36;2m");
						printf("┴");
						printf("\033[0m");
					}
					else if (c == 'N')
					{
						printf("\033[10;36;2m");
						printf("┘");
						printf("\033[0m");
					}
					else{printf("%c",c);

					}
				}
			}

		}

		fclose(fichierp);
	}
}
