/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:20:50 by dagouill          #+#    #+#             */
/*   Updated: 2025/04/29 11:40:46 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test_char(char c)
{
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P' || c == '\n')
		return (1);
	else
		return (0);
}

t_game	*initialize_struct(void)
{
	t_game	*game;

	game = (t_game *) malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->win_ptr = NULL;
	game->map = NULL;
	game->map_list = NULL;
	game->floor_img = NULL;
	game->wall_img = NULL;
	game->player_img = NULL;
	game->coll_img = NULL;
	game->exit_img = NULL;
	game->coll_total = 0;
	game->coll_count = 0;
	game->exit_found = 0;
	game->x = 0;
	game->height = 0;
	game->y = 0;
	game->mov = 0;
	return (game);
}

void	check_arg(char *file, t_game *game)
{
	char	*extension;

	extension = file;
	while (*extension)
		extension++;
	extension -= 4;
	if (ft_strncmp(extension, ".ber", 4) != 0)
		error_exit("wrong file extension\n", game);
	if (access(file, R_OK) != 0)
		error_exit("map can't be accessed\n", game);
	init_map(file, game);
	check_map(game);
	check_1(game);
	check_2(game);
	check_walls(game);
	if (!check_path(game))
		error_exit("not path to exit or collectibles\n", game);
}
