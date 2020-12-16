/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:41:47 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/10 17:43:13 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_negative_width(t_struct *f)
{
	f->wdn *= -1;
	f->lft = 1;
}

static void		ft_star_width(va_list args, t_struct *f)
{
	f->wdstar = '*';
	f->wdn = va_arg(args, int);
}

static void		ft_calc_wd(const char *s, char *wd, va_list args, t_struct *f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((s[j] == '-') || (s[j] == '0'))
		j++;
	while (s[j] != '.' && s[j] != f->type && s[j] != '\0' && s[j] != '%')
	{
		if (s[j] == '*')
		{
			ft_star_width(args, f);
			break ;
		}
		wd[i++] = s[j++];
	}
	if (f->wdstar != '*')
		f->wdn = ft_atoi(wd);
	if (f->wdn < 0)
		ft_negative_width(f);
	free(wd);
	ft_set_prec(s, args, f);
}

int				ft_set_width(const char *s, va_list args, t_struct *f)
{
	int				i;
	int				step;
	char			*wd;

	i = 0;
	step = 0;
	while ((s[i] == '-') || (s[i] == '0'))
	{
		step++;
		i++;
	}
	while (s[i] != '.' && s[i] != f->type && s[i] != '\0' && s[i] != '%')
		i++;
	if ((ft_isdigit(s[step])) || (s[step]) == '*')
		f->wd = 1;
	if ((i - step) == 0)
		wd = NULL;
	else if (!(wd = malloc(sizeof(char) * ((i - step) + 1))))
		return (0);
	if (wd)
		ft_calc_wd(s, wd, args, f);
	else
		ft_set_prec(s, args, f);
	return (0);
}
