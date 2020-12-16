/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:37:31 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/16 09:42:32 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_type_zero(char *cnbr, int len, t_struct *f)
{
	if (cnbr[0] == '-')
	{
		g_fsize += write(1, "-", 1);
		cnbr = cnbr + 1;
	}
	while (f->wdn-- > len)
		g_fsize += write(1, "0", 1);
	while (*cnbr)
		g_fsize += write(1, cnbr++, 1);
}

int				ft_type_blank(t_struct *f)
{
	if (f->wdn > 0)
		while (f->wdn--)
			g_fsize += write(1, " ", 1);
	return (0);
}

void			ft_type_left(char *cnbr, int len, t_struct *f)
{
	int		newlen;

	newlen = len;
	if (f->prcn > len)
		newlen = f->prcn;
	if (cnbr[0] == '-')
	{
		g_fsize += write(1, "-", 1);
		cnbr = cnbr + 1;
		len -= 1;
		if ((f->wdn > newlen && f->prc == 1)
			&& ((f->prcn > f->wdn) || (f->prcn > len)))
			newlen += 1;
	}
	while (f->prcn-- > len)
		g_fsize += write(1, "0", 1);
	while (*cnbr)
		g_fsize += write(1, cnbr++, 1);
	while (f->wdn-- > newlen)
		g_fsize += write(1, " ", 1);
}

void			ft_type_right(char *cnbr, int len, t_struct *f)
{
	int		newlen;

	newlen = len;
	if (f->prcn > len)
		newlen = f->prcn;
	if (cnbr[0] == '-')
	{
		len -= 1;
		if ((f->wdn > newlen && f->prc == 1)
			&& ((f->prcn > f->wdn) || (f->prcn > len)))
			newlen += 1;
	}
	while (f->wdn-- > newlen)
		g_fsize += write(1, " ", 1);
	if (cnbr[0] == '-')
	{
		g_fsize += write(1, "-", 1);
		cnbr = cnbr + 1;
	}
	while (f->prcn-- > len)
		g_fsize += write(1, "0", 1);
	while (*cnbr)
		g_fsize += write(1, cnbr++, 1);
}
