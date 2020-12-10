/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:43:56 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/10 17:44:04 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_type_int(int nbr, t_struct *f)
{
	char	*cnbr;
	int		len;
	int		p;

	cnbr = ft_itoa(nbr);
	len = ft_strlen(cnbr);
	p = f->prcn;
	if (f->prc == 1 && f->prcn == 0)
		ft_type_blank(f);
	else if (f->prc == 0 && f->wd == 0)
		ft_type_plain(cnbr);
	else if (f->prc == 1 && f->prcn > 0 && f->prcn < len && f->wdn < len)
		ft_type_plain(cnbr);
	else if (f->prc == 1 && f->prcn == 0 && f->wd == 0)
		return (0);
	else if (f->lft == 1)
		ft_type_left(cnbr, p, len, f);
	else if (f->lft == 0)
	{
		if (f->fz == 0)
			ft_type_right(cnbr, len, f);
		else
			ft_type_zero(cnbr, len, f);
	}
	return (0);
}
