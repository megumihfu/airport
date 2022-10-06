#include "avion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    Liste_avion *liste_avion, *avion_dec, *avion_att;
    //Liste_avion *nouveau;
    //Liste_avion *liste_cmp;
    avion av; //créer la structure avion av
    int carb, nbr, end;
    char id[100];
    char cmp[100];


    avion_dec = init_dec(avion_dec); 
    avion_att = init_att(avion_att);
    //liste_cmp = init_avion_cmp (liste_cmp); //pb sur cette ligne aussi
    //display(avion_att);
    
    menu (avion_dec, avion_att);//, liste_cmp);

    return 0;
}