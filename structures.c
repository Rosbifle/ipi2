#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum rot {rot_0, rot_90, rot_180, rot_270};

typedef struct{
    int id;
    int orientation;
    char terrains[6];
} tuile;

typedef struct {
    int sz;
    char** grid;
} grille;

typedef struct {
    int sz;
    tuile* deck;
} hand;

/* prend en argument une taille, renvoie un malloc n*n de cellules*/
grille init_grid_empy(int sz){
    grille g;
    g.sz=sz;
    g.grid=(char**)malloc(sz*sizeof(char*));
    int i;
    int j;
    for(i=0;i<sz;i++){
        g.grid[i]=(char*)malloc(sz*sizeof(char));
        for(j=0;j<sz;j++){
            g.grid[i][j]='v';
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
    for(i=0;i<6;i++){
        t.terrains[i]=(char)l[randint(6)];
    }
    return t;
}

/* initialise une main de n cartes*/
hand init_hand(int n){
    hand h;
    h.sz=n;
    h.deck=(tuile*)malloc(n*sizeof(tuile));
    int i;
    for(i=0;i<h.sz;i++){
        h.deck[i]=tuile_random();
    }
    return h;
}

int main(){
    srand(time(NULL));
    hand h=init_hand(4);
    int i;
    int j;
    for(i=0;i<4;i++){
        for(j=0;j<6;j++){
            printf("%c ",h.deck[i].terrains[j]);
        }
        printf("\n");
    }
    return 0;
}