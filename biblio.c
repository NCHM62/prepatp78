# include "biblio.h"
void sauvegarde(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i;
fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	for(i=0;i<ptrB->nbLivres;i++)
		{
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

		}
	fclose(fic);
	puts("SAUVEGARDE REUSSIE ..............");
	

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
int supprimerLivre(T_Bibliotheque  *ptrB, T_Titre tit){
	int indice,cpt;
	cpt=rechercherLivre(ptrB,tit);
	if(cpt==0)
		return -1;
	else{
		indice=rechercherParIndice(ptrB,tit);
		ptrB->etagere[indice]=ptrB->etagere[indice+1];
		ptrB->nbLivres--;
		}
	return 0;
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
char *format_tri(char titre[MAX_TITRE], char temp1[MAX_TITRE])
{
	strcpy(temp1, titre);
	for (int i = 0; temp1[i] != '\0'; i++)
	{
		if (temp1[i] >= 'A' && temp1[i] <= 'Z')
		{
			temp1[i] += 32;
		}
	}

	return temp1;
}
int tri_Titre(T_Bibliotheque *ptrB)
{
	T_livre aux;
	char temp1[MAX_TITRE];
	char temp2[MAX_TITRE];
	int j;
	int i;
	for ( i = 0; i < ptrB->nbLivres; i++)
	{
		j = i;
		while ((j > 0) && (strcmp(format_tri(ptrB->etagere[j - 1].titre, temp1), format_tri(ptrB->etagere[j].titre, temp2))) > 0)
		{ 
			aux = ptrB->etagere[j];
			ptrB->etagere[j] = ptrB->etagere[j - 1];
			ptrB->etagere[j - 1] = aux;
			j--;
		}
	}
	return 1;
}
int tri_auteur(T_Bibliotheque *ptrB)
{T_livre aux;
	char temp1[MAX_TITRE];
	char temp2[MAX_TITRE];
	int j;
	int i;
	for ( i = 0; i < ptrB->nbLivres; i++)
	{
		j = i;
		while ((j > 0) && (strcmp(format_tri(ptrB->etagere[j - 1].auteur, temp1), format_tri(ptrB->etagere[j].auteur, temp2))) > 0)
		{ 
			aux = ptrB->etagere[j];
			ptrB->etagere[j] = ptrB->etagere[j - 1];
			ptrB->etagere[j - 1] = aux;
			j--;
		}
	}
	return 1;
	
	
}

void init (T_Bibliotheque *ptrB)
{ //hello

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}




