/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:05:08 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/18 05:00:10 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

#define S_ERR	2
#define NO_FILE	"Can't read source file %s\n"
#define SUCCESS	"Writing output program to %s\n"
#define SUFF_F	".s"
#define SUFFIX	".cor"
#define COR		4

typedef struct		s_file
{
	char			*line;
	struct s_file	*next;
}					t_file;

typedef struct	s_data
{
	int			fd;
	int			ret;
	char		*name_cor;
	char		*name_s;
	t_file		*file;
	int			error;
}				t_data;


#endif