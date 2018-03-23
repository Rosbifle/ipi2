#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/Tuiles.h"
#include "../src/Grille.h"

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




/*
* Teste l'égalité entre deux tuiles
*/
int testTuileEgale(tuile* a, tuile* b){
    int result=1;
    int i,j;

    if (a->id != b->id){
        result =0;
    }

    if (a->orientation != b->orientation) {
        result =0;
    }
    else{
        for (i=0;i<3;i++){
            for(j=0;j<3;j++){
                if (a->contenu[i][j] != b->contenu[i][j]){
                    result = 0;
                }
            }
        }
    }

    return result;
}


/*
*
*/
int testCaseType(terrain T1, terrain T2) {
    if(T1 == T2)
        return 1;
    else
        return 0;
}

/*
*
*/
int testCaseNumero(int j, int i) {
    if(j == i)
        return 1;
    else
        return 0;
}

/*
*
*/
void test_LireCaseType() {
    grilleDeJeu g;
    g.taille = 3;
    grille_create(&g);
    g.Grille[0][0].typeCase = Vide;
    g.Grille[0][1].typeCase = Plaine;
    g.Grille[0][2].typeCase = Foret;
    g.Grille[1][0].typeCase = Lac;
    g.Grille[1][1].typeCase = Ville;
    g.Grille[1][2].typeCase = Ressource;
    g.Grille[2][0].typeCase = Usine;
    grilleDeJeu a;
    a.Grille = g.Grille;

    CU_ASSERT(testCaseType (lireCaseType(0, 0, a), Vide));
    CU_ASSERT(testCaseType (lireCaseType(0, 1, a), Plaine));
    CU_ASSERT(testCaseType (lireCaseType(0, 2, a), Foret));
    CU_ASSERT(testCaseType (lireCaseType(1, 0, a), Lac));
    CU_ASSERT(testCaseType (lireCaseType(1, 1, a), Ville));
    CU_ASSERT(testCaseType (lireCaseType(1, 2, a), Ressource));
    CU_ASSERT(testCaseType (lireCaseType(2, 0, a), Usine));
}

/*
*
*/
void test_lireCaseNumeroTuile() {
    grilleDeJeu g;
    g.taille = 3;
    grille_create(&g);
    g.Grille[0][0].numeroTuile = 1;
    g.Grille[0][1].numeroTuile = 10;
    g.Grille[0][2].numeroTuile = 100;
    g.Grille[1][0].numeroTuile = 1000;
    g.Grille[1][1].numeroTuile = 10000;
    grilleDeJeu a;
    a.Grille = g.Grille;

    CU_ASSERT(testCaseType (lireCaseNumeroTuile(0, 0, a), 1));
    CU_ASSERT(testCaseType (lireCaseNumeroTuile(0, 1, a), 10));
    CU_ASSERT(testCaseType (lireCaseNumeroTuile(0, 2, a), 100));
    CU_ASSERT(testCaseType (lireCaseNumeroTuile(1, 0, a), 1000));
    CU_ASSERT(testCaseType (lireCaseNumeroTuile(1, 1, a), 10000));
}

/*
* Test l'initialisation d'une tuile
*/
void test_init_tuile(){
    tuile a,b;

    b.id = 0;
    b.orientation = 0;
    b.contenu[0][0] ='P';
    b.contenu[0][1] = 'F';
    b.contenu[0][2] = 'E';
    b.contenu[1][0] = 'L';
    b.contenu[1][1] = 'V';
    b.contenu[1][2] = 'E';
    b.contenu[2][0] = 'R';
    b.contenu[2][1] = 'U';
    b.contenu[2][2] = 'E';

    tuile_init(&a, 0, 'P', 'F', 'L', 'V', 'R', 'U');
    CU_ASSERT(testTuileEgale (&a,&b)==1);
}

/*
*
*/
int testCreate(grilleDeJeu a) {
    int n = a.taille;
    int i = 0;
    int j = 0;
    if(sizeof(a.Grille)/sizeof(laCase*) != n)
        return 0;
    else {
        for(i = 0; i < n; i++) {
            if(sizeof(a.Grille[i])/sizeof(laCase*) != n)
                return 0;
        }
    }
    for(i= 0; i< n; i++) {
        for(j= 0; j <n; j++){
            if(a.Grille[i][j].typeCase != Vide)
                return 0;
        }
    }
    return 1;
}

/*
*
*/
void test_grilleCreate() {
    int a = 1, b = 10, c = 100, d = 1000, e = 10000;
    grilleDeJeu A1;
    grilleDeJeu B2;
    grilleDeJeu C3;
    grilleDeJeu D4;
    grilleDeJeu E5;
    A1.taille = a;
    B2.taille = b;
    C3.taille = c;
    D4.taille = d;
    E5.taille = e;

    grille_create(&A1);
    grille_create(&B2);
    grille_create(&C3);
    grille_create(&D4);
    grille_create(&E5);

    CU_ASSERT(testCreate (A1)==1);
    CU_ASSERT(testCreate (B2)==1);
    CU_ASSERT(testCreate (C3)==1);
    CU_ASSERT(testCreate (D4)==1);
    CU_ASSERT(testCreate (E5)==1);
}

