/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ptr_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:22:07 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/16 09:40:04 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_type_ptr_zero(char *cnbr, int len, t_struct *f)
{
	g_fsize += write(1, "0x", 2);
	while (f->wdn-- > len)
		g_fsize += write(1, "0", 1);
	while (*cnbr)
		g_fsize += write(1, cnbr++, 1);
}

int				ft_type_ptr_blank(t_struct *f)
{
	if (f->wdn > 2)
		while (f->wdn-- > 2)
			g_fsize += write(1, " ", 1);
	g_fsize += write(1, "0x", 2);
	return (0);
}

void			ft_type_ptr_left(char *cnbr, int len, t_struct *f)
{
	int		newlen;

	newlen = len;
	if (f->prcn > len)
		newlen = f->prcn;
	else if (f->prcn < len)
		newlen = len + 2;
	g_fsize += write(1, "0x", 2);
	while (f->prcn-- > len)
		g_fsize += write(1, "0", 1);
	while (*cnbr)
		g_fsize += write(1, cnbr++, 1);
	while (f->wdn-- > newlen)
		g_fsize += write(1, " ", 1);
}

void			ft_type_ptr_right(char *cnbr, int len, t_struct *f)
{
	int		newlen;

	newlen = len;
	if (f->prcn > len)
		newlen = f->prcn;
	else if (f->prcn < len)
		newlen = len + 2;
	while (f->wdn-- > newlen)
		g_fsize += write(1, " ", 1);
	g_fsize += write(1, "0x", 2);
	while (f->prcn-- > len)
		g_fsize += write(1, "0", 1);
	while (*cnbr)
		g_fsize += write(1, cnbr++, 1);
}

int				ft_type_ptr(uintptr_t ptr, t_struct *f)
{
	char	*cptr;
	int		len;

	cptr = ft_itoa_base(ptr, 16);
	len = ft_strlen(cptr);
	if (f->prc == 1 && f->prcn == 0 && ptr == 0)
		ft_type_ptr_blank(f);
	else if (f->lft == 1)
		ft_type_ptr_left(cptr, len, f);
	else if (f->fz == 1 && f->prc == 0)
		ft_type_ptr_zero(cptr, len, f);
	else
		ft_type_ptr_right(cptr, len, f);
	return (0);
}
