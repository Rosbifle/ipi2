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

typedef struct Historique{
	action Play;
	struct Historique * next;
} Historique;

void lib_grille(grille* g);
tuile tuile_random();
hand init_hand(int n);
void pose_tuile(grille* g, tuile t, int x, int y);
grille init_grid(int sz);