/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:55:52 by glebouch          #+#    #+#             */
/*   Updated: 2019/07/02 15:55:55 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

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

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;

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

int			ft_fill_alphabet_color(t_storage **st, SDL_Texture ***tab,
	int color)
{
	int		i;

	i = -1;
	while (++i < 37)
	{
		if (i < 10)
			(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text,
				ft_itoa(i), argb_to_sdl(color));
		else if (i < 36)
			(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text,
				ft_ctoa((char)(i + 87)), argb_to_sdl(color));
		else
			(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text,
				" ", argb_to_sdl(color));
		if ((*st)->win->surface == NULL)
			return (FAILURE);
		if (((*tab)[i] = SDL_CreateTextureFromSurface((*st)->win->renderer,
			(*st)->win->surface)) == NULL)
		{
			SDL_FreeSurface((*st)->win->surface);
			return (FAILURE);
		}
		SDL_FreeSurface((*st)->win->surface);
	}
	return (SUCCESS);
}

int			ft_init_alphabet_color(t_storage **st)
{
	if (!((*st)->win->tab_w = malloc(sizeof(*(*st)->win->tab_w) * 37)))
		return (FAILURE);
	if ((ft_fill_alphabet_color(st, &(*st)->win->tab_w, WHITE)) != SUCCESS)
		return (FAILURE);
	if (!((*st)->win->tab_b = malloc(sizeof(SDL_Texture *) * 37)))
		return (FAILURE);
	if ((ft_fill_alphabet_color(st, &(*st)->win->tab_b, P1)) != SUCCESS)
		return (FAILURE);
	if (!((*st)->win->tab_o = malloc(sizeof(SDL_Texture *) * 37)))
		return (FAILURE);
	if ((ft_fill_alphabet_color(st, &(*st)->win->tab_o, P2)) != SUCCESS)
		return (FAILURE);
	if (!((*st)->win->tab_v = malloc(sizeof(SDL_Texture *) * 37)))
		return (FAILURE);
	if ((ft_fill_alphabet_color(st, &(*st)->win->tab_v, P3)) != SUCCESS)
		return (FAILURE);
	if (!((*st)->win->tab_g = malloc(sizeof(SDL_Texture *) * 37)))
		return (FAILURE);
	if ((ft_fill_alphabet_color(st, &(*st)->win->tab_g, P4)) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int			ft_init_win(t_storage **st)
{
	(*st)->win->pause = 0;
	if (TTF_Init() < 0)
		return (FAILURE);
	if (((*st)->win->ttf_text = TTF_OpenFont("monofonto.ttf", 80)) == NULL)
		return (FAILURE);
	if (!((*st)->win->rect = malloc(sizeof(SDL_Rect))))
		return (FAILURE);
	if (!((*st)->win->event = malloc(sizeof(SDL_Event))))
		return (FAILURE);
	(*st)->win->nb_threads = 0;
	if (ft_init_alphabet_color(st) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int			ft_init_sdl(t_storage **st)
{
	t_win	*win;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (FAILURE);
	if (!(win = malloc(sizeof(t_win *))))
		return (FAILURE);
	(*st)->win = win;
	if (((*st)->win->window = SDL_CreateWindow("Virtual Corewar Arena",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE)) == NULL)
		return (FAILURE);
	if (((*st)->win->renderer = SDL_CreateRenderer((*st)->win->window, -1, 0))
		== NULL)
		return (FAILURE);
	if (SDL_SetRenderDrawColor((*st)->win->renderer, 0, 0, 0, 255) < 0)
		return (FAILURE);
	if (SDL_RenderClear((*st)->win->renderer) < 0)
		return (FAILURE);
	return (SUCCESS);
}

int			ft_print_game(t_storage **st)
{
	if (ft_print_threads(st) != SUCCESS)
		return (FAILURE);
	if (ft_print_grid(st) != SUCCESS)
		return (FAILURE);
	if (ft_print_infos(st) != SUCCESS)
		return (FAILURE);
	SDL_RenderPresent((*st)->win->renderer);
	if (SDL_RenderClear((*st)->win->renderer) < 0)
		return (FAILURE);
	return (SUCCESS);
}
