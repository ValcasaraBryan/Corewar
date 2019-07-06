/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:57:47 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/01 18:57:49 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE  500

int					get_next_line(const int fd, char **line);
t_list				*ft_check_link(t_list **list, const int fd);
int					ft_add_line(char **rest, char *buf, const int fd);
int					ft_add_line_next(char **rest, char **line);
void				ft_free_list(t_list **list, const int fd);

#endif
