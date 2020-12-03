/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:01:37 by sthrace           #+#    #+#             */
/*   Updated: 2020/11/30 19:06:08 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_struct
{
    int     leftalign;
    int     fillzeros;
    int     precise;
    int     precision;
    int     width;
    char    type;
    char    precstar;
    char    widthstar;
}               t_struct;

int			ft_printf(const char *format, ...);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int		    ft_toupper(int c);
int		    ft_atoi(const char *str);
void        ft_type_char(char c, t_struct *formats);
void        ft_type_str(char *c, t_struct *formats);

#endif
