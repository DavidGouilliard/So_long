/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 03:18:08 by dagouill          #+#    #+#             */
/*   Updated: 2025/04/26 05:30:53 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	free_map(game->map);
	ft_lstclear(&(game->map_list), free);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	error_exit(char *str, t_game *game)
{
	free_game(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	init_array(t_game *game, int height)
{
	int		i;
	int		len;
	t_list	*p;
	char	*line;

	i = 0;
	p = game->map_list;
	game->map = (char **) malloc(sizeof(char *) * (height + 1));
	if (game->map == NULL)
		error_exit("malloc error\n", game);
	while (p)
	{
		line = (char *) p->content;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map[i] = ft_strdup(line);
		if (game->map[i] == NULL)
			error_exit("malloc error\n", game);
		i++;
		p = p->next;
	}
	game->map[i] = NULL;
	game->height = height;
	ft_lstclear(&(game->map_list), free);
}

int	test_char(char c)
{
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P' || c == '\n')
		return (1);
	else
		return (0);
}
