/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:28:18 by lcadinot          #+#    #+#             */
/*   Updated: 2023/09/23 17:52:37 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end(t_philo *p)
{
	pthread_mutex_lock(&p->mutex->end);
	if (p->var->dead == 1 || p->var->finish == p->var->num_philo)
	{
		pthread_mutex_unlock(&p->mutex->end);
		return (1);
	}
	pthread_mutex_unlock(&p->mutex->end);
	return (0);
}

void	join_threads(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->num_philo)
	{
		if (pthread_join(var->threads[i], NULL) != 0)
			pthread_detach(var->threads[i]);
		i++;
	}
}

void	destroy_and_free(t_var *var)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&var->philos->mutex->print);
	pthread_mutex_destroy(&var->philos->mutex->end);
	while (i < var->num_philo)
	{
		pthread_mutex_destroy(&var->philos->mutex->forks[i]);
		i++;
	}
	free(var->philos->mutex->forks);
	free(var->philos);
	free(var->threads);
	free(var->forks);
}

void	check_death(t_philo *p)
{
	long long int	t;

	t = get_time();
	pthread_mutex_lock(&p->mutex->end);
	if (t - p->last_meal > p->var->ttd && p->var->dead == 0)
	{
		p->var->dead = 1;
		pthread_mutex_lock(&p->mutex->print);
		printf("%lld #%u died\n", t - p->var->start, p->n);
		pthread_mutex_unlock(&p->mutex->print);
	}
	pthread_mutex_unlock(&p->mutex->end);
}
