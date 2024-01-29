/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:50:14 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 15:04:34 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_fork_status(int status)
{
	int	ret;

	ret = 0;
	if (WIFEXITED(status))
		ret = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		ret = WTERMSIG(status) + 128;
		if (ret == 130)
			ft_putstr("\n");
		if (ret == 131)
			ft_putstr_fd("Quit (core dumped)\n", 2);
		if (ret == 139)
			ft_putstr_fd("Segmentation fault (core dumped)\n", 2);
	}
	return (ret);
}

int	wait_last_cmd(t_list	*pids)
{
	int		status;
	t_list	*tmp;

	status = 0;
	if (!pids)
		return (0);
	tmp = pids;
	while (tmp)
	{
		waitpid(*(int *)tmp->content, &status, 0);
		tmp = tmp->next;
	}
	return (get_fork_status(status));
}
