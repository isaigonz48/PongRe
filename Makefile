all: Pong

Pong: Game.o main.o Border.o Ball.o Paddle.o Player.o
	g++ -o $@ $^ -lSDL2 -lSDL2_ttf

run:
	./Pong
