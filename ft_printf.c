/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:04:56 by sthrace           #+#    #+#             */
/*   Updated: 2020/11/17 18:48:37 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int			ft_printf(const char *format, ...)
{
	va_list	args;		/* point on next unnamed arguement */
	int		i;			/*	array counter */
	int		j;			/* 	arg array counter	*/
	char	*p;			/*   */
	char	*arg;		/*	declare *char type variable to hold string arguement	*/
	
	va_start(args, format);  /* set arg to 1st unnamed arguement */
	i = 0;
	while (format[i])	/* loop over array */
	{
		j = 0;
		if (format[i] != '%')	/* print value if it is not equal to '%' */
		{
			write(1, &format[i], 1);
		}
		else
		{
			arg = va_arg(args, char*);	/*	here we need to automate the type of arg */
				while(arg[j])
				{
					write(1, &arg[j], 1);
					j++;
				}
				i++;
		}
		i++;
	}
	va_end(args);	/* empy variadic arguements list	*/
	return (0);
}

int			main()
{
	ft_printf("Say %s to this %s!\n", "Hello", "world");
//	printf("Say %s to %s  %s!\n", "Hello", "this", "world");
}
