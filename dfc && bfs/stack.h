/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:09:51 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/06 18:11:08 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_H
# define __STACK_H

# include <stdlib.h>
# include <stdio.h>

typedef struct				s_stack_elem
{
	int						id;
	struct s_stack_elem		*top_elem;
	struct s_stack_elem		*bot_elem;
}							t_stack_elem;

typedef struct				s_stack
{
	struct s_stack_elem		*top_node;
	struct s_stack_elem		*bot_node;
}							t_stack;

/* stack.c */
void						stack_init(t_stack *stack);
void						push(t_stack *stack, int id);
void						pop(t_stack *stack);
int							top(t_stack stack);
int							stack_size(t_stack *stack);
/* queue.c */
void                        enqueue(t_stack *stack, int id);
void                        dequeue(t_stack *stack);
/* print_stack.c */
void                        print_stack_id(t_stack stack);
void                        rev_print_stack_id(t_stack stack);

#endif
