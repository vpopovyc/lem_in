/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:03:01 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/03/21 20:03:07 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEM_IN_H
# define __LEM_IN_H

# include "libft.h"

typedef struct	s_acmx
{
	short		**mx;
}				t_acmx;

typedef struct	s_data
{

}				t_data;

/* ft_fill_mx.c */
void			ft_create_mx(t_acmx *mx);
/* ft_get_input.c */
void			ft_get_input(t_data *input);
#endif
