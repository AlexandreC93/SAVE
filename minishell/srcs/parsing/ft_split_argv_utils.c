/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_argv_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:21:30 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 12:24:20 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_worcount_2(int *i, int *count, const char *str)
{
	char	quote;

	quote = '\0';
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		(*count)++;
		quote = str[*i];
		(*i)++;
		while (str[*i] && (str[*i] != quote))
			(*i)++;
		if (str[*i] && str[*i] == quote)
			quote = '\0';
		(*i)++;
	}
	else if (str[*i] != '|')
	{
		(*count)++;
		while (str[*i] && !(ft_isspace(str[*i])) && str[*i] != '|')
			(*i)++;
	}
	if (str[*i] == '|')
	{
		(*count)++;
		(*i)++;
	}
}

int	ft_wordcount(const char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
			ft_worcount_2(&i, &count, str);
	}
	return (count);
}

static int	ft_wordlen2(const char *str)
{
	char	quote;
	int		len;

	quote = *str;
	len = 1;
	str++;
	while (*str && *str != quote)
	{
		str++;
		len++;
	}
	if (*str == quote)
	{
		quote = '\0';
		len++;
		str++;
	}
	return (len);
}

int	ft_wordlen(const char *str)
{
	int		len;

	len = 0;
	while (ft_isspace(*str))
		str++;
	while (*str && !(ft_isspace(*str)))
	{
		if (*str == '\'' || *str == '\"')
			return (ft_wordlen2(str));
		else if (*str == '|')
		{
			if (len == 0)
				return (1);
			else
				return (len);
		}
		else
		{
			str++;
			len++;
		}
	}
	return (len);
}
