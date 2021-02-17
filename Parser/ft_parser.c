/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:59:57 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 17:06:40 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_type(char *str, int i, t_struct *f)
{
	if ((str[i] == 'l' && str[i + 1] == 'l') ||
		(str[i] == 'h' && str[i + 1] == 'h'))
	{
		if (str[i] == 'l')
			f->flagl = 2;
		else
			f->flagh = 2;
	}
	else if ((str[i] == 'l' && str[i + 1] != 'l') ||
			(str[i] == 'h' && str[i + 1] != 'h'))
	{
		if (str[i] == 'l')
			f->flagl = 1;
		else
			f->flagh = 1;
	}
	else if (str[i] == 'L')
		f->flagfl = 1;
	if (!str[i + f->flagfl + f->flagl + f->flagh])
		return (0);
	f->type = str[i + f->flagh + f->flagl + f->flagfl];
	return (i + f->flagfl + f->flagl + f->flagh);
}

static int		ft_precision(char *str, int i, t_struct *f, va_list args)
{
	if (str[i] == '.')
	{
		f->precision = 0;
		i++;
		while (str[i] == '*' || (str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] == '*')
			{
				f->precision = va_arg(args, int);
				if (f->precision < 0)
					f->precision = -1;
				i++;
				break ;
			}
			f->precision = f->precision * 10 + (str[i] - 48);
			i++;
		}
	}
	return (i);
}

static int		ft_width(char *str, int i, t_struct *f, va_list args)
{
	while (str[i] == '*' || (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '*')
		{
			f->width = va_arg(args, int);
			if (f->width < 0)
			{
				f->width = -f->width;
				f->flagleft = 1;
			}
			i++;
			break ;
		}
		f->width = f->width * 10 + (str[i] - 48);
		i++;
	}
	return (i);
}

int				ft_parser(char *str, va_list args, int i, t_struct *f)
{
	while (str[i] == ' ' || str[i] == '-' ||
		str[i] == '0' || str[i] == '#' || str[i] == '+')
	{
		if (str[i] == ' ')
			f->flagspace = 1;
		else if (str[i] == '-')
			f->flagleft = 1;
		else if (str[i] == '0')
			f->flagzero = 1;
		else if (str[i] == '#')
			f->flaghash = 2;
		else if (str[i] == '+')
			f->flagsign = 1;
		i++;
	}
	i = ft_width(str, i, f, args);
	i = ft_precision(str, i, f, args);
	i = ft_type(str, i, f);
	if (f->flagleft == 1)
		f->flagzero = 0;
	ft_select_type(args, f);
	return (i);
}
