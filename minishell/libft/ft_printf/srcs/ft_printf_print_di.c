/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_di.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:39:49 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/01/23 21:54:10 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_sign(t_flags *flags, int digit)
{
	if (digit < 0)
		return ("-");
	else if (flags->plus)
		return ("+");
	else if (flags->space)
		return (" ");
	return (0);
}

int	ft_put_digit(t_flags *flags, long long int digit)
{
	char	*s;
	char	*sign;
	int		len;
	int		to_print;

	len = 0;
	to_print = 0;
	if (digit < 0)
		s = ft_itoa_base(-digit, DEC_BASE);
	else
		s = ft_itoa_base(digit, DEC_BASE);
	sign = ft_get_sign(flags, digit);
	if (sign)
		len = 1;
	to_print += ft_strlen(s);
	if (to_print > flags->precision)
		flags->precision = to_print;
	if (flags->minus == 1)
		len = ft_handle_left_justify(flags, len, sign, s);
	else
		len = ft_handle_right_justify(flags, len, sign, s);
	free(s);
	return (len + flags->precision);
}

int	ft_printf_print_di(t_flags *flags, va_list ap)
{
	long long int	digit;
	int				len;

	len = 0;
	digit = va_arg(ap, int);
	if (digit == 0 && flags->dot && !flags->precision && !flags->width)
		return (0);
	else if (digit == 0 && flags->dot && !flags->precision && flags->width)
	{
		while (len < flags->width)
			len += ft_putchar(' ');
		return (len);
	}
	return (ft_put_digit(flags, digit));
}
