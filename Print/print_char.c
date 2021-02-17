/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:09:24 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 17:09:39 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_type_char(int c, t_struct *f)
{
	if (f->flagleft == 0)
	{
		while (f->width-- > 1)
			if (f->flagzero == 0)
				g_fsize += write(1, " ", 1);
			else
				g_fsize += write(1, "0", 1);
	}
	g_fsize += write(1, &c, 1);
	if (f->flagleft == 1)
		while (f->width-- > 1)
			g_fsize += write(1, " ", 1);
}
