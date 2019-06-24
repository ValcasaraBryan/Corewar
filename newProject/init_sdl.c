

void ft_init_win(&win)
{
	win->renderer = NULL;
	win->ttf_text = NULL;
	win->width = WIDTH;
	win->height = HEIGHT;
}


int ft_init_font(t_win *win)
{
	if (TTF_Init() < 0)
		return(0);
	win->ttf_text = NULL;
	win->ttf_text = TTF_OpenFont("monofonto.ttf", 50);
	if (win->ttf_player == NULL || win->ttf_text == NULL)
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
	return (1);
}

int ft_init_sdl()
{
	t_win *win;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (0);
	ft_init_win(&win);
	ft_init_window(&win);
	ft_init_font(&win);
}

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
	SDL_RenderCopy(win->renderer, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);

}

void ft_str_create_and_print(struct, char *str1, char *str2, line)
{
	char *dest;

	if(!(dest = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1))))
		return ;
	dest = ft_strcat(dest, str1);
	dest = ft_strcat(dest, str2);
	free(str1);
	free(str2);
	ft_print_text(struct, dest, line);
	free(dest);
}

void ft_put_players(t_win *win, int *line)
{
	t_storage tmp = storage->champion;

	while (tmp)
	{
		ft_str_create_and_print(win, "Player -1 : ", tmp->name, *line);
		*line++;
		ft_str_create_and_print(win, "Last_live :                 ", ft_itoa(lastlive), *line);
		*line++;
		// ft_str_create_and_print(win, "Lives in current periode :    ", ft_itoa(lastlive), *line);
		// *line += 2;
		tmp = tmp->next;
	}
}


void ft_put_infos(t_win *win)
{
	int line = 1;

	
	if (!win->pause)
		ft_print_text(win, "PAUSE", line);
	else
		ft_print_text(win, "RUNNING", line);
	line += 2;
	ft_str_create_and_print(win, "Cycles : ", ft_itoa(storage->cycle), line);
	line++;
	ft_str_create_and_print(win, "Processes : ", ft_itoa(win->nb_process), line);
	line += 2;
	ft_put_players(win, &line);
	line++;
	// ft_str_create_and_print(win, "CYCLE_TO_DIE :", ft_itoa(win->nb_process), line);
	// ft_str_create_and_print(win, "CYCLE_DELTA : ", ft_itoa(win->nb_process), line);
	// ft_str_create_and_print(win, "NBR_LIVE : ", ft_itoa(win->nb_process), line);
	// ft_str_create_and_print(win, "MAX_CHECKS : ", ft_itoa(win->nb_process), line);

}

int ft_put_treads(t_win *win)
{
	SDL_Rect rect;
	win->texture = SDL_CreateTexture(win->renderer, SDL_PIXELFORMAT_RGBA8888, 
                               SDL_TEXTUREACCESS_TARGET, 0, 0);
	SDL_Rect rect;
	SDL_SetRenderDrawColor(win->renderer, 100, 100, 100, 255); /* On dessine en gris */
	SDL_SetRenderTarget(win->renderer, win->texture); /* On va dessiner sur la texture */
	// while (thread)
	// {
	int where = 128;
	// SDL_RenderFillRect(win->renderer, &rect);
	rect.x = where % 64 * OCT_W;
	rect.y = where / 64 * OCT_H;
	rect.h = OCT_H;
	rect.w = OCT_W;
	SDL_RenderFillRect(win->renderer, &rect);
	// }
	SDL_SetRenderTarget(win->renderer, NULL);
	SDL_RenderCopy(win->renderer, win->texture, NULL, &rect);
	SDL_DestroyTexture(texture);
	free(rect);
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

	write(1, str, 256);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(win->ttf_text, str, white);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(win->renderer, surfaceMessage);
	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = y; // controls the rect's y coordinte
	Message_rect.w = OCT_W * 64; // 21 controls the width of the rect
	Message_rect.h = OCT_H; // controls the height of the rect
	SDL_RenderCopy(win->renderer, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}


int ft_print_grid(t_win *win)
{
	int i = 0;

	while(i < 64)
	{
		ft_write_line_in_renderer(win, i * OCT_H, ft_tab_int_to_string(grid[i]));
		i++;
	}
	return (1);
}

void ft_print_game()
{
	ft_put_treads();
	ft_print_grid();
	if(end)
		ft_put_infos_end();
	else
		ft_put_infos();
}


