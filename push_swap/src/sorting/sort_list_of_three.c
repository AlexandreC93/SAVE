/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:58:33 by lcadinot          #+#    #+#             */
/*   Updated: 2023/01/26 17:58:34 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	top_is_greater(t_list *a, int smallest)
{
	if (a->first->next->nbr == smallest)
		ra(a);
	else
	{
		ra(a);
		sa(a);
	}
}

void	top_is_median(t_list *a, int smallest)
{
	if (a->first->next->nbr == smallest)
		sa(a);
	else
		rra(a);
}

void	top_is_smallest(t_list *a)
{
	sa(a);
	ra(a);
}

void	sort_list_of_three(t_list *a, int smallest, int median, int greatest)
{
	if (a->first->nbr == greatest)
		top_is_greater(a, smallest);
	else if (a->first->nbr == median)
		top_is_median(a, smallest);
	else if (a->first->nbr == smallest)
		top_is_smallest(a);
}
