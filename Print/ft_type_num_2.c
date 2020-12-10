/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_num_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:29:42 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/10 18:31:26 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_type_blank(t_struct *f)
{
	if (f->wd == 1 && f->fz == 1)
		while (f->wdn--)
			write(1, "0", 1);
	else if (f->wd == 1 && f->fz == 0)
		while (f->wdn--)
			write(1, " ", 1);
}

static void		ft_type_prec_zero_short(char *cnbr, int len, t_struct *f)
{
	if (cnbr[0] == '-')
	{
		cnbr = cnbr + 1;
		write(1, "-", 1);
		while (f->prcn-- > len - 1)
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

static void		ft_type_prec_zero(char *cnbr, int len, t_struct *f)
{
	if (f->prcn > f->wdn)
		ft_type_prec_zero_short(cnbr, len, f);
	else if (cnbr[0] == '-')
	{
		cnbr = cnbr + 1;
		while (f->wdn-- - (f->prcn > len ? f->prcn + 1 : len))
			write(1, " ", 1);
		write(1, "-", 1);
		while (f->prcn-- > len - 1)
			write(1, "0", 1);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
	else if (cnbr[0] != '-')
	{
		while (f->wdn-- - (f->prcn > len ? f->prcn : len))
			write(1, " ", 1);
		while (f->prcn-- > len)
			write(1, "0", 1);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
}

void			ft_type_zero(char *cnbr, int len, t_struct *f)
{
	if (f->prc == 1)
		ft_type_prec_zero(cnbr, len, f);
	else if (cnbr[0] == '-')
	{
		cnbr = cnbr + 1;
		write(1, "-", 1);
		while (f->wdn-- > len)
			write(1, "0", 1);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
	else if (cnbr[0] != '-')
	{
		while (f->wdn-- > len)
			write(1, "0", 1);
		while (*cnbr)
			write(1, cnbr++, 1);
	}
}
