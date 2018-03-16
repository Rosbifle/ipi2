typedef struct{
    int id;
    int orientation;
    char terrains[6];
} tuile;

typedef struct {
    int sz;
    char** grid;
} grille;

typedef struct {
    int sz;
    tuile* deck;
} hand;

void lib_grille(grille* g);
tuile tuile_random();
hand init_hand(int n);
void pose_tuile(grille* g, tuile t, int x, int y);
