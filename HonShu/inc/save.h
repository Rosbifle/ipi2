/**
 * \file save.h
 * 
 * 3 fonctions
 * 
 * - char * tuile_toString(tuile t) : ECRIRE
 * - int save(action historique, hand main) : ECRIRE
 * - action load(hand * main) : ECRIRE
 */

#include "structures.h"
#include <string.h>

char * tuile_toString(tuile t);

int save(action historique, hand main);

action load(hand * main);