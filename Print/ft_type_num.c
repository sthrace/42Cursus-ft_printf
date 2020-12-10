/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:37:31 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/10 18:29:17 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_type_prec_right(char *cnbr, int len, t_struct *f)
{
	if (cnbr[0] == '-')
	{
		cnbr = cnbr + 1;
		len = len - 1;
		write(1, "-", 1);
		while (f->prcn-- > len)
			write(1, "0", 1);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
	else if (cnbr[0] != '-')
	{
		while (f->prcn-- > len)
			write(1, "0", 1);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
}

static void		ft_type_prec_left(char *cnbr, int p, int len, t_struct *f)
{
	if (cnbr[0] == '-')
	{
		cnbr = cnbr + 1;
		write(1, "-", 1);
		while (p-- > len - 1)
			write(1, "0", 1);
		while (*cnbr)
			write(1, cnbr++, 1);
		while ((f->wdn-- - (f->prcn + len)) > 0)
			write(1, " ", 1);
	}
	else if (cnbr[0] != '-')
	{
		while (p-- > len)
			write(1, "0", 1);
		while (*cnbr)
			write(1, cnbr++, 1);
		while ((f->wdn-- - (f->prcn + len)) > 0)
			write(1, " ", 1);
	}
}

void			ft_type_right(char *cnbr, int len, t_struct *f)
{
	if (f->wdn > f->prcn)
	{
		if (cnbr[0] == '-')
		{
			cnbr = cnbr + 1;
			while ((f->wdn-- - (f->prcn > len ? f->prcn + 1 : len)) > 0)
				write(1, " ", 1);
			write(1, "-", 1);
			while (f->prcn-- > len - 1)
				write(1, "0", 1);
			while (*cnbr)
				write(1, cnbr++, 1);
		}
		else if (cnbr[0] != '-')
		{
			while ((f->wdn-- - (f->prcn > len ? f->prcn : len)) > 0)
				write(1, " ", 1);
			while (f->prcn-- > len)
				write(1, "0", 1);
			while (*cnbr)
				write(1, cnbr++, 1);
		}
	}
	else
		ft_type_prec_right(cnbr, len, f);
}

void			ft_type_left(char *cnbr, int p, int len, t_struct *f)
{
	if (f->wdn >= f->prcn)
	{
		if (cnbr[0] == '-')
		{
			cnbr = cnbr + 1;
			write(1, "-", 1);
			while (p-- > len - 1)
				write(1, "0", 1);
			while (*cnbr)
				write(1, cnbr++, 1);
			while ((f->wdn-- - (f->prcn > len ? f->prcn + 1 : len)) > 0)
				write(1, " ", 1);
		}
		else if (cnbr[0] != '-')
		{
			while (p-- > len)
				write(1, "0", 1);
			while (*cnbr)
				write(1, cnbr++, 1);
			while ((f->wdn-- - (f->prcn > len ? f->prcn : len)) > 0)
				write(1, " ", 1);
		}
	}
	else
		ft_type_prec_left(cnbr, p, len, f);
}

void			ft_type_plain(char *cnbr)
{
	while (*cnbr)
		write(1, cnbr++, 1);
}
