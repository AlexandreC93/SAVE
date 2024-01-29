/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:38:28 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/01/24 18:02:46 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrl(char *s, int len)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < len)
		ft_putchar(s[i++]);
}

int	ft_get_len(t_flags *flags, char *s)
{
	int	len;

	len = ft_strlen(s);
	if (flags->dot)
	{
		if (flags->precision > 0)
		{
			if (flags->precision < len)
				len = flags->precision;
		}
		else
			len = 0;
	}
	return (len);
}

char	*ft_get_str(t_flags *flags, va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		if (flags->dot && flags->precision < 6)
			return ("");
		else
			return ("(null)");
	}
	return (s);
}

int	ft_printf_print_s(t_flags *flags, va_list ap)
{
	char	*s;
	int		len;
	int		retval;

	retval = 0;
	len = 0;
	s = ft_get_str(flags, ap);
	len = ft_get_len(flags, s);
	if (flags->minus == 1)
	{
		ft_putstrl(s, len);
		while (retval + len < flags->width)
			retval += ft_putchar(' ');
	}
	else
	{
		while (retval + len < flags->width)
			retval += ft_putchar(' ');
		ft_putstrl(s, len);
	}
	return (retval + len);
}
