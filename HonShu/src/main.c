#include <stdio.h>
#include "../inc/structures.h"
#include "../inc/save.h"
/*#include "../inc/jugement.h"*/

/**
 *\brief 
  \param 
 *\return 
*/
int main(){
    srand(time(NULL));
    hand h=init_hand(4);
    grille g=init_grid(4);
    tuile t=tuile_random();
    tuile r=tuile_random();   
    int c[2]={1,0};
    action a=init_action(t, c, rot_0);
    action b=init_action(r, c, rot_0);
    historique* h=init_historique(); 
    add(a,&h);
    int c=read_terrain(g,0,0);
    printf("%d",c);
    r=pop(&h).t;
    show_tuile(r);
    tuile r=tuile_random(); 
    pose_tuile_histo(g,t,1,0,&h,rot_0);
    r=pop(&h).t;
    show_tuile(r);
    tuile r=tuile_random();
    show_tuile(r);
    pose_tuile_histo(g,r,1,0,&h,rot_0);
    pose_tuile_histo(g,t,1,0,&h,rot_0);
    ret_last_tuil(g,&h,4,rot_0);
    t=pop(&h).t;
    return 0;
}


