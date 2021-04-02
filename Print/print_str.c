#include "ft_printf.h"

void			ft_type_str(char *str, t_struct *f)
{
	if (!str)
		str = "(null)";
	while (str[f->length])
		f->length++;
	if (f->precision > -1 && f->precision < f->length)
		f->length = f->precision;
	else if (f->precision == 0)
		f->length = 0;
	f->spaces = f->width - f->length;
	if (f->flagleft == 0)
		while (f->spaces-- > 0)
			g_fsize += write(1, " ", 1);
	g_fsize += write(1, str, f->length);
	if (f->flagleft == 1)
		while (f->spaces-- > 0)
			g_fsize += write(1, " ", 1);
}
