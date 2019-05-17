/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:12:51 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/10 14:36:44 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <wchar.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
/*
**	free
*/
int					free_line(char **line);
int					free_tab_str(char ***str);
/*
**	ft_is
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
/*
**	ft_to_lst
*/
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
/*
**	ft_mem
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memjoin(void *dst, size_t len_dst,
					void *src, size_t len_src);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
/*
**	ft_print
*/
int					ft_buff_printf(int fd, int fd_sortie);
void				ft_print_words_tables(char **tab);
/*
**	ft_put
*/
int					ft_putchar(char c);
int					ft_putchar_fd(char c, int fd);
int					ft_putchar_len(char c, int len, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *s, int fd);
int					ft_putstr_len(const char *str, size_t len, int fd);
/*
**	ft_str
*/
int					ft_str_is_digit(char *str);
int					ft_str_is_int(char *str);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2, int select_to_free);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strnchr(const char *s, int c, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strndup(const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnjoin(char const *s1, char const *s2, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
/*
**	ft_to
*/
int					ft_tolower(int c);
int					ft_toupper(int c);
/*
**	ft_to_ascii
*/
char				*ft_dotoa(double nb, unsigned int precision);
char				*ft_itoa(int n);
char				*ft_lltoa(long long n);
char				*ft_lltoa_base(long long nb, const char *base);
char				*ft_ulltoa(unsigned long long n);
char				*ft_ulltoa_base(unsigned long long nb, const char *base);
/*
**	ft_to_int
*/
int					ft_atoi(const char *str);
long long			ft_atoll(const char *str);
unsigned long long	ft_atoull(const char *str);
/*
**	ft_unicode
*/
int					*ft_putval_tab(wchar_t c, int octet);
int					ft_putwchar(int *tab, unsigned int octet, int fd);
int					ft_unicode_to_str(char **data, wchar_t *str,
					unsigned int precision);
long				ft_set_octet(int octet);
long				ft_set_unichar(long masque_byte, int len, wchar_t c);
int					*tab_unix(int octet, int len, wchar_t str);
int					ft_wchar_len(wchar_t c);
int					ft_wset_plage_byte(int len);
/*
**	maths
*/
long long			ft_absolue(long long nb);
int					pgcd(int x, int y);
int					ft_sqrt(int nb);
int					ft_recursive_factorial(int nb);
long				ft_recursive_power(long nb, int power);
int					ft_fibonacci(int index);
int					ft_is_prime(int nb);
int					ft_find_next_prime(int nb);
/*
**	ft_len
*/
int					ft_len_tab_str(char **tab);
#endif
