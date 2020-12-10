/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:55:02 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/09 17:57:00 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_type_chr_zero(char c, t_struct *f)
{
	while (f->wdn-- > 1)
		write(1, "0", 1);
	write(1, &c, 1);
}

static void		ft_type_chr_right(char c, t_struct *f)
{
	while (f->wdn-- > 1)
		write(1, " ", 1);
	write(1, &c, 1);
}

static void		ft_type_chr_left(char c, t_struct *f)
{
	write(1, &c, 1);
	while (f->wdn-- > 1)
		write(1, " ", 1);
}

void			ft_type_char(char c, t_struct *f)
{
	if (f->wdn > 1 && f->lft == 0)
	{
		if (f->fz == 0)
			ft_type_chr_right(c, f);
		else if (f->fz == 1)
			ft_type_chr_zero(c, f);
	}
	else if (f->wdn > 1 && f->lft == 1)
		ft_type_chr_left(c, f);
	else
		write(1, &c, 1);
}
