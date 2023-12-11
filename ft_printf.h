/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatco <diatco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:24:55 by diatco            #+#    #+#             */
/*   Updated: 2023/12/11 09:53:40 by diatco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int ft_printf(const char *f, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int ft_putnbr(long nb);
int ft_nhex_low(unsigned int nb);
int ft_nhex_up(unsigned int nb);
int ft_putptr(uintptr_t p, int index);



#endif
