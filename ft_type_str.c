#include "ft_printf.h"

static void     ft_type_str_len(char *c, t_struct *formats)
{
    int len;

    len = (int)(ft_strlen(c));
    if (formats->leftalign == 1 && formats->width > len)
    {
        while(*c)
            write(1, c++, 1);
        while (formats->width--)
            write(1, " ", 1);
    }
    else if (formats->fillzeros == 1 && formats->width > len)
    {
        while (formats->width-- > len)
            write(1, "0", 1);
        while(len-- > 0)
            write(1, c++, 1);
    }
    else
    {
        while (len < formats->width--)
            write(1, " ", 1);
        while (len--)
            write(1, c++, 1);
    }
}

void        ft_type_str(char *c, t_struct *formats)
{
    if (formats->width == 0)
    {
        while (*c)
            write(1, c++, 1);
    }
    else
        ft_type_str_len(c, formats);
}