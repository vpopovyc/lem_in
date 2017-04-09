/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:18:41 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/21 18:18:45 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_exit(char *sv)
{
	ft_putendl(sv);
	exit(-1);
}

void	ft_tdata_init(t_data *new, char **av)
{
	new->fd = open(*(++av), O_RDWR);
	new->input = ft_strnew(0);
}

int main(int ac, char **av)
{
	t_acmx	mx;
	t_data	input;
	t_root	root;

	ft_tdata_init(&input, av);
	ft_get_input(&input, &mx, &root);
	ft_find_connection_component(mx.acmx, root.n_ofbinds);
	ft_path_traversal(&root, mx.acmx, root.n_ofbinds);
	return 0;
}
