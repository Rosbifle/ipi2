#include <stdio.h>
#include <string.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "../inc/manipulation.h"
#include "../inc/structures.h"
#include "../inc/save.h"
#include "../inc/jugement.h"

/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite(void)
{
    if (NULL == (temp_file = fopen("tests/temp.txt", "w+"))) {
        return -1;
    }
    else {
        return 0;
    }
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite(void)
{
    if (0 != fclose(temp_file)) {
        return -1;
    }
    else {
        temp_file = NULL;
        return 0;
    }
}




void test_init_grid(void){
    grille g = init_grid(5);
    CU_ASSERT_NOT_EQUAL(g.grid,NULL);
    lib_grille(&g);
}

void test_tuile_random(void){
    int l = 118;
    tuile t;
    int i;
    for(i = 0; i < 6; i++){
        t.terrains[i]=(char)l;
    }
    CU_ASSERT_EQUAL(t.terrains[0],'v');
    CU_ASSERT_EQUAL(t.terrains[1],'v');
    CU_ASSERT_EQUAL(t.terrains[2],'v');
    CU_ASSERT_EQUAL(t.terrains[3],'v');
    CU_ASSERT_EQUAL(t.terrains[4],'v');
    CU_ASSERT_EQUAL(t.terrains[5],'v');
    
}

void test_init_action(void){
    tuile t = tuile_random();
    int coord[2] = {0,0};
    int orientation = rot_0;
    action ac = init_action(t,coord,orientation);
    CU_ASSERT_EQUAL(ac.coord[0],0);
    CU_ASSERT_EQUAL(ac.coord[1],0);
    CU_ASSERT_EQUAL(ac.orientation,rot_0);
}

void test_lib_grille(void){
    grille g = init_grid(5);
    lib_grille(&g);
    CU_ASSERT_EQUAL(g.grid,NULL);
}




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
    int l = 118;
    tuile t;
    int i;
    for(i = 0; i < 6; i++){
        t.terrains[i]=(char)l;
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































