/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 03:22:15 by dagouill          #+#    #+#             */
/*   Updated: 2025/04/26 05:28:21 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(char *file, t_game *game)
{
	int		fd;
	int		height;
	t_list	*line;
	char	*raw_line;

	height = 0;
	fd = open(file, O_RDONLY, 0777);
	if (fd < 0)
		error_exit("error map open\n", game);
	while (1)
	{
		raw_line = get_next_line(fd);
		if (raw_line == NULL)
			break ;
		line = ft_lstnew((void *)raw_line);
		if (line == NULL)
		{
			free(raw_line);
			error_exit("malloc error\n", game);
		}
		ft_lstadd_back(&(game->map_list), line);
		height++;
	}
	if (height == 0)
		error_exit("map empty\n", game);
	init_array(game, height);
	close(fd);
}

void	check_1(t_game *game)
{
	int		len;
	int		len2;
	int		i;
	char	*line;

	len = 0;
	i = 0;
	line = game->map[0];
	while (*line && *line++ != '\n')
		len++;
	while (i < game->height)
	{
		len2 = 0;
		line = game->map[i];
		while (*line && *line != '\n')
		{
			if (test_char(*line++) == 0)
				error_exit("forbidden char on map\n", game);
			len2++;
		}
		if (len != len2)
			error_exit("map not rectangular\n", game);
		i++;
	}
	game->lenght = len;
}

void	check_cep(t_game *game, int coll, int ex, int pos)
{
	game->coll_total = coll;
	if (ex != 1)
		error_exit("wrong exit count\n", game);
	if (pos != 1)
		error_exit("wrong start count\n", game);
	if (coll < 1)
		error_exit("no collectibles\n", game);
}

void	check_2(t_game *game)
{
	int		coll;
	int		ex;
	int		pos;
	int		i;
	char	*line;

	coll = 0;
	ex = 0;
	pos = 0;
	i = -1;
	while (i++ < game->height - 1)
	{
		line = game->map[i];
		while (*line)
		{
			if (*line == 'C')
				coll++;
			else if (*line == 'E')
				ex++;
			else if (*line == 'P')
				pos++;
			line++;
		}
	}
	check_cep(game, coll, ex, pos);
}

void	check_walls(t_game *game)
{
	int		i;
	char	*line;

	i = 1;
	line = game->map[0];
	while (*line)
		if (*line++ != '1')
			error_exit("map not enclosed\n", game);
	while (i < game->height - 1)
	{
		line = game->map[i];
		if (*line != '1')
			error_exit("map not enclosed\n", game);
		while (*line)
			line++;
		if (*(line - 1) != '1')
			error_exit("map not enclosed\n", game);
		i++;
	}
	line = game->map[i];
	while (*line)
		if (*line++ != '1')
			error_exit("map not enclosed\n", game);
}
