/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:37:04 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/02/10 19:12:18 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_count(unsigned long num)
{
	int	count;

	count = 0;
	while (num)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

void	ft_hh(unsigned long num, char a)
{
	if (num <= 9)
		ft_putc(num + '0');
	else if (num >= 10 && num <= 15)
	{
		if (a == 'X')
			ft_putc(num + 55);
		else if (a == 'x')
			ft_putc(num + 87);
	}
	else
	{
		ft_hh(num / 16, a);
		ft_hh(num % 16, a);
	}
}

int	ft_hex(unsigned long num, char a)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_hh(num, a);
	return (ft_count(num));
}

int	ft_p(unsigned long str, char a)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (str == 0)
		len += (write(1, "0", 1));
	else
	{
		ft_hex(str, a);
		len += ft_count(str);
	}
	return (len);
}
