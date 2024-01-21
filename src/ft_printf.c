/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis <mreis@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:39:18 by mreis             #+#    #+#             */
/*   Updated: 2024/01/15 19:50:44 by mreis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list arg)
{
	if (specifier == 'c')
		return (putchar_len(va_arg(arg, int)));
	else if (specifier == 's')
		return (putstr_len(va_arg(arg, char *)));
	else if (specifier == 'p')
		return (putptr_len((unsigned long)(va_arg(arg, void *)), 0));
	else if (specifier == 'd' || specifier == 'i')
		return (put_nbr_u_hex_len(va_arg(arg, int), 10, 0));
	else if (specifier == 'u')
		return (put_nbr_u_hex_len(va_arg(arg, unsigned int), 10, 0));
	else if (specifier == 'x')
		return (put_nbr_u_hex_len(va_arg(arg, unsigned int), 16, 0));
	else if (specifier == 'X')
		return (put_nbr_u_hex_len(va_arg(arg, unsigned int), 16, 1));
	else if (specifier == '%')
		return (putchar_len('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	if (format == NULL)
		return (0);
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), args);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}

// int	main()
// {
// 	int count;

// 	ft_printf("lets test a tring %s, today is %d, in hex %x, char->%c\n",
// 				"mariana",
// 				26,
// 				27,
// 				'z');
// 	count = ft_printf("hello %s\n", "john");
// 	ft_printf("the chars written are %d\n", count);
// 	// count = ft_printf("%d\n", INT_MIN);
// 	// ft_printf("the chars written are %d\n", count);
// 	// count = printf("%d\n", INT_MIN);
// 	// printf("the chars written are %d\n", count);
// }
