/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:11:09 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 19:51:08 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_get_number_of_lemings(char **sv)
{
	int		n;
	char	*line;

	get_next_line(0, &line);
	n = ft_atoi(line);
	n <= 0 ? ft_exit("Number of lemings is equal 0 or lower") : 0;
	*sv = ft_strnfjoin(*sv, line, ft_strlen(line));
	ft_strdel(&line);
	return (n);
}

static void		ft_flag_distribution(char *flag, char *line)
{
	if (ft_strstr(line, "##start"))
	{
		if (*flag == 0x1 || *flag == 0x2 || *flag == 0x20)
			ft_exit("Wrong general instructions");
		*flag = 0x1;
	}
	else if (ft_strstr(line, "##end"))
	{
		if (*flag == 0x1 || *flag == 0x2 || *flag == 0x20)
			ft_exit("Wrong general instructions");
		*flag = 0x2;
	}
}

static void		ft_line_managment(char *line, char **sv)
{
	*sv = ft_strnfjoin(*sv, "\n", 1);
	*sv = ft_strnfjoin(*sv, line, ft_strlen(line));
	ft_strdel(&line);
}

static void		ft_parse(t_root *root, t_acmx *mx, char **sv)
{
	char	*line;
	char	flag;
	char	*t_line;
	t_room	*node;

	flag = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (*line == '#')
			ft_flag_distribution(&flag, line);
		else if ((t_line = ft_strstr(line, " ")))
		{
			if (ft_strstr(t_line + 1, " "))
			{
				node = ft_get_room(line, &flag);
				ft_bind_to_root(root, &node);
			}
		}
		else if (ft_strstr(line, "-"))
			ft_get_edges(root, mx, line, &flag);
		else
			ft_exit("Wrong order of input on stdin");
		ft_line_managment(line, sv);
	}
}

void			ft_get_input(t_data *input, t_acmx *mx, t_root *root)
{
	input->leming_n = ft_get_number_of_lemings(&input->input);
	root->n_ofbinds = 0;
	root->n_ofpaths = 0;
	root->binds = NULL;
	ft_parse(root, mx, &input->input);
	ft_validate_names_to_instructions(root->binds, (int)root->n_ofbinds);
}
