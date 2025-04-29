/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:30:21 by dagouill          #+#    #+#             */
/*   Updated: 2025/04/29 11:41:14 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game, int x, int y)
{
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx_ptr,
				game->win_ptr, game->floor_img, x * 64, y * 64);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->coll_img, x * 64, y * 64);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->exit_img, x * 64, y * 64);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->wall_img, x * 64, y * 64);
			if (y == game->y && x == game->x)
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->player_img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/floor.xpm", &w, &h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall.xpm", &w, &h);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player.xpm", &w, &h);
	game->coll_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/coll.xpm", &w, &h);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/exit.xpm", &w, &h);
	if (!game->floor_img || !game->wall_img || !game->player_img
		|| !game->coll_img || !game->exit_img)
		error_exit("error loading images\n", game);
}

void	move_player(int keycode, t_game *game)
{
	if (keycode == XK_d
		&& game->map[game->y][game->x + 1] != '1')
		game->x += 1;
	else if (keycode == XK_a
		&& game->map[game->y][game->x - 1] != '1')
		game->x -= 1;
	else if (keycode == XK_w
		&& game->map[game->y - 1][game->x] != '1')
		game->y -= 1;
	else if (keycode == XK_s
		&& game->map[game->y + 1][game->x] != '1')
		game->y += 1;
}

int	game_end(t_game *game)
{
	if (game->coll_count == game->coll_total
		&& game->map[game->y][game->x] == 'E')
	{
		ft_printf("You WON!!!\n", game->mov);
		mlx_loop_end(game->mlx_ptr);
	}
	return (0);
}
