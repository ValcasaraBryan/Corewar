#include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>
#include "../op.h"
#include <math.h>
#include <unistd.h>
#include "./SDL2_ttf.framework/Headers/SDL_ttf.h"
#include <stdbool.h>
#define WIDTH 1900
#define HEIGHT 1152
#define WHITE 0xff0000
#define GREY 0x202020
# define P1 0x33cc33
# define P2 0x0099ff
# define P3 0xff00ff
# define P4 0xff9933
# define OCT_W 23
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
	TTF_Font		*ttf_player;
	TTF_Font		*ttf_text;
	SDL_Event		event;
	SDL_Renderer 	*renderer;
	SDL_Texture 	*texture;
	char			game_color[MEM_SIZE];
	char			game_process[MEM_SIZE];
	int				colors[4];
	int				width;
	int				height;
	int				text_height;
	int				text_start;
	int 			pause;
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


void ft_print_text(t_win *win, char *str, int line)
{
	SDL_Color Grey = {255, 255, 255, 255};

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(win->ttf_text, str, Grey);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(win->renderer, surfaceMessage);
	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 66 * OCT_W;  //controls the rect's x coordinate 
	Message_rect.y = line * OCT_H; // controls the rect's y coordinte
	Message_rect.w = ft_strlen(str) * 7; // 21 controls the width of the rect
	Message_rect.h = OCT_H; // controls the height of the rect
	// write(1, "a", 1);
	SDL_RenderCopy(win->renderer, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

// void ft_str_create_and_print(struct, char *str1, char *str2, line)
// {
// 	char *dest;

// 	if(!(dest = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str3) + 1))))
// 		return ;
// 	dest = ft_strcat(dest, str1);
// 	dest = ft_strcat(dest, str2);
// 	free(str1);
// 	free(str2);
// 	ft_print_text(struct, dest, line);
// 	free(dest);
// }

// void ft_put_players(t_win *win, int *line)
// {
// 	t_storage tmp = storage->champion;

// 	while (tmp)
// 	{
// 		ft_str_create_and_print(win, "Player -1 : ", tmp->name, *line);
// 		*line++;
// 		ft_str_create_and_print(win, "Last_live :                 ", ft_itoa(lastlive), *line);
// 		*line++;
// 		// ft_str_create_and_print(win, "Lives in current periode :    ", ft_itoa(lastlive), *line);
// 		// *line += 2;
// 		tmp = tmp->next;
// 	}
// }


// void ft_put_infos(t_win *win)
// {
// 	int line = 1;

	
// 	if (!win->pause)
// 		ft_print_text(win, "PAUSE", line);
// 	else
// 		ft_print_text(win, "RUNNING", line);
// 	line += 2;
// 	ft_str_create_and_print(win, "Cycles : ", ft_itoa(storage->cycle), line);
// 	line++;
// 	ft_str_create_and_print(win, "Processes : ", ft_itoa(win->nb_process), line);
// 	line += 2;
// 	ft_put_players(win, &line);
// 	line++;
// 	// ft_str_create_and_print(win, "CYCLE_TO_DIE :", ft_itoa(win->nb_process), line);
// 	// ft_str_create_and_print(win, "CYCLE_DELTA : ", ft_itoa(win->nb_process), line);
// 	// ft_str_create_and_print(win, "NBR_LIVE : ", ft_itoa(win->nb_process), line);
// 	// ft_str_create_and_print(win, "MAX_CHECKS : ", ft_itoa(win->nb_process), line);

// }

int	init_font(t_win *win)
{
	if (TTF_Init() < 0)
		return(0);
	win->ttf_player = NULL;
	win->ttf_player = TTF_OpenFont("Raleway-Regular.ttf", 50);
	win->ttf_text = NULL;
	win->ttf_text = TTF_OpenFont("Raleway-Regular.ttf", 12);
	if (win->ttf_player == NULL || win->ttf_text == NULL)
		return(0);
	return (1);
}
void ft_create_rect(t_win *win, int y, char *str);

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

char *ft_tab_int_to_string(int *tab)
{
	char *line;
	int i = 0;


	if (!(line = malloc(sizeof(char) * 257)))
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

int ft_put_treads(t_win *win)
{
	win->texture = SDL_CreateTexture(win->renderer, SDL_PIXELFORMAT_RGBA8888, 
                               SDL_TEXTUREACCESS_TARGET, 0, 0);
	SDL_Rect rect;
	SDL_SetRenderDrawColor(win->renderer, 100, 100, 100, 255); /* On dessine en violet */
	SDL_SetRenderTarget(win->renderer, win->texture); /* On va dessiner sur la texture */
	// while (thread)
	// {
	int where = 128;
	// SDL_RenderFillRect(win->renderer, &rect);
	rect.x = where % 64 * OCT_W;
	rect.y = where / 64 * OCT_H;
	rect.h = OCT_H;
	rect.w = OCT_W;
	// }
	SDL_RenderFillRect(win->renderer, &rect);
	SDL_SetRenderTarget(win->renderer, NULL);
	SDL_RenderCopy(win->renderer, win->texture, NULL, &rect);
}

int init_window(t_win *win)
{
	win->renderer = NULL;
	SDL_Event event;
	bool gameRunning = true;
	SDL_Surface *text = NULL;
	if (!(win->window = SDL_CreateWindow("Virtual Corewar Arena",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		win->width, win->height, SDL_WINDOW_RESIZABLE)))
		return(0);
	// put_line(win->surface, (t_point){50, 50}, (t_point){WIDTH - 50, 50}, WHITE);

	if (!(win->renderer = SDL_CreateRenderer(win->window, -1, 0)))
		printf("SDL_Init failed: %s\n", SDL_GetError());
	if (SDL_SetRenderDrawColor(win->renderer, 0, 0, 0, 255))
		printf("toto0");
	// SDL_RenderClear(win->renderer);
//	SDL_RenderPresent(renderer);


	TTF_Init();
	
	win->ttf_text = TTF_OpenFont("monofonto.ttf", 50); //this opens a font style and sets a size

	SDL_Color Gold = {215, 154, 16};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
	SDL_Color Grey = {255, 0, 0};
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(win->ttf_text, "00", Grey); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first


	SDL_Texture* Message = SDL_CreateTextureFromSurface(win->renderer, surfaceMessage); //now you can convert it into a texture

	// SDL_Rect Message_rect; //create a rect
	// Message_rect.x = 0;  //controls the rect's x coordinate 
	// Message_rect.y = 0; // controls the rect's y coordinte
	// Message_rect.w = 15; // controls the width of the rect
	// Message_rect.h = 15; // controls the height of the rect
	
	// SDL_RenderCopy(win->renderer, Message, NULL, &Message_rect);

	// Message_rect.x = 0;  //controls the rect's x coordinate 
	// Message_rect.y = 200; // controls the rect's y coordinte
	// Message_rect.w = 15; // controls the width of the rect
	// Message_rect.h = 15; // controls the height of the rect

	// SDL_RenderCopy(win->renderer, Message, NULL, &Message_rect);
	// SDL_RenderClear(win->renderer);
	//
	//SDL_RenderPresent(renderer);

	int i = 0;
	int j;
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
	write(1, "C", 1);

	
	ft_put_treads(win);
	// ft_put_infos(win);

	while(i < 64)
	{
		ft_create_rect(win, i * OCT_H, ft_tab_int_to_string(grid[i]));
		i++;
	}

	write(1, "D", 1);
	SDL_RenderPresent(win->renderer);

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
	TTF_CloseFont(win->ttf_text);
	TTF_Quit();
	SDL_Quit();
	return (1);
}

void ft_create_rect(t_win *win, int y, char *str)
{
	SDL_Color Grey = {255, 255, 255, 255};

	write(1, str, 256);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(win->ttf_text, str, Grey);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(win->renderer, surfaceMessage);
	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = y; // controls the rect's y coordinte
	Message_rect.w = OCT_W * 64; // 21 controls the width of the rect
	Message_rect.h = OCT_H; // controls the height of the rect
	// write(1, "a", 1);
	SDL_RenderCopy(win->renderer, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

int init_sdl(t_win *win)
{
	win->width = WIDTH;
	win->height = HEIGHT;
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
	win.pause = 0;
//	create_player(1, "toto");
//	create_player(2, "tata");
	init_sdl(&win);
	return(0);
}
