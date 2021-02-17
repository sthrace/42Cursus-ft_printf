/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:10:41 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 17:31:55 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_type_decimal(long double decimal, t_struct *f)
{
	while (f->zerofront-- > 0)
	{
		write(1, "0", 1);
		f->precision--;
	}
	if (f->precision > 0)
		ft_putnbr(decimal, 10, "0123456789");
	if (f->flagleft == 1)
		while (f->spaces-- > 0)
			write(1, " ", 1);
}

void			ft_type_left(long long whole, t_struct *f)
{
	if (f->flagzero == 1)
	{
		while (f->spaces-- > 0)
			write(1, "0", 1);
	}
	if (f->flagsign == 1 && f->negative == 1)
		write(1, "-", 1);
	else if (f->negative == 0 && f->flagsign == 1)
		write(1, "+", 1);
	else if (f->flagspace == 1)
	{
		write(1, " ", 1);
		f->spaces = f->spaces - 1;
	}
	f->flagsign = 2;
	f->flagspace = 2;
	ft_putnbr(whole, 10, "0123456789");
	if (f->precision > 0 || (f->precision == 0 && f->flaghash == 1))
		if (f->type != 'g')
			write(1, ".", 1);
}

void			ft_type_right(t_struct *f)
{
	if (f->flagleft == 0)
	{
		if (f->flagzero == 0)
		{
			if (f->flagspace == 1)
			{
				write(1, " ", 1);
				f->spaces = f->spaces - 1;
				f->flagspace = 2;
			}
			while (f->spaces-- > 0)
				write(1, " ", 1);
		}
		if (f->negative == 1)
			write(1, "-", 1);
		else if (f->negative == 0 && f->flagsign == 1)
			write(1, "+", 1);
		else if (f->flagspace == 1)
		{
			write(1, " ", 1);
			f->spaces = f->spaces - 1;
		}
		f->flagsign = 2;
		f->flagspace = 2;
	}
}

static void		ft_sort_decimal(long double dcdbl, long long whole, t_struct *f)
{
	int			cnt;
	long long	multiplier;
	long long	decimal;

	cnt = f->precision;
	multiplier = 1;
	while (cnt-- > 0)
	{
		dcdbl = dcdbl * 10;
		if (dcdbl < 0.9)
			f->zerofront = f->zerofront + 1;
		multiplier = multiplier * 10;
	}
	dcdbl = (long long)(dcdbl * 10) % 10 > 4 ? dcdbl + 1 : dcdbl;
	decimal = (long long)dcdbl;
	if (decimal / multiplier > 0.5 && (f->precision < 2 ||
		f->precision == 6) && (whole % 2 != 0 || (whole == 0 && dcdbl != 1.5)))
	{
		decimal = 0;
		f->zerofront = f->precision - 1;
		whole = whole + 1;
	}
	ft_type_right(f);
	ft_type_left(whole, f);
	ft_type_decimal(decimal, f);
}

void			ft_type_float(long double nbr, t_struct *f)
{
	long int	whole;
	long double	decdouble;
	int			corrector;

	if (nbr < 0.0 || 1 / nbr < 0.0)
	{
		nbr = -nbr;
		f->flagsign = 1;
		f->negative = 1;
	}
	if (f->flagsign == 1)
		f->flagspace = 0;
	(f->precision == -1) ? f->precision = 6 : f->precision + 0;
	whole = (long long int)nbr;
	corrector = 1;
	if (f->precision == 0 && f->flaghash != 1)
		corrector = 0;
	f->length = ft_nbrlen(whole, 10) + f->precision +
				corrector + f->flagsign + f->flagspace;
	f->spaces = f->width - f->length + f->flagspace;
	decdouble = (nbr - whole);
	g_fsize += f->length;
	if (f->width > f->length)
		g_fsize += f->width - f->length;
	ft_sort_decimal(decdouble, whole, f);
}
