/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:58:18 by lcadinot          #+#    #+#             */
/*   Updated: 2023/01/26 17:58:19 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pb_zero(t_list *a, t_list *b)
{
	if (a->first->nbr == 0)
		pb(a, b);
	else if (a->first->next->nbr == 0)
	{
		sa(a);
		pb(a, b);
	}
	else if (a->first->next->next->nbr == 0)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (a->first->next->next->next->nbr == 0)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (a->first->next->next->next->next->nbr == 0)
	{
		rra(a);
		pb(a, b);
	}
}

void	pb_one(t_list *a, t_list *b)
{
	if (a->first->nbr == 1)
		pb(a, b);
	else if (a->first->next->nbr == 1)
	{
		sa(a);
		pb(a, b);
	}
	else if (a->first->next->next->nbr == 1)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (a->first->next->next->next->nbr)
	{
		rra(a);
		pb(a, b);
	}
}

void	sort_list_of_five(t_list *a)
{
	t_list	*b;

	b = initialization(-1);
	if (b == NULL)
		return ;
	pb_zero(a, b);
	pb_one(a, b);
	if (a_is_sorted(a))
	{
		pa(b, a);
		pa(b, a);
		sup_all_list(b);
		return ;
	}
	sort_list_of_three(a, 2, 3, 4);
	pa(b, a);
	pa(b, a);
	sup_all_list(b);
}
