
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
