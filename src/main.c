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

int main(int ac, char **av)
{
	t_acmx	mx;
	t_data	input;
	char	*line;

	ft_get_input(&input);
	ft_create_mx(&mx);
	get_next_line(0, &line);
	printf("%s\n", line);
	return 0;
}
