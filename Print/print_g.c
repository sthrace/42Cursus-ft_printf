#include "ft_printf.h"

static void		ft_corrector(long long decimal, long long whole, t_struct *f)
{
	int			cnt;

	cnt = f->precision;
	while (cnt-- > 0)
	{
		if (decimal % 10 != 0)
			break ;
		decimal = decimal / 10;
	}
	if (f->flagleft == 0)
		ft_type_right(f);
	else
		ft_type_left(whole, f);
	if (decimal != 0)
	{
		write(1, ".", 1);
		ft_type_decimal(decimal, f);
	}
}

static void		ft_sort_decimal(long double dcdbl, long long whole, t_struct *f)
{
	int			cnt;
	long long	multiplier;
	long long	decimal;

	cnt = f->precision;
	multiplier = 1;
	while (cnt-- > 0)
	{
		dcdbl = dcdbl * 10;
		if (dcdbl < 0.9)
			f->zerofront = f->zerofront + 1;
		multiplier = multiplier * 10;
	}
	dcdbl = (long long)(dcdbl * 10) % 10 > 4 ? dcdbl + 1 : dcdbl;
	decimal = (long long)dcdbl;
	if (decimal / multiplier > 0.5 && (f->precision < 2 ||
		f->precision == 6) && (whole % 2 != 0 || (whole == 0 && dcdbl != 1.5)))
	{
		decimal = 0;
		f->zerofront = f->precision - 1;
		whole = whole + 1;
	}
	ft_corrector(decimal, whole, f);
}

void			ft_type_g(long double nbr, t_struct *f)
{
	long int	whole;
	long double	decdouble;
	int			corrector;

	if (nbr < 0.0 || 1 / nbr < 0.0)
	{
		nbr = -nbr;
		f->flagsign = 1;
		f->negative = 1;
	}
	if (f->flagsign == 1)
		f->flagspace = 0;
	if (f->precision == -1)
		f->precision = 6;
	whole = (long long int)nbr;
	corrector = 1;
	if (f->precision == 0 && f->flaghash != 1)
		corrector = 0;
	f->length = ft_nbrlen(whole, 10) + f->precision + corrector + f->flagsign;
	f->spaces = f->width - f->length;
	decdouble = (nbr - whole);
	g_fsize = f->length;
	ft_sort_decimal(decdouble, whole, f);
}
