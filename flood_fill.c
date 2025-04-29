/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 04:20:24 by dagouill          #+#    #+#             */
/*   Updated: 2025/04/26 05:09:12 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pos(t_game *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'P')
				return ;
			game->x++;
		}
		game->y++;
	}
}

char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **) malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	while (i < game->height)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			error_exit("malloc error\n", game);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	fill(char **map, t_game *game, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'E')
		game->exit_found = 1;
	else if (map[y][x] == 'C')
		game->coll_count++;
	map[y][x] = 'X';
	fill(map, game, x + 1, y);
	fill(map, game, x - 1, y);
	fill(map, game, x, y + 1);
	fill(map, game, x, y - 1);
}

int	check_path(t_game *game)
{
	char	**copy;

	copy = NULL;
	get_pos(game);
	copy = copy_map(game);
	fill(copy, game, game->x, game->y);
	free_map(copy);
	game->x = 0;
	game->y = 0;
	if (game->coll_count == game->coll_total
		&& game->exit_found == 1)
	{
		get_pos(game);
		game->coll_count = 0;
		return (1);
	}
	else
		return (0);
}
