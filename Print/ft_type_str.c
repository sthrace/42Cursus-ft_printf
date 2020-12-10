/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:58:13 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/09 18:02:12 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_type_str_zero(char *str, t_struct *f)
{
	int		len;

	len = ft_strlen(str);
	while (f->wdn-- - len > 0)
		write(1, "0", 1);
	while (*str)
		write(1, str++, 1);
}

static void		ft_type_str_right(char *str, t_struct *f)
{
	int		len;

	len = ft_strlen(str);
	while (f->wdn-- - len > 0)
		write(1, " ", 1);
	while (*str)
		write(1, str++, 1);
}

static void		ft_type_str_left(char *str, t_struct *f)
{
	int		len;

	len = ft_strlen(str);
	while (*str)
		write(1, str++, 1);
	while (f->wdn-- - len > 0)
		write(1, " ", 1);
}

void			ft_type_str(char *str, t_struct *f)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (f->prc == 1 && f->prcn < len)
		str = ft_substr(str, 0, f->prcn);
	if (f->prc == 0 && f->wd == 0)
		while (*str)
			write(1, str++, 1);
	else if (f->lft == 1)
		ft_type_str_left(str, f);
	else if (f->lft == 0)
	{
		if (f->fz == 0)
			ft_type_str_right(str, f);
		else if (f->fz == 1)
			ft_type_str_zero(str, f);
	}
}
