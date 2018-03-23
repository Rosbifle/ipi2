/**
 * \file structures.h
 * 
 * 5 type et 7 fonctions
 * 
 * - type \a tuile : ECRIRE 
 * \a action : ECRIRE 
 * \a grille : ECRIRE
 * \a hand : ECRIRE
 * \a Historique : ECRIRE
 * 
 * - void lib_grille(grille* g) : ECRIRE 
 * - tuile tuile_random() : ECRIRE
 * - hand init_hand(int n) : ECRIRE
 * - void pose_tuile(grille* g, tuile t, int x, int y) : ECRIRE
 * - grille init_grid(int sz) : ECRIRE 
 * - bool test_zone_limite(action ac, grille g) : ECRIRE
 * - int village_ville(grille g) : ECRIRE
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
    int orientation;
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

void lib_grille(grille* g);
tuile tuile_random();
hand init_hand(int n);
void pose_tuile(grille* g, tuile t, int x, int y);
grille init_grid(int sz);
bool test_zone_limite(action ac, grille g);
int village_ville(grille g);


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

#include"structures.h"

int read_terrain(grille g, int x, int y);
void action_add(tuile t, int x, int y, historique* historique,enum pos rot_a);
int ret_last_tuil(grille* g, historique* historique ,int sz);
