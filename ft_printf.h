/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:22:41 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/02/09 14:29:20 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_s(char *a);
int	ft_p(unsigned long str, char a);
int	ft_putnbr(int nb);
int	ft_u(unsigned int nb);
int	ft_hex(unsigned long num, char a);
int	ft_printf(const char *a, ...);
int	ft_putchar(int c);

#endif
