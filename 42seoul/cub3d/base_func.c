/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:36:23 by huchoi            #+#    #+#             */
/*   Updated: 2021/04/02 17:25:59 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	message_exit(void)
{
	ft_putstr_fd("Error\nwhy you want to play this game...???", 1);
	exit(0);
}

int		is_only_zero_blank_one(char *arr)
{
	int idx;

	idx = 0;
	while (arr[idx])
	{
		if (ft_strchr("012 NEWS", arr[idx++]) == 0)
			return (-1);
	}
	return (1);
}

int		check_first(char *buf)
{
	if (ft_strchr(buf, '0') != 0)
		message_exit();
	return (1);
}

int		check_last(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i++] != '1')
			message_exit();
	}
	return (1);
}
