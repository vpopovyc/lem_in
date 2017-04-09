/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection_component.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:41:46 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/09 16:41:57 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_charzero(char ar[], size_t n)
{
    size_t	i;
    
    i = 0;
    while (i < n)
    {
        ar[i] = 0;
        i++;
    }
}

static void     ft_vertex_compare(short vertex, short n_of_vertex)
{
    if (vertex != n_of_vertex)
        ft_exit("k > 1");
}

static void     ft_add_vetx(char mark[], short n, short *vertex, t_stack *stack)
{
    *vertex += 1;
    mark[n] = MARKED;
    enqueue(stack, n);
}

void            ft_find_connection_component(char **acmx, int n_of_vertex)
{
    char    mark[n_of_vertex];
    short   n;
    short   i;
    short   vertex;
    t_stack stack;

    ft_charzero(mark, (size_t)n_of_vertex);
    i = START_VERTEX;
    vertex = 1;
    stack_init(&stack);
    enqueue(&stack, i);
    mark[i] = MARKED;
    while (stack_size(&stack))
    {
        i = top(stack);
        n = -1;
        while (++n < n_of_vertex)
        {
            if (acmx[i][n] == CON_EXST && mark[n] == UNMARK)
                ft_add_vetx(mark, n, &vertex, &stack);
        }
        dequeue(&stack);
    }
    ft_vertex_compare(vertex, n_of_vertex);
}
