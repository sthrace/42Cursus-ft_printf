/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:44:44 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/14 09:23:24 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_type_hexa(unsigned int nbr, t_struct *f)
{
	char	*cnbr;
	int		len;

	cnbr = ft_itoa_base(nbr, 16);
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

static char		*ft_convert(char *cnbr)
{
	int		i;

	i = 0;
	while (cnbr[i] != '\0')
	{
		if (cnbr[i] > 96 && cnbr[i] < 123)
			cnbr[i] = ft_toupper(cnbr[i]);
		i++;
	}
	return (cnbr);
}

int				ft_type_hexaup(unsigned int nbr, t_struct *f)
{
	char	*cnbr;
	int		len;

	cnbr = ft_convert(ft_itoa_base(nbr, 16));
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
