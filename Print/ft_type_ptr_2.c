/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ptr_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:22:07 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/10 18:23:38 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_type_ptr_blank(t_struct *f)
{
	write(1, "0x", 2);
	if (f->wd == 1 && f->fz == 1)
		while (f->wdn--)
			write(1, "0", 1);
	else if (f->wd == 1 && f->fz == 0)
		while (f->wdn--)
			write(1, " ", 1);
}

static void		ft_type_prec_ptr_zero(char *cnbr, int len, t_struct *f)
{
	if (f->prcn > f->wdn)
	{
		while (f->prcn-- > len - 2)
			write(1, "0", 1);
		write(1, "0x", 2);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
	else
	{
		while (f->wdn-- - (f->prcn > len ? f->prcn : len))
			write(1, " ", 1);
		while (f->prcn-- > len)
			write(1, "0", 1);
		write(1, "0x", 2);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
}

void			ft_type_ptr_zero(char *cnbr, int len, t_struct *f)
{
	if (f->prc == 1)
		ft_type_prec_ptr_zero(cnbr, len, f);
	else
	{
		while (f->wdn-- > len)
			write(1, "0", 1);
		write(1, "0x", 2);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
}

void			ft_type_ptr_right(char *cnbr, int len, t_struct *f)
{
	if (f->wdn > f->prcn)
	{
		while ((f->wdn-- - (f->prcn > len ? f->prcn : len)) > 0)
			write(1, " ", 1);
		while (f->prcn-- > len)
			write(1, "0", 1);
		write(1, "0x", 2);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
	else
	{
		while (f->prcn-- > len)
			write(1, "0", 1);
		write(1, "0x", 2);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
}

void			ft_type_ptr_left(char *cnbr, int p, int len, t_struct *f)
{
	if (f->wdn >= f->prcn)
	{
		while (p-- > len)
			write(1, "0", 1);
		write(0, "0x", 2);
		while (*cnbr)
			write(1, cnbr++, 1);
		while ((f->wdn-- - (f->prcn > len ? f->prcn : len)) > 0)
			write(1, " ", 1);
	}
	else
	{
		while (p-- > len)
			write(1, "0", 1);
		write(1, "0x", 1);
		while (*cnbr)
			write(1, cnbr++, 1);
		while ((f->wdn-- - (f->prcn + len)) > 0)
			write(1, " ", 1);
	}
}
