#include <stdio.h>
#include <string.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "../inc/save.h"
#include "../inc/structures.h"




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

void test_init_hand(void){
    hand h;
    init_hand(5);
    CU_ASSERT_EQUAL(h.sz,5)
    free(h.deck);
}

void test_pose_tuile(void){
    grille g = init_grid(100);
    int l[6]={102, 108, 112, 114, 117, 118};
    tuile t;
    int i;
    for(i = 0; i < 6; i++){
        t.terrains[i]=(char)l[i];
    }
    int x = 50;
    int y = 50;
    pose_tuile(g, t, x, y, rot_0);
    CU_ASSERT_EQUAL(g.grid[x][y],'f');
    CU_ASSERT_EQUAL(g.grid[x][y+1],'l');
    CU_ASSERT_EQUAL(g.grid[x][y+2],'p');
    CU_ASSERT_EQUAL(g.grid[x+1][y],'r');
    CU_ASSERT_EQUAL(g.grid[x+1][y+1],'u');
    CU_ASSERT_EQUAL(g.grid[x+1][y+2],'v');

    pose_tuile(g, t, x, y, rot_180);
    CU_ASSERT_EQUAL(g.grid[x][y],'v');
    CU_ASSERT_EQUAL(g.grid[x][y+1],'u');
    CU_ASSERT_EQUAL(g.grid[x][y+2],'r');
    CU_ASSERT_EQUAL(g.grid[x+1][y],'p');
    CU_ASSERT_EQUAL(g.grid[x+1][y+1],'l');
    CU_ASSERT_EQUAL(g.grid[x+1][y+2],'f');

    pose_tuile(g, t, x, y, rot_90);
    CU_ASSERT_EQUAL(g.grid[x][y],'r');
    CU_ASSERT_EQUAL(g.grid[x][y+1],'f');
    CU_ASSERT_EQUAL(g.grid[x+1][y],'u');
    CU_ASSERT_EQUAL(g.grid[x+1][y+1],'l');
    CU_ASSERT_EQUAL(g.grid[x+2][y],'v');
    CU_ASSERT_EQUAL(g.grid[x+2][y+1],'p');

    pose_tuile(g, t, x, y, rot_270);
    CU_ASSERT_EQUAL(g.grid[x][y],'p');
    CU_ASSERT_EQUAL(g.grid[x][y+1],'v');
    CU_ASSERT_EQUAL(g.grid[x+1][y],'l');
    CU_ASSERT_EQUAL(g.grid[x+1][y+1],'u');
    CU_ASSERT_EQUAL(g.grid[x+2][y],'f');
    CU_ASSERT_EQUAL(g.grid[x+2][y+1],'r');
  
    lib_grille(&g);
}

void test_pose_tuile_histo(void){
    grille g = init_grid(100);
    int l[6]={102, 108, 112, 114, 117, 118};
    tuile t;
    hlist newHlist = init_historique(); 
    int i;
    for(i = 0; i < 6; i++){
        t.terrains[i]=(char)l[i];
    }
    int x = 50;
    int y = 50;
    pose_tuile_histo(g, t, x, y, &newHlist, rot_0);
    CU_ASSERT_EQUAL(g.grid[x][y],'f');
    CU_ASSERT_EQUAL(g.grid[x][y+1],'l');
    CU_ASSERT_EQUAL(g.grid[x][y+2],'p');
    CU_ASSERT_EQUAL(g.grid[x+1][y],'r');
    CU_ASSERT_EQUAL(g.grid[x+1][y+1],'u');
    CU_ASSERT_EQUAL(g.grid[x+1][y+2],'v');

    pose_tuile_histo(g, t, x, y,&newHlist, rot_180);
    CU_ASSERT_EQUAL(g.grid[x][y],'v');
    CU_ASSERT_EQUAL(g.grid[x][y+1],'u');
    CU_ASSERT_EQUAL(g.grid[x][y+2],'r');
    CU_ASSERT_EQUAL(g.grid[x+1][y],'p');
    CU_ASSERT_EQUAL(g.grid[x+1][y+1],'l');
    CU_ASSERT_EQUAL(g.grid[x+1][y+2],'f');

    pose_tuile_histo(g, t, x, y,&newHlist, rot_90);
    CU_ASSERT_EQUAL(g.grid[x][y],'r');
    CU_ASSERT_EQUAL(g.grid[x][y+1],'f');
    CU_ASSERT_EQUAL(g.grid[x+1][y],'u');
    CU_ASSERT_EQUAL(g.grid[x+1][y+1],'l');
    CU_ASSERT_EQUAL(g.grid[x+2][y],'v');
    CU_ASSERT_EQUAL(g.grid[x+2][y+1],'p');

    pose_tuile_histo(g, t, x, y,&newHlist, rot_270);
    CU_ASSERT_EQUAL(g.grid[x][y],'p');
    CU_ASSERT_EQUAL(g.grid[x][y+1],'v');
    CU_ASSERT_EQUAL(g.grid[x+1][y],'l');
    CU_ASSERT_EQUAL(g.grid[x+1][y+1],'u');
    CU_ASSERT_EQUAL(g.grid[x+2][y],'f');
    CU_ASSERT_EQUAL(g.grid[x+2][y+1],'r');
  
    lib_grille(&g);
}






int main(){
    CU_pSuite pSuite =NULL;
    //Intialise le registre de test 
    if (CU_initialize_registry() != CUE_SUCCESS){
        return CU_get_error();
    }

    //Ajoute de la suite au registre
    pSuite = CU_add_suite("Suite", init_suite, clean_suite);
    if(pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    //Ajoute du test à la suite
    if ((CU_add_test(pSuite, "Test de creation d'une grille", test_init_grid) == NULL) ||
        (CU_add_test(pSuite, "Test de creation d'une tuile", test_tuile_random) == NULL) ||
        (CU_add_test(pSuite, "Test de creation d'une action", test_init_action) == NULL) ||
        (CU_add_test(pSuite, "Test de liberation de memoire", test_lib_grille) == NULL) ||
        (CU_add_test(pSuite, "Test de Creation de hand", test_init_hand) == NULL) ||
        (CU_add_test(pSuite, "Test de poser une tuille", test_pose_tuile) == NULL) ||
        (CU_add_test(pSuite, "Test d'ajouter cette action a l'historique", test_pose_tuile_histo) == NULL) ||
        
        ){
        CU_cleanup_registry();
        return CU_get_error();
    }
    //Exécute tous les tests
    CU_basic_set_mode (CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

























