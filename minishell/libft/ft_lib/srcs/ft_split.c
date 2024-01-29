/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:32:26 by dkeraudren        #+#    #+#             */
/*   Updated: 2023/02/27 22:14:03 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	ft_count_words(char const *s, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s[index])
	{
		if (s[index] != c
			&& (s[index + 1] == c
				|| s[index + 1] == '\0'))
			count++;
		index++;
	}
	return (count);
}

static void	fill_word(char *dest, char const *src, char c)
{
	int	index;

	index = 0;
	while (src[index] != c && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
}

static int	free_list(char **to_free)
{
	int	index;

	index = 0;
	while (to_free[index])
	{
		free(to_free[index]);
		index++;
	}
	return (0);
}

static int	fill_me(char const *s, char c, char **to_fill)
{
	int	index;
	int	jndex;
	int	word;

	index = 0;
	word = 0;
	while (s[index])
	{
		if (s[index] == c)
			index++;
		else
		{
			jndex = 0;
			while (s[index + jndex] != c && s[index + jndex])
				jndex++;
			to_fill[word] = (char *)malloc((jndex + 1) * sizeof(char));
			if (to_fill[word] == NULL)
				return (free_list(to_fill));
			fill_word(to_fill[word], s + index, c);
			index += jndex;
			word++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret_val;
	int		words;

	words = ft_count_words(s, c);
	ret_val = malloc((words + 1) * sizeof(char *));
	if (ret_val == NULL)
		return (0);
	ret_val[words] = NULL;
	if (!(fill_me(s, c, ret_val)))
	{
		free(ret_val);
		return (0);
	}
	return (ret_val);
}
