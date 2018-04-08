#include "../inc/recouvrement.h"


/* returns a cases with x, y values */
cases createCase(int x, int y){
	cases * c = malloc(sizeof(cases));
	c->x = x;
	c->y = y;
	c->next = NULL;
	return c;
}

/*adds box to init*/
void addCase(cases ** init, cases * box){
	box->next = *init;
	*init = box;
}
/*adds every case of toAdd to init*/
void add_cases(cases ** init, cases * toAdd){
	while(toAdd != NULL)
		addCase(init, toAdd);
}
/* renvoie la liste des cases prises par la pose de l'action a */
cases * casestaken(action a){
	cases * list;
	addCase(&list, createCase(a.x, a.y));
	addCase(&list, createCase(a.x+1, a.y+1));
	addCase(&list, createCase(a.x, a.y+1));
	addCase(&list, createCase(a.x+1, a.y));

	if (a.orientation ==rot_0 || a.orientation == rot_180){
        addCase(&list, createCase(a.x, a.y+2));;
       	addCase(&list, createCase(a.x+1, a.y+2));

    }    

    else if (a.orientation == rot_90 || a.orientation == rot_270){
        addCase(&list, createCase(a.x+2, a.y));;
       	addCase(&list, createCase(a.x+2, a.y+1));
    }
}

/*Deletes aenlever from c if exists, does nothing otherwise */
void enlever(cases **c, cases aenlever){
	if((*c)->x == aenlever.x && (*c)->y == aenlever.y){
		*c = (*c)->next;
		return; 
	}
	cases *test = *c, *sec = (*c)->next;
	while(test != NULL)
		if(sec->x == aenlever.x && sec->y == aenlever.y)
		{
			test->next = sec->next;
			return;
		}
		test = sec;
		sec = sec->next;
}

/* elimine les élements de aenlever présents dans c */
void delListecases(cases ** c, cases * aenlever){
	while(aenlever != NULL)
		enlever(c, *aenlever);
		aenlever = aenlever->next;
}


/* retourne si les cases prises par ac sont recouvertes par celles de c */
int recouvre(action ac, cases *c){
	cases * ca = casestaken(ac);
	delListecases(&ca, c);
	if (ca == NULL){
		return 1;
	}
	return 0;
}

int recouvrementTtl(hlist prev, action ac){
	cases * cas = casestaken(ac);
	while(prev != NULL){
		if(recouvre(prev.Play, cas))
			return 1;
		add_cases(&cas, casestaken(prev.Play));
		prev = prev.next;
	}
}