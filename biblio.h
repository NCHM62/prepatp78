#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 10 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void lireDateSysteme(T_Emp *E);
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
int  chercherLivre( T_Bibliotheque  *ptrB, char* titre);
int  chercherLivreaut( T_Bibliotheque  *ptrB, char* auteur);
int supprimerLivre(T_Bibliotheque  *ptrB, char* titre);
int Emprunt_Livre(T_Bibliotheque *ptrB);
int Rendre_Livre(T_Bibliotheque *ptrB);
char *format_tri(char titre[MAX_TITRE], char temp1[MAX_TITRE]);
int tri_Titre(T_Bibliotheque *ptrB);
int tri_auteur(T_Bibliotheque *ptrB);
int tri_Annee(T_Bibliotheque *ptrB);
int livre_Dispo(T_Bibliotheque *ptrB);
int tri_Code(T_Bibliotheque *ptrB);
void Emprunts_en_retard(T_Bibliotheque* ptrB);
void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
#endif
