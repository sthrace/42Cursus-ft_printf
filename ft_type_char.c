/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:56:10 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/03 14:56:18 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void     ft_type_char_len(char c, t_struct *formats)
{
    if (formats->leftalign == 1)
    {
        write(1, &c, 1);
        while (formats->width--)
            write(1, " ", 1);
    }
    else if (formats->fillzeros == 1)
    {
        while (1 < formats->width--)
            write(1, "0", 1);
        write(1, &c, 1);
    }
    else
    {
        while (1 < formats->width--)
            write(1, " ", 1);
        write(1, &c, 1);
    }
}

void        ft_type_char(char c, t_struct *formats)
{
    if (formats->width <= 1)
        write(1, &c, 1);
    else if (formats->width > 1)
        ft_type_char_len(c, formats);        
}
