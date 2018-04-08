#include "../inc/structures.h"

typedef struct Cases {
	int x;
	int y;
	struct Cases * next;
} cases;


cases createCase(int x, int y);

void addCase(cases ** init, cases * box);

void add_cases(cases ** init, cases * toAdd);

cases * casestaken(action a);

void enlever(cases **c, cases aenlever);

void delListecases(cases ** c, cases *aenlever);

int recouvre(action ac, cases *c);

int recouvrementTtl(hlist prev, action ac);