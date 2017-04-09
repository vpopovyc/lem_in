/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 19:30:36 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/06 19:30:46 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#define MAX_GRAPH 4
#define CON_EXST 1
#define NO_CONN 0

int		main(void)
{
	t_stack stack;
	
	char	i;
	char	n;
	char	start = 0;
	char	end = 3;
	printf("start: %hhi end: %hhi\n", start, end);
	
	char	matrix[MAX_GRAPH][MAX_GRAPH] =
	{
		{0, 1, 1, 0},
		{1, 0, 1, 1},
		{1, 1, 0, 0},
		{0, 1, 0, 0}
	};
	char	visited[MAX_GRAPH] = {0, 0, 0, 0};
	char	neighbour[MAX_GRAPH] = {0, 0, 0, 0};
	
	stack_init(&stack);
	push(&stack, (int)start);
	visited[start] = 1;
	
	while (stack_size(&stack))
	{
		i = top(stack);
		if (i == end || neighbour[i] == MAX_GRAPH)
		{
			if (i == end)
				rev_print_stack_id(stack);
			visited[i] = 0;
			pop(&stack);
		}
		else
		{
			n = neighbour[i];
			++neighbour[i];
			if (matrix[i][n] == CON_EXST && visited[n] == NO_CONN)
			{
				neighbour[n] = 0;
				push(&stack, (int)n);
				visited[n] = 1;
			}
		}
	}
}
