all: Pong

Pong: Game.cpp main.cpp
	g++ -o $@ $^ -lSDL2

run:
	./Pong
