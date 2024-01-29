/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:40:40 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/01/25 22:01:37 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_precision(t_flags *flags, int len, char *s)
{
	int	zero_count;

	if (flags->precision > len)
	{
		zero_count = 0;
		while (zero_count < flags->precision - len)
		{
			ft_putchar('0');
			zero_count++;
		}
	}
	ft_putstr(s);
}

int	ft_handle_left_justify(t_flags *flags, int len, char *sign, char *s)
{
	if (sign)
		ft_putstr(sign);
	ft_print_precision(flags, ft_strlen(s), s);
	while (len < flags->width - flags->precision)
	{
		ft_putchar(flags->pad);
		len++;
	}
	return (len);
}

int	ft_handle_right_justify(t_flags *flags, int len, char *sign, char *s)
{
	if (sign && flags->pad == '0')
		ft_putstr(sign);
	while (len < flags->width - flags->precision)
	{
		ft_putchar(flags->pad);
		len++;
	}
	if (sign && flags->pad != '0')
		ft_putstr(sign);
	ft_print_precision(flags, ft_strlen(s), s);
	return (len);
}

int	ft_get_ast_precision(va_list ap, t_flags *flags)
{
	int	precision;

	precision = va_arg(ap, int);
	if (precision < 0)
	{
		flags->dot = 0;
		precision = 0;
	}
	return (precision);
}
