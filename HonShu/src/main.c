#include <stdio.h>
#include "structures.h"
#include "manipulation.h"
#include "save.h"
#include "manipulation.h"

/**
 *\brief 
  \param 
 *\return 
*/
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