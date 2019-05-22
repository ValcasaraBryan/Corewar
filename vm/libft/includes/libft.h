/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:06:26 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/22 15:31:08 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H

# define _LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/*
** ------------------------- ft_atoi                  -------------------------
*/
int			ft_atoi(const char *str);

/*
** ------------------------- ft_putchar               -------------------------
*/
void		ft_putchar(char c);

/*
** ------------------------- ft_putnbr                -------------------------
*/
void		ft_putnbr(int n);

/*
** ------------------------- ft_putstr                -------------------------
*/
void		ft_putstr(char const *s);

/*
** ------------------------- ft_strdup                -------------------------
*/
char		*ft_strdup(const char *s1);

/*
** ------------------------- ft_strlen                -------------------------
*/
size_t		ft_strlen(const char *s);

/*
** ------------------------- ft_strnew                -------------------------
*/
char		*ft_strnew(size_t size);

#endif
