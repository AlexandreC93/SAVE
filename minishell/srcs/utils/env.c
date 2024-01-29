/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:13:35 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 17:10:52 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*add_env(t_env	*envars, char *key, char *value)
{
	t_env	*envar;

	envar = malloc(sizeof(t_env));
	if (!envar)
		return (NULL);
	envar->key = ft_strdup(key);
	if (value != NULL)
		envar->value = ft_strdup(value);
	else
		envar->value = NULL;
	if (envars != NULL)
		envar->next = envars;
	else
		envar->next = NULL;
	return (envar);
}

t_env	*remove_env(t_env	*envars, char *key)
{
	t_env	*previous;
	t_env	*first;

	previous = NULL;
	first = envars;
	while (envars)
	{
		if (ft_strncmp(key, envars->key,
				ft_get_max(ft_strlen(key), ft_strlen(envars->key))) == 0)
		{
			if (previous != NULL)
				previous->next = envars->next;
			else
				first = envars->next;
			free_t_env(envars);
			break ;
		}
		previous = envars;
		envars = envars->next;
	}
	return (first);
}

t_env	*edit_env(t_env	*envars, char *key, char *value)
{
	t_env	*tmp;

	tmp = remove_env(envars, key);
	return (add_env(tmp, key, value));
}

char	**build_env(t_env	*envars)
{
	int		i;
	char	**env;
	t_env	*tmp;
	char	*tmp_var;

	i = 0;
	tmp = envars;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	env = ft_calloc(i + 1, sizeof(char *));
	if (!env)
		return (NULL);
	i = 0;
	while (envars)
	{
		tmp_var = ft_strjoin(envars->key, "=");
		env[i] = ft_strjoin(tmp_var, envars->value);
		free(tmp_var);
		envars = envars->next;
		i++;
	}
	return (env);
}

char	*get_envar(t_env *envars, char *key)
{
	if (!key)
		return (NULL);
	if (ft_strcmp(key, "?") == 0)
		return (ft_itoa(g_status));
	while (envars)
	{
		if (!envars->key)
		{
			envars = envars->next;
			continue ;
		}
		if (ft_strncmp(key, envars->key,
				ft_get_max(ft_strlen(key), ft_strlen(envars->key))) == 0)
			return (envars->value);
		envars = envars->next;
	}
	return ("");
}
