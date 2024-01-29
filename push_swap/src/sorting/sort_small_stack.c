/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:58:41 by lcadinot          #+#    #+#             */
/*   Updated: 2023/01/26 17:58:42 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_small_stack(t_list *a)
{
	sort_list(a);
	if (a == NULL)
		return ;
	if (a->nb_elem == 2)
		sa(a);
	else if (a->nb_elem == 3)
		sort_list_of_three(a, 0, 1, 2);
	else if (a->nb_elem == 4)
		sort_list_of_four(a);
	else if (a->nb_elem == 5)
		sort_list_of_five(a);
}
