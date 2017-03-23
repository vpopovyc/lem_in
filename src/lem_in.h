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

typedef struct		s_acmx
{
	char			**mx;
}					t_acmx;

typedef struct		s_room
{
	char			flag;
	short			x;
	short			y;
	char			*name;
	char			*color;
	struct s_room	**edge;
}					t_room;

typedef struct		s_root
{
	char			flag;
	struct s_room	**room;
}					t_root;

typedef struct		s_data
{
	char			*input;
	int				fd;
	int				leming_n;
}					t_data;

/* main.c */
void				ft_exit(char *sv);
void				ft_tdata_init(t_data *new, char **av);
/* ft_fill_mx.c */
void				ft_create_mx(t_acmx *mx);
/* ft_get_input.c */
void				ft_get_input(t_data *input);
int					ft_get_number_of_lemings(char **sv, int fd);

#endif /* __LEM_IN_H */
