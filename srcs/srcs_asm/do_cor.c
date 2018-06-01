/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:49:10 by kda-silv          #+#    #+#             */
/*   Updated: 2018/06/01 21:35:05 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		create_file(t_data *data, char *source)
{
	int			fd;
	int			count;

	count = (int)ft_strlen(source) + 2;
//	ft_putstr(ft_itoa(count));
//	ft_putchar('\n');
	if ((data->file_cor = ft_memalloc(count * sizeof(char))) == NULL)
		asm_error("Error malloc", 1, data, NULL);
	if ((data->file_cor = ft_strncat(data->file_cor, source, count - 2)) == NULL)
		asm_error("Error malloc", 1, data, data->file_cor);
	/*ft_putstr("!!!!!!!!!!!!!!\n");
	int debug1;
	int	debug2;
	debug1 = -1;
	while (data->tab[++debug1] != NULL)
	{
		debug2 = -1;
		while (data->tab[debug1][++debug2] != NULL)
		{
			ft_putstr(data->tab[debug1][debug2]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	ft_putstr("=================\n");
	ft_putstr(data->file_cor);
	ft_putchar('\n');
	ft_putstr(ft_itoa(count));
	ft_putchar('\n');*/
	/*
	** Bug
	** entre les eux affichanges les donnees de data->tab sont modifier de mainiere aleatoire
	** alors qu'on y touche ps du tout ici
	** ce qui provoque un segfault a la destruction de data->tab
	*/
	data->file_cor[count - 3] = 'c';
	data->file_cor[count - 2] = 'o';
	data->file_cor[count - 1] = 'r';
	data->file_cor[count] = '\0';
	/*ft_putstr(data->file_cor);
	ft_putchar('\n');
	ft_putstr("##########\n");
	debug1 = -1;
	while (data->tab[++debug1] != NULL)
	{
		debug2 = -1;
		while (data->tab[debug1][++debug2] != NULL)
		{
			ft_putstr(data->tab[debug1][debug2]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	ft_putstr("@@@@@@@@@@\n");*/
	if ((fd = open(data->file_cor, O_RDWR | O_CREAT | O_TRUNC, 0755)) == -1)
		asm_error("Error creat file", 1, data, data->file_cor);
	return (fd);
}

void			do_cor(t_data *data, char *source)
{
	int			count;

	data->fd = create_file(data, source);
	write(data->fd, &data->header, sizeof(t_header));
	count = -1;
	while (data->tab[++count] != NULL)
		do_function(data, count);
	close(data->fd);
}