/*
*
*/
void test_tuileRandom() {
    tuile a, b;
    tuile_init_random(&a, 1);
    tuile_init_random(&b, 2);
    CU_ASSERT(testTuileEgale (&a,&b)==1);
}


/*
* Teste si la rotation d'une tuile est bien réalisée, dans les 4 cas d'orientations
*/
void test_rotation(){
    tuile a,b,c,d,e;

    a.id = 0;
    a.orientation = 0;
    a.contenu[0][0] ='V';
    a.contenu[0][1] = 'V';
    a.contenu[0][2] = 'E';
    a.contenu[1][0] = 'F';
    a.contenu[1][1] = 'P';
    a.contenu[1][2] = 'E';
    a.contenu[2][0] = 'U';
    a.contenu[2][1] = 'L';
    a.contenu[2][2] = 'E';

    b.id = 0;
    b.orientation = 1;
    b.contenu[0][0] = 'U';
    b.contenu[0][1] = 'F';
    b.contenu[0][2] = 'V';
    b.contenu[1][0] = 'L';
    b.contenu[1][1] = 'P';
    b.contenu[1][2] = 'V';
    b.contenu[2][0] = 'E';
    b.contenu[2][1] = 'E';
    b.contenu[2][2] = 'E';

    c.id = 0;
    c.orientation = 2;
    c.contenu[0][0] = 'L';
    c.contenu[0][1] = 'U';
    c.contenu[0][2] = 'E';
    c.contenu[1][0] = 'P';
    c.contenu[1][1] = 'F';
    c.contenu[1][2] = 'E';
    c.contenu[2][0] = 'V';
    c.contenu[2][1] = 'V';
    c.contenu[2][2] = 'E';

    d.id = 0;
    d.orientation = 3;
    d.contenu[0][0] = 'V';
    d.contenu[0][1] = 'P';
    d.contenu[0][2] = 'L';
    d.contenu[1][0] = 'V';
    d.contenu[1][1] = 'F';
    d.contenu[1][2] = 'U';
    d.contenu[2][0] = 'E';
    d.contenu[2][1] = 'E';
    d.contenu[2][2] = 'E';

    e.id = 0;
    e.orientation = 0;
    e.contenu[0][0] ='V';
    e.contenu[0][1] = 'V';
    e.contenu[0][2] = 'E';
    e.contenu[1][0] = 'F';
    e.contenu[1][1] = 'P';
    e.contenu[1][2] = 'E';
    e.contenu[2][0] = 'U';
    e.contenu[2][1] = 'L';
    e.contenu[2][2] = 'E';

    tuile_rotation(&a);
    CU_ASSERT(testTuileEgale (&a,&b)==1);
    tuile_rotation(&a);
    CU_ASSERT(testTuileEgale (&a,&c)==1);
    tuile_rotation(&a);
    CU_ASSERT(testTuileEgale (&a,&d)==1);
    tuile_rotation(&a);
    CU_ASSERT(testTuileEgale (&a,&e)==1);

}

int Compare_Grille(grilleDeJeu a ,grilleDeJeu b){
    int i,j;

    if (a.taille != b.taille) {
        return 0;
    }

    if (a.nbTuilePosees != b.nbTuilePosees) {
        return 0;
    }

    for (i = 0;i < a.taille;i++){
        for(j=0; i < a.taille ; j++){
            if ( a.Grille[i][j].typeCase != b.Grille[i][j].typeCase)
        return 0;
        }
    }

    return 1;
}


int main(){
    CU_pSuite pSuite =NULL;
    //intialisation du registre de test CUNIT
    if (CU_initialize_registry() != CUE_SUCCESS){
        return CU_get_error();
    }

    //Ajout de la suite au registre
    pSuite = CU_add_suite("Suite", init_suite, clean_suite);
    if(pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    //ajout du test à la suite
    if ((CU_add_test (pSuite, "Test de rotation", test_rotation) == NULL) ||
        (CU_add_test(pSuite, "Test d'initialisation d'une tuile", test_init_tuile) == NULL) ||
        (CU_add_test(pSuite, "Test de Lecture de terrain d'une case", test_LireCaseType) == NULL) ||
         (CU_add_test(pSuite, "Test de Creation de Grille", test_grilleCreate) == NULL)
        ){
        CU_cleanup_registry();
        return CU_get_error();
    }
    //Execution de tous les tests
    CU_basic_set_mode (CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
