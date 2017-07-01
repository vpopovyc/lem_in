/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:04:35 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/14 20:37:45 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/stack.h"

void	stack_delete(t_stack *stack)
{
	t_uint	n;

	n = stack_size(stack);
	while (n)
	{
		pop(stack);
		--n;
	}
	stack_init(stack);
}

void	print_stack_id(t_stack stack)
{
	int	n;

	n = stack_size(&stack);
	while (n)
	{
		ft_printf("%d ", stack.top_node->id);
		stack.top_node = stack.top_node->bot_elem;
		--n;
	}
	ft_printf("\n");
}

void	rev_print_stack_id(t_stack stack)
{
	int	n;

	n = stack_size(&stack);
	while (n)
	{
		ft_printf("%d ", stack.bot_node->id);
		stack.bot_node = stack.bot_node->top_elem;
		--n;
	}
	ft_printf("\n");
}
