/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:32:14 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/03 09:29:48 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_type(const char *str, va_list args, t_struct *formats)
{
	if (formats->type == 'c')
		ft_type_char(va_arg(args, int), formats);
	if (formats->type == 's')
		ft_type_str(va_arg(args, char*), formats);
	if (formats->type == 'p')
		return (0);
	if (formats->type == 'd')
		return (0);
	if (formats->type == 'u')
		return (0);
	if (formats->type == 'x')
		return (0);
	if (formats->type == 'X')
		return (0);
	if (formats->type == 'n')
		return (0);
	if (formats->type == 'f')
		return (0);
	if (formats->type == 'g')
		return (0);
	if (formats->type == 'e')
		return (0);
	str = str + 1;
	return (0);
}

static void			ft_init_formats(t_struct *formats)
{
	formats->leftalign = 0;
    formats->fillzeros = 0;
    formats->precise = 0;
    formats->precision = 0;
    formats->width = 0;
    formats->type = '0';
    formats->precstar = '0';
}

static int		ft_set_prec(const char *str, va_list args, t_struct *formats)
{
	char*		pprec;
	int			digits;
	char*		nbr;

	pprec = NULL;
	digits = 0;
	if (formats->precise == 1)
	{
		pprec = (ft_strchr(str, '.') + 1);
		while (*pprec++ != formats->type)
		{
			digits++;
		}
		if (!(nbr = malloc(sizeof(char)* digits + 1)))
			return (0);
		while (digits >= 0)
		{
			nbr[digits - 1] = *(pprec - 2);
			digits--;
			pprec--;
		}
		formats->precision = ft_atoi(nbr);
		if (*pprec == '*')
			formats->precision = va_arg(args, int);
		free(nbr);
	}
	ft_type(str, args, formats);
	return (0);
}

static int		ft_set_width(const char *str, va_list args, t_struct *formats)
{
	int				i;
	int				digits;
	char*			wd;

	i = 0;
	digits = 1;
//	printf("%s ", str);
	while ((str[i] == '-') || (str[i] == '0'))
		i++;
	if (formats->precise == 1)
	{
		while (str[++i] != '.')
			digits++;
		if (*(ft_strchr((char *)str, '.') - 1) == '*')
			formats->width = va_arg(args, int);
	}
	else if (formats->precise == 0)
	{
		while (str[++i] != formats->type)
			digits++;
		if (*(ft_strchr((char *)str, formats->type) - 1) == '*')
			formats->width = va_arg(args, int);
	}
	if (!(wd = malloc(sizeof(char)*digits + 1)))
		return (0);
	while (digits >= 0)
	{
		wd[digits - 1] = str[i - 1];
		digits--;
		i--;
	}
	if (formats->width == 0)
		formats->width = ft_atoi(wd);
	free(wd);
	ft_set_prec(str, args, formats);
	return (0);
}

static void		ft_resolve_arg(const char *str, va_list args, t_struct *formats)
{
	if (ft_strchr((char *)str, '-'))
		formats->leftalign = 1;
	if (str[0] == '0')
		formats->fillzeros = 1;
	if (ft_strchr((char *)str, '.'))
		formats->precise = 1;
	if (ft_strchr((char *)str, 'c'))
		formats->type = 'c';
	else if (ft_strchr((char *)str, 's'))
		formats->type = 's';
	else if (ft_strchr((char *)str, 'p'))
		formats->type = 'p';
	else if ((ft_strchr((char *)str, 'd') || (ft_strchr((char *)str, 'i'))))
		formats->type = 'd';
	else if (ft_strchr((char *)str, 'u'))
		formats->type = 'u';
	else if (ft_strchr((char *)str, 'x'))
		formats->type = 'x';
	else if (ft_strchr((char *)str, 'X'))
		formats->type = 'X';
	else if (ft_strchr((char *)str, 'n'))
		formats->type = 'n';
	else if (ft_strchr((char *)str, 'f'))
		formats->type = 'f';
	else if (ft_strchr((char *)str, 'g'))
		formats->type = 'g';
	else if (ft_strchr((char *)str, 'e'))
		formats->type = 'e';
	ft_set_width(str, args, formats);
}

static int		ft_extract_arg(char *str, va_list args, t_struct *formats)
{
	int			i;
	int			len;

	i = 0;
	len = 1;
	while (str[i] != '\0' && str[i] != 'c' && str[i] != 's'
		&& str[i] != 'p' && str[i] != 'd' && str[i] != 'i'
		&& str[i] != 'u' && str[i] != 'x' && str[i] != 'X'
		&& str[i] != 'n' && str[i] != 'f' && str[i] != 'g'
		&& str[i] != 'e')
	{
		if (str[i + 1] == '%')
		{
			write(1, &str[i + 1], 1);
			len = 1;
			break ;
		}
		else if (str[i] == '-' || str[i] == '0' ||
			str[i] == '.' || str[i] == '*' ||
			(str[i] > 48 && str[i] < 58))
			len++;
		i++;
	}
	ft_resolve_arg(ft_substr(str, 1, len), args, formats);
	return (len);
}

static int		ft_strparse(const char *str, va_list args)
{
	int			i;
	t_struct	formats;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_formats(&formats);
			i += ft_extract_arg((char *)&str[i], args, &formats) + 1;
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (0);
}

int			ft_printf(const char *str, ...)
{
	va_list		args;

	va_start(args, str);
	if (!(ft_strchr((char *)str, '%')))
	{
		write(1, &str[0], ft_strlen((char *)str));
		return (0);
	}
	else
		ft_strparse((char *)str, args);
	va_end(args);
	return (0);
}
