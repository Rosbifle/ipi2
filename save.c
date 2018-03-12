#include <structures.h>

/* Proposition d'ecriture du fichier */
/* 
taille_grille
//tuiles en main
1: tuile.toString val1;val2
2: tuile.toString 
...
//historique posage de tuiles (à développer) //ptet creer un struct action qui est en fait un {tuile; coordonnée;} et faire historique est un action[12], il n'y a que 12 tours.
0 tuile.toString:coordonee1:coordonee2 //celle la est la tuile initiale.
1 tuile.toString:...
2 tuile.toString:... 
... pour chaque tour
après pour la relecture il suffit de prendre une grille vide et d'insérer les tuiles 
*/

/**
loads the game saved in saveHonshu.txt.
@returns The story of the loaded game.
@assigns main: the hand of the player during the loaded game.

*/

action load(hand * main){
	int i, test, dropped, coord[2];
	action grid = grille();
	FILE *f = fopen("saveHonshu.txt", "r");
	//reading size
	fscanf(f, "%d", &grid.size);
	// reading hand
	for(i = 0; i < 12; i ++){
		fscanf(f, "%d", &test);
		if(test != i + 1){ //c-a-d qu'on arrive a l'historique du
			break;
		}
		//read en expression réguliere en fonction de tuile.toString pour le moment: orientation:v1;v2;v3;v4;v5;v6:c1:c2
		fscanf(f, "%d %c;%c;%c;%c;%c;%c", main.tuile[i].orientation, main.tuile[i]->val[0], main.tuile[i]->val[1], main.tuile[2],
				main.tuile->val[3], main.tuile[i]->val[4], main.tuile[i]->val[5], main.tuile[i]->val[6]);
	}
	main -> sz = i + 1;
	//reading historique
	dropped = 13 - i; // il y a la tuile de départ + 12 - i tuiles posées.
	tuile pose = tuile();
	for(i = 0; i < dropped; i ++){
		fscanf(f, "%d", test);
		if(test != i){ //c-a-d qu'on arrive a la fin de l'historique soit la fin du fichier save
			break;
		}
		fscanf(f, "%d:%c;%c;%c;%c;%c;%c:%d:%d",
			&pose.orientation, &pose.terrains[0], &pose.terrains[1], &pose.terrains[3],
			&pose.terrains[4], &pose.terrains[5], &pose.terrains[6], &coord[0], &coord[1]);
		insert(grid, tuile, coord);
	}

}
