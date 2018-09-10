all: Pong

Pong: Game.o main.o Ball.o Player.o Paddle.o
	g++ -o $@ $^ -lSDL2

run:
	./Pong
