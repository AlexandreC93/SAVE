/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:37:20 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/01/24 20:01:36 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_print_c(t_flags *flags, va_list ap)
{
	char	c;
	int		len;

	c = va_arg(ap, int);
	len = 0;
	if (flags->minus == 1)
	{
		len += ft_putchar(c);
		while (len < flags->width)
			len += ft_putchar(' ');
	}
	else
	{
		len = 1;
		while (len < flags->width)
			len += ft_putchar(' ');
		ft_putchar(c);
	}
	return (len);
}
