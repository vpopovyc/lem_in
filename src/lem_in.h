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
	char			**acmx;
}					t_acmx;

typedef struct		s_room
{
	char			flag;
	char			*name;
	uint			id;
}					t_room;

typedef struct		s_root
{
	char			flag;
	uint			n_ofbinds;
	struct s_room	**binds;
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
/* fill_mx.c */
void				ft_get_edges(t_root *root, t_acmx *mx, char *line, char *flag);
void				ft_insert_connection_by_ids(char **mx, uint id_1, uint id_2);
uint				ft_get_id_from_name(t_room **binds, char *name_to_find);
void				ft_null_it(char **mx, uint n);
/* ft_get_input.c */
void				ft_flag_distribution(char *flag, char *line);
void				ft_line_managment(char *line, char *sv);
void				ft_parse(t_root *root, t_acmx *mx, int fd, char *sv);
void				ft_get_input(t_data *input, t_acmx *mx);
int					ft_get_number_of_lemings(char **sv, int fd);
/* get_rooms.c */
t_room				*ft_create_room(char *name, char *flag);
void				ft_check_room_info(char *line);
t_room				*ft_get_room(char *line, char *flag);
/* root_binds.c */
t_room				**ft_rebind_rooms(t_room **old_binds, uint n_ofbinds);
void				ft_bind_to_root(t_root *root, t_room **node);
#endif /* __LEM_IN_H */

/* To do 
 * 
 * parse all input 
 * 
 */
