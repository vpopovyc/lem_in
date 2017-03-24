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

t_room	*ft_create_room(char *name)
{
	t_room			*new;
	static int		id;

	new = (t_room*)ft_memalloc(sizeof(t_room));
	new->name = name;
	new->flag = 0;
	new->id = id++;
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
} /* ended here [3] */

void	ft_get_room(char *line, char *flag, char *color)
{
	char	*name;
	char	*tmp;
	char	fl;

	fl = 0;
	name = ft_strndup(line, ft_strclen(line, ' '));
	tmp = ft_strstr(line, " ") + 1;

	/* ended here [2] */
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
}

void	ft_parse_rooms(t_root *root, int fd, char *sv)
{
	char	*line;
	char	flag;
/*	t_room	*node; */

	color = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == '#')
			ft_flag_distribution(&flag, line, &color);
		else if (ft_strstr(ft_strstr(line, " ") + 1, " "))
			ft_get_room(line, flag, color);
		/* ended here [1] */
	}
}

void	ft_get_input(t_data *input)
{
	t_root	root;

	input->leming_n = ft_get_number_of_lemings(&input->input, input->fd);
	ft_parse_rooms(&root, input->fd, input->input);
}
