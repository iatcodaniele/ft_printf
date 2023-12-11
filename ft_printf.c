/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:15 by diatco            #+#    #+#             */
/*   Updated: 2023/12/11 11:22:00 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int print_format(const char type, va_list ap)
{
	int i = 0;

	if(type =='c')
		i = ft_putchar(va_arg(ap, int));
	if(type == 's')
		i = ft_putstr(va_arg(ap, char *));
	if(type == 'p')
		i = ft_putptr(va_arg(ap, uintptr_t), 0);
	if(type == 'd' || type == 'i')
		i = ft_putnbr(va_arg(ap, int));
	if(type == 'u')
		i = ft_putnbr(va_arg(ap, unsigned int));
	if (type == 'x')
		i = ft_nhex_low(va_arg(ap, unsigned int));
	if (type == 'X')
		i = ft_nhex_up(va_arg(ap, unsigned int));
	if(type == '%')
		i = ft_putchar('%');

	return i;
}

int ft_printf(const char *f, ...)
{
	va_list ap;
	int i = 0;
	int count = 0;
	va_start(ap, f);

	while(f[i])
	{
		if(f[i] == '%')
		{
			count += print_format(f[i+1], ap);
			i++;
		}
		else
			count += ft_putchar(f[i]);
		i++;
	}
	va_end(ap);
	return count;
}

int main()
{
    int n = 42;
    unsigned int u_n = 234;
    char c = 'a';
    char *str = "ciao sono Dani";
    void *ptr = &n;  // Puntatore a una variabile int
	ft_printf("Carattere: %c\n", c);
	ft_printf("Stringa: %s\n", str);
	printf("%d\n", printf("%p\n", ptr));
	ft_printf("%i\n", ft_printf("%p\n", ptr));
    ft_printf("Numero intero in base 10: %d\n", n);
	ft_printf("Numero intero: %i\n", n);
    ft_printf("Numero intero senza segno: %u\n", u_n);
	printf("%i\n", ft_printf("Numero intero senza segno: %u\n", u_n));
	printf("%i\n", printf("Numero intero senza segno: %u\n", u_n));
	printf("Numero intero senza segno: %u\n", u_n);
	ft_printf("Numero intero in esadecimale minuscolo: %x\n", n);
	ft_printf("Numero intero in esadecimale maiuscolo: %X\n", n);
	printf("Numero intero in esadecimale minuscolo: %x\n", n);
	printf("Numero intero in esadecimale maiuscolo: %X\n", n);
	ft_printf("percentuale: %%\n");
    return (0);
}
