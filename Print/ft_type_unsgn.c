/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_unsgn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:44:12 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/10 18:03:36 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_type_unsgn_int(unsigned int nbr, t_struct *f)
{
	char	*cnbr;
	int		ln;
	int		p;

	cnbr = ft_itoa_unsignedint(nbr);
	ln = ft_strlen(cnbr);
	p = f->prcn;
	if (f->prc == 1 && f->prcn == 0)
		ft_type_blank(f);
	else if (f->prc == 0 && f->wd == 0)
		ft_type_plain(cnbr);
	else if (f->prc == 1 && f->prcn > 0 && f->prcn < ln && f->wdn < ln)
		ft_type_plain(cnbr);
	else if (f->prc == 1 && f->prcn == 0 && f->wd == 0)
		return (0);
	else if (f->lft == 1)
		ft_type_left(cnbr, p, ln, f);
	else if (f->lft == 0)
	{
		if (f->fz == 0)
			ft_type_right(cnbr, ln, f);
		else
			ft_type_zero(cnbr, ln, f);
	}
	return (0);
}
