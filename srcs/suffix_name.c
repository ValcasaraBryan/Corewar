/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suffix_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:43:27 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/05 15:58:48 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		suffix_name(t_data *data, const char *s)
{
	int		i;
	char	*name;

	if (!data->name_s)
		return (0);
	i = ft_strlen(data->name_s) + 1;
	while (--i >= 0)
		if (!ft_strcmp(data->name_s + i, SUFF_F))
			break ;
	if (!(name = ft_strcut(data->name_s, 0, i)))
		return (error_malloc());
	if (!(data->name_cor = ft_strndup((const char *)name, i + COR)))
		return (error_malloc());
	free_line(&name);
	ft_strcat(data->name_cor, (char *)s);
	return (1);
}
