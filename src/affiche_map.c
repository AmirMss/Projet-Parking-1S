#include "../inc/parking.h"

void affiche_map(char *fichier){

	char c;
	FILE* fichierp;

	fichierp = NULL;
	fichierp = fopen(fichier , "r");

	if (fichierp != NULL)
	{
		while ((c=fgetc(fichierp)) != EOF)
		{
			if (c == 'U')
			{
				printf("\033[10;36;2m");
				printf("╔"); // On l'affiche
				printf("\033[0m");
			}
			else if (c == 'B')
			{
				printf("\033[10;36;2m");
				printf("═");
				printf("\033[0m");
			}
			else if (c == 'A')
			{
				printf("\033[10;36;2m");
				printf("║");
				printf("\033[0m");
			}
			else if (c == 'x')
			{
				printf("\033[10;36;2m");
				printf("▀");
				printf("\033[0m");
			}
			else if (c == 'K')
			{
				printf("\033[10;36;2m");
				printf("╚");
				printf("\033[0m");
			}
			else if (c == 'M')
			{
				printf("\033[10;36;2m");
				printf("╗");
				printf("\033[0m");
			}
			else if (c == 'L')
			{
				printf("\033[10;36;2m");
				printf("╝");
				printf("\033[0m");
			}
			else if (c == '6')
			{
				printf("\033[10;36;2m");
				printf("╬");
				printf("\033[0m");
			}
			else if (c == 'R')
			{
				printf("\033[10;36;2m");
				printf("╩");
				printf("\033[0m");
			}
			else if (c == '9')
			{
				printf("\033[10;36;2m");
				printf("╦");
				printf("\033[0m");
			}
			else if (c == '0')
			{
				printf("\033[10;36;2m");
				printf(" ");
				printf("\033[0m");
			}
			else if (c == 's')
			{
				printf("\033[10;36;2m");
				printf("▌");
				printf("\033[0m");
			}
			else if (c == '3')
			{
				printf("\033[10;36;2m");
				printf("╣");
				printf("\033[0m");
			}
			else if (c == 'G')
			{
				printf("\033[10;36;2m");
				printf("╠");
				printf("\033[0m");
			}
			else{printf("%c",c);
			}
		}
		fclose(fichierp);
	}
}
