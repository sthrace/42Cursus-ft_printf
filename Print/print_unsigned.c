/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:42:09 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 18:45:21 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_main(long long nbr, t_struct *f)
{
	if (f->flaghash == 2 && nbr != 0)
	{
		write(1, "0x", 2);
		f->flaghash = 0;
	}
	while (f->zeros-- > 0)
		g_fsize += write(1, "0", 1);
	if (f->length > 0)
		ft_putnbr(nbr, 10, "0123456789");
	g_fsize += f->length;
}

static void		ft_formatted_print(long long nbr, t_struct *f)
{
	if (f->flagleft == 1)
		ft_print_main(nbr, f);
	while (f->spaces-- > 0)
	{
		if (f->flagzero == 1 && f->precision == -1)
		{
			if (f->flaghash == 2 && nbr != 0)
			{
				write(1, "0x", 2);
				f->flaghash = 0;
			}
			g_fsize += write(1, "0", 1);
		}
		else
			g_fsize += write(1, " ", 1);
	}
	if (f->flagleft == 0)
		ft_print_main(nbr, f);
}

void			ft_type_unsigned(long long nbr, t_struct *f)
{
	if (f->flagh == 1)
		nbr = (unsigned short int)nbr;
	if (f->flagh == 2)
		nbr = (unsigned char)nbr;
	f->length = ft_nbrlen(nbr, 10) + f->flaghash;
	if (f->precision >= f->length)
		f->zeros = f->precision - f->length + f->flaghash;
	else if (f->precision == 0 && nbr == 0)
		f->length = 0;
	f->spaces = f->width - f->zeros - f->length;
	ft_formatted_print(nbr, f);
}
