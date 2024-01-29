/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:25:25 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/02/03 21:39:05 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_print_type(t_flags *flags, va_list ap)
{
	int	count;

	count = 0;
	if (flags->type == 'c')
		count += ft_printf_print_c(flags, ap);
	else if (flags->type == 's')
		count += ft_printf_print_s(flags, ap);
	else if (flags->type == 'p')
		count += ft_printf_print_p(flags, ap);
	else if (flags->type == 'd' || flags->type == 'i')
		count += ft_printf_print_di(flags, ap);
	else if (flags->type == 'u')
		count += ft_printf_print_u(flags, ap);
	else if (flags->type == 'x' || flags->type == 'X')
		count += ft_printf_print_x(flags, ap);
	else if (flags->type == '%')
		count += ft_putchar('%');
	return (count);
}

void	ft_printf_init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->dot = 0;
	flags->type = 0;
	flags->pad = ' ';
}

void	ft_clean_flags(t_flags *flags)
{
	if (flags->precision || flags->minus)
	{
		flags->zero = 0;
		flags->pad = ' ';
	}
	if (flags->zero)
	{
		if (flags->minus)
			flags->zero = 0;
		else
			flags->pad = '0';
	}
}

int	ft_print_loop(va_list ap, const char *str)
{
	int			i;
	int			count;
	int			*ret_handler;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret_handler = ft_printf_parse(str + i + 1, ap);
			i += ret_handler[0] + 1;
			count += ret_handler[1];
			free(ret_handler);
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			count;

	count = 0;
	va_start(ap, str);
	if (write(1, "", 0) == -1)
		return (-1);
	count = ft_print_loop(ap, str);
	va_end(ap);
	if (count < 0)
		return (-1);
	return (count);
}
