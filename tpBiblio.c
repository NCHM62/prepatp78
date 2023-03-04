// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

int menu()
{
	int choix;
// au programme du TP7 :
printf("\n\n 1 - Ajouter un nouveau livre dans la bibliothèque "); 
printf("\n 2 - Afficher tous les livres de la bibliothèque "); 
printf("\n 3 - Rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - Rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - Supprimer un livre de la bibliothèque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


// au programme du TP8 :
// ajouter le champ emprunteur à votre structure T_Livre
/*
printf("\n 6 - Emprunter un livre de la bibliothèque");
printf("\n 7 - Restituer/rendre un livre de la bibliothèque");
printf("\n 8 - Trier les livres (par titre)");
printf("\n 9 - Trier les livres (par auteur)");
printf("\n 10 - Trier les livres (par année)");
*/
// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
// printf("\n 11- Lister les livres disponibles "); 
// printf("\n 12 - Lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
return choix;


}



int main()
{
int reponse,chx;
T_Titre titre;
T_Aut auteur;
T_Bibliotheque B; 
init( &B );

do
{
chx= menu();
switch(chx)
	{
	case  1 : reponse = ajouterLivre(&B);
				if (reponse==1)
					printf("\n Ajout réussi !!!\n");
					else
					printf("\nImpossible d'ajouter (bibliotheque pleine)\n");
			break;
	case 2 : reponse=afficherBibliotheque(&B);
			if (reponse==0)	
					printf("\nLa bibliotheque est vide\n");

			break;	
	case 3: 
		printf("\nSaisir le titre du livre : ");
		lire(titre,60);
		reponse=chercherLivre(&B,titre);
			
		if (reponse>=1)
				printf ("\nLe livre est dans la biblio, en %d exemplaire(s)",reponse);
		else
				printf("\nLe livre n'est pas dans la biblio");
		break;
	case 4:
		printf("\nSaisir le nom de l'auteur : ");
		lire(auteur,60);
		reponse=chercherLivreaut(&B,auteur);
		
		if (reponse>=1)
				printf ("\nLe ou les livre(s) de l'auteur sont dans la biblio, en %d exemplaire(s)\n",reponse);
		else
				printf("\nLe ou les livres de l'auteur ne sont pas dans la biblio\n");
		
			break;
	
	case 5:
			/*supprimerLivre(&B);*/
			printf("\nSaisir le titre du livre : ");
			lire(titre,60);
			reponse=supprimerLivre(&B, titre);
			if (reponse>0)
				printf ("Le livre a été supprimé %d fois dans la bibliothéque", reponse);
			else if(reponse==0)
				printf("Le livre n'a pas été supprimé");
			break;
	
	
	
	
	}

}while(chx!=0);






return 0;

}

