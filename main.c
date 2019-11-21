#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "affiche_map.c"
#include "affiche_voiture.c"
#include "efface_voiture.c"

int main(int argc, char *argv[])
{
sleep(1);
affiche_map("map.txt");
sleep(1);
//printf("\033[%d;%dH", 20, 20);
affiche_voiture("test.txt",20,20);
printf("\033[%d;%dH", 700, 0);
sleep(1);
efface_voiture(20,20);
printf("\033[%d;%dH", 700, 0);
    return 0;
}

