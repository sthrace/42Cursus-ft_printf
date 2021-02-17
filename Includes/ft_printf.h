/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:01:37 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 18:48:27 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_struct
{
	int		flagleft;
	int		flagzero;
	int		precision;
	int		width;
	char	type;
	int		spaces;
	int		zeros;
	int		flagl;
	int		flagh;
	int		flaghash;
	int		flagspace;
	int		flagsign;
	int		length;
	int		intmin;
	int		negative;
	int		zerofront;
	int		flagfl;
}					t_struct;

int					g_fsize;
int					ft_printf(const char *format, ...);
int					ft_parser(char *str, va_list args, int i, t_struct *f);
void				ft_init_formats(t_struct *f);
void				ft_select_type(va_list args, t_struct *f);
void				ft_putnbr(long long nbr, int base, char *ascii);
int					ft_nbrlen(long long nbr, int base);
void				ft_type_int(long long nbr, t_struct *f);
void				ft_type_char(int c, t_struct *f);
void				ft_type_str(char *str, t_struct *f);
void				ft_type_unsigned(long long nbr, t_struct *f);
void				ft_type_hexa(long nbr, t_struct *f);
void				ft_type_pointer(unsigned long long nbr, t_struct *f);
void				ft_type_float(long double nbr, t_struct *f);
void				ft_type_octal(long long nbr, t_struct *f);
void				ft_type_g(long double nbr, t_struct *f);
void				ft_type_right(t_struct *f);
void				ft_type_left(long long whole, t_struct *f);
void				ft_type_decimal(long double decimal, t_struct *f);

#endif
