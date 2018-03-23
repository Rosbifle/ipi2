#include "./../inc/structures.h"

/* prend en argument une taille, renvoie un malloc n*n de char*/
/**
 *\brief 
  \param 
 *\return 
*/
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
    pose_tuile(g, tuile_random(), (sz-1)/2-1, (sz-1)/2-1, rot_0);
    return g;
}

historique* init_historique(){
    return NULL;
}

/*creer une action*/
/**
 *\brief 
  \param 
 *\return 
*/
action init_action(tuile tuile, int coord[2], int orientation){
    action act;
    act.t = tuile;
    act.coord[0] = coord[0];
    act.coord[1] = coord[1];
    act.orientation = orientation;
    return act;
}

/* libère la grille pointée par g*/
/**
 *\brief 
  \param 
 *\return 
*/
void lib_grille(grille* g){
    int i;
    for(i=0;i<g->sz;i++){
        free(g->grid[i]);
    }
    free(g->grid);
}

/* génère un nombre random entre 0 et n-1*/
/**
 *\brief 
  \param 
 *\return 
*/
int randint(int n){
    return rand()%n;
}

/* génère une tuile random*/
/**
 *\brief 
  \param 
 *\return 
*/
tuile tuile_random(){
    /*102='f', 108='l', 112='p', 114='r', 117='u', 118='v'*/
    int l[6]={102, 108, 112, 114, 117, 118};
    tuile t;
    int i;
    for(i=0;i<6;i++){
        t.terrains[i]=(char)l[randint(6)];
    }
    return t;
}

/**
 *\brief 
  \param 
 *\return 
*/
void add(action a, historique** h){
    historique* newHist=malloc(sizeof(historique));
    newHist->next=*h;
    newHist->Play=a;
    *h=newHist;
}

/**
 *\brief 
  \param 
 *\return 
*/
action pop(historique** h){
    action a=(*h)->Play;
    (*h)=(*h)->next;
    return a;
}

/* initialise une main de n cartes*/
/**
 *\brief 
  \param 
 *\return 
*/
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



/*retourne type de terrains d'une case*/
/**
 *\brief 
  \param 
 *\return 
*/
int read_terrain(grille g, int x, int y){
    return g.grid[x][y];
}

/**
 *\brief 
  \param 
 *\return 
*/
action* action_create(tuile t, int x, int y, enum pos rot_a){
    action* pose=malloc(sizeof(action));
    pose->t=t;
    pose->coord[0]=x;
    pose->coord[1]=y;
    pose->orientation=rot_a;
    return pose;
}

/**
 *\brief 
  \param 
 *\return 
*/
int pose_tuile_histo(grille g, tuile t, int x, int y, hlist* historique,enum pos rot_a){
    if (posable(g , t, x, y,rot_a)==1){
        a = action(t, {x, y}, rot_a);
        add(a, historique);
        if (rot_a==rot_0){
            g.grid[x][y]=t.terrains[0];  
            g.grid[x][y+1]=t.terrains[1];
            g.grid[x][y+2]=t.terrains[2];
            g.grid[x+1][y]=t.terrains[3];
            g.grid[x+1][y+1]=t.terrains[4];
            g.grid[x+1][y+2]=t.terrains[5];
        }    
        if (rot_a==rot_180){
            g.grid[x][y]=t.terrains[5];  
            g.grid[x][y+1]=t.terrains[4];
            g.grid[x][y+2]=t.terrains[3];
            g.grid[x+1][y]=t.terrains[2];
            g.grid[x+1][y+1]=t.terrains[1];
            g.grid[x+1][y+2]=t.terrains[0];
        }   
        if (rot_a==rot_90){
            g.grid[x][y]=t.terrains[3];  
            g.grid[x][y+1]=t.terrains[0];
            g.grid[x+1][y]=t.terrains[4];
            g.grid[x+1][y+1]=t.terrains[1];
            g.grid[x+2][y]=t.terrains[5];
            g.grid[x+2][y+1]=t.terrains[2];
        }
        if (rot_a==rot_270){
            g.grid[x][y]=t.terrains[2];  
            g.grid[x][y+1]=t.terrains[5];
            g.grid[x+1][y]=t.terrains[1];
            g.grid[x+1][y+1]=t.terrains[4];
            g.grid[x+2][y]=t.terrains[0];
            g.grid[x+2][y+1]=t.terrains[3];
        }
        return 0;
    }
    return 1; 
}
/**
 *\brief 
  \param 
 *\return 
*/
int pose_tuile_histo_action(grille g, hlist* histo, action act){
  return pose_tuile_histo(g, act.t, act.coord[0], act.coord[1], histo, act.orientation);
}


/**
 *\brief 
  \param 
 *\return 
*/
int pose_tuile(grille g, tuile t, int x, int y,enum pos rot_a){
    if (posable(g , t, x, y,rot_a)==1){
        if (rot_a==rot_0){
            g.grid[x][y]=t.terrains[0];  
            g.grid[x][y+1]=t.terrains[1];
            g.grid[x][y+2]=t.terrains[2];
            g.grid[x+1][y]=t.terrains[3];
            g.grid[x+1][y+1]=t.terrains[4];
            g.grid[x+1][y+2]=t.terrains[5];
        }    
        if (rot_a==rot_180){
            g.grid[x][y]=t.terrains[5];  
            g.grid[x][y+1]=t.terrains[4];
            g.grid[x][y+2]=t.terrains[3];
            g.grid[x+1][y]=t.terrains[2];
            g.grid[x+1][y+1]=t.terrains[1];
            g.grid[x+1][y+2]=t.terrains[0];
        }   
        if (rot_a==rot_90){
            g.grid[x][y]=t.terrains[3];  
            g.grid[x][y+1]=t.terrains[0];
            g.grid[x+1][y]=t.terrains[4];
            g.grid[x+1][y+1]=t.terrains[1];
            g.grid[x+2][y]=t.terrains[5];
            g.grid[x+2][y+1]=t.terrains[2];
        }
        if (rot_a==rot_270){
            g.grid[x][y]=t.terrains[2];  
            g.grid[x][y+1]=t.terrains[5];
            g.grid[x+1][y]=t.terrains[1];
            g.grid[x+1][y+1]=t.terrains[4];
            g.grid[x+2][y]=t.terrains[0];
            g.grid[x+2][y+1]=t.terrains[3];
        }
        return 0;
    }
    return 1; 
}


/**
 *\brief 
  \param 
 *\return 
*/
int ret_last_tuil(grille g, hlist hist ,int sz, enum pos rot_a){
    if (hist->next==NULL){
        return 1;
    }
    lib_grille(&g);
    pop(&hist);
    g=init_grid(sz);
    while (hist->next != NULL){
        pose_tuile(g,(hist->Play).t,hist->Play.coord[1],hist->Play.coord[2], rot_a);
        hist=hist->next;
    }
    return 0;
}

void show_tuile(tuile t){
    int k;
    for(k=0;k<6;k++){
        if(k==3){
            printf("\n");
        }
        printf("%d",t.terrains[k]);
    }
    return;
}
