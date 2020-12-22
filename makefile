Game.exe : main.o nbgame.o
	gcc -o Game.exe main.o nbgame.o

main.o : main.c nbgame.h
	gcc -c main.c

nbgame.o : nbgame.c nbgame.h
	gcc -c nbgame.c

