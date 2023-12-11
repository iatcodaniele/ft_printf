/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:22:54 by diatco            #+#    #+#             */
/*   Updated: 2023/12/11 11:19:40 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *str)
{
	int i = 0;

	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int ft_putnbr(long nb)
{
	int i = 0;

	if(nb <= -2147483648)
	{
		return ft_putstr("-2147483648");
	}
	if(nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		i++;
	}
	if(nb < 10)
		i += ft_putchar(nb + 48);
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putchar((nb % 10) + 48);
	}
	return i;
}

int ft_nhex_low(unsigned int nb)
{
	int i = 0;
	char *symb = "0123456789abcdef";

	if(nb >= 16)
	{
		i += ft_nhex_low(nb / 16);
		i += ft_nhex_low(nb % 16);
	}
	else
		i += ft_putchar(symb[nb]);

	return i;
}

int ft_nhex_up(unsigned int nb)
{
	int i = 0;
	char *symb = "0123456789ABCDEF";

	if(nb >= 16)
	{
		i += ft_nhex_up(nb / 16);
		i += ft_nhex_up(nb % 16);
	}
	else
		i += ft_putchar(symb[nb]);

	return i;
}

int ft_putptr(uintptr_t p, int index)
{
	char *symbols = "0123456789abcdef";
	int i = 0;

	if(!p && !index)
		return ft_putstr("(nil)");
	if(index == 0)
		i += ft_putstr("0x");

	if(p >= 16)
	{
		i += ft_putptr(p / 16, 1);
		i += ft_putptr(p % 16, 1);
	}
	else
		i += ft_putchar(symbols[p]);

	return i;
}
