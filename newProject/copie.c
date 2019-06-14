#include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>
#include "../op.h"
#include <math.h>
#include <unistd.h>
#include "./SDL2_ttf.framework/Headers/SDL_ttf.h"
#include <stdbool.h>
#define WIDTH 1200
#define LENGTH 1000
#define WHITE 0xff0000
#define GREY 0x202020
# define P1 0x33cc33
# define P2 0x0099ff
# define P3 0xff00ff
# define P4 0xff9933

typedef union					u_color
{
	int				color;
	unsigned char	rgb[4];
}					t_color;

typedef struct		s_win
{
	SDL_Window		*window;
	SDL_Surface		*surface;
	TTF_Font		*ttf_player;
	TTF_Font		*ttf_text;
	SDL_Event		event;
	char			game_color[MEM_SIZE];
	char			game_process[MEM_SIZE];
	int				colors[4];
	int				width;
	int				length;
	int				text_height;
	int				text_start;
}					t_win;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct s_player
{
	struct s_player *next;
	int num;
	char* name;
}				t_player;

// extern t_player *g_players;

SDL_Color	argb_to_sdl(Uint32 color)
{
	t_color	c;

	c = (t_color)((int)color);
	return ((SDL_Color){c.rgb[2], c.rgb[1], c.rgb[0], c.rgb[3]});
}

void		put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	((Uint32 *)surface->pixels)[y * surface->w + x] = pixel;
}

void		put_line(SDL_Surface *surface, t_point start, t_point end
		, Uint32 pixel)
{
	t_point		d;
	t_point		s;
	int			err1;
	int			err2;

	d.x = abs(start.x - end.x);
	d.y = abs(start.y - end.y);
	s.x = -1 + 2 * (start.x < end.x);
	s.y = -1 + 2 * (start.y < end.y);
	err1 = ((d.x > d.y) * d.x + (d.x <= d.y) * -d.y) / 2;
	while (1)
	{
		put_pixel(surface, start.x, start.y, pixel);
		if (start.x == end.x && start.y == end.y)
			break ;
		err2 = err1;
		err1 -= d.y * (err2 > -d.x);
		start.x += s.x * (err2 > -d.x);
		err1 += d.x * (err2 < d.y);
		start.y += s.y * (err2 < d.y);
	}
}

void		put_text(SDL_Surface *surface, SDL_Surface *text, int x, int y)
{
	SDL_BlitSurface(text, NULL, surface, &((SDL_Rect){x, y, 0, 0}));
}

/*void	put_players(t_win *win, int nb_players, int colors[4])
{
	char		str[256];
	t_player	*player;
	SDL_Surface	*tmp;

	player = g_players;
	while (player != NULL)
	{
		strcpy(str, "Player 1 : toto\n");
		tmp = TTF_RenderText_Blended(win->ttf_player, str,
									argb_to_sdl(colors[nb_players - 1]));
		put_text(win->surface, tmp, 1088 + 125,
				50 + (nb_players - 1) * 75);
		SDL_FreeSurface(tmp);
		player = player->next;
		nb_players--;
	}
}*/

int	init_font(t_win *win)
{
	if (TTF_Init() < 0)
		return(0);
	win->ttf_player = NULL;
	win->ttf_player = TTF_OpenFont("Raleway-Regular.ttf", 20);
	win->ttf_text = NULL;
	win->ttf_text = TTF_OpenFont("Raleway-Regular.ttf", 12);
	if (win->ttf_player == NULL || win->ttf_text == NULL)
		return(0);
	return (1);
}

int init_window(t_win *win)
{
	SDL_Renderer *renderer = NULL;
	SDL_Event event;
	bool gameRunning = true;
	// TTF_Font *police = NULL;
	// SDL_Color Black = {0, 0, 0};
	SDL_Surface *text = NULL;
	// SDL_Surface *surfText = NULL;
	// SDL_Rect position;
	if (!(win->window = SDL_CreateWindow("Virtual Corewar Arena",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		win->width, win->length, SDL_WINDOW_RESIZABLE)))
		return(0);
	// win->surface = SDL_GetWindowSurface(win->window);
	// SDL_SetWindowBordered(win->window, SDL_TRUE);
	// SDL_SetSurfaceAlphaMod(win->surface, 255);
	// SDL_SetSurfaceBlendMode(win->surface, SDL_BLENDMODE_NONE);
	// put_line(win->surface, (t_point){50, 50}, (t_point){WIDTH - 50, 50}, WHITE);
	// put_line(win->surface, (t_point){50, 50}, (t_point){50, LENGTH - 50}, WHITE);
	// put_line(win->surface, (t_point){WIDTH - 50, 50}, (t_point){WIDTH - 50, LENGTH - 50}, WHITE);
	// put_line(win->surface, (t_point){50, LENGTH - 50}, (t_point){WIDTH - 50, LENGTH - 50}, WHITE);
	// SDL_FillRect(win->surface, NULL, GREY);
	if (!(renderer = SDL_CreateRenderer(win->window, -1, 0)))
		printf("SDL_Init failed: %s\n", SDL_GetError());
	if (SDL_SetRenderDrawColor(renderer, 215, 154, 16, 255))
		printf("toto0");
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);


	TTF_Init();
	// TTF_OpenFont("browzko.ttf", 30);
	// text = TTF_RenderText_Blended(police, "Salut Camille", Black);
	// position.x = 0;
	// position.y = 0;
	// SDL_BlitSurface(text, NULL, SDL_GetWindowSurface(win->window), &position);
	
	TTF_Font* Sans = TTF_OpenFont("browzko.ttf", 100); //this opens a font style and sets a size

	SDL_Color White = {215, 154, 16};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00\n 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = 0; // controls the rect's y coordinte
	Message_rect.w = 1000; // controls the width of the rect
	Message_rect.h = 200; // controls the height of the rect
	
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	// SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	while (gameRunning)
	{
    	if (SDL_PollEvent(&event))
    	{
    	    if (event.type == SDL_QUIT)
    	    {
    		    gameRunning = false;
    	    }
    	}
    }
	//tmp = TTF_RenderText_Blended(win->ttf_text, str,
	//								argb_to_sdl(WHITE));
   // SDL_Flip(win->surface);
	// sleep(5);
	//SDL_RenderFillRect(renderer, &rect);
	// sleep(5);

	// SDL_PumpEvents();
	// SDL_Delay(5000);
	TTF_CloseFont(Sans);
	TTF_Quit();
	SDL_Quit();
	return (1);
}

int init_sdl(t_win *win)
{
	win->width = WIDTH;
	win->length = LENGTH;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (0);
	// SDL_GL_SetSwapInterval(1);
	init_window(win);
	init_font(win);
//	put_players(win, 2, (int[4]){P1, P2, P3, P4});
	//put_player(t);
	return(1);
}

void	*ft_memalloc(size_t len)
{
	char	*tmp;

	if ((tmp = (char*)malloc(sizeof(*tmp) * len)) == 0)
		return (NULL);
	bzero(tmp, len);
	return (tmp);
}

/*int			create_player(int number, char *str)
{
	t_player	*new;

	if (!(new = ft_memalloc(sizeof(t_player) + 1)))
		return (-1);
	new->next = g_players;
	new->num = number;
	strcpy(new->name, str);
	// new->live = 0;
	g_players = new;
	return (0);
}*/

int main ()
{
	t_win win;

//	create_player(1, "toto");
//	create_player(2, "tata");
	init_sdl(&win);
	return(0);
}














