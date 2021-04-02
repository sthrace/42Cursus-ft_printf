#include "ft_printf.h"

static void		ft_print_main(unsigned long long nbr, t_struct *f)
{
	write(1, "0x", 2);
	if (f->length > 0)
		ft_putnbr(nbr, 16, "0123456789abcdef");
	g_fsize += f->length;
}

static void		ft_print_flags(unsigned long long nbr, t_struct *f)
{
	if (f->flagleft == 1)
		ft_print_main(nbr, f);
	while (f->spaces-- > 0)
		g_fsize += write(1, " ", 1);
	if (f->flagleft == 0)
		ft_print_main(nbr, f);
}

void			ft_type_pointer(unsigned long long nbr, t_struct *f)
{
	f->length = ft_nbrlen(nbr, 16) + 2;
	f->spaces = f->width - f->length;
	ft_print_flags(nbr, f);
}
