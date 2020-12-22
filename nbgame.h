#ifndef NBGAME_H
#define NBGAME_H

typedef struct nbg *nbgame;

nbgame create(void);
void drop(nbgame);
int* getnum(nbgame);
void reset(nbgame);
void match(nbgame, int*, int*, int*);

#endif
