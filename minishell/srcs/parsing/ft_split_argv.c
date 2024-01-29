/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:20:25 by lcadinot          #+#    #+#             */
/*   Updated: 2023/10/30 20:07:36 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_split_arg2(const char **str, char **arr, int *i)
{
	char	quote;
	int		j;

	quote = '\0';
	j = 0;
	arr[*i] = ft_calloc(ft_wordlen(str[0]) + 1, sizeof(char));
	if (!arr[*i])
		return (ft_free_2d_list(arr), ERROR);
	while (*str[0] && ft_isspace(*str[0]))
		str[0]++;
	if (*str[0] == '\"' || *str[0] == '\'')
	{
		quote = *str[0];
		arr[*i][j++] = *str[0]++;
		while (*str[0] && *str[0] != quote)
			arr[*i][j++] = *str[0]++;
		arr[(*i)++][j] = *str[0]++;
		return (1);
	}
	while ((*str[0] && (!ft_isspace(*str[0]))) && *str[0] != '|')
		arr[*i][j++] = *str[0]++;
	return (0);
}

char	**ft_split_argv(const char *str)
{
	int		i;
	int		words;
	char	**arr;

	i = 0;
	words = ft_wordcount(str);
	arr = ft_calloc(words + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < words)
	{
		if (ft_split_arg2(&str, arr, &i) == 1)
			continue ;
		if (*str == '|' && arr[i][0] == '\0')
		{
			arr[i++][0] = *str++;
			continue ;
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
