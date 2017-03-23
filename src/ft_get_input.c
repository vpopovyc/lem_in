/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:11:09 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/21 21:11:13 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_get_number_of_lemings(char **sv, int fd)
{
	int		n;
	char	*line;

	get_next_line(fd, &line);
	n = ft_atoi(line);
	n <= 0 ? ft_exit("Number of lemings is equal 0 or lower") : 0;
	*sv = ft_strnfjoin(*sv, line, ft_strlen(line));
	ft_strdel(&line);
	return (n);
}

t_room	*ft_create_room(char *name, char *color, short x, short y)
{
	t_room *new;

	x < 0 || y < 0 ? ft_exit("Negative values for room cords") : 0;
	new = (t_room*)ft_memalloc(sizeof(t_room));
	new->name = name;
	new->color = color;
	new->flag = 0;
	new->x = x;
	new->y = y;
	return (new);
}

void	ft_get_room(char *line, char *flag, char *color)
{
	char	**sv;
	short	x;
	short	y;

	sv = ft_strsplit(line, ' ');
	name = ft_strndup(line,)
}

void	ft_flag_distribution(char *flag, char *line, char **color)
{
	if (ft_strstr(line, "##start"))
	{
		if (*flag == 1 || *flag == 2)
			ft_exit("Wrong general instructions");
		*flag = 1;
	}
	else if (ft_strstr(line, "##end"))
	{
		if (*flag == 1 || *flag == 2)
			ft_exit("Wrong general instructions");
		*flag = 2;
	}
	else if (ft_strstr(line, "##room_color"))
		*color = ft_strdup(ft_strstr(line, " ") + 1);
}

void	ft_parse_rooms(t_root *root, int fd, char *sv)
{
	char	*line;
	char	*color;
	char	flag;
/*	t_room	*node; */

	color = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == '#')
			ft_flag_distribution(&flag, line, &color);
		else if (ft_strstr(ft_strstr(line, " ") + 1, " "))
			ft_get_room(line, flag, color);
		
	}
}

void	ft_get_input(t_data *input)
{
	t_root	root;

	input->leming_n = ft_get_number_of_lemings(&input->input, input->fd);
	ft_parse_rooms(&root, input->fd, input->input);
}
