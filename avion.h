#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//Definition de la structure avion
typedef struct avion{
    char identifiant[20];
    int carburant;
    char compagnie[20];
}avion;
 
//Definition de la structure de la liste chainee avion decollage
typedef struct Liste_avion{
    struct avion donnee;
    int priorite; //1 prio sinon = 0
    struct Liste_avion *next;
}Liste_avion;

/*
typedef struct Liste_compagnie{
    char nom[20];
    char acronyme[20];
    char liste_avion[20];  // Tableau contenant les identifiants des avions de la compagnie
    struct Liste_compagnie *next;
}Liste_compagnie;

*/
//La liste chainee des avions de  decollage
Liste_avion * avion_dec;
//La liste chainee des avions d'atterissage
Liste_avion * avion_att;
//liste chainée de tous les avions
Liste_avion *liste_cmp;


// La question 1
//Pour ajouter un avion dans une liste des avions qui sont en attente de decollage on crée d'abord l'avion.
avion creer_avion(char id[20], int carb, char cmp[20])
{
    avion av;
    strcpy(av.identifiant, id);
    av.carburant = carb;
    strcpy(av.compagnie, cmp);

    return av; 
}

Liste_avion *creer_element_liste(avion av)
{
    Liste_avion * liste_avion;

    liste_avion = (Liste_avion *)malloc(sizeof(Liste_avion));
    liste_avion->next = NULL;
    liste_avion->donnee = av;
    liste_avion->priorite=0;

    return liste_avion;
}


