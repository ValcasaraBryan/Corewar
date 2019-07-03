#include <corewar.h>

void		ft_free_visu(t_storage **st)
{
	if (st == NULL || *st == NULL || (*st)->win == NULL)
		return ;
	if ((*st)->win->rect)
		free((*st)->win->rect);
	if ((*st)->win->event)
		free((*st)->win->event);
	if ((*st)->win->tab_b)
		free((*st)->win->tab_b);
	if ((*st)->win->tab_o)
		free((*st)->win->tab_o);
	if ((*st)->win->tab_v)
		free((*st)->win->tab_v);
	if ((*st)->win->tab_g)
		free((*st)->win->tab_g);

	printf("fff\n");
	if ((*st)->win->surface)
		SDL_FreeSurface((*st)->win->surface);
	if ((*st)->win->renderer)
		SDL_DestroyRenderer((*st)->win->renderer);
	if ((*st)->win->texture)
		SDL_DestroyTexture((*st)->win->texture);
	if ((*st)->win->message)
		SDL_DestroyTexture((*st)->win->message);
	if ((*st)->win->window)
		SDL_DestroyWindow((*st)->win->window);
	if (TTF_WasInit())
	{
		TTF_CloseFont((*st)->win->ttf_text);
		TTF_Quit();
	}
	SDL_Quit();
	free((*st)->win);
}