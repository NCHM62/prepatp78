# include "biblio.h"


int  chercherLivre( T_Bibliotheque  *ptrB, char* titre)
{ 
	int i=0, compteur=0;
	while( i < ptrB->nbLivres){
	
		if((strcmp(((ptrB->etagere)[i].titre),titre) == 0))
			compteur++;
		i++;
		}
	return compteur;
}

void afficherLivreAuteur(T_Bibliotheque *ptrB)
{
	int comparation, i, flag = 0;
	char auteur[MAX_TITRE];
	lireChaine("Saisir le nom de l'auteur dont vous voulez les livres : ", auteur, MAX_TITRE);
	for (i = 0; i < ptrB->nbLivres; i++)
	{
		comparation = strcmp(auteur, (ptrB->etagere[i].auteur));
		if (comparation == 0)
		{
		
			afficherLivre(&(ptrB->etagere[i]));
			flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("Il n'y a pas de livre de cet auteur.");
	}
}
int Emprunt_Livre(T_Bibliotheque *ptrB)
{
	char M_Code[MAX_CODE];
	char M_Emprunteur[MAX];
	lireChaine("Donnez le code du livre a  rechercher: ", M_Code, MAX_CODE);
	for (int i = 0; i <= ptrB->nbLivres; i++)
	{
		if (!(strcmp(ptrB->etagere[i].code, M_Code)))
		{
			if (!(strcmp(ptrB->etagere[i].emprunteur.nomemprunteur, "")))
			{
				lireChaine("Donnez votre Prenom et NOM sous la forme: \"Prenom NOM\" :", M_Emprunteur, MAX);
				strcpy(ptrB->etagere[i].emprunteur.nomemprunteur, M_Emprunteur);

				return 1;
			}
			return -1;
		}
	}
	return 0;
}

int Rendre_Livre(T_Bibliotheque *ptrB)
{
	char M_Code[MAX_CODE];
	lireChaine("Donnez le code du livre a  rendre: ", M_Code, MAX_CODE);
	for (int i = 0; i <= ptrB->nbLivres; i++)
	{
		if (!(strcmp(ptrB->etagere[i].code, M_Code)))
		{
			if (strcmp(ptrB->etagere[i].emprunteur.nomemprunteur, ""))
			{
				strcpy(ptrB->etagere[i].emprunteur.nomemprunteur, "");
				return 1;
			}
			return -1;
		}
	}
	return 0;
}

void init (T_Bibliotheque *ptrB)
{ //hello

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
	if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
		{
		saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
		ptrB->nbLivres++;
		return 1;
		}
	return 0;
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
	int i;
	if(ptrB->nbLivres==0)
		return 0;
		else
			{
			for(i=0;i<ptrB->nbLivres;i++)
				{
				afficherLivre( &(ptrB->etagere[i])  );
			
				}
		return 1;
		}
}

int  chercherLivreaut( T_Bibliotheque  *ptrB, char* auteur)
{ 
	int i=0, compteur=0;
	while( i < ptrB->nbLivres){
	
		if((strcmp(((ptrB->etagere)[i].auteur),auteur) == 0))
			compteur++;
		i++;
		}
	return compteur;
}

int supprimerLivre(T_Bibliotheque  *ptrB, char* titre)
{
    int i = 0, nb_suppressions = 0;
    while (i < ptrB->nbLivres) {
        if (strcmp(ptrB->etagere[i].titre, titre) == 0) {
            // Déplacer tous les livres suivants d'une position vers la gauche
            for (int j = i; j < ptrB->nbLivres - 1; j++) {
                ptrB->etagere[j] = ptrB->etagere[j + 1];
            }
            // Réduire le nombre total de livres dans l'étagère
            ptrB->nbLivres--;
            nb_suppressions++;
        } else {
            i++;
        }
    }
    return nb_suppressions;
}

