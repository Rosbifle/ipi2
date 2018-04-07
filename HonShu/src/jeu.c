#include <stdio.h>
#include "../inc/structures.h"
#include "../inc/save.h"
/*#include "../inc/jugement.h"*/

int selecttuile (hand* main, int tour, int choix, tuile* aposer){
    int k;
    for(k=0, k<13-tour,k++){
        if(main->disp[k]==1){
            if(k==choix){
                aposer=&(main->deck[k]);
                main->disp[k]=0;
                return 1;
            }
        }
    }
    return 0;
}

void coordpose(action* pose){
    printf("coordonnee de x:\n");
    scanf("%d", &(pose->coord[0]));
    printf("coordonnee de x:\n");
    scanf("%d", &(pose->coord[1]));
}
