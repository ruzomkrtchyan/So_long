/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:19:15 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/04 14:11:16 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_tokos(va_list ap, char a)
{
	int	len;

	len = 0;
	if (a == 'c')
		len += ft_putchar(va_arg(ap, int));
	if (a == 's')
		len += ft_s(va_arg(ap, char *));
	if (a == 'p')
		len += ft_p(va_arg(ap, unsigned long), 'x');
	if (a == 'd' || a == 'i')
		len += ft_putnbr(va_arg(ap, int));
	if (a == 'u')
		len += ft_u(va_arg(ap, unsigned int));
	if (a == 'x' || a == 'X')
		len += ft_hex(va_arg(ap, unsigned int), a);
	if (a == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *a, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, a);
	while (a[i])
	{
		if (a[i] == '%')
		{
			len += ft_tokos(ap, a[i + 1]);
			i++;
		}
		else
			len += ft_putchar(a[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
