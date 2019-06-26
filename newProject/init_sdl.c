#include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>
#include "../op.h"
#include <math.h>
#include <unistd.h>
#include "./SDL2_ttf.framework/Headers/SDL_ttf.h"
#include <stdbool.h>
#define WIDTH 4000
#define HEIGHT 1152
#define WHITE 0xff0000
#define GREY 0x202020
# define P1 0x33cc33
# define P2 0x0099ff
# define P3 0xff00ff
# define P4 0xff9933
# define OCT_W 28
# define OCT_H 18
#include <time.h>
#include <stdlib.h>

typedef union					u_color
{
	int				color;
	unsigned char	rgb[4];
}					t_color;

typedef struct		s_win
{
	SDL_Window		*window;
	SDL_Surface		*surface;
	TTF_Font		*ttf_text;
	SDL_Event		event;
	SDL_Renderer 	*renderer;
	SDL_Texture 	*texture;
	SDL_Rect 		rect;
	int				colors[4];
	int				width;
	int				height;
	int				text_height;
	int				text_start;
	int 			pause;
}					t_win;
// extern t_player *g_players;

SDL_Color	argb_to_sdl(Uint32 color)
{
	t_color	c;

	c = (t_color)((int)color);
	return ((SDL_Color){c.rgb[2], c.rgb[1], c.rgb[0], c.rgb[3]});
}

char *ft_itoa_hexa(int a)
{
	char *str;
	char *tab;

	tab = "0123456789abcdef";
	if(!(str = malloc(sizeof(char) * 3)))
		return (NULL);
	str[0] = tab[a / 16];
	str[1] = tab[a % 16];
	str[2] = '\0';
	return (str);
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		++i;
	while (src[j])
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
	return (dest);
}

void ft_init_win(t_win *win)
{
	win->pause = 0;
	write(1, "ch", 2);
	win->renderer = NULL;
	write(1, "ch", 2);
	win->ttf_text = NULL;
	write(1, "ch", 2);
	win->width = WIDTH;
	write(1, "ch", 2);
	win->height = HEIGHT;
	write(1, "ch", 2);
	win->rect.x = 0;
	win->rect.y = 0;
	win->rect.w = WIDTH;
	win->rect.h = HEIGHT;

}


int ft_init_font(t_win *win)
{
	if (TTF_Init() < 0)
		return(0);
	win->ttf_text = NULL;
	win->ttf_text = TTF_OpenFont("monofonto.ttf", 80);
	if (win->ttf_text == NULL)
		return(0);
	return (1);
}

int ft_init_window(t_win *win)
{
	if (!(win->window = SDL_CreateWindow("Virtual Corewar Arena",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		win->width, win->height, SDL_WINDOW_RESIZABLE)))
		return (0);
	if (!(win->renderer = SDL_CreateRenderer(win->window, -1, 0)))
		printf("SDL_Init failed: %s\n", SDL_GetError());
	if (SDL_SetRenderDrawColor(win->renderer, 0, 0, 0, 255))
		printf("toto0");
	SDL_RenderClear(win->renderer);
	return (1);
}

int ft_init_sdl(t_win *win)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (0);
	ft_init_window(win);
	ft_init_font(win);
	return (1);
}

void ft_print_text(t_win *win, char *str, int line)
{
	SDL_Color white = {255, 255, 255, 255};

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(win->ttf_text, str, white);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(win->renderer, surfaceMessage);
	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 66 * OCT_W;  //controls the rect's x coordinate 
	Message_rect.y = line * OCT_H; // controls the rect's y coordinte
	Message_rect.w = ft_strlen(str) * 7; // 21 controls the width of the rect
	Message_rect.h = OCT_H; // controls the height of the rect
	SDL_RenderCopy(win->renderer, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

void ft_str_create_and_print(t_win *win, char *str1, char *str2, int line)
{
	char *dest;

	if(!(dest = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1))))
		return ;
	dest = ft_strcat(dest, str1);
	dest = ft_strcat(dest, str2);
	// free(str1);
	// free(str2);
	ft_print_text(win, dest, line);
	// free(dest);
}

void ft_put_players(t_win *win, int line)
{
	// t_storage tmp = storage->champion;

	// while (tmp)
	// {
		ft_str_create_and_print(win, "Player : ", "toto", line); //tmp->name, *line);
		line++;
		ft_str_create_and_print(win, "Last_live :                 ", "12", line); //ft_itoa(lastlive), *line);
		line++;
		// ft_str_create_and_print(win, "Lives in current periode :    ", ft_itoa(lastlive), *line);
		// *line += 2;
		// tmp = tmp->next;
	// }
}


void ft_put_infos(t_win *win)
{
	int line = 1;

	
	if (win->pause)
		ft_print_text(win, "PAUSE", line);
	else
		ft_print_text(win, "RUNNING", line);
	line += 2;
	ft_str_create_and_print(win, "Cycles : ", "12", line); //ft_itoa(storage->cycle), line);
	line++;
	ft_str_create_and_print(win, "Processes : ", "1", line); //ft_itoa(win->nb_process), line);
	line += 2;
	ft_put_players(win, line);
	line+= 5;
	// ft_str_create_and_print(win, "CYCLE_TO_DIE :", ft_itoa(win->nb_process), line);
	// ft_str_create_and_print(win, "CYCLE_DELTA : ", ft_itoa(win->nb_process), line);
	// ft_str_create_and_print(win, "NBR_LIVE : ", ft_itoa(win->nb_process), line);
	// ft_str_create_and_print(win, "MAX_CHECKS : ", ft_itoa(win->nb_process), line);

}

