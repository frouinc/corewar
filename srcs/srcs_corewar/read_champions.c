/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:34:50 by cyrillef          #+#    #+#             */
/*   Updated: 2017/12/06 16:12:03 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			read_file(int fd, t_champion *champion)
{
	int				index;
	char			buff[1];
	unsigned char	tmp_hex[3];
	t_header		tmp;

	if (read(fd, &tmp, sizeof(t_header)) <= 0)
		corewar_error("Error when reading champion's header.\n");
	ft_strcpy(champion->name, tmp.prog_name);
	ft_strcpy(champion->comment, tmp.comment);
	champion->magic = tmp.magic;
	index = 0;
	bzero(buff, 1);
	bzero(tmp_hex, 3);
	bzero(champion->code, 1024);
	while (read(fd, buff, 1) > 0)
	{
		number_to_hex_str(buff[0], &tmp_hex);
		tmp_hex[2] = ' ';
		ft_strncpy((char *)&champion->code[index], (char*)tmp_hex, 3);
		index += 3;
		bzero(buff, 1);
		bzero(tmp_hex, 3);
	}
	champion->size = ft_strlen(champion->code) / 3;
}

int					read_champion(t_champion *champion)
{
	int				fd;

	if ((fd = open(champion->filename, O_RDONLY)) == -1)
		corewar_error("Can't open champion.\n");
	read_file(fd, champion);
	if (champion->size > CHAMP_MAX_SIZE)
	{
		free(champion);
		return (-1);
	}
	close(fd);
	return (1);
}

int					read_champions(t_data *data)
{
	t_champion		*node;
	int				i;

	node = data->champions;
	i = 0;
	while (node)
	{
		i++;
		if (i > MAX_PLAYERS)
			return (-1);
		if (read_champion(node) != 1)
			return (-1);
		node = node->next;
	}
	return (1);
}