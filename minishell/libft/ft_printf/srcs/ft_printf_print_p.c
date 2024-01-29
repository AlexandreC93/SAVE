/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:39:13 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/01/23 22:05:54 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_null_pointer(t_flags *flags)
{
	int	len;

	len = 5;
	if (flags->width > 5)
	{
		if (flags->minus)
		{
			ft_putstr("(nil)");
			while (len < flags->width)
				len += ft_putchar(' ');
		}
		else
		{
			while (len < flags->width)
				len += ft_putchar(' ');
			ft_putstr("(nil)");
		}
	}
	else
		ft_putstr("(nil)");
	return (len);
}

int	ft_put_pointer(t_flags *flags, unsigned long long pointer)
{
	char	*value;
	int		len;

	value = ft_itoa_base(pointer, HEX_BASE);
	len = ft_strlen(value) + 2;
	if (flags->minus == 1)
	{
		ft_putstr("0x");
		ft_putstr(value);
		while (len < flags->width)
			len += ft_putchar(' ');
	}
	else
	{
		while (len < flags->width)
			len += ft_putchar(' ');
		ft_putstr("0x");
		ft_putstr(value);
	}
	free(value);
	return (len);
}

int	ft_printf_print_p(t_flags *flags, va_list ap)
{
	unsigned long long	pointer;

	pointer = va_arg(ap, unsigned long long);
	if (!pointer)
		return (ft_handle_null_pointer(flags));
	return (ft_put_pointer(flags, pointer));
}
