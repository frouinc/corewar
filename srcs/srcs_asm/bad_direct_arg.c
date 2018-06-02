/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_direct_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 15:34:44 by kda-silv          #+#    #+#             */
/*   Updated: 2018/06/02 15:37:23 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			bad_direct_arg(t_data *data, char **tab, int count, int count_word)
{
	while (tab[count_word][++count] != '\0'
		&& tab[count_word][count] != SEPARATOR_CHAR
		&& tab[count_word][count] != COMMENT_CHAR)
		if (tab[count_word][count] < '0'
			|| tab[count_word][count] > '9')
			asm_error("Bad DIRECT Argument", 2, data, data->line);
	return (count);
}
