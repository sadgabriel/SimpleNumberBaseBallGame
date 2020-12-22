#include "nbgame.h"
#include <stdlib.h>
#include <time.h>


struct nbg{
	int num[4];
};

nbgame create(void){
	nbgame new_game = malloc(sizeof(struct nbg));
	return new_game;
}

void drop(nbgame game){
	free(game);
}

int* getnum(nbgame game){
	return game->num;
}

void reset(nbgame game){
	srand(time(0));
	int i = 0;
	while (i < 4){
		game->num[i] = rand()%10;

		int j = 0;
		for (; j < i; j++){
			if (game->num[i] == game->num[j]) break;
		}
		if (j == i) i++;
	}
}

void match(nbgame game, int* numbers, int* s_num, int* b_num){
	int s = 0;
	int b = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
	 		if (game->num[i] == numbers[j]){
				if (i == j) s += 1;
				else b += 1;
			}
		}
	}
	*s_num = s;
	*b_num = b;
}

