/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:04:07 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/10 18:19:07 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_type_ptr_plain(char *cnbr)
{
	write(1, "0x", 2);
	while (*cnbr)
		write(1, cnbr++, 1);
}

int				ft_type_ptr(uintptr_t ptr, t_struct *f)
{
	char	*cptr;
	int		len;
	int		p;

	cptr = ft_itoa_base(ptr, 16);
	len = ft_strlen(cptr) + 2;
	p = f->prcn;
	if (f->prc == 1 && f->prcn == 0)
		ft_type_ptr_blank(f);
	else if (f->prc == 0 && f->wd == 0)
		ft_type_ptr_plain(cptr);
	else if (f->prc == 1 && f->prcn > 0 && f->prcn < len && f->wdn < len)
		ft_type_ptr_plain(cptr);
	else if (f->prc == 1 && f->prcn == 0 && f->wd == 0)
		return (0);
	else if (f->lft == 1)
		ft_type_ptr_left(cptr, p, len, f);
	else if (f->lft == 0)
	{
		if (f->fz == 0)
			ft_type_ptr_right(cptr, len, f);
		else
			ft_type_ptr_zero(cptr, len, f);
	}
	return (0);
}
