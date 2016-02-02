/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:23:15 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/01/06 19:19:29 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void			ft_print_board(char **board, int side)
{
	int		i;

	i = 0;
	while (i < side)
	{
		ft_putstr(board[i]);
		i++;
	}
}

static char		**ft_get_board(int side)
{
	char	**board;
	int		i;

	i = 0;
	if (!(board = (char**)malloc(sizeof(*board) * side + 1)))
		return (NULL);
	board[side] = 0;
	while (i < side)
	{
		if (!(board[i] = (char*)malloc(sizeof(**board) * (side + 1))))
			return (NULL);
		ft_memset(board[i], '.', side);
		board[i][side] = '\0';
		i++;
	}
	return (board);
}

void			ft_get_size(t_pos *tab, int side)
{
	char	**board;
	int		size;
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = (tab + i)->nb_tetri * 4;
	if (side == 0)
	{
		while ((side * side) < size)
		{
			tmp = (side * side);
			side++;
		}
	}
	board = ft_get_board(side);
	ft_resolution(board, side, tab, 0);
}
