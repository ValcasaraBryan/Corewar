
// #include <SDL2/SDL_ttf.h>
// #include "../op.h"
#include <math.h>
#include <unistd.h>
#include <stdbool.h>
#define WIDTH 2300
#define HEIGHT 1152
#define WHITE 0xffffff
#define GREY 0x202020
# define P1 0x33cc33
# define P2 0x0099ff
# define P3 0xff00ff
# define P4 0xff9933
# define OCT_W 28
# define OCT_H 18
# define LETTER_W 7
#include <time.h>
#include <stdlib.h>
#include "corewar.h"

// typedef union					u_color
// {
// 	int				color;
// 	unsigned char	rgb[4];
// }					t_color;

// typedef struct		s_win
// {
// 	SDL_Window		*window;
// 	SDL_Surface		*surface;
// 	TTF_Font		*ttf_text;
// 	SDL_Event		event;
// 	SDL_Renderer 	*renderer;
// 	SDL_Texture 	*texture;
// 	SDL_Rect 		rect;
// 	int				colors[4];
// 	int				width;
// 	int				height;
// 	int				text_height;
// 	int				text_start;
// 	int 			pause;
// }					t_win;
// extern t_player *g_players;

SDL_Color	argb_to_sdl(Uint32 color)
{
	t_color	c;

	c = (t_color)((int)color);
	return ((SDL_Color){c.rgb[2], c.rgb[1], c.rgb[0], c.rgb[3]});
}

