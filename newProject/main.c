#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>


int main(int argc, char **argv)
{	
    // Notre fenêtre
	
    SDL_Window* fenetre;
    SDL_GLContext contexteOpenGL;
	
    SDL_Event evenements;
    bool terminer = false;
	
	
    // Initialisation de la SDL
	
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("quit1");
        SDL_Quit();
		
        return -1;
    }
	
	
    // Version d'OpenGL
	
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
	
    // Double Buffer
	
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	
	
    // Création de la fenêtre

    fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if(fenetre == 0)
    {
        printf("quit2");
        SDL_Quit();
        return -1;
    }


    // Création du contexte OpenGL

    contexteOpenGL = SDL_GL_CreateContext(fenetre);

    // if(contexteOpenGL == 0)
    // {
        // printf("quit3");
        // SDL_DestroyWindow(fenetre);
        // SDL_Quit();
// 
        // return -1;
    // }
	
	
    // Boucle principale
	
    while(!terminer)
    {
        SDL_WaitEvent(&evenements);
		
        if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
        terminer = true;
    }
	
	
    // On quitte la SDL
	
    SDL_GL_DeleteContext(contexteOpenGL);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
	
    return 0;
}