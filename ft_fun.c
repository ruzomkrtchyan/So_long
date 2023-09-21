/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:19:51 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/02/09 14:31:13 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s(char *a)
{
	int	i;

	i = 0;
	if (a == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (a[i])
	{
		write(1, &a[i], 1);
		i++;
	}
	return (i);
}

void	ft_putch(char c)
{
	write(1, &c, 1);
}

int	ft_len(int nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
		count = 1;
	while (nb)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	tmp;

	tmp = nb;
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putch('-');
		nb = -nb;
		ft_putnbr(nb);
	}	
	else if (nb >= 0 && nb <= 9)
		ft_putch(nb + '0');
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (ft_len(tmp));
}

int	ft_u(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 0 && nb <= 9)
		len += ft_putchar(nb + '0');
	else if (nb > 9)
	{
		len += ft_u(nb / 10);
		len += ft_u(nb % 10);
	}
	return (len);
}
