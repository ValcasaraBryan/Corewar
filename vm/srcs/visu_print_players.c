/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_players.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:15:22 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 19:43:50 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int			ft_print_name_colored(t_storage **st, char *intro,
	char *name, int num_player)
{
	SDL_Surface		*srf;
	SDL_Texture		*msg;
	SDL_Rect		rect;

	if ((srf = TTF_RenderText_Solid((*st)->win->ttf_text, name,
		argb_to_sdl(ft_color_octet(num_player)))) == NULL)
		return (FAILURE);
	if ((msg = SDL_CreateTextureFromSurface((*st)->win->renderer, srf)) == NULL)
	{
		SDL_FreeSurface(srf);
		srf = NULL;
		return (FAILURE);
	}
	rect.x = 66 * OCT_W + ft_strlen(intro) * 9;
	rect.y = (8 + (num_player - 1) * 4) * OCT_H;
	rect.w = ft_strlen(name) * 9;
	rect.h = OCT_H;
	return (ft_finish(st, &srf, &msg, &rect));
}

static int			ft_put_players_inner_a(t_storage **st, int line,
	int nb_players, t_champion **current)
{
	char			*str;
	char			*str_tmp;
	int				flag_return;

	if (!(str = malloc(sizeof(char) * (10 + ft_nbrlen((*current)->number)))))
		return (FAILURE);
	ft_bzero(str, sizeof(char) * (10 + ft_nbrlen((*current)->number)));
	str = ft_strcat(str, "Player ");
	str_tmp = ft_itoa((*current)->number);
	str = ft_strcat(str, str_tmp);
	free(str_tmp);
	str = ft_strcat(str, ": ");
	str_tmp = ft_strdup((*current)->name);
	if (ft_str_create_and_print(st, str, &str_tmp, line) != SUCCESS)
	{
		free(str);
		return (FAILURE);
	}
	flag_return = ft_print_name_colored(st, str, (*current)->name,
		nb_players) != SUCCESS ? FAILURE : SUCCESS;
	free(str);
	return (flag_return);
}

static int			ft_put_players_inner_b(t_storage **st, int line,
	t_champion **current)
{
	char			*str_tmp;

	str_tmp = ft_itoa((*current)->last_live);
	if (ft_str_create_and_print(st, "   Last_live :                  ",
		&str_tmp, line + 1) != SUCCESS)
		return (FAILURE);
	str_tmp = ft_itoa((*current)->current_lives);
	if (ft_str_create_and_print(st, "   Lives in current period :    ",
		&str_tmp, line + 2) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int					ft_put_players(t_storage **st, int line)
{
	int				nb_players;
	t_champion		*current;

	nb_players = 0;
	current = (*st)->first_champion;
	while (current != NULL)
	{
		nb_players += 1;
		if (ft_put_players_inner_a(st, line, nb_players, &current) != SUCCESS)
			return (FAILURE);
		if (ft_put_players_inner_b(st, line, &current) != SUCCESS)
			return (FAILURE);
		line += 4;
		current = current->next;
	}
	return (nb_players * 3);
}
