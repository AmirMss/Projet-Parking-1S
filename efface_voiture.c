#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "efface_voiture.h"

void efface_voiture(int x, int y){
char c;
int i = 0, j = 0;


	for(i=0; i<2 ; i++){
		printf("\033[%d;%dH", x, y);
		x++;
		for(j=0; j<8; j++){
		printf(" ");
	
		}
       
    	}
}
