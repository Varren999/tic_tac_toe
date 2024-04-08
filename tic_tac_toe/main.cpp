#include "Game.h"

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	Game game;
	game.Play();
	return 0;
}