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

	cnbr = ft_itoa(nbr);
	len = ft_strlen(cnbr);
	if (f->prc == 1 && f->prcn == 0 && nbr == 0)
		ft_type_blank(f);
	else if (f->lft == 1)
		ft_type_left(cnbr, len, f);
	else if (f->fz == 1 && f->prc == 0)
		ft_type_zero(cnbr, len, f);
	else
		ft_type_right(cnbr, len, f);
	return (0);
}
