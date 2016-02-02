/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:40:29 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/01/06 13:55:00 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int		ft_read_file(char *file, t_pos *tab)
{
	int		fd;
	int		ret;
	int		nb_fig;
	char	buf[BUF_SIZE + 1];

	nb_fig = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_check_file(buf, 0, 0) != 0)
			return (0);
		nb_fig++;
		ft_get_coor(buf, tab, nb_fig);
	}
	ft_up_left(tab, nb_fig);
	if (buf[20] != '\0')
		return (0);
	if (nb_fig > 26)
		return (0);
	return (nb_fig);
}

int				main(int ac, char **av)
{
	int		nb_fig;
	t_pos	tab[26];

	ft_bzero(tab, 26 * sizeof(t_pos));
	nb_fig = 0;
	if (ac == 2)
	{
		nb_fig = ft_read_file(av[1], tab);
		if (nb_fig == 0)
		{
			write(1, "error\n", 6);
			return (0);
		}
		ft_get_size(tab, 0);
	}
	return (0);
}
