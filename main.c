#include <stdio.h>
#include "nbgame.h"
#include <stdlib.h>

#define MAX_SIZE 20

static int prev[MAX_SIZE][6];
static int prev_size = 0;

void prev_reset(){
	prev_size = 0;
}

void prev_insert(int* num, int s, int b){
	for (int i = 0; i < 4; i++){
		prev[prev_size][i] = num[i];
	}
	prev[prev_size][4] = s;
	prev[prev_size][5] = b;
	prev_size++;
}

int main(void){
	nbgame mygame = create();
	while(1){
		reset(mygame);
		prev_reset();

		while(1){
			printf("\n----------------------------\n");

			for (int i = 0; i < prev_size; i++){
				printf("%d%d%d%d : %dS %dB\n", prev[i][0], prev[i][1], prev[i][2],
						prev[i][3], prev[i][4], prev[i][5]);
			}
			printf("\nEnter the number.\n\n");


			int player_num = 0;
			int num[4];

			while (1){
				scanf("%d",&player_num);
				int c;
				while ((c = getchar()) != '\n');

				if (player_num > 0 && player_num < 10000){
					for (int i = 3; i >= 0; i--){
					num[i] = player_num % 10;
					player_num /= 10;
					}

					int ok = 0;
					for (int i = 0; i < 4; ++i){
						for (int j = 0; j < 4; ++j){
							if (num[i] == num[j]) ++ok;
						}
					}
					if (ok == 4) break;
				}

				printf("Invalid Number. Please Enter Again.\n");
				player_num = 0;
			}
			

			int s, b;
			match(mygame, num, &s, &b);
			if (s == 4) {
				printf("You Win!\nOne More Game? y/n\n");

				char yn;
				while (1){
					scanf(" %c", &yn);
					if (yn == 'y') break;
					else if (yn == 'n') exit(0);
				}
				break;
			}

			prev_insert(num, s, b);
			if (prev_size == MAX_SIZE) {
				printf("Game Over");
				break;
			}
		}
	}

	
	return 0;
}

