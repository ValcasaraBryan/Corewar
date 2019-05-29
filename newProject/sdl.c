#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "./SDL2_ttf.framework/Headers/SDL_ttf.h"
//#include "~/Desktop/glebouch/SDL2_ttf.framework/Headers/SDL_ttf.h"
  
void pause();
  
int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
	SDL_Event event;

	SDL_Window *screen = SDL_CreateWindow("Ma fenêtre de jeu", 
						  SDL_WINDOWPOS_UNDEFINED, 
						  SDL_WINDOWPOS_UNDEFINED, 
						  640, 480, 
						  0);
	SDL_Renderer *renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
	/* sleep(3);
	
	TTF_Init();
	TTF_Font *font;
	font = TTF_OpenFont( "browzko.ttf", 30); 
	SDL_Color textColor = {255, 255, 255};
	SDL_Surface *message = TTF_RenderText_Solid(font, "Test pour sdl_ttf", textColor);
	SDL_Texture *ouecrire = SDL_CreateTextureFromSurface(rendu, message);
	SDL_Rect dest = { 0, 0, 100, 100};
	
	write(1, "toto10\n", 7);
	int continuer = 1;
	while (continuer)
	{
		SDL_RenderCopy(rendu, message, NULL, &dest);
		write(1, "toto15\n", 7);
		SDL_WaitEvent(&event);
		switch(event.type)
			case SDL_QUIT:
			{
				continuer = 0;
				break;
			}
		write(1, "toto15\n", 7);
	}*/
	TTF_Font* Sans = TTF_OpenFont("browzko.ttf", 24);
	SDL_Color White = {255, 255, 0};
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = 0; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 100; // controls the height of the rect
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	SDL_RenderPresent(renderer);
	pause();
	SDL_DestroyTexture(Message);
	TTF_CloseFont(Sans);
	TTF_Quit();
	//pause(); // Mise en pause du programme
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
  
	return EXIT_SUCCESS;
}
  
void pause()
{
	int continuer = 1;
	SDL_Event event;
  
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
		}
	}
}