# include "biblio.h"


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


int  chercherLivre( T_Bibliotheque  *ptrB)
{ int i;
 int RepeatLivre = 0;
while( strcmp((ptrB->etagere[i]).titre),ptrL->titre) != 0)
	i++;
if(strcmp((ptrB->etagere[i]).titre),ptrL->titre) == 0)
	do{
		RepeatLivre = RepeatLivre + 1;
		i++;
	}while(strcmp((ptrB->etagere[i]).titre),ptrL->titre) == 0);
	return RepeatLivre;
else
 	return 0;	
}


