/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_data_addition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:08:49 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 20:12:52 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_uint				ft_size_of_pp(char **sv)
{
	register t_uint	n;

	n = 0;
	while (sv && sv[n])
		++n;
	return (n);
}

char				*ft_stack_to_string(t_stack stack)
{
	int		n;
	char	*sv;
	char	*forfree;
	char	*t_sv;

	sv = ft_strnew(0);
	n = stack_size(&stack);
	while (n)
	{
		forfree = sv;
		t_sv = ft_itoa(stack.bot_node->id);
		sv = ft_strjoin(sv, t_sv);
		stack.bot_node = stack.bot_node->top_elem;
		if (n > 1)
			sv = ft_strnfjoin(sv, " ", 1);
		free(t_sv);
		free(forfree);
		--n;
	}
	return (sv);
}
