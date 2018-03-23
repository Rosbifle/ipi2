/**
 * \file save.h
 * 
 * 3 fonctions
 * 
 * - char * tuile_toString(tuile t) : Affiche une tuile
 * - int save(action historique, hand main) : Sauvegarde une tuile dans le fichier save_honshu.txt
 * - action load(hand * main) : Charge une partie
 */

#include "structures.h"
#include <string.h>

char * tuile_toString(tuile t);

int save(action historique, hand main);

action load(hand * main);
