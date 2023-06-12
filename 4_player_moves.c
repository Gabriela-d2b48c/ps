/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_player_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:02:20 by gabriela          #+#    #+#             */
/*   Updated: 2023/06/12 14:58:46 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Set player to non-occupied element and set the W/A/S/D
(up, down, left, right) movement */
void	ft_move_player(t_struct *game, int row, int col)
{
	game->gta.map[row][col] = '0';
	if (game->key == W)
		game->gta.map[row - 1][col] = 'P';
	if (game->key == A)
		game->gta.map[row][col - 1] = 'P';
	if (game->key == S)
		game->gta.map[row + 1][col] = 'P';
	if (game->key == D)
		game->gta.map[row][col + 1] = 'P';
	ft_player_placement(game);
}

/* Check if enemy is located in the spot where the player want to move.
If so, return 1, if not, return 0 */
int	ft_check_enemy(t_struct *game, int row, int col)
{
	if ((game->gta.map[row - 1][col] == 'X' && game->key == W)
	|| (game->gta.map[row][col - 1] == 'X' && game->key == A)
	|| (game->gta.map[row + 1][col] == 'X' && game->key == S)
	|| (game->gta.map[row][col + 1] == 'X' && game->key == D))
	{
		game->player.enemy_check = 42;
		ft_move_player(game, row, col);
		return (1);
	}
	return (0);
}

/* Check if wall is located in the spot where the player wants to move,
if he'll reach exit or encounter enemy or cast. Move player and enemy. */
int	ft_check_path(t_struct *game, int row, int col)
{
	if ((game->gta.map[row - 1][col] != '1' && game->key == W)
	|| (game->gta.map[row][col - 1] != '1' && game->key == A)
	|| (game->gta.map[row + 1][col] != '1' && game->key == S)
	|| (game->gta.map[row][col + 1] != '1' && game->key == D))
	{
		game->player.moves++;
		if (ft_check_exit(game, row, col) == 1)
			return (1);
		if (ft_check_enemy(game, row, col) == 1)
			return (1);
		if ((game->gta.map[row - 1][col] == 'C' && game->key == W)
		|| (game->gta.map[row][col - 1] == 'C' && game->key == A)
		|| (game->gta.map[row + 1][col] == 'C' && game->key == S)
		|| (game->gta.map[row][col + 1] == 'C' && game->key == D))
			game->gta.cash--;
		ft_move_player(game, row, col);
		if (ft_move_enemy(&game->gta) == 1)
		{
			game->player.enemy_check = 42;
			game->gta.map[game->player.player_on_row]
			[game->player.player_on_col] = 'P';
			return (1);
		}
	}
	return (0);
}

/* If pressing W/A/S/D (up, down, left, right) leads to exit return 1, 
if not, return 0. */
int	ft_check_exit(t_struct *game, int row, int col)
{
	if ((game->gta.map[row - 1][col] == 'E' && game->key == W)
	|| (game->gta.map[row][col - 1] == 'E' && game->key == A)
	|| (game->gta.map[row + 1][col] == 'E' && game->key == S)
	|| (game->gta.map[row][col + 1] == 'E' && game->key == D))
		return (1);
	return (0);
}

/* Update players position based on W/A/S/D (up, down, left, right) keys. 
Check path for exit or enemy (game over) or rebuild the map. */
int	ft_move(t_struct *game, int keycode)
{
	int	row;
	int	col;

	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		game->key = keycode;
		if (game->key == A)
			game->last_key = A;
		if (game->key == D)
			game->last_key = D;
		row = game->player.player_on_row;
		col = game->player.player_on_col;
		if (ft_check_path(game, row, col) == 1)
			return (1);
		ft_occupy_map(game);
	}
	return (0);
}