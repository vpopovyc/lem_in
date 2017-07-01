/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:03:01 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/04/15 20:53:44 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEM_IN_H
# define __LEM_IN_H

# include "libft/includes/libft.h"

# define MARKED         1
# define UNMARK         0
# define BAD_MARK       -1
# define START_VERTEX   0
# define CON_EXST       1
# define NO_CONN        0
# define NOT_MARKED     0
# define START			1
# define NOT_PARALLEL   0
# define NOT_CLEANED	0
# define TO_BE_CLEANED	1
# define IMPORTANT_PATH	0
# define NO_SIZE		0
# define FIRST_INIT		0
# define STRAIGHT_WAY	1
# define START_ROOM		1
# define END_ROOM		2
# define SHORTEST_PATH	0
# define NO_ROOMS		NULL

typedef struct		s_sort
{
	t_uint			i;
	t_uint			size;
	t_uint			tmp;
	t_uint			num_of_pos;
	char			ans;
	char			**free;
}					t_sort;

typedef struct		s_acmx
{
	char			**acmx;
}					t_acmx;

typedef struct		s_room
{
	char			flag;
	char			*name;
	t_uint			id;
	t_uint			path_id;
	t_uint			path_node;
	t_uint			lem;
}					t_room;

typedef struct		s_path
{
	char			*path;
	t_uint			lenght;
}					t_path;

typedef struct		s_root
{
	char			flag;
	t_uint			start;
	t_uint			end;
	t_uint			n_ofbinds;
	t_uint			n_ofpaths;
	struct s_room	**binds;
	struct s_path	**path_set;
}					t_root;

typedef struct		s_data
{
	char			*input;
	int				leming_n;
	t_uint			*last_node;
	t_uint			size;
	t_uint			u_size;
	struct s_path	**path;
}					t_data;

/*
** main.c
*/
void				ft_exit(char *sv);
/*
** fill_mx.c
*/
void				ft_get_edges(t_root *root,
		t_acmx *mx, char *line, char *flag);
void				ft_insert_connection_by_ids(char **mx,
		t_uint id_1, t_uint id_2);
t_uint				ft_get_id_from_name(t_room **binds, char *name_to_find);
void				ft_null_it(char **mx, t_uint n);
/*
** ft_get_input.c
*/
void				ft_get_input(t_data *input, t_acmx *mx, t_root *root);
/*
** get_rooms.c
*/
t_room				*ft_create_room(char *name, char *flag);
void				ft_check_room_info(char *line);
t_room				*ft_get_room(char *line, char *flag);
/*
** root_binds.c
*/
void				ft_validate_names_to_instructions(t_room **binds, int n);
t_room				**ft_rebind_rooms(t_room **old_binds, t_uint n_ofbinds);
void				ft_bind_to_root(t_root *root, t_room **node);
/*
**  connection_component.c
*/
void				ft_charzero(char ar[], size_t n);
void				ft_find_connection_component(char **acmx, int n_of_vertics);
/*
** paths_traversal.c
*/
void				ft_path_traversal(t_root *root, char **acmx, t_uint n_max);
/*
** root_path_set.c
*/
void				ft_path_to_root(t_root *root, t_stack stack);
/*
** path_data_set.c
*/
char				*ft_stack_to_string(t_stack stack);
void				ft_path_to_data(t_data *input, t_path **set,
		t_uint set_size);
void				ft_path_to_stack(t_stack *stack,
		t_stack stk, t_uint j, t_path **set);
/*
** storage_data.c
*/
t_uint				ft_size_of_pp(char **sv);
char				**ft_storage_clean_up(char **old_storage, t_uint *size);
char				**ft_temp_result(t_stack *stack,
		char **old_storage, t_uint size);
/*
** storage_data_addition.c
*/
char				*ft_stack_to_string(t_stack stack);
t_uint				ft_size_of_pp(char **sv);
/*
**  illative_path.c
*/
void				ft_charff(char ar[], t_uint n);
t_path				**ft_illative_path(char **path,
		t_uint lmn_n, t_path **set, t_uint size);
/*
** illative_path_2.c
*/
char				**ft_sort(char *sv, t_path **set, char ***free);
t_path				**ft_sort_and_decide(t_path **set,
		char **path, char *mark, t_uint *ar);
/*
**  min_path.c
*/
t_path				**ft_ret_opt_path(char **sv, t_path **set, t_uint *size);
t_path				**ft_find_shortest_path(char *mark,
		t_path **set, char **path, t_uint *size);
/*
** rooms_spot.c
*/
t_uint				ft_spot_rooms(t_path **path, t_room **room);
/*
** output.c
*/
void				ft_push_all_leming_ahead(t_uint path_id,
		t_uint path_node, t_room *prev, t_room **rooms);
void				ft_push_leming(t_uint path_id,
		t_uint leming, t_room **set, t_uint **node);
void				ft_polzi_v_konec(t_room *prev, t_room **set);
void				ft_polzi_suqa(t_room *curr, t_room *prev);
void				ft_push_all_once(t_room **set, t_uint lem);
/*
**  output_addition.c
*/
void				ft_push_back_to_stack(t_stack *stack,
		t_uint *ar, t_uint size);
t_room				*ft_st(t_room **set);
t_room				*ft_find_room(t_uint path_id,
		t_uint path_node, t_room **set);
void				ft_fill_stor(t_stack *stack, t_uint *ar, t_uint size);
void				ft_fill_stack(t_stack *stack, t_uint n);
/*
** move_lmns.c
*/
void				ft_move(t_data *input, t_root *root);
#endif
