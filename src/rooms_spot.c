/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_spot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:32:35 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 20:02:40 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_mark_end_room(t_room **room)
{
	register t_uint	i;

	i = UINT_MAX;
	while (room[++i])
	{
		if (room[i]->flag == END_ROOM)
		{
			room[i]->path_id = UINT_MAX;
			room[i]->path_node = UINT_MAX;
			break ;
		}
	}
}

static void		ft_mark_room(char **node, t_uint size,
	t_room **room, t_uint mark)
{
	t_uint	i;
	t_uint	id;

	i = UINT_MAX;
	if (size == STRAIGHT_WAY)
		ft_mark_end_room(room);
	else
	{
		size -= 1;
		while (++i < size)
		{
			id = ft_atoi(node[i]);
			room[id]->path_id = mark;
			room[id]->path_node = i + 1;
		}
	}
	ft_ppdel(&node);
}

t_uint			ft_spot_rooms(t_path **path, t_room **room)
{
	t_uint	i;

	i = UINT_MAX;
	while (path[++i])
		ft_mark_room(ft_strsplit(path[i]->path, ' '),
				path[i]->lenght, room, i + 1);
	return (i);
}
