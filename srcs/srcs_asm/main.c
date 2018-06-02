/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:53 by cyrillef          #+#    #+#             */
/*   Updated: 2018/06/02 17:43:47 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		check_file(t_data *data, char **av, int count)
{
	if (av[count][ft_strlen(av[count]) - 1] != 's'
		|| av[count][ft_strlen(av[count]) - 2] != '.')
		asm_error("usage: ./asm \"file_name.s\"", 1, data, NULL);
	if ((data->fd = open(av[count], O_RDONLY)) == -1)
		asm_error("usage: ./asm \"file_name.s\"", 1, data, NULL);
}

static void		delete_data(t_data data)
{
	int			count;

	count = -1;
	if (data.file_cor != NULL)
		free(data.file_cor);
	if (data.tab != NULL)
	{
		while (data.tab[++count] != NULL)
			ft_word_tab_free(data.tab[count]);
		free(data.tab);
	}
	if (data.labels != NULL)
		ft_word_tab_free(data.labels);
}

static t_data	init_data(t_data data)
{
	data.header.magic = COREWAR_EXEC_MAGIC;
	data.name = 0;
	data.comment = 0;
	data.tab = NULL;
	data.labels = NULL;
	data.nbr_line = 0;
	data.check_cmd = 0;
	data.fd = -1;
	return (data);
}

int				main(int ac, char **av)
{
	t_data		data;
	int			count;

	if (ac < 2)
		asm_error("usage: ./asm \"file_name.s\"", 1, &data, NULL);
	count = 0;
	while (++count < ac)
	{
		data = init_data(data);
		check_file(&data, av, count);
		parsing_champ(&data, 0, NULL);
		if (close(data.fd) == -1)
			asm_error("fail close error", 2, &data, NULL);
		do_cor(&data, av[count]);
		ft_putstr_fd(GREEN, 1);
		ft_putstr_fd(data.file_cor, 1);
		ft_putstr_fd(" has been created !\n", 1);
		ft_putstr_fd(RESET, 1);
		delete_data(data);
	}
	return (0);
}
