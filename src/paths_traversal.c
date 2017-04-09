/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_traversal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 17:56:31 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/09 17:56:41 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void     ft_way_or_pop(char mrk[], short i, t_root *root, t_stack *stack)
{
    if (i == root->end)
        ft_path_to_root(root, *stack);
    mrk[i] = UNMARK;
    pop(stack);
}

static void     ft_push_to_stack(char mrk[], char nb[], short n, t_stack *stack)
{
    nb[n] = START_VERTEX;
    push(stack, n);
    mrk[n] = MARKED;
}

void            ft_path_traversal(t_root *root, char **acmx, uint n_max)
{
    t_stack stack;
    short   i;
    short   n;
    char    mark[n_max];
    char    neighbour[n_max];

    ft_charzero(mark, n_max);
    ft_charzero(neighbour, n_max);
    stack_init(&stack);
    push(&stack, root->start);
    mark[root->start] = MARKED;
    while (stack_size(&stack))
    {
        i = top(stack);
        if (i == root->end || neighbour[i] == n_max)
            ft_way_or_pop(mark, i, root, &stack);
        else
        {
            n = neighbour[i]++;
            if (acmx[i][n] == CON_EXST && mark[n] == NOT_MARKED)
                ft_push_to_stack(mark, neighbour, n, &stack);
        }
    }
}
