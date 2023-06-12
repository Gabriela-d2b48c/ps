/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_enemy_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:50:04 by gabriela          #+#    #+#             */
/*   Updated: 2023/06/12 15:00:54 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Move enemy down (increasing row index) or up (decreasing row index),
or keep him in place if he'd bump into cash, wall, exit or other enemy */
int	ft_enemy_down_up(t_map *gta, int enemy_no, int row, int col)
{
	int	random;
	int	dir;

	random = rand();
	if (random % 2 == 0)
		dir = 1;
	else
		dir = -1;
	if (gta->map[row + dir][col] != '1' && gta->map[row + dir][col] != 'C'
		&& gta->map[row + dir][col] != 'E' && gta->map[row + dir][col] != 'X')
	{
		gta->map[row][col] = '0';
		if (gta->map[row + dir][col] == 'P')
			return (1);
		gta->map[row + dir][col] = 'X';
		gta->enemy_on_row[enemy_no] = row + dir;
	}
	else
		gta->map[row][col] = 'X';
	gta->enemy_last_row[enemy_no] = row;
	gta->enemy_last_col[enemy_no] = col;
	return (0);
}

/* Move enemy left (decreasing column index) or right (increasing column index).
or keep him in place if he'd bump into cash, wall, exit or other enemy */
int	ft_enemy_left_right(t_map *gta, int enemy_no, int row, int col)
{
	int	random;
	int	dir;

	random = rand();
	if (random % 2 == 0)
		dir = 1;
	else
		dir = -1;
	if (gta->map[row][col + dir] != '1' && gta->map[row][col + dir] != 'C'
		&& gta->map[row][col + dir] != 'E' && gta->map[row][col + dir] != 'X')
	{
		gta->map[row][col] = '0';
		if (gta->map[row][col + dir] == 'P')
			return (1);
		gta->map[row][col + dir] = 'X';
		gta->enemy_on_row[enemy_no] = col + dir;
	}
	else
		gta->map[row][col] = 'X';
	gta->enemy_last_row[enemy_no] = row;
	gta->enemy_last_col[enemy_no] = col;
	return (0);
}

/* Move each enemy to a some direction. */
int	ft_enemy_movement(t_map *gta)
{
	int	enemy_no;
	int	row;
	int	col;

	enemy_no = 0;
	while (enemy_no < gta->counter_enemy)
	{
		row = gta->enemy_on_row[enemy_no];
		col = gta->enemy_on_col[enemy_no];
		if ((enemy_no % 2) == 0)
		{
			if (ft_enemy_down_up(gta, enemy_no, row, col) == 1)
				return (1);
		}
		else
		{
			if (ft_enemy_left_right(gta, enemy_no, row, col) == 1)
				return (1);
		}
		enemy_no++;
	}
	return (0);
}