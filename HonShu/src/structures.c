#include "structures.h"

/* prend en argument une taille, renvoie un malloc n*n de char*/
grille init_grid(int sz){
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
    pose_tuile(&g, tuile_random(), (sz-1)/2-1, (sz-1)/2-1);
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

void add(action a, historique** h){
    historique* newHist=malloc(sizeof(historique));
    newHist->next=*h;
    newHist->Play=a;
    *h=newHist;
}

void pop(historique** h){
    action a=(*h)->Play;
    (*h)=(*h)->next;
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
