/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:47:30 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/14 20:35:33 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/stack.h"

void	enqueue(t_stack *stack, int id)
{
	t_stack_elem *new_elem;

	new_elem = (t_stack_elem*)malloc(sizeof(t_stack_elem));
	new_elem->id = id;
	new_elem->top_elem = NULL;
	new_elem->bot_elem = NULL;
	if (stack->top_node == NULL)
	{
		stack->top_node = new_elem;
		stack->bot_node = new_elem;
	}
	else
	{
		stack->bot_node->bot_elem = new_elem;
		new_elem->top_elem = stack->bot_node;
		stack->bot_node = new_elem;
	}
}

void	dequeue(t_stack *stack)
{
	pop(stack);
}
