/**
 * \file jugement.h
 * 
 * 2 fonctions
 * 
 * - bool test_zone_limite(action ac, grille g) : ECRIRE 
 * - int village_ville(grille g) : ECRIRE
 */
#ifndef STRUCTURES_H
#define STRUCTURES_H
#include<stdio.h>
#include<stdlib.h>
#include"structures.h"

bool test_zone_limite(action ac, grille g);
int village_ville(grille g);
bool posable(grille g, tuile t, int x, int y, enum pos rot_a );

#endif
