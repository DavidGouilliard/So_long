/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:59:07 by dagouill          #+#    #+#             */
/*   Updated: 2025/04/26 06:31:56 by dagouill         ###   ########.fr       */
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
	check_map(game);
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

void	print_mov(t_game *game)
{
	game->mov += 1;
	ft_printf("%d\n", game->mov);
	ft_printf("coll_count %d\n", game->coll_count);
	ft_printf("coll_total %d\n", game->coll_total);
}

int	game_end(t_game *game)
{
	if (game->coll_count == game->coll_total
		&& game->map[game->y][game->x] == 'E')
		mlx_loop_end(game->mlx_ptr);
	return (0);
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

int	on_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		mlx_loop_end(game->mlx_ptr);
	if (keycode == XK_d || keycode == XK_a
		|| keycode == XK_w || keycode == XK_s)
	{
		if (game->map[game->y][game->x] == 'C')
		{
			game->map[game->y][game->x] = '0';
			game->coll_count += 1;
		}
		move_player(keycode, game);
		print_mov(game);
	}
	game_end(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map(game);
	return (0);
}

int	on_destroy(t_game *game)
{
	mlx_loop_end(game->mlx_ptr);
	return (0);
}

void	game_loop(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L << 0, &on_keypress, game);
	mlx_hook(game->win_ptr, 17, 0, &on_destroy, game);
	mlx_loop(game->mlx_ptr);
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

int	main(int ac, char **av)
{
	t_game	*game;

	game = initialize_struct();
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game);
		exit(1);
	}
	if (ac != 2)
		error_exit("wrong argument count\n", game);
	check_arg(av[1], game);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->lenght * 64, game->height * 64, "so_long");
	if (!game->win_ptr)
		error_exit("win_ptr failed\n", game);
	load_images(game);
	draw_map(game, 0, 0);
	game_loop(game);
	free_game(game);
	return (0);
}
