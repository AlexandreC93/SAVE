/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:39:07 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/02/20 21:46:33 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "../../ft_lib/includes/ft_lib.h"

# define FLAGS "-0.# +"
# define TYPES "cspdiuxX%"
# define HEX_BASE "0123456789abcdef"
# define HEX_BASE_CAPS "0123456789ABCDEF"
# define DEC_BASE "0123456789"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		precision;
	int		width;
	int		plus;
	int		space;
	int		hash;
	int		dot;
	char	type;
	char	pad;
}				t_flags;

int		ft_printf(const char *format, ...);
// ft_printf_parse.c
int		ft_printf_parse_flags(const char *format, t_flags *flags);
int		ft_printf_parse_width(const char *format, t_flags *flags, va_list ap);
int		ft_printf_parse_prcsn(const char *format, t_flags *flags, va_list ap);
int		ft_printf_parse_type(const char *format, t_flags *flags);
int		*ft_printf_parse(const char *format, va_list ap);
//  ft printf.c
void	ft_printf_init_flags(t_flags *flags);
int		ft_printf_print_type(t_flags *flags, va_list ap);
void	ft_clean_flags(t_flags *flags);

int		ft_printf_print_c(t_flags *flags, va_list ap);
int		ft_printf_print_s(t_flags *flags, va_list ap);
int		ft_printf_print_p(t_flags *flags, va_list ap);
int		ft_printf_print_di(t_flags *flags, va_list ap);
int		ft_printf_print_u(t_flags *flags, va_list ap);
int		ft_printf_print_x(t_flags *flags, va_list ap);

// ft_printf_print_utils.c
int		ft_handle_right_justify(t_flags *flags, int len, char *sign, char *s);
int		ft_handle_left_justify(t_flags *flags, int len, char *sign, char *s);
void	ft_print_precision(t_flags *flags, int len, char *s);
int		ft_get_ast_precision(va_list ap, t_flags *flags);

#endif