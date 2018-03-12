#include"manipulation.h"


/*retourne type de terrain d'une case*/
int read_terrain(int x, int y){
    return g.grid[x][y];
}

/*change l'orientation de la tuile*/
void rot_tuile(tuile* t, int orient){
    t->orientation=orient;
    return ;
}

void action_add(tuile t, int x, int y, action* historique){
    action pose;
    pose.tuile=t;
    pose.x=x;
    pose.y=y;
    pose.next=NULL;
    historique->next=&pose;
    return;
}

int pose_tuile(grille* g, tuile t, int x, int y, action* historique){
    if (posable(*g , t, x, y)==0){
        action_add(t, x, y, &historique);
        if (t.orientation==rot_0){
            g->grid[x][y]=t.terrain[0];  
            g->grid[x][y+1]=t.terrain[1];
            g->grid[x][y+2]=t.terrain[2];
            g->grid[x+1][y]=t.terrain[3];
            g->grid[x+1][y+1]=t.terrain[4];
            g->grid[x+1][y+2]=t.terrain[5];
        }    
        if (t.orientation==rot_180){
            g->grid[x][y]=t.terrain[5];  
            g->grid[x][y+1]=t.terrain[4];
            g->grid[x][y+2]=t.terrain[3];
            g->grid[x+1][y]=t.terrain[2];
            g->grid[x+1][y+1]=t.terrain[1];
            g->grid[x+1][y+2]=t.terrain[0];
        }   
        if (t.orientation==rot_90){
            g->grid[x][y]=t.terrain[3];  
            g->grid[x][y+1]=t.terrain[0];
            g->grid[x+1][y]=t.terrain[4];
            g->grid[x+1][y+1]=t.terrain[1];
            g->grid[x+2][y]=t.terrain[5];
            g->grid[x+2][y+1]=t.terrain[2];
        }
        if (t.orientation==rot_270){
            g->grid[x][y]=t.terrain[2];  
            g->grid[x][y+1]=t.terrain[5];
            g->grid[x+1][y]=t.terrain[1];
            g->grid[x+1][y+1]=t.terrain[4];
            g->grid[x+2][y]=t.terrain[0];
            g->grid[x+2][y+1]=t.terrain[3];
        }
    return 0;
    }
    return 1;
    
}