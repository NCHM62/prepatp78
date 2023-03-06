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
	}
}

void chargement(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i=0;
fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	do
		{

		fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
		i++;
		}
		while(!feof(fic));
	fclose(fic);
	ptrB->nbLivres=i-1;
	puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");

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
		{
			afficherLivre( &(ptrB->etagere[i])  );
			compteur++;
		}
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

int Emprunt_Livre(T_Bibliotheque *ptrB)
{
	char M_Code[MAX_CODE];
	char M_Emprunteur[MAX];
	lireChaine("Donnez le code du livre a  rechercher: ", M_Code, MAX_CODE);
	for (int i = 0; i <= ptrB->nbLivres; i++)
	{
		if (!(strcmp(ptrB->etagere[i].code, M_Code)))
		{	
			//printf(">%d<\n",strcmp(ptrB->etagere[i].emprunteur.nomemprunteur, ""));
			if (strcmp(ptrB->etagere[i].emprunteur.nomemprunteur, "")==0)
			{
				lireChaine("Donnez votre Prenom et NOM sous la forme: \"Prenom NOM\" :", M_Emprunteur, MAX);
				strcpy((*ptrB).etagere[i].emprunteur.nomemprunteur, M_Emprunteur);
				//date empreint
				lireDateSysteme(&((*ptrB).etagere[i].emprunteur));
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
	lireChaine("Donnez le code du livre a  rendre: ", M_Code, MAX_CODE);
	for (int i = 0; i <= ptrB->nbLivres; i++)
	{
		if (!(strcmp(ptrB->etagere[i].code, M_Code)))
		{
			if (!(strcmp(ptrB->etagere[i].emprunteur.nomemprunteur, "")))
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
