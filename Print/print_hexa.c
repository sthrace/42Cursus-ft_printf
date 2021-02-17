/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:31:49 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 18:45:47 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_main(long nbr, t_struct *f, char *ascii, int base)
{
	if (f->flaghash == 2)
	{
		if (nbr != 0)
		{
			if (f->type == 'X')
				g_fsize = write(1, "0X", 2);
			else
				g_fsize = write(1, "0x", 2);
		}
		f->flaghash = 0;
	}
	while (f->zeros-- > 0)
		g_fsize += write(1, "0", 1);
	if (f->length > 0 || (nbr == 0 && f->precision != 0))
		ft_putnbr(nbr, base, ascii);
	g_fsize += f->length;
}

static void		ft_formatted_print(long nbr, t_struct *f, char *ascii, int base)
{
	if (f->flagleft == 1)
		ft_print_main(nbr, f, ascii, base);
	while (f->spaces-- > 0)
	{
		if (f->flagzero == 1 && f->precision == -1)
		{
			if (f->flaghash == 2)
			{
				if (nbr != 0)
				{
					if (f->type == 'X')
						g_fsize = write(1, "0X", 2);
					else
						g_fsize = write(1, "0x", 2);
				}
				f->flaghash = 0;
			}
			g_fsize += write(1, "0", 1);
		}
		else
			g_fsize += write(1, " ", 1);
	}
	if (f->flagleft == 0)
		ft_print_main(nbr, f, ascii, base);
}

void			ft_type_hexa(long nbr, t_struct *f)
{
	char	*ascii;
	int		base;

	base = 16;
	if (f->flagh == 1)
		nbr = (unsigned short int)nbr;
	if (f->flagh == 2)
		nbr = (unsigned char)nbr;
	if (f->type == 'X')
		ascii = "0123456789ABCDEF";
	else
		ascii = "0123456789abcdef";
	f->length = ft_nbrlen(nbr, base);
	if (nbr == 0)
		f->flaghash = 0;
	if (f->precision >= f->length)
		f->zeros = f->precision - f->length;
	else if (f->precision == 0 && nbr == 0)
		f->length = 0;
	f->spaces = f->width - f->zeros - f->length - f->flaghash;
	ft_formatted_print(nbr, f, ascii, base);
}
