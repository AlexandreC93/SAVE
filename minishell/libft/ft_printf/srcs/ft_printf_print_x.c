/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:41:26 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/01/25 21:22:17 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x(t_flags *flags, long long int x)
{
	char	*s;
	int		len;
	int		to_print;

	len = 0;
	to_print = 0;
	if (flags->type == 'X')
		s = ft_itoa_base(x, HEX_BASE_CAPS);
	else
		s = ft_itoa_base(x, HEX_BASE);
	if (flags->hash && x != 0 && flags->type == 'X')
		len += ft_putstr("0X");
	else if (flags->hash && x != 0 && flags->type == 'x')
		len += ft_putstr("0x");
	to_print += ft_strlen(s);
	if (to_print > flags->precision)
		flags->precision = to_print;
	if (flags->minus == 1)
		len = ft_handle_left_justify(flags, len, 0, s);
	else
		len = ft_handle_right_justify(flags, len, 0, s);
	free(s);
	return (len + flags->precision);
}

int	ft_printf_print_x(t_flags *flags, va_list ap)
{
	unsigned int	x;
	int				len;

	len = 0;
	x = va_arg(ap, unsigned int);
	if (x == 0 && flags->dot && !flags->precision && !flags->width)
		return (0);
	else if (x == 0 && flags->dot && !flags->precision && flags->width)
	{
		while (len < flags->width)
			len += ft_putchar(' ');
		return (len);
	}
	return (ft_put_x(flags, x));
}
