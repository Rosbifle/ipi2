#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum rot {rot_0, rot_90, rot_180, rot_270};
typedef struct {
    char id;
 } cell ;

typedef struct prout{
    int id;
    int orientation;
    cell c[6];
} tuile;

typedef struct {
    int sz;
    cell** grid;
} grille;

typedef struct {
    int sz;
    tuile* deck;
} hand;

/* prend en argument une taille, renvoie un malloc n*n de cellules*/
grille init_grid_empy(int sz){
    grille g;
    g.sz=sz;
    g.grid=(cell**)malloc(sz*sizeof(cell*));
    int i;
    int j;
    for(i=0;i<sz;i++){
        g.grid[i]=(cell*)malloc(sz*sizeof(cell));
        for(j=0;j<sz;j++){
            g.grid[i][j].id='v';
        }
    }
    return g;
}

/* libère la grille pointée par g*/
void lib_grille(grille* g){
    free(g);
}

/* génère un nombre random entre 0 et n-1*/
int randint(int n){
    return rand()%n;
}

/* génère une tuile random*/
tuile tuile_random(){
    /*des trucs ici*/
    int l[6]={102, 108, 112, 114, 117, 118};
    tuile t;
    int i;
    for(i;i<6;i++){
        t.c[i].id=(char)l[randint(6)];
    }
    return t;
}

/* initialise une main de n cartes*/
hand init_hand(int n){
    hand h;
    h.sz=n;
    h.deck=(tuile*)malloc(n*sizeof(tuile));
    int i;
    for(i;i<h.sz;i++){
        h.deck[i]=tuile_random();
    }
    return h;
}

int main(){
    srand(time(NULL));
    printf("%i, %i, %i, %i, %i, %i", 'p', 'v', 'u', 'l', 'f', 'r');
    return 0;
}