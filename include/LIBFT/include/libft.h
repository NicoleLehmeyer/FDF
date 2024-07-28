/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:37:00 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/11 14:44:50 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

//LIBRARY: ctype.h
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

//LIBRARY: stdlib.h
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

//LIBRARY: strings.h
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

//LIBRARY: string.h
size_t	ft_strlcat(char *dst, const char *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);

//NON-STANDARD FUNCTIONS
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (f)(unsigned int, char*));

//NON-PROJECT FUNCTIONS
void	ft_free_array(char **array);

//PRINTF HEADER
int		ft_printf(const char *s, ...);
void	ft_c(int c, int *len);
void	ft_s(const char *s, int *len);
void	ft_p(size_t p, int *len);
void	ft_num(int d, int *len);
void	ft_u(unsigned int u, int *len);
void	ft_hex(unsigned int x, int *len, const char datatype);

//GNL HEADER
char	*get_next_line(int fd);
char	*ft_readtilnl(int fd, char *linestart);
char	*ft_cutline(char *linestart);
char	*ft_movepointer(char *linestart);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif