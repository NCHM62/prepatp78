#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("\nTITRE : ", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR : ", (ptrL->auteur), MAX);
/*lireChaine("EDITEUR : ", (ptrL->editeur), MAX);
lireChaine("ANNEE : ", (ptrL->annee), MAX);*/
}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("\nTITRE :", (ptrL->titre));
afficherChaine("\nAUTEUR :", (ptrL->auteur));
/*lireChaine("\nEDITEUR : ", (ptrL->editeur));
lireChaine("\nANNEE : ", (ptrL->annee));*/
printf("\n");
}
