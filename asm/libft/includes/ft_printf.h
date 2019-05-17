/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:32:42 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/10 14:36:19 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# define LEFT				1
# define ZERO				2
# define SIGN				3
# define BLANK				4
# define HASHTAG			5
# define INT_LONG			6
# define INT_LONG_LONG		7
# define INT_SHORT			8
# define INT_SHORT_SHORT	9
# define J_FLAG				10
# define Z_FLAG				11
# define POINT				12
# define LARGEUR			13
# define LENGHT_TAB 		14

# define CONV				"sSpdDioOuUxXcCfFeEaAn%"
# define NO_C				"sSpdDioOuUxXfFeEaAn"
# define FLAG				"lhjz-+. #0123456789"
# define ALL				"sSpdDioOuUxXcCfFeEaAn%lhjz-+. #0123456789"
# define ENT				"dDFfioOuUxXp"
# define UNSIGNED_			"oOXxuUp"
# define HEXA_MIN			"0123456789abcdef"
# define HEXA_MAJ			"0123456789ABCEDF"
# define OCTAL				"01234567"
# define DECIMAL			"0123456789"

typedef struct				s_string
{
	char					char_of_arg;
	char					*data;
	int						len;
	int						tab[LENGHT_TAB];
	int						index;
	int						fd;
}							t_string;

typedef struct				s_conver
{
	int						tab;
	char					*(*fonction)(va_list ap);
}							t_conv;

typedef struct				s_conver_base
{
	int						tab;
	char					*(*fonction)(va_list ap, char *hexa);
}							t_conv_base;

int							ft_printf(const char *format, ...);
unsigned int				nb_percent(const char *format);
int							parsing_params(char *arg);
int							params(char comp, const char *list);
int							parsing(const char *format, t_string *list,
							va_list ap, unsigned int nb_percent);

int							p_of_params(char *format);
int							parsing_arg(char *argument, va_list ap, int len,
							t_string *list);
int							init_list(va_list ap, char c, t_string *list);
int							add_arg(t_string *list, va_list ap);
int							inter_flag(const char *format, int *len_write,
							t_string *list, int *len_arg);

int							change_string(t_string *list);
void						priority_precision_largeur_sign_hashtag(t_string
							*list);
void						priority_precision_largeur_sign_hashtag_(t_string
							*list);
void						priority_precision_largeur(t_string *list);
int							add_precision(t_string *list);

void						flag_optional(char *arg, int len, t_string *list);
int							largeur_of_camp(char *arg, t_string *list, int i);
int							flag_optional_suit(char *arg, t_string *list,
							int i);
int							list_add_conversion(char *string, t_string *list);
int							binary_flag(int *tab, int len);

int							print_zero_space_char(t_string *list, int octet);
char						*flag_int_sign(t_string list, va_list ap);
char						*flag_int_unsigned(t_string list, va_list ap,
							char *hexa);
int							unsigned_value(va_list ap, char c, t_string *list);
int							option_char(t_string *list, wchar_t c);
void						reset_tab_int(t_string *list, int len);

int							free_data(t_string *list, unsigned int nb_percent,
							int ret, va_list ap);
int							retour_err(int *len_write, int f);
char						add_sign(t_string *list);
int							ft_fprintf(const char *format, int fd, ...);

char						*string_s(va_list ap);
char						conv_c(va_list ap);
wchar_t						conv_long_c(va_list ap);
char						*conv_int(va_list ap);
char						*conv_long(va_list ap);
char						*conv_long_long(va_list ap);
char						*conv_char(va_list ap);
char						*conv_uchar(va_list ap, char *hexa);
char						*conv_intmax(va_list ap);
char						*conv_uintmax(va_list ap, char *hexa);
char						*conv_size_t(va_list ap, char *hexa);
char						*conv_ssize_t(va_list ap);
char						*conv_float(va_list ap, unsigned int precision);
char						*conv_uint(va_list ap, char *hexa);
char						*conv_ulong(va_list ap, char *hexa);
char						*conv_ulong_long(va_list ap, char *hexa);
char						*conv_short(va_list ap);
char						*conv_ushort(va_list ap, char *hexa);
char						*conv_void(va_list ap, char *hexa);
char						*string_unix(va_list ap, t_string *list);
#endif
