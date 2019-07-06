/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:56:11 by glebouch          #+#    #+#             */
/*   Updated: 2019/07/06 08:37:25 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int			ft_print_text(t_storage **st, char *str, int line)
{
	SDL_Surface		*srf;
	SDL_Texture		*msg;
	SDL_Rect		rect;

	if ((srf = TTF_RenderText_Solid((*st)->win->ttf_text, str,
		argb_to_sdl(WHITE))) == NULL)
		return (FAILURE);
	if ((msg = SDL_CreateTextureFromSurface((*st)->win->renderer, srf)) == NULL)
	{
		SDL_FreeSurface(srf);
		srf = NULL;
		return (FAILURE);
	}
	rect.x = 66 * OCT_W;
	rect.y = line * OCT_H;
	rect.w = ft_strlen(str) * 9;
	rect.h = OCT_H;
	return (ft_finish(st, &srf, &msg, &rect));
}

int					ft_finish(t_storage **st, SDL_Surface **srf,
	SDL_Texture **msg, SDL_Rect *rect)
{
	SDL_FreeSurface(*srf);
	(*srf) = NULL;
	if ((SDL_RenderCopy((*st)->win->renderer, (*msg), NULL, rect)) < 0)
	{
		SDL_DestroyTexture(*msg);
		(*msg) = NULL;
		return (FAILURE);
	}
	SDL_DestroyTexture(*msg);
	(*msg) = NULL;
	return (SUCCESS);
}

int					ft_str_create_and_print(t_storage **st, char *str1,
	char **str2, int line)
{
	char			*dest;
	int				size_total;

	size_total = ft_strlen(str1) + ft_strlen(*str2);
	if (!(dest = (char *)malloc(sizeof(char) * (size_total + 1))))
	{
		free(*str2);
		return (FAILURE);
	}
	ft_bzero(dest, sizeof(char) * (size_total + 1));
	dest = ft_strcat(dest, str1);
	dest = ft_strcat(dest, (*str2));
	free(*str2);
	if (ft_print_text(st, dest, line) != SUCCESS)
	{
		free(dest);
		return (FAILURE);
	}
	free(dest);
	return (SUCCESS);
}

static int			ft_print_infos_b(t_storage **st, int *var_cycle_to_die,
	int line)
{
	char			*str_tmp;

	str_tmp = ft_itoa(*var_cycle_to_die);
	if (ft_str_create_and_print(st, "CYCLE_TO_DIE : ",
		&str_tmp, line) != SUCCESS)
		return (FAILURE);
	str_tmp = ft_itoa(CYCLE_DELTA);
	if (ft_str_create_and_print(st, "CYCLE_DELTA :  ",
		&str_tmp, line + 2) != SUCCESS)
		return (FAILURE);
	str_tmp = ft_itoa((*st)->nb_live_current);
	if (ft_str_create_and_print(st, "NBR_LIVE :     ",
		&str_tmp, line + 4) != SUCCESS)
		return (FAILURE);
	str_tmp = ft_itoa(MAX_CHECKS);
	if (ft_str_create_and_print(st, "MAX_CHECKS :   ",
		&str_tmp, line + 6) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int					ft_print_infos_a(t_storage **st, int *var_cycle_to_die)
{
	int				line;
	char			*str_tmp;

	line = 1;
	if ((ft_print_text(st, (*st)->win->pause == 1
		? "PAUSE" : "RUNNING", line)) != SUCCESS)
		return (FAILURE);
	str_tmp = ft_itoa((*st)->cycle);
	if (ft_str_create_and_print(st, "Cycles :  ",
		&str_tmp, line + 2) != SUCCESS)
		return (FAILURE);
	str_tmp = ft_itoa((*st)->win->nb_threads);
	if (ft_str_create_and_print(st, "Threads : ",
		&str_tmp, line + 4) != SUCCESS)
		return (FAILURE);
	if ((line += ft_put_players(st, line + 7) + 10) < 12)
		return (FAILURE);
	ft_print_infos_b(st, var_cycle_to_die, line);
	return (SUCCESS);
}
