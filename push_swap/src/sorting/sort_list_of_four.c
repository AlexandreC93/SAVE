/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:58:27 by lcadinot          #+#    #+#             */
/*   Updated: 2023/02/03 17:55:19 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	top_is_second(t_list *a, t_list *b)
{
	if ((a->first->nbr > a->first->next->nbr)
		&& (a->first->next->next->nbr < a->first->next->next->next->nbr))
	{
		sa(a);
		return ;
	}
	pb(a, b);
	sort_list_of_three(a, 0, 2, 3);
	pa(b, a);
	sa(a);
}

void	top_is_third(t_list *a)
{
	sa(a);
	sort_list_of_four(a);
}

t_list	*where_is_top(t_list *a, t_list *b)
{
	if (a->first->nbr == 0)
	{
		pb(a, b);
		sort_list_of_three(a, 1, 2, 3);
		pa(b, a);
	}
	else if (a->first->nbr == 1)
		top_is_second(a, b);
	else if (a->first->nbr == 2)
		top_is_third(a);
	else if (a->first->nbr == 3)
	{
		if ((a->first->next->nbr == 0) && (a->first->next->next->nbr == 1)
			&& (a->first->next->next->next->nbr == 2))
			ra(a);
		else
		{
			pb(a, b);
			sort_list_of_three(a, 0, 1, 2);
			pa(b, a);
			ra(a);
		}
	}
	return (b);
}

void	sort_list_of_four(t_list *a)
{
	t_list	*b;

	b = initialization(-1);
	if (b == NULL)
		return ;
	b = where_is_top(a, b);
	sup_all_list(b);
}
