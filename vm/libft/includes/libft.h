/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:06:26 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/19 17:34:38 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H

# define _LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/*
** ------------------------- ft_atoi				---------------------------
*/
int			ft_atoi(const char *str);

/*
** ------------------------- ft_putchar				---------------------------
*/
void		ft_putchar(char c);

/*
** ------------------------- ft_putnbr				---------------------------
*/
void		ft_putnbr(int n);

/*
** ------------------------- ft_putstr				---------------------------
*/
void		ft_putstr(char const *s);

/*
** ------------------------- ft_putstr_fd			---------------------------
*/
void		ft_putstr_fd(char const *s, int fd);

/*
** ------------------------- ft_strcmp				---------------------------
*/
int			ft_strcmp(const char *s1, const char *s2);

/*
** ------------------------- ft_strdup				---------------------------
*/
char		*ft_strdup(const char *s1);

/*
** ------------------------- ft_strlen				---------------------------
*/
size_t		ft_strlen(const char *s);

/*
** ------------------------- ft_strnew				---------------------------
*/
char		*ft_strnew(size_t size);

#endif
