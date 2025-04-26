/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:12:22 by dagouill          #+#    #+#             */
/*   Updated: 2025/04/26 05:14:34 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
	void		*mlx_ptr;
	char		**map;
	t_list		*map_list;
	int			lenght;
	int			height;
	int			coll_total;
	int			coll_count;
	int			exit_found;
	int			x;
	int			y;
}	t_game;

void	free_map(char **map);
void	free_game(t_game *game);
void	error_exit(char *str, t_game *game);
void	init_array(t_game *game, int height);
int		test_char(char c);

void	init_map(char *file, t_game *game);
void	check_1(t_game *game);
void	check_cep(t_game *game, int coll, int ex, int pos);
void	check_2(t_game *game);
void	check_walls(t_game *game);

void	get_pos(t_game *game);
char 	**copy_map(t_game *game);
void	fill(char **map, t_game *game, int x, int y);
int		check_path(t_game *game);

#endif