static int	ft_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*s;

	size = ft_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(s = (char *)malloc(size + 1)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[size] = '\0';
	while (n > 0)
	{
		s[size - 1] = n % 10 + 48;
		n = n / 10;
		--size;
	}
	return (s);
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

int ft_color_octet(int player)
{
	if (player == 0)
		return (WHITE);
	else if (player == 1)
		return (P1);
	else if (player == 2)
		return (P2);
	else if (player == 3)
		return (P3);
	else if (player == 4)
		return (P4);
	return (-1);
}

char	*ft_ctoa(char c)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void ft_fill_alphabet_color(t_storage **st, SDL_Texture ***tab_color, int color)
{
	int i = -1;
	SDL_Texture *tmp;

	while (++i < 37)
	{
	printf("coucouatt\n");
		if (i < 10)
			(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text, ft_itoa(i), argb_to_sdl(color));
		if (i < 36)
			(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text, ft_ctoa((char)i), argb_to_sdl(color));
		else
			(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text, " ", argb_to_sdl(color));
	printf("coucouat\n");
		(*tab_color)[i] = SDL_CreateTextureFromSurface((*st)->win->renderer, (*st)->win->surface);
	printf("coucoua\n");
		SDL_FreeSurface((*st)->win->surface);
	printf("coucou\n");
	}
}

int ft_init_alphabet_color(t_storage **st)
{
	printf("coucoua\n");
	if (!((*st)->win->tab_w = malloc(sizeof(*(*st)->win->tab_w) * 37)))
		return (0);
	printf("coucoub\n");
	ft_fill_alphabet_color(st, &(*st)->win->tab_w, WHITE);
	printf("coucouc\n");
	if (!((*st)->win->tab_b = malloc(sizeof(SDL_Texture *) * 37)))
		return (0);
	ft_fill_alphabet_color(st, &(*st)->win->tab_b, P1);
	if (!((*st)->win->tab_o = malloc(sizeof(SDL_Texture *) * 37)))
		return (0);
	ft_fill_alphabet_color(st, &(*st)->win->tab_o, P2);
	if (!((*st)->win->tab_v = malloc(sizeof(SDL_Texture *) * 37)))
		return (0);
	ft_fill_alphabet_color(st, &(*st)->win->tab_v, P3);
	if (!((*st)->win->tab_g = malloc(sizeof(SDL_Texture *) * 37)))
		return (0);
	ft_fill_alphabet_color(st, &(*st)->win->tab_g, P4);
	if(&(*st)->win->tab_g[0])
	{
		printf("ola\n");
		sleep(3);
	}
	return (1);
}

int ft_init_font(t_storage **st);

int ft_init_win(t_storage **st)
{
	t_win *win;
	if (!(win = malloc(sizeof(t_win *))))
		return (0);
	(*st)->win = win;
	printf("coucou1win\n");
	char c = 98;
	write(1, &c, 1);
	(*st)->win->pause = 0;
	printf("coucou1\n");
	// write(1, "ch", 2);
	(*st)->win->renderer = NULL;
	// write(1, "ch", 2);
	if (!ft_init_font(st))
		return (0);
	// write(1, "ch", 2);
	(*st)->win->width = WIDTH;
	// write(1, "ch", 2);
	(*st)->win->height = HEIGHT;
	// write(1, "ch", 2);
	if (!((*st)->win->rect = malloc(sizeof(SDL_Rect))))
		return (0);
	(*st)->win->rect->x = 0;
	(*st)->win->rect->y = 0;
	(*st)->win->rect->w = WIDTH;
	(*st)->win->rect->h = HEIGHT;
	(*st)->win->nb_threads = 0;

	printf("coucou123\n");
	ft_init_alphabet_color(st);
	printf("coucou1456\n");
	// if (!((*st)->win->tab_w = malloc(sizeof((*st)->win->tab_w) * 37)))
	// 	return (0);
	// int i = -1;
	// while (++i < 37)
	// {
	// 	if (i < 10)
	// 		(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text, ft_itoa(i), argb_to_sdl(WHITE));
	// 	if (i < 36)
	// 		(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text, ft_ctoa((char)i), argb_to_sdl(WHITE));
	// 	else
	// 		(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text, " ", argb_to_sdl(WHITE));
	// 	(*st)->win->tab_w[i] = SDL_CreateTextureFromSurface((*st)->win->renderer, (*st)->win->surface);
	// }
	printf("coucou1\n");
	return (1);
}


int ft_init_font(t_storage **st)
{
	if (TTF_Init() < 0)
		return (0);
	printf("coucouifont 2\n");
	// (*st)->win->ttf_text = NULL;
	(*st)->win->ttf_text = TTF_OpenFont("monofonto.ttf", 80);
	printf("coucofontt 23\n");
	if ((*st)->win->ttf_text == NULL)
		return (0);
	printf("coucoufont 24\n");
	return (1);
}

int ft_init_window(t_storage **st)
{
	if (!((*st)->win->window = SDL_CreateWindow("Virtual Corewar Arena",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		(*st)->win->width, (*st)->win->height, SDL_WINDOW_RESIZABLE)))
		return (0);
	if (!((*st)->win->renderer = SDL_CreateRenderer((*st)->win->window, -1, 0)))
		printf("SDL_Init failed: %s\n", SDL_GetError());
	if (SDL_SetRenderDrawColor((*st)->win->renderer, 0, 0, 0, 255))
		printf("toto0");
	SDL_RenderClear((*st)->win->renderer);
	return (1);
}

int ft_init_sdl(t_storage **st)
{
	printf("coucouinit\n");
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (0);
	printf("coucouinit 2\n");
	if (!ft_init_window(st))
		return (0);
	printf("coucouinit 23\n");
	printf("coucouinit 24\n");
	return (1);
}

void ft_print_text(t_storage **st, char *str, int line)
{
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;
	SDL_Rect rect;

	surfaceMessage = TTF_RenderText_Solid((*st)->win->ttf_text, str, argb_to_sdl(WHITE));
	Message = SDL_CreateTextureFromSurface((*st)->win->renderer, surfaceMessage);
	rect.x = 66 * OCT_W;  //controls the rect's x coordinate 
	rect.y = line * OCT_H; // controls the rect's y coordinte
	rect.w = ft_strlen(str) * 9; // 21 controls the width of the rect
	rect.h = OCT_H; // controls the height of the rect
	SDL_RenderCopy((*st)->win->renderer, Message, NULL, &rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

void ft_print_name_colored(t_storage **st, char *intro, char *name , int num_player)
{
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;
	SDL_Rect rect;

	surfaceMessage = TTF_RenderText_Solid((*st)->win->ttf_text, name, argb_to_sdl(ft_color_octet(num_player)));
	Message = SDL_CreateTextureFromSurface((*st)->win->renderer, surfaceMessage);
	rect.x = 66 * OCT_W + ft_strlen(intro) * 9;  //controls the rect's x coordinate 
	rect.y = (8 + (num_player - 1) * 4) * OCT_H; // controls the rect's y coordinte
	rect.w = ft_strlen(name) * 9; // 21 controls the width of the rect
	rect.h = OCT_H; // controls the height of the rect
	SDL_RenderCopy((*st)->win->renderer, Message, NULL, &rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

void ft_str_create_and_print(t_storage **st, char *str1, char *str2, int line)
{
	char *dest;

	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1))))
		return ;
	bzero(dest, ft_strlen(str1) + ft_strlen(str2) + 1);
	// printf("%p\n", &dest);
	// write(1, "\n dest1 = ", 10);
	// write(1, dest, ft_strlen(dest));
	dest = ft_strcat(dest, str1);
	dest = ft_strcat(dest, str2);
	// free(str2);
	// write(1, "\n str1 = ", 9);
	// write(1, str1, ft_strlen(str1));
	// write(1, "\n str2 = ", 9);
	// write(1, str2, ft_strlen(str2));
	// write(1, "\n dest = ", 9);
	// write(1, dest, ft_strlen(dest));
	// write(1, "\n", 1);
	ft_print_text(st, dest, line);
	free(dest);
}

int ft_put_players(t_storage **st, int line)
{
	t_champion *tmp = (*st)->first_champion;
	int nb_players = 0;

	while (tmp)
	// while (++nb_players <= 3)
	{
		nb_players++;
		char *str;
		str = malloc(sizeof(char) * (10 + ft_size(1)));
		bzero(str, 10 + ft_size(12));
		str = ft_strcat(str, "Player ");
		str = ft_strcat(str, ft_itoa_hexa(1));
		str = ft_strcat(str, ": ");
		ft_str_create_and_print(st, str, "\0", line); //tmp->name, *line);
		ft_print_name_colored(st, str, tmp->name, nb_players);
		line++;
		ft_str_create_and_print(st, "   Last_live :                   ", "12", line); //ft_itoa(lastlive), *line);
		line++;
		ft_str_create_and_print(st, "   Lives in current periode :    ", "0", line);//ft_itoa(lastlive), *line);
		line += 2;
		free(str);
		tmp = tmp->next;
	}
	return (nb_players * 3);
}


void ft_put_infos(t_storage **st)
{
	int line = 1;

	if ((*st)->win->pause)
		ft_print_text(st, "PAUSE", line);
	else
		ft_print_text(st, "RUNNING", line);
	line += 2;
	ft_str_create_and_print(st, "Cycles : ", ft_itoa((*st)->cycle), line);
	line += 2;
	ft_str_create_and_print(st, "Processes : ", ft_itoa((*st)->win->nb_threads), line);
	line += 3;
	line += ft_put_players(st, line) + 2;
	ft_str_create_and_print(st, "CYCLE_TO_DIE : ", ft_itoa(CYCLE_TO_DIE), line);
	line += 2;
	ft_str_create_and_print(st, "CYCLE_DELTA : ", ft_itoa(CYCLE_DELTA), line);
	line += 2;
	ft_str_create_and_print(st, "NBR_LIVE : ", ft_itoa((*st)->nb_live_current), line);
	line += 2;
	ft_str_create_and_print(st, "MAX_CHECKS : ", ft_itoa(MAX_CHECKS), line);

}

int ft_put_treads(t_storage **st)
{
	t_thread *tmp;

	tmp = (*st)->first_thread;
	(*st)->win->nb_threads = 0;
	(*st)->win->texture = SDL_CreateTexture((*st)->win->renderer, SDL_PIXELFORMAT_RGBA8888,
                               SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);
	 // On va dessiner sur la texture	
	SDL_SetRenderTarget((*st)->win->renderer, (*st)->win->texture);
	SDL_SetRenderDrawColor((*st)->win->renderer, 0, 0, 0, 255);
	SDL_RenderFillRect((*st)->win->renderer, &(SDL_Rect){0, 0, WIDTH, HEIGHT});
	SDL_SetRenderDrawColor((*st)->win->renderer, 100, 100, 100, 255);
	while (tmp != NULL)
	{
		printf("w = %d\n", tmp->where);
		(*st)->win->rect->x = tmp->where % 64 * OCT_W;
		(*st)->win->rect->y = tmp->where / 64 * OCT_H;
		(*st)->win->rect->w = OCT_W;
		(*st)->win->rect->h = OCT_H;
		SDL_RenderFillRect((*st)->win->renderer, (*st)->win->rect);
		tmp = tmp->next;
		(*st)->win->nb_threads++;
	}
	SDL_SetRenderTarget((*st)->win->renderer, NULL);
	SDL_RenderCopy((*st)->win->renderer, (*st)->win->texture, NULL, &(SDL_Rect){0, 0, WIDTH, HEIGHT});
	SDL_DestroyTexture((*st)->win->texture);
	(*st)->win->texture = NULL;
	return(1);
}

/*int ft_put_treads(t_storage **st)
{
	t_thread *tmp = (*st)->first_thread;
	SDL_Rect *rect;
	SDL_Texture *texture;

	(*st)->win->nb_threads = 0;
	if (!(rect = malloc(sizeof(SDL_Rect))))
		return (0);
	texture = SDL_CreateTexture((*st)->win->renderer, SDL_PIXELFORMAT_RGBA8888, 
                               SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);

	SDL_RenderClear((*st)->win->renderer);

	SDL_SetRenderTarget((*st)->win->renderer, texture);  // On va dessiner sur la texture
	SDL_SetRenderDrawColor((*st)->win->renderer, 0, 0, 0, 255);
	SDL_RenderFillRect((*st)->win->renderer, &(SDL_Rect){0, 0, WIDTH, HEIGHT});
	SDL_SetRenderDrawColor((*st)->win->renderer, 100, 100, 100, 255);
	while (tmp)
	{
		printf("w = %d\n", tmp->where);
		rect->x = tmp->where % 64 * OCT_W;
		rect->y = tmp->where / 64 * OCT_H;
		rect->w = OCT_W;
		rect->h = OCT_H;
		SDL_RenderFillRect((*st)->win->renderer, rect);
		tmp = tmp->next;
		(*st)->win->nb_threads++;
	}
	SDL_SetRenderTarget((*st)->win->renderer, NULL);
	SDL_RenderCopy((*st)->win->renderer, texture, NULL, &(*st)->win->rect);
	SDL_DestroyTexture(texture);
	texture = NULL;
	return(1);
}*/

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

void ft_write_octet_in_renderer(t_storage **st, char *str, int grid2)
{
	/*SDL_Surface *surface_message;
	SDL_Texture *message;

	surface_message = TTF_RenderText_Solid((*st)->win->ttf_text, str, argb_to_sdl(grid2));
	message = SDL_CreateTextureFromSurface((*st)->win->renderer, surface_message);
	// SDL_RenderCopy((*st)->win->renderer, message, NULL, rect);
	SDL_FreeSurface(surface_message);
	SDL_DestroyTexture(message);*/





	(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text, str, argb_to_sdl(grid2));
	SDL_RenderCopy((*st)->win->renderer, (*st)->win->message, NULL, (*st)->win->rect);
	SDL_FreeSurface((*st)->win->surface);
	//SDL_DestroyTexture((*st)->win->message);





	free(str);
}



/*
void ft_write_octet_in_renderer(t_storage **st, int i, int j)
{
	// SDL_Surface *surface_message;
	// SDL_Texture *message;

	(*st)->win->rect.x = j * OCT_W + OCT_W / 6;
	(*st)->win->rect.y = i * OCT_H;
	(*st)->win->rect.w = 2 * OCT_W / 3;
	(*st)->win->rect.h = OCT_H;
	(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text, ft_itoa_hexa((*st)->grid[i][j]), argb_to_sdl((*st)->color_grid[i][j]));
	(*st)->win->message = SDL_CreateTextureFromSurface((*st)->win->renderer, (*st)->win->surface);
	SDL_SetRenderTarget((*st)->win->renderer, (*st)->win->texture);  // On va dessiner sur la texture
	SDL_RenderCopy((*st)->win->renderer, (*st)->win->message, NULL, &(*st)->win->rect);
	SDL_FreeSurface((*st)->win->surface);
	SDL_DestroyTexture((*st)->win->message);
	// free(str);
}*/

/*
void ft_create_rect(t_storage **st, int i, char *str)
{
	(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text, str, argb_to_sdl(WHITE));
	(*st)->win->message = SDL_CreateTextureFromSurface((*st)->win->renderer, (*st)->win->surface);
	SDL_Rect Message_rect;
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = i * OCT_H;
	Message_rect.w = OCT_W * 64; // controls the width of the rect
	Message_rect.h = OCT_H;
	SDL_RenderCopy((*st)->win->renderer, (*st)->win->message, NULL, &Message_rect);
	SDL_FreeSurface((*st)->win->surface);
	SDL_DestroyTexture((*st)->win->message);

}

void ft_print_grid(t_storage **st)
{
	int i = 0;
	while (i < 64)
	{
		ft_create_rect(st, i, ft_tab_int_to_string((*st)->grid[i]));
		i++;
	}
}
*/

SDL_Texture *ft_grep_caract( SDL_Texture **tab, char c)
{
	// printf("coucou ici c = %c\n", c);
	if (c >= '0' && c <= '9')
	{
		// printf("CHIFFRE c = %c\n", c);
		return (tab[c - 48]);
	}
	if (c >= 'a' && c <= 'z')
	{
		// printf("LETTRE c = %c\n", c);
		return (tab[c - 97 + 10]);
	}
	return (NULL);
}

SDL_Texture *ft_grep_texture(t_storage **st, char c, int color)
{
	// if (color)
		// printf("coucou là color = %d\n", color);
	if (color == 0)
	{
		// printf("color = %c et ", color);
		return (ft_grep_caract((*st)->win->tab_w, c));
	}
	if (color == 1)
	{
		// printf("color = %c et ", color);
		return (ft_grep_caract((*st)->win->tab_b, c));
	}
	if (color == 2)
	{
		// printf("color = %c et ", color);
		return (ft_grep_caract((*st)->win->tab_o, c));
	}
	if (color == 3)
	{
		// printf("color = %c et ", color);
		return (ft_grep_caract((*st)->win->tab_v, c));
	}
	else if (color == 4)
	{
		// printf("color = %c et ", color);
		return (ft_grep_caract((*st)->win->tab_g, c));
	}
	return (NULL);
}

void ft_write_caract_in_renderer(t_storage **st, int i, int j, char *str)
{
	int k = -1;
	while (++k < 4)
	{
		// printf("                ah bon i = %d j = %d\n", i , j);
		(*st)->win->rect->y = i * OCT_H;
		(*st)->win->rect->x = j * OCT_W + k * LETTER_W;
		(*st)->win->rect->h = OCT_H;
		(*st)->win->rect->w = LETTER_W;
		if(!((*st)->win->tab_w)[36])
			printf("TA MERE");
		if (k == 0 || k == 3)
			SDL_RenderCopy((*st)->win->renderer, (*st)->win->tab_w[36], NULL, (*st)->win->rect);
		else
		{
			// printf("str = %s c = %c\n", str, str[k - 1]);
			SDL_RenderCopy((*st)->win->renderer, ft_grep_texture(st, str[k - 1], (*st)->color_grid[i][j]), NULL, (*st)->win->rect);
		}
	}
}

void ft_print_grid(t_storage **st)
{
	int i = 0;
	int j = 0;

	(*st)->win->message = SDL_CreateTextureFromSurface((*st)->win->renderer, (*st)->win->surface);
	while(i < 64)
	{
		j = 0;
		while (j < 64)
		{
			ft_write_caract_in_renderer(st, i, j, ft_itoa_hexa((*st)->grid[i][j]));
			j++;
		}
		i++;
	}
}


/*
void ft_print_grid(t_storage **st)
{
	int i = 0;
	int j = 0;

	(*st)->win->message = SDL_CreateTextureFromSurface((*st)->win->renderer, (*st)->win->surface);
	while(i < 64)
	{
		j = 0;
		while (j < 64)
		{
			(*st)->win->rect->x = j * OCT_W + OCT_W / 6;
			(*st)->win->rect->y = i * OCT_H;
			(*st)->win->rect->w = 2 * OCT_W / 3;
			(*st)->win->rect->h = OCT_H;

			ft_write_octet_in_renderer(st, ft_itoa_hexa((*st)->grid[i][j]), ft_color_octet((*st)->color_grid[i][j]));
			j++;
		}
		i++;
	}
}
*/

int ft_print_game(t_storage **st)
{

	printf("coucou\n");
    // if (SDL_PollEvent(&(*st)->win->event))
    // {

	ft_put_treads(st);
	ft_print_grid(st);
	ft_put_infos(st);
	SDL_RenderPresent((*st)->win->renderer);
    SDL_RenderClear((*st)->win->renderer);
        // sleep(1);
    // }
    return (1);
}


// int main()
// {
// 	int gameRunning = 1;
// 	t_win win;
// 	// bzero(win);
// 	// win->pause = 0;
// 	ft_init_win(&win);
// 	ft_init_sdl(&win);
// 	while (gameRunning)
// 	{
//     	if (SDL_PollEvent(&win.event))
//     	{
//     	    if (win.event.type == SDL_QUIT ||win. event.key.keysym.sym == SDLK_ESCAPE)
//     		    gameRunning = false;
//     	    if (win.event.type == SDL_KEYDOWN && win.event.key.keysym.sym == SDLK_SPACE)
//     	    	win.pause = (win.pause == 1)? 0 : 1;
//     	    ft_print_game(&win);
//     	}
//     }
//     SDL_DestroyWindow(win.window);
       // SDL_DestroyRenderer((*st)->win->renderer);
// 		TTF_Quit();
//     SDL_Quit();
// 	// write(1, "bh", 2);
// 	return(0);
// }

