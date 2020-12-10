/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:40:29 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/10 17:41:34 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_calc_prec(int d, char *ptr, va_list args, t_struct *f)
{
	char		*nbr;

	if (!(nbr = malloc(sizeof(char) * d)))
		return (0);
	nbr[d] = '\0';
	while (d >= 1)
	{
		if (*(ptr - 1) == '*')
		{
			f->prcstar = '*';
			f->prcn = va_arg(args, int);
			break ;
		}
		nbr[d - 1] = *(ptr - 1);
		ptr--;
		d--;
	}
	if (nbr && f->prcstar != '*')
		f->prcn = ft_atoi(nbr);
	if (f->prcn < 0)
		f->prc = 0;
	ft_type(args, f);
	return (0);
}

void			ft_set_prec(const char *str, va_list args, t_struct *f)
{
	char		*ptr;
	int			digits;

	digits = 0;
	if (f->prc == 1)
	{
		if (*(ft_strchr(str, '.') + 1) == f->type)
		{
			f->prcn = 0;
			ft_type(args, f);
		}
		else
		{
			ptr = (ft_strchr(str, '.') + 1);
			while ((*ptr > 47 && *ptr < 58) || (*ptr == '*'))
			{
				digits++;
				ptr++;
			}
			ft_calc_prec(digits, ptr, args, f);
		}
	}
	else if (f->prc == 0)
		ft_type(args, f);
}
