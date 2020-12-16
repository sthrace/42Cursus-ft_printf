/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:07:44 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/14 09:22:44 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int n)
{
	unsigned int		len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char				*out;
	unsigned int		nbr;
	unsigned int		dgt;
	int					i;

	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)n;
	dgt = ft_nbrlen(nbr);
	i = 0;
	if (!(out = (char *)malloc(sizeof(char) * (dgt + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (out[i] = '-'))
		dgt++;
	i = dgt - 1;
	while (nbr >= 10)
	{
		out[i--] = (char)(nbr % 10 + 48);
		nbr = nbr / 10;
	}
	out[i] = (char)(nbr % 10 + 48);
	out[dgt] = '\0';
	return (out);
}

char		*ft_itoa_unsignedint(unsigned int n)
{
	char				*out;
	unsigned int		dgt;
	int					i;

	dgt = ft_nbrlen(n);
	if (!(out = (char *)malloc(sizeof(char) * (dgt + 1))))
		return (0);
	i = dgt - 1;
	while (n >= 10)
	{
		out[i--] = (char)(n % 10 + 48);
		n = n / 10;
	}
	out[i] = (char)(n % 10 + 48);
	out[dgt] = '\0';
	return (out);
}

int			ft_check_ascii(unsigned long long n, unsigned int base)
{
	int				ascii;

	ascii = 0;
	if (n % base < 10)
		ascii = 48;
	else
		ascii = 87;
	return (ascii);
}

char		*ft_itoa_base(unsigned long long n, unsigned int base)
{
	char				*out;
	int					i;
	unsigned long long	nbr;

	i = 0;
	nbr = n;
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	if (!(out = malloc(sizeof(char) * (i + 1))))
		return (0);
	out[i + 1] = '\0';
	while (n >= base)
	{
		out[i--] = (char)(n % base + ft_check_ascii(n, base));
		n = n / base;
	}
	if ((n == 0) || (n % base < 10))
		out[i] = (char)(n % base + 48);
	else
		out[i] = (char)(n % base + 87);
	return (out);
}
