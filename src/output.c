/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:00:32 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 19:58:54 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_push_leming(t_uint path_id, t_uint leming,
	t_room **set, t_uint **node)
{
	t_room	*next;

	next = ft_find_room(path_id, 1, set);
	(*node)[path_id] = 1;
	next->lem = leming;
	ft_putstr("\033[0;34m");
	write(1, "L", 1);
	ft_putnbr(leming);
	write(1, "-", 1);
	ft_putstr(next->name);
	write(1, " ", 1);
	ft_putstr("\x1b[0m");
}

void	ft_push_all_once(t_room **set, t_uint lem)
{
	t_uint	i;
	char	*name;

	i = UINT_MAX;
	write(1, "\n", 1);
	while (set[++i])
	{
		if (set[i]->flag == END_ROOM)
		{
			name = set[i]->name;
			break ;
		}
	}
	while (lem)
	{
		ft_putstr("\033[1;36m");
		write(1, "L", 1);
		ft_putnbr(lem);
		write(1, "-", 1);
		ft_putstr(name);
		write(1, " ", 1);
		--lem;
	}
	write(1, "\n", 1);
	ft_putstr("\x1b[0m");
}

void	ft_polzi_suqa(t_room *curr, t_room *prev)
{
	if (prev->lem == 0)
		return ;
	ft_putstr("\033[0;34m");
	write(1, "L", 1);
	ft_putnbr(prev->lem);
	write(1, "-", 1);
	ft_putstr(curr->name);
	write(1, " ", 1);
	curr->lem = prev->lem;
	prev->lem = 0;
	ft_putstr("\x1b[0m");
}

void	ft_polzi_v_konec(t_room *prev, t_room **set)
{
	t_uint			i;
	char			*name;
	static t_uint	count;

	if (prev->lem == 0)
		return ;
	i = UINT_MAX;
	while (set[++i])
	{
		if (set[i]->flag == END_ROOM)
		{
			name = set[i]->name;
			break ;
		}
	}
	ft_putstr("\033[0;35m");
	write(1, "L", 1);
	ft_putnbr(prev->lem);
	write(1, "-", 1);
	ft_putstr(name);
	write(1, " ", 1);
	prev->lem = 0;
	ft_putstr("\x1b[0m");
	++count;
}

void	ft_push_all_leming_ahead(t_uint path_id, t_uint path_node,
		t_room *prev, t_room **rooms)
{
	t_room *current;

	current = ft_find_room(path_id, path_node, rooms);
	if (current == NULL)
		return (ft_polzi_v_konec(prev, rooms));
	else if (current->lem == 0)
	{
		if (path_node == 1)
			return ;
		return (ft_polzi_suqa(current, prev));
	}
	else
		ft_push_all_leming_ahead(path_id, path_node + 1, current, rooms);
	if (current->lem == 0)
	{
		if (path_node == 1)
			return ;
		return (ft_polzi_suqa(current, prev));
	}
}
