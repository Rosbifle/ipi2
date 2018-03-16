#include <structures.h>

/* ecriture du fichier */
/* 
taille_grille
//tuiles en main
1val1;val2;...
2val1;val2;...
...
// historique
1val1;val2;...:coord1:coord2
2val1;val2;...:coord1:coord2
...
*/
/**
render a tuile to string as val1;val2;val3;...
@returns: the string of tuile  t
*/
char * tuile_toString(tuile t){
	int i;
	char str[11];
	sprintf(str, %c;%c;%c;%c;%c;%c, tuile.terrains[0], tuile.terrains[1], 
		tuile.terrains[2], tuile.terrains[3],  tuile.terrains[4], tuile.terrains[5]
	return str;
}
/**
Saves the game in saveHonshu.txt
@assigns: nothing
@returns: 0 if ok 1 if error
*/

int save(action historique, hand main){
	FILE *f = fopen("saveHonshu.txt", "w");
	char * main, histo;
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
	//print size
	fprintf(f, "%d\n", historique.sz);
	//print hand
	for(i = 0; i < main.sz; i ++){
		fprintf(f, "%d%s\n", i, tuile_toString(main.deck[i]));
	}
	// print histo
	i = 0;
	while(historique != NULL){
		fprintf(f, "%d %d%s:%d:%d\n", i, historique.Play.orientation, tuile_toString(historique.tuile),
			historique.Play.coord[0], historique.Play.coord[1]);
		historique = historique.next;
		i ++;
	}
	return 0;
	fclose(f);
}

/**
loads the game saved in saveHonshu.txt.
@returns The story of the loaded game.
@assigns: main: the hand of the player during the loaded game.

*/

historique load(hand * main){
	int i, test, dropped, coord[2];
	grille grid;
	FILE *f = fopen("saveHonshu.txt", "r");
	//reading size
	fscanf(f, "%d", &grid.size);
	//alloc_grille(grid) <-- alloc la taille de la grille.
	// reading hand
	for(i = 0; i < 12; i ++){
		fscanf(f, "%d", &test);
		if(test != i){ //c-a-d qu'on arrive a l'historique du
			break;
		}
		//read en expression réguliere en fonction de tuile.toString : v1;v2;v3;v4;v5;v6:c1:c2
		fscanf(f, "%c;%c;%c;%c;%c;%c", main.tuile[i]->val[0], main.tuile[i]->val[1], 
				main.tuile[2], main.tuile->val[3], main.tuile[i]->val[4], 
				main.tuile[i]->val[5], main.tuile[i]->val[6]);
	}
	main -> sz = i + 1;
	//reading historique
	dropped = 13 - i; // il y a la tuile de départ + 12 - i tuiles posées.
	action a;
	tuile pose = tuile();
	for(i = 0; i < dropped; i ++){
		fscanf(f, "%d ", test);
		if(test != i){ //c-a-d qu'on arrive a la fin de l'historique soit la fin du fichier save
			break;
		}
		fscanf(f, "%d:%c;%c;%c;%c;%c;%c:%d:%d", a.orientation,
			pose.terrains[0], &pose.terrains[1], &pose.terrains[3],
			&pose.terrains[4], &pose.terrains[5], &pose.terrains[6], coord[0], coord[1]);
		a.t = pose;
		a.coord = coord;
		pose_tuile(grid, a);
	}

}
