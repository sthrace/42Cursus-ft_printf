/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:32:14 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/14 09:25:04 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_resolve_arg(const char *str, va_list args, t_struct *f)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (f->lft == 1)
		f->fz = 0;
	if (ft_strchr((char *)str, '.'))
		f->prc = 1;
	if ((ft_strchr("cspdiuxXnfge", str[i])) || (ft_strchr((char *)str, '%')))
		f->type = (str[ft_strlen(str) - 1]);
	ft_set_width(str, args, f);
}

static int		ft_extract_arg(char *str, va_list args, t_struct *f, int i)
{
	while ((str[i] == '0') || (str[i] == '-'))
	{
		if (i >= ft_strlen(str) - 1)
		{
			return (0);
			break ;
		}
		if (ft_strchr(&str[i], '-'))
			f->lft = 1;
		if (ft_strchr(&str[i], '0'))
			f->fz = 1;
		i++;
	}
	while ((ft_isdigit(str[i])) || (str[i] == '*') || (str[i] == '.'))
	{
		if (i >= ft_strlen(str) - 1)
		{
			return (0);
			break ;
		}
		i++;
	}
	if ((ft_strchr("cspdiuxXnfge", str[i]) != NULL) || (str[i] == '%'))
		ft_resolve_arg(ft_substr(str, 1, i), args, f);
	return (i);
}

static int		ft_finddelimiter(const char *str, va_list args, int i)
{
	t_struct	f;

	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1])
			{
				ft_init_formats(&f);
				i += ft_extract_arg((char *)&str[i], args, &f, 1) + 1;
			}
			else
				return (g_fsize);
		}
		else if (str[i] != '%')
		{
			g_fsize += write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;

	va_start(args, str);
	g_fsize = 0;
	if (!(ft_strchr((char *)str, '%')))
	{
		g_fsize = ft_strlen(str);
		write(1, &str[0], ft_strlen((char *)str));
		return (g_fsize);
	}
	else
		ft_finddelimiter((char *)str, args, 0);
	va_end(args);
	return (g_fsize);
}
