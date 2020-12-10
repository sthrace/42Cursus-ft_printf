/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:06:21 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/10 17:07:03 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	size_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	size_s = ft_strlen(s);
	i = 0;
	while (i < len && i + start < size_s)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
