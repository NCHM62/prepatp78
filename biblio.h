#define CAPACITE_BIBLIO 10 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
int  chercherLivre( T_Bibliotheque  *ptrB, char* titre);
int supprimerLivre(T_Bibliotheque  *ptrB, T_Titre tit);
int Emprunt_Livre(T_Bibliotheque *ptrB);
int Rendre_Livre(T_Bibliotheque *ptrB);
int rechercherParIndice(const T_Bibliotheque  *ptrB, T_Titre tit);
int tri_Titre(T_Bibliotheque *ptrB);
int tri_auteur(T_Bibliotheque *ptrB);
int tri_annee(T_bibliotheque *ptrB);
#endif
