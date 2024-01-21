/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfr_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis <mreis@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:00:05 by mreis             #+#    #+#             */
/*   Updated: 2024/01/15 19:50:54 by mreis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_len(int c)
{
	return (write (1, &c, 1));
}

int	putstr_len(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (putstr_len("(null)"));
	while (*str)
	{
		count += putchar_len((int)*str);
		str++;
	}
	return (count);
}

int	putptr_len(unsigned long ptr, int ptr_prefix)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (ptr == 0)
		return (putstr_len(PTR_NULL));
	else
	{
		if (ptr_prefix == 0)
		{
			count += write(1, "0x", 2);
			ptr_prefix = 1;
		}
		if (ptr >= 16)
		{
			count += putptr_len(ptr / 16, ptr_prefix);
			ptr %= 16;
		}
		if (ptr <= 16)
			count += write(1, &symbols[ptr], 1);
		return (count);
	}
	return (count);
}

int	put_nbr_u_hex_len(long n, int base, int is_uppercase)
{
	int		count;
	char	*symbols;

	count = 0;
	if (is_uppercase == 1)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (put_nbr_u_hex_len(-n, base, is_uppercase) + 1);
	}
	else if (n < base)
		return (putchar_len(symbols[n]));
	else
	{
		count += put_nbr_u_hex_len((n / base), base, is_uppercase);
		count += put_nbr_u_hex_len((n % base), base, is_uppercase);
		return (count);
	}
}
