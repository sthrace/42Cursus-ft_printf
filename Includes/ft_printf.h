/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:01:37 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/14 09:24:46 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_struct
{
	int		lft;
	int		fz;
	int		prc;
	int		prcn;
	int		wd;
	int		wdn;
	char	type;
	char	prcstar;
	char	wdstar;
}					t_struct;

int					g_fsize;
int					ft_type(va_list args, t_struct *f);
void				ft_init_formats(t_struct *f);
void				ft_set_prec(const char *str, va_list args, t_struct *f);
int					ft_set_width(const char *s, va_list args, t_struct *f);
int					ft_printf(const char *str, ...);
char				*ft_strchr(const char *s, int c);
int					ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
void				ft_type_char(char c, t_struct *f);
void				ft_type_str(char *c, t_struct *f);
int					ft_type_int(int nbr, t_struct *f);
char				*ft_itoa(int n);
int					ft_isdigit(int c);
int					ft_type_unsgn_int(unsigned int nbr, t_struct *f);
char				*ft_itoa_unsignedint(unsigned int n);
char				*ft_itoa_base(unsigned long long n, unsigned int base);
int					ft_type_hexa(unsigned int nbr, t_struct *f);
int					ft_isalpha(int c);
int					ft_type_ptr(uintptr_t ptr, t_struct *f);
int					ft_type_hexaup(unsigned int nbr, t_struct *f);
void				ft_type_right(char *cnbr, int len, t_struct *f);
void				ft_type_left(char *cnbr, int len, t_struct *f);
int					ft_type_blank(t_struct *f);
void				ft_type_zero(char *cnbr, int len, t_struct *f);

#endif
