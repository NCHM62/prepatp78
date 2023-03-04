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
int  chercherLivre( T_Bibliotheque  *ptrB, char* titre);
int  chercherLivreaut( T_Bibliotheque  *ptrB, char* auteur);
int supprimerLivre(T_Bibliotheque  *ptrB, char* titre);
#endif
