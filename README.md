# ipi2
Projet IPI S2

J'ai créé une branch 'developing' sur laquelle on taffe. on travaille sur developing et on ne push/commit sur le master que quand ça marche.

Doxgen:
Une module pour le commentaire

11111111pour une fonction:
/**
 *\brief lis la COORDONNEE (x,y) DE LA GRILLE
  \param x>=0 , y>=0 , tableau char * g NOT NULL
 *\return le char en coordonnées (x,y) de la grille g
*/

22222222pour un .h:
/**
 * \file structuile.h
 * 
 * 1 type et 3 fonctions
 * 
 * - type \a tuile : pointeur vers une structure contenant 
 * \a point : un tableau de char 3x2 
 * \a pos : un couple d'int pour la position de la tuile
 * \a num : l'identifiant unique de la tuile
 * \a ort : orientation de la tuile
 * 
 * - ini_tuile(void) : génère une tuile aléatoirement
 * - initi_tuiles(nb_tuile) : génère nb_tuile aléatoirement
 * - initi_tuiles_fichier( FILE* fp) : génère les tuiles à partir d'un fichier
 */

3333333 il faut copier ce que vous avez ecrire devant la fonction sur celle dans le fichier .h
