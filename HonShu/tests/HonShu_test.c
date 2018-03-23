#include <stdio.h>
#include <string.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "../inc/manipulation.h"
#include "../inc/structures.h"
#include "../inc/save.h"
#include "../inc/jugement.h"


void test_test_zone_limite(void){
    grille g = init_grid(100);
    tuile t = tuile_random();
    
    int coord[2] = {0,0};
    int orientation = rot_0;
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(test_zone_limite(ac,g),true);
    
    coord[2] = {99,99};
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(test_zone_limite(ac,g),false);
    
    coord[2] = {0,0};
    orientation = rot_180;
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(test_zone_limite(ac,g),true);
    
    coord[2] = {99,99};
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(test_zone_limite(ac,g),false);
    
    coord[2] = {0,0};
    orientation = rot_90;
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(test_zone_limite(ac,g),true);
    
    coord[2] = {99,99};
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(test_zone_limite(ac,g),false);
    
    coord[2] = {0,0};
    orientation = rot_270;
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(test_zone_limite(ac,g),true);
    
    coord[2] = {99,99};
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(test_zone_limite(ac,g),false);
    
    lib_grille(&g);
}

void test_village_vill(void){
    grille g = init_grid(100);
    int l[6]={118, 118, 118, 118, 118, 118};
    tuile t;
    int i;
    for(i=0;i<6;i++){
        t.terrains[i]=(char)l[randint(6)];
    }
    
    int coord[2] = {0,0};
    int orientation = rot_0;
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(village_ville(grille g),6);

    lib_grille(&g);
}

void test_posable(void){
    grille g = init_grid(100);
    tuile t = tuile_random();
    
    int coord[2] = {0,0};
    int orientation = rot_0;
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(posable(g, t, coord[0], coord[1], orientation),1);
    
    coord[2] = {99,99};
    action ac = init_action(t, coord, orientation);
    CU_ASSERT_EQUAL(posable(g, t, coord[0], coord[1], orientation),0);
                    
}
















