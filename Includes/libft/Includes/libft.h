/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:14:27 by Lmatkows          #+#    #+#             */
/*   Updated: 2024/12/19 10:39:54 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1 || BUFFER_SIZE > 8000000
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 4
#  endif
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# define HEXALOW "0123456789abcdef"
# define HEXAUP "0123456789ABCDEF"

/*
	libft
*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const	char *str);
void	*ft_memset(void	*adr, int c, size_t len);
void	*ft_bzero(void	*adr, size_t len);
void	*ft_memcpy(void	*dest, const void *src, size_t len);
void	*ft_memmove(void	*dest, const void *src, size_t len);
size_t	ft_strlcpy(char *dest, char *src, size_t len);
size_t	ft_strlcat(char *dest, const char *src, size_t size_d_fin);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char	const *s, unsigned int start, size_t	len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
	libft bonus
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
	printf
*/

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putadr(void *p);
int		ft_putdec(int d);
int		ft_putundec(unsigned int u);
int		ft_putlowhexa(unsigned int x);
int		ft_putuphexa(unsigned int X);
int		ft_adrhexa(unsigned long X);
int		ft_findset(char c, char *set);
char	ft_symb(const char *arg, int i);
int		ft_isvar(const char *s, int i);
int		ft_print_sth(va_list elem, char symb);
int		ft_printf(const char *arg, ...);

/*
	GNL
*/

char	*gnl_strjoin(char *s1, char *s2);
int		gnl_strlen(char *s);
char	*gnl_substrto(char *str, char c);
char	*gnl_substrfrom(char *str, char c);
int		gnl_strchr(char *str, char c);
char	*get_next_line(int fd);

/*
	other
*/

int		ft_strstr(const char *s1, const char *s2);
int		ft_atoi_base(const char *str, const char *base);

#endif
