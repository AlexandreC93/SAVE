/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:14:55 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/01/24 18:14:53 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_parse_flags(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	while (format[i] == '-' || format[i] == '0'
		|| format[i] == '#' || format[i] == ' '
		|| format[i] == '+')
	{
		if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		else if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		i++;
	}
	return (i);
}

int	ft_printf_parse_width(const char *format, t_flags *flags, va_list ap)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[i]))
	{
		flags->width = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	else if (format[i] == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
		i++;
	}
	return (i);
}

int	ft_printf_parse_prcsn(const char *format, t_flags *flags, va_list ap)
{
	int	i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		flags->dot = 1;
		if (format[i] == '*')
		{
			flags->precision = ft_get_ast_precision(ap, flags);
			i++;
		}
		else if (ft_isdigit(format[i]))
		{
			flags->precision = ft_atoi(&format[i]);
			while (ft_isdigit(format[i]))
				i++;
		}
		else
			flags->precision = 0;
	}
	return (i);
}

int	ft_printf_parse_type(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	if (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
		|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
		|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
	{
		flags->type = format[i];
		i++;
	}
	return (i);
}

int	*ft_printf_parse(const char *format, va_list ap)
{
	t_flags	flags;
	int		i;
	int		*ret;

	i = 0;
	ret = (int *)malloc(sizeof(int) * 2);
	if (!ret)
		return (NULL);
	ft_printf_init_flags(&flags);
	i += ft_printf_parse_flags(format + i, &flags);
	i += ft_printf_parse_width(format + i, &flags, ap);
	i += ft_printf_parse_prcsn(format + i, &flags, ap);
	i += ft_printf_parse_type(format + i, &flags);
	ft_clean_flags(&flags);
	ret[0] = i;
	ret[1] = ft_printf_print_type(&flags, ap);
	return (ret);
}
