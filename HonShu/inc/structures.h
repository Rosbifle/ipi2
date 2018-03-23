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
    tuile* deck;
} hand;

struct Historique{
  action Play;
  struct Historique* next;
} ;
typedef struct Historique historique;
typedef historique* hlist;

grille init_grid(int sz);
historique* init_historique();
action init_action(tuile tuile, int coord[2], int orientation);
tuile tuile_random(); 
void lib_grille(grille * g);
void add(action a, historique** h);
action pop(historique** h);
hand init_hand(int n);
int read_terrain(grille g, int x, int y);
action* action_create(tuile t, int x, int y, enum pos rot_a);
int pose_tuile_histo(grille g, tuile t, int x, int y, historique* historique,enum pos rot_a);
int pose_tuile(grille g, tuile t, int x, int y,enum pos rot_a);
int pose_tuile_histo_action(grille g, hlist historique, action act);

int ret_last_tuil(grille g, hlist hist ,int sz, enum pos rot_a);


/**
 * \file manipulation.h
 * 
 * 5 fonctions
 * 
 * - int read_terrain(int x, int y) : ECRIRE
 * - void action_add(tuile t, int x, int y, historique* historique,enum pos rot_a) : ECRIRE
 * - int pose_tuile_histo(grille* g, tuile t, int x, int y, historique* historique, enum pos rot_a) : ECRIRE
 * - int pose_tuile(grille* g, tuile t, int x, int y) : ECRIRE
 * - int ret_last_tuil(grille* g, historique* historique ,int sz) : ECRIRE
 */



