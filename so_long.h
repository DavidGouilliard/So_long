/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:12:22 by dagouill          #+#    #+#             */
/*   Updated: 2025/04/29 11:41:56 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "libft/get_next_line.h"
# include <X11/keysym.h>
# include <fcntl.h>

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*floor_img;
	void		*wall_img;
	void		*player_img;
	void		*coll_img;
	void		*exit_img;
	char		**map;
	t_list		*map_list;
	int			lenght;
	int			height;
	int			coll_total;
	int			coll_count;
	int			exit_found;
	int			x;
	int			y;
	int			mov;
}	t_game;

void	free_map(char **map);
void	free_game(t_game *game);
void	error_exit(char *str, t_game *game);
void	init_array(t_game *game);
int		test_char(char c);

void	init_map(char *file, t_game *game);
void	check_1(t_game *game);
void	check_cep(t_game *game, int coll, int ex, int pos);
void	check_2(t_game *game);
void	check_walls(t_game *game);

void	get_pos(t_game *game);
char	**copy_map(t_game *game);
void	fill(char **map, t_game *game, int x, int y);
int		check_path(t_game *game);
void	check_map(t_game *game);
int		test_char(char c);

t_game	*initialize_struct(void);
void	print_mov(t_game *game);

int		game_end(t_game *game);
void	move_player(int keycode, t_game *game);
void	load_images(t_game *game);
void	draw_map(t_game *game, int x, int y);

void	check_arg(char *file, t_game *game);
int		on_keypress(int keycode, t_game *game);
int		on_destroy(t_game *game);
void	game_loop(t_game *game);

#endif
