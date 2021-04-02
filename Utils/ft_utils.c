#include "ft_printf.h"

int				ft_nbrlen(long long nbr, int base)
{
	int		i;

	i = 1;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

void			ft_putnbr(long long nbr, int base, char *ascii)
{
	if (nbr >= base)
		ft_putnbr(nbr / base, base, ascii);
	write(1, &ascii[nbr % base], 1);
}
