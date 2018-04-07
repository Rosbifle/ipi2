/**
 * \file structures.h
 * 
 * 5 type et 7 fonctions
 * 
 * - type \a tuile : Contient 6 caractères parmi : L R U F V P
 * \a action : Contient une tuile , ses coordonnées et son orientation de placement 
 * \a grille : Contient la taille et un tableau n*n
 * \a hand : Contient le nombre de tuiles et une liste de tuiles
 * \a Historique : Une pile d’action 
 * 
 * - void lib_grille(grille* g) : Libère la grille
 * - tuile tuile_random() : Génère une tuile aléatoire 
 * - hand init_hand(int n) : Initialise la liste
 * - void pose_tuile(grille* g, tuile t, int x, int y) : Pose la tuile
 * - grille init_grid(int sz) : Initialise la grille
 * - bool test_zone_limite(action ac, grille g) : Teste si on peut poser la tuile
 * - int village_ville(grille g) : Detecte le plus grand village de la grille
 */
#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum pos {rot_0, rot_90, rot_180, rot_270};

#define bool int
#define true 1
#define false 0

typedef struct{
    int id;
    char terrains[6];
} tuile;

typedef struct {
	tuile t;
	int coord[2];
	int orientation;
} action;

typedef struct {
    int sz;
    char** grid;
} grille;

typedef struct {
    int sz;
    int* disp;
    tuile* deck;
} hand;

struct Historique{
  action Play;
  struct Historique* next;
} ;
typedef struct Historique historique;
typedef historique* hlist;
/*
 *\brief initialise une grille
 *\param la taille de la grille
 *\return une grille
*/
grille init_grid(int sz);
/*
 *\brief initialise un historique
 *\param /
 *\return une adresse vide (dernier élément d'un historique)
*/
historique* init_historique();
/*
 *\brief initialise une action 
 *\param une tuile, sa coordonnée et son orientation de placement
 *\return une action
*/
action init_action(tuile tuile, int coord[2], int orientation);
/*
 *\brief génère une tuile aléatoirement 
 *\param /
 *\return une tuile
*/
tuile tuile_random(); 
/*
 *\brief libère une grille (malloc)
 *\param le pointeur vers cette grille
 *\return /
*/
void lib_grille(grille * g);
/*
 *\brief ajoute une action a à l'historique
 *\param une action, l'adresse de l'adresse vers l'historique
 *\return /
*/
void add(action a, historique** h);
/*
 *\brief  pop la dernière action de l'historique
 *\param l'adresse de l'adresse vers l'historique
 *\return l'action qui a été pop
*/
action pop(historique** h);
/*
 *\brief initialise une main 
 *\param la taille de la main
 *\return une main
*/
hand init_hand(int n);
/*
 *\brief lit la case du terrain de coordonnée donnée 
 *\param une grille, deux coordonnées x et y
 *\return un entier ASCII
*/
int read_terrain(grille g, int x, int y);
/*
 *\brief crée une action
 *\param une grille g, les coordonnées de placement x et y
 *\return une adresse vers l'action créée
*/
action* action_create(tuile t, int x, int y, enum pos rot_a);
/*
 *\brief affiche le contenu d'une tuile 
 *\param une tuile t
 *\return /
*/
void show_tuile(tuile t);
/*
 *\brief pose une tuile et enregistre l'action dans l'historique
 *\param une grille g, une tuile t, des coordonnées x et y, un adresse d'adresse vers un historique, une position
 *\return 0 si ça réussit, 1 si ça rate
*/
int pose_tuile_histo(grille g, tuile t, int x, int y, hlist* historique,enum pos rot_a);
/*
 *\brief pose une tuile simplement
 *\param une grille g, une tuile t, des coordonnées x et y, une position
 *\return 0 si ça réussit, 1 si ça rate
*/
int pose_tuile(grille g, tuile t, int x, int y,enum pos rot_a);
/*
 *\brief alias pour pose_tuile_histo avec une action au lieu des différents 
 *\param prend une grille g, une adresse d'une adresse vers un historique et une action
 *\return 0 si ça réussit, 1 si ça rate
*/
int pose_tuile_histo_action(grille g, hlist* histo, action act);
/*
 *\brief retire la dernière tuile
 *\param une grille, une adresse vers une adresse d'une liste, la taille et la position de la dernière tuile
 *\return 0 si ça réussit, 1 si ça rate
*/
int ret_last_tuil(grille g, hlist hist ,int sz, enum pos rot_a);



#endif
