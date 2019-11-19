#include <stdio.h>
#include <stdlib.h>
#include "affiche_voiture.h"

void affiche_voiture(char *fichier,int x, int y){
char c;
int i = 0, j = 0;
FILE* fichierp = NULL;

    fichierp = fopen(fichier , "r");

    if (fichierp != NULL)
    {
	printf("\033[%d;%dH", x, y);
        while ((c=fgetc(fichierp)) != EOF)
        {
            if(j>6){
		printf("\033[%d;%dH", x, y);
		j++;
		}
	     else{
		//printf("\033[%d;%dH", x, y);
		j = 0;
		}

            printf("%c", c);

        }

        fclose(fichierp);
    }
}
