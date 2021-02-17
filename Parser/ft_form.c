/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:40:12 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 18:49:13 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_formats(t_struct *f)
{
	f->flagleft = 0;
	f->flagzero = 0;
	f->precision = -1;
	f->width = 0;
	f->type = '0';
	f->spaces = 0;
	f->zeros = 0;
	f->flaghash = 0;
	f->flagspace = 0;
	f->flagsign = 0;
	f->flagl = 0;
	f->flagh = 0;
	f->length = 0;
	f->intmin = 0;
	f->negative = 0;
	f->zerofront = 0;
	f->flagfl = 0;
}
