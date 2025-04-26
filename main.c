/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:59:07 by dagouill          #+#    #+#             */
/*   Updated: 2025/04/26 05:17:28 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	check_1(game);
	check_2(game);
	check_walls(game);
	if (!check_path(game))
		error_exit("not path to exit or collectibles\n", game);
}

t_game	*initialize_struct(void)
{
	t_game	*game;

	game = (t_game *) malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game);
		exit(1);
	}
	game->map = NULL;
	game->map_list = NULL;
	game->coll_total = 0;
	game->coll_count = 0;
	game->exit_found = 0;
	game->x = 0;
	game->y = 0;
	return (game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = initialize_struct();
	if (ac != 2)
		error_exit("wrong argument count\n", game);
	check_arg(av[1], game);
	free_game(game);
	return (0);
}
