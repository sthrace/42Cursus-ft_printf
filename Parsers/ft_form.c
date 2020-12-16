/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:40:12 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/14 09:25:24 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_type(va_list args, t_struct *f)
{
	if (f->type == 'c')
		ft_type_char(va_arg(args, int), f);
	if (f->type == '%')
		ft_type_char('%', f);
	if (f->type == 's')
		ft_type_str(va_arg(args, char*), f);
	if (f->type == 'p')
		ft_type_ptr(va_arg(args, uintptr_t), f);
	if ((f->type == 'd') || (f->type == 'i'))
		ft_type_int(va_arg(args, int), f);
	if (f->type == 'u')
		ft_type_unsgn_int(va_arg(args, unsigned int), f);
	if (f->type == 'x')
		ft_type_hexa(va_arg(args, int), f);
	if (f->type == 'X')
		ft_type_hexaup(va_arg(args, int), f);
	if (ft_strchr("nfge", f->type))
		return (0);
	return (0);
}

void		ft_init_formats(t_struct *f)
{
	f->lft = 0;
	f->fz = 0;
	f->prc = 0;
	f->prcn = 0;
	f->wd = 0;
	f->wdn = 0;
	f->type = '0';
	f->prcstar = '0';
	f->wdstar = '0';
}
