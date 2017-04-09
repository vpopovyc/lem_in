/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:23:23 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/09 15:23:32 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#define MAX_GRAPH   4
#define CON_EXST    1
#define NO_CONN     0
#define NOT_VISTD   0
#define VISITED     1

int main(void)
{
    t_stack stack;
    
    char	i;
    char	n;
    int     vertex;
    char	start = 0;
    
    char	matrix[MAX_GRAPH][MAX_GRAPH] =
    {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
    };
    char	visited[MAX_GRAPH] = {0, 0, 0, 0};
    
    vertex = 1;
    stack_init(&stack);
    enqueue(&stack, (int)start);
    visited[start] = 1;
    
    while (stack_size(&stack))
    {
        i = top(stack);
        n = 0;
        while (n < MAX_GRAPH)
        {
            if (matrix[i][n] == CON_EXST && visited[n] == NOT_VISTD)
            {
                ++vertex;
                visited[n] = VISITED;
                enqueue(&stack, (int)n);
            }
            n++;
        }
        dequeue(&stack);
    }
    if (vertex == MAX_GRAPH)
        printf("k == 1\n");
    else
        printf("k > 1\n");
}