Liste_avion *add_element(Liste_avion *tete, Liste_avion *nouveau)
{
    Liste_avion *tmp = NULL;

    if(tete == NULL)
        {
            tete = nouveau;
        }

        else 
        {
            tmp = tete;

            while(tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = nouveau;
        }

        return tete;
}


Liste_avion *init_dec (Liste_avion *liste_avion)
{
    avion av4, av1, av2, av3;
    Liste_avion *nouveau4, *nouveau1, *nouveau2, *nouveau3;
    
    char id[20];
    int carb;
    char cmp[20];
    
    //Avion1
    strcpy(id, "Boieng528_FvJ7");
    carb = 42;
    strcpy(cmp, "Transavia");
    av1 = creer_avion(id, carb, cmp); //initialisation de la struct avion
    nouveau1 =  creer_element_liste(av1); //initialise la liste chainée
    liste_avion = add_element(liste_avion, nouveau1); //ajouter le nouvel element

    //avion2
    strcpy(id, "Boieng627_2Gf5R");
    carb = 58;
    strcpy(cmp, "RAM");
    av2 = creer_avion(id, carb, cmp); //initialisation de la struct avion
    nouveau2 =  creer_element_liste(av2); //initialise la liste chainée
    liste_avion = add_element(liste_avion, nouveau2); //ajouter le nouvel élément

    //avion3
    strcpy(id, "Boieng17_AKA71");
    carb = 67;
    strcpy(cmp, "Transavia");
    av3 = creer_avion(id, carb, cmp); //initialisation de la struct avion
    nouveau3 =  creer_element_liste(av3); //initialise la liste chainée
    liste_avion = add_element(liste_avion, nouveau3); //ajouter le nouvel élément

    //avion4
    strcpy(id, "Boieng90hd_GZ1");
    carb = 25;
    strcpy(cmp, "RAM");
    av4 = creer_avion(id, carb, cmp); //initialisation de la struct avion
    nouveau4 =  creer_element_liste(av4); //initialise la liste chainée
    liste_avion = add_element(liste_avion, nouveau4); //ajouter le nouvel élément

    return liste_avion;
}

Liste_avion *init_att (Liste_avion *liste_avion)
{
    avion av4, av1, av2, av3;
    Liste_avion *nouveau4, *nouveau1, *nouveau2, *nouveau3;
    
    char id[20];
    int carb;
    char cmp[20];
    
    //Avion1
    strcpy(id, "Boieng56_12xC4");
    carb = 43;
    strcpy(cmp, "Transavia");
    av1 = creer_avion(id, carb, cmp); //initialisation de la struct avion
    nouveau1 =  creer_element_liste(av1); //initialise la liste chainée
    liste_avion = add_element(liste_avion, nouveau1); //ajouter le nouvel élément

    //avion2
    strcpy(id, "Boieng52_93Hk8");
    carb = 84;
    strcpy(cmp, "RAM");
    av2 = creer_avion(id, carb, cmp); //initialisation de la struct avion
    nouveau2 =  creer_element_liste(av2); //initialise la liste chainée
    liste_avion = add_element(liste_avion, nouveau2); //ajouter le nouvel élément

    //avion3
    strcpy(id, "Boieng34_Th07x");
    carb = 62;
    strcpy(cmp, "Transavia");
    av3 = creer_avion(id, carb, cmp); //initialisation de la struct avion
    nouveau3 =  creer_element_liste(av3); //initialise la liste chainée
    liste_avion = add_element(liste_avion, nouveau3); //ajouter le nouvel élément

    //avion4
    strcpy(id, "Boieng7_Z72gd0");
    carb = 55;
    strcpy(cmp, "RAM");
    av4 = creer_avion(id, carb, cmp); //initialisation de la struct avion
    nouveau4 =  creer_element_liste(av4); //initialise la liste chainée
    liste_avion = add_element(liste_avion, nouveau4); //ajouter le nouvel élément

    return liste_avion;
}


avion saisir_caract_dec(Liste_avion *liste_avion, Liste_avion *nouveau, int carb, char id[20], char cmp[20])
{
    avion av;

    printf("\nVeuillez saisir le pourcentage de carburant : ");
    scanf("%d", &carb);
    av.carburant = carb;

    printf("\nVeuillez saisir le nom de l'avion : ");
    scanf("%s", id);
    strcpy(av.identifiant, id);

    printf("\nVeuillez saisir le nom de la compagnie : ");
    scanf("%s", cmp);
    strcpy(av.compagnie, cmp);

    printf("\nL'avion que vous souhaitez ajouter sur la liste de décollage est l'appareil %s de la compagnie %s avec %d pourcent de carburant\n", av.identifiant, av.compagnie, av.carburant);

    return av;
}

avion saisir_caract_att (Liste_avion *liste_avion, Liste_avion *nouveau, int carb, char id[20], char cmp[20])
{
    avion av;
    av.carburant = 0;

    printf("\nVeuillez saisir le nom de l'avion : ");
    scanf("%s", id);
    strcpy(av.identifiant, id);
    printf("\nVeuillez saisir le nom de la compagnie : ");
    scanf("%s", cmp);
    strcpy(av.compagnie, cmp);

    printf("\nL'avion que vous souhaitez ajouter est l'appareil %s de la compagnie %s\n", av.identifiant, av.compagnie);

    return av;
}


void display (Liste_avion *tete)
{
    Liste_avion *tmp = tete;

    if(tete == NULL)
    {
        printf("La liste est vide\n");
    }

    else
    {
        while(tmp != NULL)
        {
            if(tmp->priorite==1){
                printf("\nNom de l'avion : %s\nNom de la compagnie : %s\nPourcentage de carburant restant : %d\nL'avion est prioritaire !!\n", tmp->donnee.identifiant, tmp->donnee.compagnie, tmp->donnee.carburant);

            }
            else{
                printf("\nNom de l'avion : %s\nNom de la compagnie : %s\nPourcentage de carburant restant : %d\nL'avion n est pas prioritaire !!\n", tmp->donnee.identifiant, tmp->donnee.compagnie, tmp->donnee.carburant);

            }
            tmp = tmp->next;
        }
    }
}


Liste_avion *supp_id (Liste_avion *tete, char id[20])
{
    Liste_avion *tmp, *tmp2;
    tmp = tete;

    if(tete == NULL)
    {
        printf("La liste est vide\n");
    }

    else 
    {
        while(tmp != NULL) 
        {
            if(strcmp((tmp->next)->donnee.identifiant, id) == 0)
            {
                tmp2 = (tmp->next)->next;
                tmp->next = tmp2;
                break;
            }
            tmp = tmp->next;
        }

        if(tmp == NULL)
        {
            printf("L'identifiant de cet avion est inexistant\n");
        }
    }

    return tete;
}

Liste_avion *prioritaire (Liste_avion *tete)
{
    Liste_avion *tmp;

    if(tete == NULL)
    {
        printf("La liste est vide\n");
    }

    else 
    {
        tmp = tete; 

        while(tmp != NULL)
        {
            if(tmp->donnee.carburant < 45)
            {
                tmp->priorite = 1;
            }
            tmp = tmp->next;
        }
    }

    if(tmp == NULL)
    {
        printf("Le nom de cette compagnie est inexistant\n");
    }

    return tete;
}

/*
Liste_avion *init_avion_cmp (Liste_avion *liste_cmp)
{
    avion av1, av2, av3, av4, av5, av6, av7, av8;
    Liste_avion *nv1, *nv2, *nv3, *nv4, *nv5, *nv6, *nv7, *nv8;
    
    char id[20];
    int carb;
    char cmp[20];
    
    //Avion1
    strcpy(id, "Boieng56_12xC4");
    carb = 43;
    strcpy(cmp, "Transavia");
    av1 = creer_avion(id, carb, cmp); //initialisation de la struct avion
    nv1 =  creer_element_liste(av1); //initialise la liste chainée
    liste_cmp = add_element(liste_cmp, nv1); //ajouter le nouvel élément

    //avion2
    strcpy(id, "Boieng52_93Hk8");
    carb = 84;
    strcpy(cmp, "RAM");
    av2 = creer_avion(id, carb, cmp);
    nv2 =  creer_element_liste(av2);
    liste_cmp = add_element(liste_cmp, nv2); 

    //avion3
    strcpy(id, "Boieng34_Th07x");
    carb = 62;
    strcpy(cmp, "Transavia");
    av3 = creer_avion(id, carb, cmp);
    nv3 =  creer_element_liste(av3);
    liste_cmp = add_element(liste_cmp, nv3); 

    //avion4
    strcpy(id, "Boieng7_Z72gd0");
    carb = 55;
    strcpy(cmp, "RAM");
    av4 = creer_avion(id, carb, cmp);
    nv4 =  creer_element_liste(av4);
    liste_cmp = add_element(liste_cmp, nv4); 

    //Avion5
    strcpy(id, "Boieng528_FvJ7");
    carb = 42;
    strcpy(cmp, "Transavia");
    av5 = creer_avion(id, carb, cmp);
    nv5 =  creer_element_liste(av5);
    liste_cmp = add_element(liste_cmp, nv5); 

    //avion6
    strcpy(id, "Boieng627_2Gf5R");
    carb = 58;
    strcpy(cmp, "RAM");
    av6 = creer_avion(id, carb, cmp);
    nv6 =  creer_element_liste(av6);
    liste_cmp = add_element(liste_cmp, nv6); 

    //avion7
    strcpy(id, "Boieng17_AKA71");
    carb = 67;
    strcpy(cmp, "Transavia");
    av7 = creer_avion(id, carb, cmp);
    nv7 =  creer_element_liste(av7);
    liste_cmp = add_element(liste_cmp, nv7); 

    //avion8
    strcpy(id, "Boieng90hd_GZ1");
    carb = 25;
    strcpy(cmp, "RAM");
    av8 = creer_avion(id, carb, cmp);
    nv8 =  creer_element_liste(av8);
    liste_cmp = add_element(liste_cmp, nv8); 

    return liste_cmp;
}

Liste_avion *afficher_caract (char cmp[20], Liste_avion *tete)
{
    Liste_avion *tmp;
    tmp = tete;
    //char var[20];

    if(tmp == NULL)
    {
        printf("La liste est vide\n");
    }

    else 
    {
        while(tmp != NULL)
        {
            if(strcmp(tmp->donnee.compagnie, cmp) == 0)
            {
                printf("Le nom de l'avion est : %s\n", tmp->donnee.identifiant);
                printf("Le pourcentage de carburant est : %d\n\n", tmp->donnee.carburant);
            }
        }
    }
}
*/

Liste_avion *ajouter_cmp (Liste_avion *tete, Liste_avion *nouveau)
{
    Liste_avion *tmp = NULL;

    if(tete == NULL)
        {
            tete = nouveau;
        }

        else 
        {
            tmp = tete;

            while(tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = nouveau;
        }

        return tete;
}

int ajouter_listeNoire(char liste_noire[100][100], char cmp[100], int n)
{
    strcpy(liste_noire[n], cmp);
    n++;
    return n;
}

void afficher_listeNoire(char liste_noire[100][100], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%s",liste_noire[i]);
        printf("\n");
    }
}

Liste_avion *prior_LN (Liste_avion *tete, char cmp[100])
{
    Liste_avion *tmp;

    if(tete == NULL)
    {
        printf("La liste est vide\n");
    }

    else 
    {
        tmp = tete; 

        while(tmp != NULL)
        {
            if(strcmp(tmp->donnee.compagnie,cmp) == 0)
            {
                tmp->priorite = 1;
            }
            tmp = tmp->next;
        }
    }

    return tete;
}

Liste_avion *suppr_LN_Dec (Liste_avion *tete, char cmp[20])
{
    Liste_avion *tmp, *tmp2;
    tmp = tete;

    if(tete == NULL)
    {
        printf("La liste est vide\n");
    }

    else 
    {
        while(tmp != NULL) 
        {
            if(strcmp((tmp->next)->donnee.compagnie, cmp) == 0)
            {
                tmp2 = (tmp->next)->next;
                tmp->next = tmp2;
            }
            tmp = tmp->next;
        }

        if(tmp == NULL)
        {
            printf("La compagnie est inexistante\n");
        }
    }

    return tete;
}


//pb liée à la fonction supp_LN et afficher_LN 
    int menu (Liste_avion *avion_dec, Liste_avion *avion_att)//, Liste_avion *liste_cmp) 
    {
        avion av;
        Liste_avion *nouveau;
        Liste_avion *tete;
        int carb, nbr, end, i; //num_caract, num_saisi, size;
        char id[20], cmp[20], liste_cmp_avion[20];
        char liste_N[100][100];
        //char cmp_LN[100]={"Transavia"};
        int len;


        system("clear");
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("- Ajouter des avions en attente de décollage -------------------- 1\n");
        printf("- Ajouter des avions en attente d'atterrissage sans préciser le\n");      
        printf("  pourcentage de carburant -------------------------------------- 2\n");
        printf("- Supprimer un avion en attente de décollage -------------------- 3\n");
        printf("- Supprimer un avion en attente d'atterrissage\n"); 
        printf("  pour des causes météorologique -------------------------------- 4\n");
        printf("- URGENCE : priorité aux avions en attente d'atterissage -------- 5\n");
        printf("- Mettre un avion sur la liste noire ---------------------------- 6\n");
        printf("- Afficher les caractéristiques des avions d'une compagnie ------ 7\n");
        printf("- Afficher la liste des avions en attente de décolage ----------- 8\n");
        printf("- Afficher la liste des avions en attente d'atterrissage -------- 9\n");
        printf("- Afficher l'historique d'utilisation de la piste d'aéroport ---- 10\n");
        printf("\nVotre choix est : ");

        scanf("%d", &nbr);
        system("clear");

        //display(liste_avion);


        switch(nbr)
        { 
             case 1 : 
                av = saisir_caract_dec (avion_dec, nouveau, carb, id, cmp);
                nouveau =  creer_element_liste(av); //initialise la liste chainée
                avion_dec = add_element(avion_dec, nouveau);
            break;

            case 2 :   
                av = saisir_caract_att (avion_att, nouveau, carb, id, cmp);
                nouveau =  creer_element_liste(av); //initialise la liste chainée
                avion_att = add_element(avion_att, nouveau);
            break;

            case 3 : 
                printf("Veuillez saisir l'identifiant de l'avion que vous souhaitez supprimer : ");
                scanf("%s", id);
                avion_dec = supp_id (avion_dec, id);
            break;

            case 4 : 
                printf("Veuillez saisir l'identifiant de l'avion que vous souhaitez supprimer à cause de problèmes météorologique : ");
                scanf("%s", id);
                avion_dec = supp_id (avion_att, id);
            break;
            
            case 5 : 
                avion_att = prioritaire (avion_att);
                display(avion_att);
            break;
            
            case 6 : //faire supprimer les avions qui allaient décoller et atterir de cette compagnie                 
                printf("Veuillez saisir le nom de la compagnie que vous souhaitez faire passer dans la liste noire : ");
                scanf("%s", cmp);
                printf("%s", cmp);
                
                len = 2;
                len = ajouter_listeNoire(liste_N, cmp, len);
                afficher_listeNoire(liste_N, len);
                avion_att = prior_LN (avion_att, cmp); 
                printf("La liste d'atterrissage est :\n");
                display(avion_att);
                printf("-----------------------------------------------------------------\n");
                avion_dec = suppr_LN_Dec(avion_dec, cmp);
                printf("La liste de décollage est :\n");
                display(avion_dec);
            break;
            
            case 7 : 
                printf("Veuillez saisir le nom de la compagnie dont vous souhaitez afficher les caractéristiques : ");
                scanf("%s", cmp);
                //liste_cmp = init_avion_cmp(liste_cmp);
                //afficher_caract (cmp, liste_cmp);
            break;

            case 8 :
                display(avion_dec);
            break;
            
            case 9 : 
                system("clear");
                avion_att = init_dec(avion_att);
                display(avion_att);
            break;

            case 10 : 
                system("cat ./aeroport_log.txt");
            break;

            default : 
                printf("Une erreur est survenue, veuillez rééssayer svp\n");
            break;
        }

        sleep(3);
        printf("\nSouhaitez-vous revenir au menu (tapez 1) ou souhaitez vous le quittez (tapez 2)?\n");
        scanf("%d", &end);

        while(end == 1)
        {
            menu(avion_dec, avion_att);//, liste_cmp);
        }

        if(end == 2)
        {
            return 0;
        }
    }



    /*
Liste_avion *supp (Liste_avion *tete)
{
    if(tete == NULL)
    {
        printf("La liste est vide\n");
    }

    else    
    {
        tete = tete->next;   
    }

    return tete;
}

void display_cmp (Liste_avion *tete, char cmp[20])
{
    Liste_avion *tmp, *tmp2;
    tmp = tete;

    if(tete == NULL)
    {
        printf("La liste est vide\n");
    }

    else 
    {
        printf("Veuillez saisir la compagnie de l'avion que vous souhaitez afficher : ");
        scanf("%s", cmp);

        while(tmp != NULL) 
        {
            if(strcmp((tmp->next)->donnee.compagnie, cmp) == 0)
            {
                display(tete);
                break;
            }
            tmp = tmp->next;
        }

        if(tmp == NULL)
        {
            printf("La compagnie n'a pas de caractéristiques précisé sur ces avions\n");
        }
    }
}
*/
