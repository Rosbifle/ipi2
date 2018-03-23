#include"./../inc/manipulation.h"


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
void action_add(tuile t, int x, int y, historique* historique, enum pos rot_a){
    action pose;
    pose.t=t;
    pose.coord[0]=x;
    pose.coord[1]=y;
    pose.next=NULL;
    pose.orientation=rot_a;
    historique->next=&pose;
    return;
}

/**
 *\brief 
  \param 
 *\return 
*/
int pose_tuile_histo(grille* g, tuile t, int x, int y, historique* historique,enum pose rot_a){
    if (posable(*g , t, x, y,rot_a)==0){
        action_add(t, x, y, historique, rot_a);
        if (rot_a->==rot_0){
            g->grid[x][y]=t.terrains[0];  
            g->grid[x][y+1]=t.terrains[1];
            g->grid[x][y+2]=t.terrains[2];
            g->grid[x+1][y]=t.terrains[3];
            g->grid[x+1][y+1]=t.terrains[4];
            g->grid[x+1][y+2]=t.terrains[5];
        }    
        if (rot_a==rot_180){
            g->grid[x][y]=t.terrains[5];  
            g->grid[x][y+1]=t.terrains[4];
            g->grid[x][y+2]=t.terrains[3];
            g->grid[x+1][y]=t.terrains[2];
            g->grid[x+1][y+1]=t.terrains[1];
            g->grid[x+1][y+2]=t.terrains[0];
        }   
        if (rot_a==rot_90){
            g->grid[x][y]=t.terrains[3];  
            g->grid[x][y+1]=t.terrains[0];
            g->grid[x+1][y]=t.terrains[4];
            g->grid[x+1][y+1]=t.terrains[1];
            g->grid[x+2][y]=t.terrains[5];
            g->grid[x+2][y+1]=t.terrains[2];
        }
        if (rot_a==rot_270){
            g->grid[x][y]=t.terrains[2];  
            g->grid[x][y+1]=t.terrains[5];
            g->grid[x+1][y]=t.terrains[1];
            g->grid[x+1][y+1]=t.terrains[4];
            g->grid[x+2][y]=t.terrains[0];
            g->grid[x+2][y+1]=t.terrains[3];
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
int pose_tuile(grille* g, tuile t, int x, int y,enum pose rot_a){
    if (posable(*g , t, x, y,rot_a)==0){
        if (rot_a->==rot_0){
            g->grid[x][y]=t.terrains[0];  
            g->grid[x][y+1]=t.terrains[1];
            g->grid[x][y+2]=t.terrains[2];
            g->grid[x+1][y]=t.terrains[3];
            g->grid[x+1][y+1]=t.terrains[4];
            g->grid[x+1][y+2]=t.terrains[5];
        }    
        if (rot_a==rot_180){
            g->grid[x][y]=t.terrains[5];  
            g->grid[x][y+1]=t.terrains[4];
            g->grid[x][y+2]=t.terrains[3];
            g->grid[x+1][y]=t.terrains[2];
            g->grid[x+1][y+1]=t.terrains[1];
            g->grid[x+1][y+2]=t.terrains[0];
        }   
        if (rot_a==rot_90){
            g->grid[x][y]=t.terrains[3];  
            g->grid[x][y+1]=t.terrains[0];
            g->grid[x+1][y]=t.terrains[4];
            g->grid[x+1][y+1]=t.terrains[1];
            g->grid[x+2][y]=t.terrains[5];
            g->grid[x+2][y+1]=t.terrains[2];
        }
        if (rot_a==rot_270){
            g->grid[x][y]=t.terrains[2];  
            g->grid[x][y+1]=t.terrains[5];
            g->grid[x+1][y]=t.terrains[1];
            g->grid[x+1][y+1]=t.terrains[4];
            g->grid[x+2][y]=t.terrains[0];
            g->grid[x+2][y+1]=t.terrains[3];
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
tuile pop(hlist ph){
    action act=(*ph)->A;
    *ph=&(*ph->next);
    return act.t;
}

/**
 *\brief 
  \param 
 *\return 
*/
int ret_last_tuil(grille* g, hlist historique ,int sz){
    if (historique->next==NULL){
        return 1;
    }
    for(i=0;i<sz;i++){
            free(g[i]);
            free(g);
    }
    pop(historique);
    grille* g= &init_grid_empty(sz);
    while (historique->next != NULL){
        pose_tuile(g,historique->Play->t,historique->Play->coord[1],historique->Play->coord[2]);
        historique=historique->next;
    }
    return 0;
}
