/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:42:52 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/14 11:48:02 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_convert(char c, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += ft_putnbr_base(va_arg(ap, int), "0123456789");
	if (c == 'c')
		len += ft_putchar(va_arg(ap, int));
	if (c == 's')
		len += ft_putstr(va_arg(ap, char *));
	if (c == 'x')
		len += ft_putnbr_base_unsigned(va_arg(ap, unsigned int),
				"0123456789abcdef");
	if (c == 'X')
		len += ft_putnbr_base_unsigned(va_arg(ap, unsigned int),
				"0123456789ABCDEF");
	if (c == 'u')
		len += ft_putnbr_base_unsigned(va_arg(ap, unsigned int), "0123456789");
	if (c == 'p')
		len += ft_putnbr_ptr(va_arg(ap, uintptr_t));
	if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				i;
	int				len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		if (str[i] == '%')
		{
			i++;
			len += ft_convert(str[i], ap);
		}
		i++;
	}
	return (len);
}
