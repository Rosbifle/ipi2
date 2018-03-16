
int read_terrain(int x, int y);
void rot_tuile(tuile* t, int orient);
void action_add(tuile t, int x, int y, historique* historique);
int pose_tuile_histo(grille* g, tuile t, int x, int y, historique* historique);
int pose_tuile(grille* g, tuile t, int x, int y);
int ret_last_tuil(grille* g, historique* historique ,int sz);
