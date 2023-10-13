#include "fonctions.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//Recuperation du prochain matricule
int Matricule()
{
FILE *f = fopen("matricule","r");
int matricule;
fscanf(f,"%d",&matricule);
fclose(f);

f = fopen("matricule","w");
fprintf(f,"%d",matricule+1);
fclose(f);
printf("matricule a utiliser est %d\n",matricule);
return matricule;
}

//Fonction d'ajout de VDP
void vdpAfara(vdp *v)
{
FILE *f = fopen("vdpfile","a");
fwrite(v,sizeof(vdp),1,f);
fclose(f);
}

//Fonction pour afficher la liste de tous les VDP depuis le fichier
void vdpListing(){   
vdp *v =(vdp*) malloc(sizeof(vdp));

FILE *f = fopen("vdpfile","r");

if(f!=NULL)
{
printf("*****LISTE DES VDP*****\n");
printf("%-10s\t %-10s\t %-10s\n","Nom","Prenom","Date de recrutement");

while (fread(v,sizeof(vdp),1,f) && !feof(f))
{
 printf("%-10s\t %-10s\t %10d/%d/%d\n",v->nom,v->prenom,v->daterecru.jour,v->daterecru.mois,v->daterecru.annee);
}
fclose(f);
}

else
{
  printf("Fichier inexistant\n");
  EXIT_FAILURE;
}

}

//Fonction pour charger la liste des vdp dans une liste chainée
listevdp *Load  (){   
   
vdp *v =(vdp*) malloc(sizeof(vdp));
listevdp *lvpd = (listevdp*) malloc(sizeof(listevdp));
lvpd->premier=NULL;

FILE *f = fopen("vdpfile","r");



if(f!=NULL)
{
while (fread(v,sizeof(vdp),1,f) && !feof(f))
{
vdp *vNew =(vdp*) malloc(sizeof(vdp));
strcpy(vNew->nom,v->nom);
strcpy(vNew->prenom,v->prenom);

 vNew->svt=lvpd->premier;
 lvpd->premier=vNew;  
}

fclose(f);
}

else
{
  if(f==NULL)
{
  printf("Fichier inexistant ou erreur d'ouverture\n");
}
}

return lvpd;
}

//Fonction afficher Liste
 void afficherListe(listevdp *lvdp)
 {
     vdp *cur = lvdp->premier;
     while (cur!=NULL)
     {
        printf("%s \t %s\n ",cur->nom,cur->prenom);
        cur=cur->svt;
     }
 }

//Fonction suppression par le debut
void yankerDebut()
{
    listevdp *lvdp=Load();
    vdp *aSup=lvdp->premier;
    lvdp->premier=aSup->svt;
    free(aSup);
    afficherListe(lvdp); 
}

//Fonction de suppression
void yanker(/*listevdp *lvdp,*/char *nomvdp)
{
    listevdp *lvdp=Load();
    vdp *cur=lvdp->premier,*tmp;
    vdp *aSup;
    FILE *f = fopen("vdpfile","w");
//Si le c'est le dernier element
if(cur->svt==NULL)
{
//aSup=cur;
cur=NULL;
}

else{
  //verifier la valeur suivante de lelement courant
while (strcmp(nomvdp,cur->svt->nom)!=0)
    {
        cur=cur->svt;
    }

//c'est lelement suivant qui va etre supprime
    aSup=cur->svt;
 //faire en sorte que le prochain de lelement courant
 //soit le prochain de lelement a supprimer    
    cur->svt=aSup->svt;
    free(aSup);


}
    cur=lvdp->premier;

while (cur!=NULL)
{
     fwrite(cur,sizeof(vdp),1,f);
     cur=cur->svt;
}
fclose(f);

}

//GESTION DU TRI
void echanger(vdp *e1, vdp *e2)
{
  vdp *link;
  link=e1->svt;
  e1->svt=e2->svt;
  e2->svt=link;
}

void trier(/*int ordre*/){
    vdp *cur;
    vdp *tmp;
    int permuter;
    listevdp *lvdp = Load();
    printf("Liste a trier est \n");
    afficherListe(lvdp);
    do
    {
        printf("dans la boucle\n");
        permuter=0;
        cur=lvdp->premier;
        printf("verif first vdp Nom = %s\n",cur->nom);
          while (cur->svt!=NULL)
        {
            printf("dans la deuxieme boucle\n");
            if( strcmp(cur->nom,cur->svt->nom)<0)
                {
                 echanger(cur,cur->svt);
                 permuter = 1;
                }   
       cur=cur->svt;
         }

    } while (permuter);   

    afficherListe(lvdp);
}


void echangesimple(vdp *v1, vdp *v2)
{
 vdp *tmp=(vdp*)malloc(sizeof(vdp));
 strcpy(tmp->nom,v1->nom);   
 strcpy(tmp->prenom,v1->prenom);   

strcpy(v1->nom,v2->nom);   
  strcpy(v1->prenom,v2->prenom);   

  strcpy(v2->nom,tmp->nom);   
  strcpy(v2->prenom,tmp->prenom);   
}

void triSimple()
{
    vdp *cur;
    listevdp *lvdp = Load();
    afficherListe(lvdp);
    int permuter;
    do
    {
        permuter=0;
        cur=lvdp->premier;
          while (cur->svt!=NULL)
        {
        if( strcmp(cur->nom,cur->svt->nom)>0 ) {

         echangesimple(cur,cur->svt);
          permuter = 1;
        }
        cur=cur->svt;
     }    
    } while (permuter);   

printf("Liste triee est \n");
    afficherListe(lvdp);
}

/////////////////////Importation de vdp////
void importerVpd(char *nomfichier)
{
  printf("Appel fonction importer\n");
//FILE *f = fopen("vdfile","a");
FILE *f1 = fopen(nomfichier,"r");

if(f1!=NULL)
printf("ouverture de %s\n",nomfichier);
else
printf("Erreur \n");


char nom[20],prenom[20];

printf("%-10s %-10s\n","Nom","Prenom");

    while (fscanf(f1,"%s %s",nom,prenom) !=EOF)
{
  printf("dans la boucle\n");
  vdp *v =(vdp*) malloc(sizeof(vdp));
strcpy(v->nom,nom);
strcpy(v->prenom,prenom);
   printf("%-10s %-10s\n",nom,prenom);
   vdpAfara(v);


}
}

void rechercher(int matricule)
{
  FILE *f = fopen("vdpfile","r");
  vdp *v = (vdp*)malloc(sizeof(vdp));
int nontrouve=1;
while (fread(v,sizeof(vdp),1,f) && !feof(f) && nontrouve)
{
  
  if (v->matricule==matricule)
  {
    printf("les infos du vdp du matricule %d sont :\n",matricule);
    printf("Nom : %s\n",v->nom);
    printf("Nom : %s\n",v->prenom);
    nontrouve=0;
  }
  
}
if (nontrouve)
{
  printf("Desole VDP non retrouve\n");
}


}

int menu()
{
    int c;

    printf("1- Ajouter un VDP\n");
    printf("2- Afficher la liste des VDP\n");
    printf("3- supprimer vdp\n");
    printf("4- suppimer debut\n");
    printf("5- trier\n");
    printf("Importer\n");
    printf("7-Rechercher un VDP\n");
    printf("9- Quitter\n");
    printf("Votre choix\n");
    scanf("%d",&c);
    return c;
}