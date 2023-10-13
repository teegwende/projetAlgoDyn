#include <stdio.h>
#include "structures.h"
#include <stdlib.h>
#include "fonctions.h"

int main()
{
int choix;
char nomvdp[20];

do
{
    choix = menu();
    
    switch (choix)
{
case 1:
vdp *v =(vdp*) malloc(sizeof(vdp));
v->matricule=Matricule();
    printf("Saisir nom\n");
scanf("%s",v->nom);
   printf("Saisir prenom\n");
scanf("%s",v->prenom);
printf("Saisir date de recrutement\n");
printf("Jour: ");
scanf("%d",&v->daterecru.jour);
printf("\nMois: ");
scanf("%d",&v->daterecru.mois);
printf("\nAnnée: ");
scanf("%d",&v->daterecru.annee);
vdpAfara(v);
    break;

case 2:
vdpListing();
break;

case 3:
 printf("Entrez nom vdp\n");
 scanf("%s",nomvdp);
 yanker(nomvdp);

break;
case 4:
printf("retrait premier element\n");
yankerDebut();
break;

case 5:
triSimple();
break;

case 6:
importerVpd("listevdpimportes");
break;

case 7 :
int matricule;
printf("Indiquer le matricule\n");
scanf("%d",&matricule);
rechercher(matricule);
break;

case 9:
printf("fin programme\n");
break;
default:
printf("Mauvais choix\n");
    break;
}

} while (choix!=9);

}