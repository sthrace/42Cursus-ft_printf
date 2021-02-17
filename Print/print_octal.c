/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:34:40 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 18:36:40 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_main(long long nbr, t_struct *f)
{
	if (f->flagsign == 1 || f->flagspace == 1)
	{
		if (f->negative == 0 && f->flagsign == 1)
			write(1, "+", 1);
		else if (f->flagspace == 1)
			write(1, " ", 1);
		f->flagsign = 2;
		f->flagspace = 2;
	}
	while (f->zeros-- > 0)
		g_fsize += write(1, "0", 1);
	if (f->length > (nbr == 0 && f->precision == 0 ? f->flagsign : 0))
		ft_putnbr(nbr, 8, "01234567");
	g_fsize += f->length;
}

static void		ft_print_flags(t_struct *f)
{
	while (f->spaces-- > 0)
		if (f->flagzero == 1 && f->precision == -1)
		{
			if (f->flagsign == 1 || f->flagspace == 1)
			{
				if (f->flagsign == 1)
					write(1, "+", 1);
				else if (f->flagspace == 1)
					write(1, " ", 1);
				f->flagsign = 2;
				f->flagspace = 2;
			}
			g_fsize += write(1, "0", 1);
		}
		else
			g_fsize += write(1, " ", 1);
}

static void		ft_formatted_print(long long nbr, t_struct *f)
{
	if (f->flagleft == 1)
		ft_print_main(nbr, f);
	ft_print_flags(f);
	if (f->flagleft == 0)
		ft_print_main(nbr, f);
}

void			ft_type_octal(long long nbr, t_struct *f)
{
	if (f->flagh == 1)
		nbr = (unsigned int)nbr;
	if (f->flagh == 2)
		nbr = (unsigned char)nbr;
	if (f->flagsign == 1)
		f->flagspace = 0;
	f->length = ft_nbrlen(nbr, 8) + f->flagsign + f->flagspace;
	if (f->precision >= f->length)
		f->zeros = f->precision - f->length + f->flagsign + f->flagspace;
	else if (f->precision == 0 && nbr == 0)
		f->length = f->flagsign;
	f->spaces = f->width - f->zeros - f->length;
	ft_formatted_print(nbr, f);
}
