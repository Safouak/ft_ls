/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 08:51:03 by shasnaou          #+#    #+#             */
/*   Updated: 2017/03/21 12:55:31 by shasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** ft_strsplit.c
*/

typedef struct		s_strsplit
{
	char			**tab;
	char			*cpy;
	size_t			i;
	size_t			pos;
	size_t			line;
	size_t			column;
}					t_strsplit;

/*
** ft_itoa.c
*/

typedef struct		s_itoa
{
	int				div;
	size_t			cnt;
	size_t			neg;
	size_t			i;
	char			*nb;
}					t_itoa;

/*
** part_one
*/

void				ft_bzero(void *s, size_t size);
void				*ft_memcpy(void *s, const void *s2, size_t size);
void				*ft_memccpy(void *s, const void *s2, int i,
														size_t size);
void				*ft_memmove(void *s, const void *s2, size_t size);
void				*ft_memchr(const void *s, int i, size_t size);
int					ft_memcmp(const void *s, const void *s2,
													size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *s, const char *s2);
char				*ft_strncpy(char *s, const char *s2, size_t size);
char				*ft_strcat(char *s, const char *s2);
char				*ft_strncat(char *s, const char *s2, size_t size);
size_t				ft_strlcat(char *s, const char *s2, size_t size);
char				*ft_strchr(const char *s, int i);
char				*ft_strrchr(const char *s, int i);
char				*ft_strstr(const char *s, const char *s2);
char				*ft_strnstr(const char *s, const char *s2,
														size_t size);
int					ft_strcmp(const char *s, const char *s2);
int					ft_strncmp(const char *s, const char *s2,
														size_t size);
int					ft_atoi(const char *s);
int					ft_isalpha(int i);
int					ft_isdigit(int i);
int					ft_isalnum(int i);
int					ft_isascii(int i);
int					ft_isprint(int i);
int					ft_toupper(int i);
int					ft_tolower(int i);
void				*ft_memset(void *s, int i, size_t size);

/*
** part_two
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **array);
char				*ft_strnew(size_t size);
void				ft_strdel(char **array);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s,
	void (*f)(unsigned int i, char *s));
char				*ft_strmap(char const *s, char (*f)(char c));
char				*ft_strmapi(char const *s,
	char (*f)(unsigned int i, char c));
int					ft_strequ(char const *s, char const *s2);
int					ft_strnequ(char const *s,
	char const *s2, size_t size);
char				*ft_strsub(char const *s,
	unsigned int i, size_t size);
char				*ft_strjoin(char const *s, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int i);
void				ft_putchar_fd(char c, int i);
void				ft_putstr_fd(char const *s, int i);
void				ft_putendl_fd(char const *s, int i);
void				ft_putnbr_fd(int i, int j);

/*
** bonus
*/

t_list				*ft_lstnew(void const *s, size_t size);
void				ft_lstdelone(t_list **p_list,
	void (*f)(void *s, size_t size));
void				ft_lstdel(t_list **p_list,
	void (*f)(void *s, size_t size));
void				ft_lstadd(t_list **p_list, t_list *list);
void				ft_lstiter(t_list *list, void (*f)(t_list *list));
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list *list));
void				ft_lstaddelem(t_list **list, void *content, \
									int content_size);
int					ft_lstlen(t_list *list);

/*
** extra_functions
*/

unsigned char		*ft_joinchar(unsigned char *s1, unsigned char c);
int					ft_min(int *tab, int len);
int					ft_max(int *tab, int len);
float				ft_fmin(float *tab, int len);
float				ft_fmax(float *tab, int len);
char				*ft_strjoinc(char const *s, char c, char const *s2);

#endif
