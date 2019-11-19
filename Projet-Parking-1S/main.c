#include <stdio.h>
#include <stdlib.h>
#include "affiche_map.c"
#include "affiche_voiture.c"

int main(int argc, char *argv[])
{
affiche_map("map.txt");
//printf("\033[%d;%dH", 20, 20);
affiche_voiture("voiture.pgd.txt",20,20);
printf("\033[%d;%dH", 700, 0);
    return 0;
}

