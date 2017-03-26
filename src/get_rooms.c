/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:05:30 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/26 17:05:34 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_create_room(char *name, char *m_flag)
{
	t_room			*new;
	static int		id;
	
	new = (t_room*)ft_memalloc(sizeof(t_room));
	new->name = name;
	*m_flag == 0x20 ? ft_exit("Info about room can't be after links info") : 0;
	new->flag = *m_flag;
	new->id = id++;
	*m_flag != 0 ? *m_flag = 0 : 0;
	return (new);
}

void	ft_check_room_info(char *line)
{
	char	flag;
	
	flag = 0;
	while (*line && *line != ' ')
	{
		if (ft_issign(*line))
		{
			if ((flag ^ 0x1) & 0x2 || ft_issign(*line) == 1 || flag & 0x1)
				flag |= 0x4;
			flag |= 0x1;
		}
		else if (ft_isdigit(*line))
			flag |= 0x2;
		else
			flag |= 0x4;
		++line;
	}
	if ((flag ^ 0x3) & 0x4 || !((flag ^ 0x5) & 0x2))
		ft_exit("Bad room info");
}

t_room	*ft_get_room(char *line, char *m_flag)
{
	char			*name;
	char			*t_line;
	uint			n;

	(n = (uint)ft_strclen(line, ' ')) == 0 ? ft_exit("Bad room name") : 0;
	name = ft_strndup(line, n);
	t_line = ft_strstr(line, " ") + 1;
	ft_check_room_info(t_line);
	t_line = ft_strstr(t_line, " ") + 1;
	ft_check_room_info(t_line);
	return (ft_create_room(name, m_flag));
}
