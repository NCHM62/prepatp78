# include "biblio.h"


int  chercherLivre( T_Bibliotheque  *ptrB, char* titre)
{ 
int i=0, compteur=0;
while( i < ptrB->nbLivres){
	
	if((strcmp(((ptrB->etagere)[i].titre),titre) == 0))
		compteur++;
	i++;
};
return compteur;
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
	int i=0, compteur=0;
	while( i < ptrB->nbLivres){
	
		if((strcmp(((ptrB->etagere)[i].titre),titre) == 0))
		{
			compteur++;
			/*aux = (ptrB->etagere)[i].titre
			(ptrB->etagere)[i] = (ptrB->etagere)[i + 1];*/
			//Remplacer le livre supprimé (position i) par le livre (position : i+1) [A terminer]
		}													
		i++;
	}
	return compteur;
}

/*
int supprimerLivre(T_Bibliotheque *ptrB) [code de Meryem]
{

    int i = 0, cmp;
    char M_Titre[MAX_TITRE];
    printf("\n Quel livre?");
    lireChaine("\n Saisir le titre du livre pour une supression. ", M_Titre, MAX_TITRE);
    while (i != ptrB->nbLivres + 1)
    {
        cmp = strcmp(M_Titre, (ptrB->etagere[i].titre));
        if (cmp == 0 && i != (ptrB->nbLivres) + 1)
        {
            while (i != ptrB->nbLivres)
            {

                ptrB->etagere[i] = ptrB->etagere[i + 1];
                i++;
            }
            (ptrB->nbLivres)--;
            return 1;
        }
        if (cmp == 0 && i == (ptrB->nbLivres) + 1)
        {

            ptrB->etagere[i] = ptrB->etagere[i + 1];
            (ptrB->nbLivres)--;
        }
        i++;
    }
    return 0;
}
*/
