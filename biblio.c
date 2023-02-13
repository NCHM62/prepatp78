# include "biblio.h"

int chercherLivreaut(T_Bibliotheque  *ptrB)
{

	int i;
while( strcmp((ptrB->etagere[i]).titre),ptrL->auteur) != 0)
	i++;
if(strcmp((ptrB->etagere[i]).titre),ptrL->auteur) == 0)
	return 1;
else
 	return 0;	
	
	
}
// il faut remplacer le livre à supprimer par le dernier livre

int supprimer (T_Bibliotheque  *ptrB)
{ while( strcmp((ptrB->etagere[i]).titre),ptrL->titre) != 0)
	i++;
if(strcmp((ptrB->etagere[i]).titre),ptrL->titre) == 0)   
 *ptrB=*T_tabloDeLivres[ptrB->nbLivres];
}



int  chercherLivre( T_Bibliotheque  *ptrB, char* titre)
{ int i=0, compteur=0;
while( i < ptrB->nbLivres){
	
	if(strcmp((ptrB->etagere)[i].titre),titre) == 0)
		compteur++;
	i++;
}
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


