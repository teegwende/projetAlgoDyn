#ifndef Structures_H
#define Structures_H

typedef struct dateRecru dateRecru;


struct dateRecru
{
    int jour;
    int mois;
    int annee;
};

typedef struct vdp vdp;
struct vdp
{
    int matricule;
    char nom[20];
    char prenom[30];
    dateRecru daterecru;
    vdp *svt;
};

typedef struct listevdp listevdp;
struct listevdp
{
    vdp *premier;
};

#endif