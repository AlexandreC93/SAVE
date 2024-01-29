/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:19:59 by lcadinot          #+#    #+#             */
/*   Updated: 2023/09/23 17:52:47 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_var(t_var *var, char **av)
{
	var->num_philo = ft_atol(av[1]);
	var->ttd = ft_atol(av[2]);
	var->tte = ft_atol(av[3]);
	var->tts = ft_atol(av[4]);
	var->dead = 0;
	var->finish = 0;
	if (av[5] != NULL)
		var->nmeals = ft_atol(av[5]);
	else
		var->nmeals = -1;
	var->threads = malloc(sizeof(pthread_t) * var->num_philo);
	var->philos = malloc(sizeof(t_philo) * var->num_philo);
	var->forks = malloc(sizeof(int) * var->num_philo);
}

void	start_threads(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->num_philo)
	{
		if (pthread_create(&var->threads[i], NULL, &routine, &var->philos[i])
			!= 0)
		{
			pthread_mutex_lock(&var->philos->mutex->end);
			var->dead = 1;
			pthread_mutex_lock(&var->philos->mutex->print);
			write(2, "pthread_create error\n", 21);
			pthread_mutex_unlock(&var->philos->mutex->print);
			pthread_mutex_unlock(&var->philos->mutex->end);
		}
		i++;
	}
}

void	init_philos(t_mutex *mut, t_var *var)
{
	int	i;

	i = 0;
	while (i < var->num_philo)
	{
		var->philos[i].n = i + 1;
		var->philos[i].meals = 0;
		var->philos[i].var = var;
		var->philos[i].mutex = mut;
		var->philos[i].last_meal = get_time();
		var->forks[i] = 1;
		i++;
	}
}

int	init_mutex(t_var *var)
{
	int	i;

	i = 0;
	var->philos->mutex->forks = malloc(
			sizeof(pthread_mutex_t) * var->num_philo);
	if (var->philos->mutex->forks == NULL)
		return (-1);
	while (i < var->num_philo)
	{
		if (pthread_mutex_init(&var->philos->mutex->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&var->philos->mutex->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&var->philos->mutex->end, NULL) != 0)
		return (1);
	return (0);
}
