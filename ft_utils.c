/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 09:10:41 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/03 09:30:33 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && c != *s)
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

int			ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}
