/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:38:20 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/07 18:18:48 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*case_u(t_node *p_node, char **line)//부호가 없으니 minus_express가 없는거 빼고는 case_d와 동일할것이다.
{
	int		size;
	int		plus;
	int		lenth;
	char	*ret;

	size = ft_strlen(line[5]);
	if (*line[3] != '\0' && size < atoi(line[3]))
		plus = atoi(line[3]) - size;
	else
		plus = 0;
	lenth = size + plus;
	if (p_node->is_precision == 1)
		check_zero(line, &size, &plus, &lenth);
	if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
		lenth = atoi_positive(line[2]);
	(p_node->count) += lenth;
	if (ft_atoi(line[3]) >= 0 && (p_node->is_precision == 1))
		ret = precision_unsigned(line, plus, size, lenth);
	else
		ret = no_precision_unsigned(line, size, lenth);
	return (ret);
}

char	*case_x(t_node *p_node, char **line)
{
	int		size;
	int		plus;
	int		lenth;
	char	*ret;

	size = ft_strlen(line[5]);
	if (*line[3] != '\0' && size < atoi(line[3]))
		plus = atoi(line[3]) - size;
	else
		plus = 0;
	lenth = size + plus;
	if (p_node->is_precision == 1 && size <= 1 && ft_atoi(line[3]) == 0)
		for_hex_check_zero(line, &size, &plus, &lenth);//이 부분만 다르지 나머지는 다 동일하다
	if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
		lenth = atoi_positive(line[2]);
	(p_node->count) += lenth;
	if (ft_atoi(line[3]) >= 0 && (p_node->is_precision == 1))
		ret = precision_unsigned(line, plus, size, lenth);
	else
		ret = no_precision_unsigned(line, size, lenth);
	return (ret);
}

int		for_hex_check_zero(char **line, int *p1, int *p2, int *p3)
{
	if (*line[5] == '0' && ft_atoi(line[3]) == 0)//ft_atoi(line[5])하면 안된다. line[5] = "D"일때 ft_atoi하면 0으로 처리해버림
	{
		*p1 = 0;
		*p2 = 0;
		*p3 = 0;
		return (1);
	}
	else
		return (0);
}

char	*case_big_x(t_node *p_node, char **line)
{
	int		size;
	int		plus;
	int		lenth;
	char	*ret;

	size = ft_strlen(line[5]);
	if (*line[3] != '\0' && size < atoi(line[3]))
		plus = atoi(line[3]) - size;
	else
		plus = 0;
	lenth = size + plus;
	if (p_node->is_precision == 1 && size <= 1)
		for_hex_check_zero(line, &size, &plus, &lenth);
	if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
		lenth = atoi_positive(line[2]);
	(p_node->count) += lenth;
	if (ft_atoi(line[3]) >= 0 && (p_node->is_precision == 1))
		ret = precision_unsigned(line, plus, size, lenth);
	else
		ret = no_precision_unsigned(line, size, lenth);
	return (ret);
}
