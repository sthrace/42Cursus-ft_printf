/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:32:14 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/10 17:34:33 by sthrace          ###   ########.fr       */
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
		if (ft_strchr(&str[i], '-'))
			f->lft = 1;
		if (ft_strchr(&str[i], '0'))
			f->fz = 1;
		i++;
	}
	while ((ft_strchr("cspdiuxXnfge", str[i]) == NULL)
			&& str[i] != '%' && str[i] != '\0')
	{
		if ((str[i - 1]) && (str[i - 1] == '%' && str[i] == '%'))
		{
			write(1, &str[i], 1);
			i = -1;
			break ;
		}
		i++;
	}
	if (i == -1)
		return (i + 2);
	else
		ft_resolve_arg(ft_substr(str, 1, i), args, f);
	return (i);
}

static int		ft_finddelimiter(const char *str, va_list args)
{
	int			i;
	t_struct	f;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_formats(&f);
			i += ft_extract_arg((char *)&str[i], args, &f, 1) + 1;
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (0);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;

	va_start(args, str);
	if (!(ft_strchr((char *)str, '%')))
	{
		write(1, &str[0], ft_strlen((char *)str));
		return (0);
	}
	else
		ft_finddelimiter((char *)str, args);
	va_end(args);
	return (0);
}
