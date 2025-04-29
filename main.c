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

void	print_mov(t_game *game)
{
	game->mov += 1;
	ft_printf("%d\n", game->mov);
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
	draw_map(game, 0, 0);
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
