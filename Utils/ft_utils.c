/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:50:36 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 18:51:25 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_nbrlen(long long nbr, int base)
{
	int		i;

	i = 1;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

void			ft_putnbr(long long nbr, int base, char *ascii)
{
	if (nbr >= base)
		ft_putnbr(nbr / base, base, ascii);
	write(1, &ascii[nbr % base], 1);
}