int ft_put_treads(t_win *win)
{

	int w = 128;
	SDL_Rect rect;

	win->texture = SDL_CreateTexture(win->renderer, SDL_PIXELFORMAT_RGBA8888, 
                               SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);
	
	SDL_SetRenderDrawColor(win->renderer, 100, 100, 100, 255); /* On dessine en gris */

	
	SDL_SetRenderTarget(win->renderer, win->texture);  // On va dessiner sur la texture 
	while (w < 64 * 64)
	{
		write(1, "totototo\n", 9);
		printf("w = %d\n", w);
		rect.x = w % 64 * OCT_W;
		rect.y = w / 64 * OCT_H;
		rect.w = OCT_W;
		rect.h = OCT_H;
		SDL_RenderFillRect(win->renderer, &rect);
		w = w * 2;
	}
	SDL_SetRenderTarget(win->renderer, NULL);
	// SDL_Rect rect;

	// win->texture = SDL_CreateTexture(win->renderer, SDL_PIXELFORMAT_RGBA8888, 
 //                               SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);
	// SDL_SetRenderTarget(win->renderer, win->texture); /* On va dessiner sur la texture */
	// SDL_SetRenderDrawColor(win->renderer, 150, 0, 150, 255); /* On dessine en gris */
	// // // while (thread)
	// // // {
	// int where = 128;
	// // SDL_RenderFillRect(win->renderer, &rect);
	// rect.x = where % 64 * OCT_W;
	// rect.y = where / 64 * OCT_H;
	// rect.h = OCT_H;
	// rect.w = OCT_W;
	// SDL_RenderFillRect(win->renderer, &rect);
	// // int where = 999;
	// // // SDL_RenderFillRect(win->renderer, &rect);
	// // rect.x = where % 64 * OCT_W;
	// // rect.y = where / 64 * OCT_H;
	// // rect.h = OCT_H;
	// // rect.w = OCT_W;
	// // SDL_RenderFillRect(win->renderer, &rect);
	// // }
	// SDL_SetRenderTarget(win->renderer, NULL);
	SDL_RenderCopy(win->renderer, win->texture, NULL, &win->rect);
	SDL_DestroyTexture(win->texture);
	return(1);
}

char *ft_tab_int_to_string(int *tab)
{
	char *line;
	int i = 0;


	if (!(line = malloc(sizeof(char) * (64 * 4 + 1))))
		return (NULL);
	while (i < 64)
	{
		line = ft_strcat(line, " ");
		line = ft_strcat(line, ft_itoa_hexa(tab[i]));
		line = ft_strcat(line, " ");
		i++;
	}
	return (line);
}

void ft_write_line_in_renderer(t_win *win, int y, char *str)
{
	SDL_Color white = {255, 255, 255, 255};

	// write(1, str, 256);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(win->ttf_text, str, white);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(win->renderer, surfaceMessage);
	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = y; // controls the rect's y coordinte
	Message_rect.w = OCT_W * 64; // 21 controls the width of the rect
	Message_rect.h = OCT_H; // controls the height of the rect
	SDL_RenderCopy(win->renderer, Message, NULL, &Message_rect);
	// SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}


int ft_print_grid(t_win *win)
{
	int i = 0;
	int j = 0;
	int **grid = NULL;

	grid = (int **)malloc(sizeof(int *) * 64);

	srand(time(NULL));
	while(i < 64)
	{
		j = 0;
		grid[i] = malloc (sizeof(int) * 64);
		while (j < 64)
		{
			grid[i][j] = rand() % 255;
			j++;
		}
		i++;
	}

	i = 0;
	while(i < 64)
	{
		ft_write_line_in_renderer(win, i * OCT_H, ft_tab_int_to_string(grid[i]));
		i++;
	}
	i = -1;
	while(++i < 64)
		free(grid[i]);
	free(grid);
	return (1);
}

void ft_print_game(t_win *win)
{
	ft_put_treads(win);
	write(1, "ah", 2);
	ft_print_grid(win);

	write(1, "bh", 2);
//	if(end)
//		ft_put_infos_end(win);
//	else
		ft_put_infos(win);
}


int main()
{
	int gameRunning = 1;
	write(1, "bh", 2);
	t_win win;
	write(1, "bh", 2);
	// bzero(win);
	// win->pause = 0;
	write(1, "bh", 2);
	ft_init_win(&win);
	write(1, "bh", 2);
	ft_init_sdl(&win);
	write(1, "bh", 2);
	SDL_Event event;
	while (gameRunning)
	{
    	if (SDL_PollEvent(&event))
    	{
    	    if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
    		    gameRunning = false;
    	    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
    	    	win.pause = (win.pause == 1)? 0 : 1;
			SDL_RenderClear(win.renderer);
    	    ft_print_game(&win);
			SDL_RenderPresent(win.renderer);
    	}
    }
	write(1, "bh", 2);
	return(0);
}

