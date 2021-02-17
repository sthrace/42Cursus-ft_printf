/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:37:34 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 16:41:34 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_select_type_o(va_list args, t_struct *f)
{
	if (f->type == 'o')
	{
		if (f->flagl == 0)
			ft_type_octal(va_arg(args, unsigned), f);
		else if (f->flagl == 1)
			ft_type_octal(va_arg(args, unsigned long), f);
		else if (f->flagl == 2)
			ft_type_octal(va_arg(args, unsigned long long), f);
	}
}

void				ft_select_type_nfge(va_list args, t_struct *f)
{
	if (f->type == 'f')
	{
		if (f->flagfl == 0)
			ft_type_float(va_arg(args, double), f);
		else if (f->flagfl == 1)
			ft_type_float(va_arg(args, long double), f);
	}
	if (f->type == 'g')
	{
		if (f->flagfl == 0)
			ft_type_g(va_arg(args, double), f);
		else if (f->flagfl == 1)
			ft_type_g(va_arg(args, long double), f);
	}
}

static void			ft_select_type_xdi(va_list args, t_struct *f)
{
	if (f->type == 'x' || f->type == 'X')
	{
		if (f->flagl == 0)
			ft_type_hexa(va_arg(args, unsigned), f);
		else if (f->flagl == 1)
			ft_type_hexa(va_arg(args, unsigned long), f);
		else if (f->flagl == 2)
			ft_type_hexa(va_arg(args, unsigned long long), f);
	}
	if (f->type == 'd' || f->type == 'i')
	{
		if (f->flagl == 0)
			ft_type_int(va_arg(args, int), f);
		else if (f->flagl == 1)
			ft_type_int(va_arg(args, long int), f);
		else if (f->flagl == 2)
			ft_type_int(va_arg(args, long long int), f);
	}
}

static void			ft_select_type_cspu(va_list args, t_struct *f)
{
	if (f->type == 'c')
		ft_type_char(va_arg(args, int), f);
	else if (f->type == '%')
		ft_type_char('%', f);
	else if (f->type == 's')
		ft_type_str(va_arg(args, char*), f);
	else if (f->type == 'p')
		ft_type_pointer(va_arg(args, unsigned long long), f);
	else if (f->type == 'u')
	{
		if (f->flagl == 0)
			ft_type_unsigned(va_arg(args, unsigned), f);
		else if (f->flagl == 1)
			ft_type_unsigned(va_arg(args, unsigned long), f);
		else if (f->flagl == 2)
			ft_type_unsigned(va_arg(args, unsigned long long), f);
	}
}

void				ft_select_type(va_list args, t_struct *f)
{
	if (f->type == 'c' || f->type == 's' || f->type == 'p' ||
		f->type == '%' || f->type == 'u')
		ft_select_type_cspu(args, f);
	else if (f->type == 'd' || f->type == 'i' ||
		f->type == 'x' || f->type == 'X')
		ft_select_type_xdi(args, f);
	else if (f->type == 'n' || f->type == 'f' ||
		f->type == 'g' || f->type == 'e')
	{
		if (f->flaghash == 2)
			f->flaghash = 1;
		ft_select_type_nfge(args, f);
	}
	else if (f->type == 'o')
		ft_select_type_o(args, f);
}
