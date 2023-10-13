#include "structures.h"

#ifndef Fonctions_H
#define Fonctions_H

int menu ();
void vdpAfara(vdp *v);
void vdpListing();
// listevdp* chargerListe();
listevdp* Load();
void afficherListe(listevdp *lvdp);
//void yanker(listevdp *lvdp,char *nomvdp);
void yanker(char *nomvdp);
void yankerDebut();
void trier(/*int ordre*/);
void triSimple();
void importerVpd();
int  Matricule(); //Fonction pour retrouver le matricule a utiliser lors de l'ajout d'un vdp
void rechercher(int matricule);
#endif