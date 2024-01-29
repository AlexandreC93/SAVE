/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:58:45 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 21:29:55 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_envar(int *i, char *line, char **res, t_env *envars)
{
	int		j;
	char	*envvar_key;
	char	*envvar_value;
	char	*tmp;

	(*i)++;
	j = 0;
	while (ft_isalnum(line[*i + j]))
		j++;
	envvar_key = ft_calloc(j + 1, sizeof(char));
	while (j > 0)
	{
		envvar_key[j - 1] = line[*i + j - 1];
		j--;
	}
	envvar_value = get_envar(envars, envvar_key);
	tmp = ft_strjoin(*res, envvar_value);
	free(*res);
	*res = tmp;
	(*i) += ft_strlen(envvar_key) - 1;
	if (ft_strcmp(envvar_key, "?") == 0)
		free(envvar_value);
	free(envvar_key);
}

static int	skip_between_quotes(char **line)
{
	int	i;

	i = 0;
	if (line[0][0] == '\"' || line[0][0] == '\'')
	{
		(line[0])++;
		while (line[0][i])
			i++;
		line[0][i - 1] = '\0';
		i = 0;
	}
	return (i);
}

static void	add_substr(char **res, char *line, int i)
{
	char	*tmp;
	char	*sub;

	sub = ft_substr(line, i, 1);
	tmp = ft_strjoin(*res, sub);
	free(*res);
	free(sub);
	*res = tmp;
}

char	*ft_expand(char *line, t_env *envars)
{
	char	*res;
	int		expand;
	int		i;

	i = 0;
	expand = 1;
	if (line[0] == '\'')
		expand = 0;
	res = ft_calloc(2, sizeof(char));
	if (!res)
		return (NULL);
	i = skip_between_quotes(&line);
	while (line[i])
	{
		if (line[i] == '$' && expand)
			expand_envar(&i, line, &res, envars);
		else
			add_substr(&res, line, i);
		if (!line[i])
			break ;
		i++;
	}
	return (res);
}
