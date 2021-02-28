/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 01:06:15 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/01 04:20:34 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void message_exit(void)
{
	printf("error\nwhy you paly this game...???");
	exit(0);
}
void		make_block(t_syn *p_syn, int *p_idx, int i)
{
	dda_init(&(p_syn->tri));
	dda_init_second(&(p_syn->tri));
	dda_loop(&(p_syn->tri));
	change_uclied_vertical(&(p_syn->tri));//strcut->walldist에 값이 저장된다.
	p_syn->lineHeight = (double)H / (p_syn->tri.dda.walldist);
	p_syn->drawStart = -p_syn->lineHeight / 2 + p_syn->R[1] / 2;//int연산
	if (p_syn->drawStart < 0)
		p_syn->drawStart = 0;
	p_syn->drawEnd = p_syn->lineHeight / 2 + p_syn->R[1] / 2;//int 연산
	if (p_syn->drawEnd >= H)
		p_syn->drawEnd = H - 1;
	if (p_syn->tri.dda.side == 0)
		p_syn->wallX = p_syn->tri.pos[1] + p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_y;
	else
		p_syn->wallX = p_syn->tri.pos[0] + p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_x;
	p_syn->wallX -= floor((p_syn->wallX));
	news(p_syn, p_idx);
	p_syn->texPos = (p_syn->drawStart - H / 2 + p_syn->lineHeight / 2) * p_syn->step;
	for (int y = p_syn->drawStart; y < p_syn->drawEnd; y++)
	{
		p_syn->texY = (int)p_syn->texPos & (p_syn->tri.tex[*p_idx].height - 1);
		p_syn->texPos += p_syn->step;
		p_syn->color = p_syn->tri.tex[*p_idx].data[p_syn->tri.tex[*p_idx].height * p_syn->texY + p_syn->texX];
		my_mlx_pixel_put(&(p_syn->img), i, y, p_syn->color);
	}
}

void		news(t_syn *p_syn, int *p_idx)
{
	if ((p_syn->tri.dda.raydir_x >= 0) && p_syn->tri.dda.side == 0)
	{
		*p_idx = 1;
		before_make_texture(p_syn, p_idx);
	}
	else if (p_syn->tri.dda.raydir_x <= 0 && p_syn->tri.dda.side == 0)
	{
		*p_idx = 2;
		before_make_texture(p_syn, p_idx);
	}
	else if (p_syn->tri.dda.raydir_y >= 0 && p_syn->tri.dda.side == 1)
	{
		*p_idx = 0;
		before_make_texture(p_syn, p_idx);
	}
	else if (p_syn->tri.dda.raydir_y <= 0 && p_syn->tri.dda.side == 1)
	{
		*p_idx = 3;
		before_make_texture(p_syn, p_idx);
	}
	else
		return ;
}

void		before_make_texture(t_syn *p_syn, int *p_idx)
{
	p_syn->texX = (int)(p_syn->wallX * (double)p_syn->tri.tex[3].width);
	if (p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0)
		p_syn->texX = p_syn->tri.tex[3].width - p_syn->texX - 1;
	if (p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0)
		p_syn->texX = p_syn->tri.tex[3].width - p_syn->texX - 1;
	p_syn->step = 1.0 * p_syn->tri.tex[3].height / p_syn->lineHeight;
}

void		init_for_sprite(t_syn *p_syn, int i)
{
	p_syn->spriteX = p_syn->sprites[i][0] - p_syn->tri.pos[0];
	p_syn->spriteY = p_syn->sprites[i][1] - p_syn->tri.pos[1];
	p_syn->invDet = 1.0 / (p_syn->tri.plane[0] * p_syn->tri.dir[1] - \
			p_syn->tri.dir[0] * p_syn->tri.plane[1]);
	p_syn->transformX = p_syn->invDet * (p_syn->tri.dir[1] * \
			p_syn->spriteX - p_syn->tri.dir[0] * p_syn->spriteY);
	p_syn->transformY = p_syn->invDet * (-p_syn->tri.plane[1] * p_syn->spriteX + \
			p_syn->tri.plane[0] * p_syn->spriteY);
	p_syn->spriteScreenX = (int)((p_syn->R[0] / 2) * \
			(1 + p_syn->transformX / p_syn->transformY));
	p_syn->spriteHeight = abs((int)(H / (p_syn->transformY)));
	p_syn->drawStartY = -p_syn->spriteHeight / 2 + H / 2;
	if (p_syn->drawStartY < 0)
		p_syn->drawStartY = 0;
	p_syn->drawEndY = p_syn->spriteHeight / 2 + H / 2;
	if (p_syn->drawEndY >= H)
		p_syn->drawEndY = H - 1;
	p_syn->spriteWidth = abs((int)(H / (p_syn->transformY)));
	p_syn->drawStartX = -p_syn->spriteWidth / 2 + p_syn->spriteScreenX;
	if (p_syn->drawStartX < 0)
		p_syn->drawStartX = 0;
	p_syn->drawEndX = p_syn->spriteWidth / 2 + p_syn->spriteScreenX;
	if (p_syn->drawEndX >= p_syn->R[0])
		p_syn->drawEndX = p_syn->R[0] - 1;
}
void		sort_sprites(t_syn *p_syn)
{
	ft_mergesort(p_syn, p_syn->sprites, 0, p_syn->num_of_sprite - 1);
}

double		compute_dis(t_syn *p_syn, double *sprite)
{
	double	ret;
	double	x_pos;
	double	y_pos;

	x_pos = sprite[0];
	y_pos = sprite[1];
	ret = (x_pos - p_syn->tri.pos[0]) * (x_pos - p_syn->tri.pos[0]);
	ret += (y_pos - p_syn->tri.pos[1]) * (y_pos - p_syn->tri.pos[1]);
	ret = sqrt(ret);
	return (ret);
}

void		ft_merge(t_syn *p_syn, double **arr, int start, int mid, int end)
{
	double *temp[end - start + 1];
	int idx;
	int left;
	int right;

	idx = 0;
	left = start;
	right = mid + 1;
	while (left <= mid && right <= end)
	{
		if (compute_dis(p_syn, arr[left]) > compute_dis(p_syn, arr[right]))
			temp[idx++] = arr[left++];
		else
			temp[idx++] = arr[right++];
	}
	while (left <= mid)
		temp[idx++] = arr[left++];
	while (right <= end)
		temp[idx++] = arr[right++];
	idx = start - 1;
	while (++idx <= end)
		arr[idx] = temp[idx - start];
}

void		ft_mergesort(t_syn *p_syn, double **arr, int start, int end)
{
	int	mid;

	if (start == end)
		return ;
	mid = (start + end) / 2;
	ft_mergesort(p_syn, arr, start, mid);
	ft_mergesort(p_syn, arr, mid + 1, end);
	ft_merge(p_syn, arr, start, mid, end);
}

void		make_sprite(t_syn *p_syn)
{
	for (int i = 0; i < p_syn->num_of_sprite; i++)
		p_syn->spriteDistance[i] = ((p_syn->tri.pos[0] - p_syn->sprites[i][0]) * \
	(p_syn->tri.pos[0] - p_syn->sprites[i][0]) + (p_syn->tri.pos[1] - p_syn->sprites[i][1]) * \
		(p_syn->tri.pos[1] - p_syn->sprites[i][1]));
	sort_sprites(p_syn);
	for (int i = 0; i < p_syn->num_of_sprite; i++)
	{
		init_for_sprite(p_syn, i);
		for (p_syn->stripe = p_syn->drawStartX; p_syn->stripe < p_syn->drawEndX; (p_syn->stripe)++)
		{
			p_syn->texX = (int)(256 * (p_syn->stripe - (-p_syn->spriteWidth / 2 + p_syn->spriteScreenX))\
					* p_syn->tri.tex[4].width / p_syn->spriteWidth) / 256;
			if (p_syn->transformY > 0 && p_syn->stripe > 0 && p_syn->stripe < p_syn->R[0] &&\
					p_syn->transformY < p_syn->ZBuffer[p_syn->stripe])
			{
				for (p_syn->y = p_syn->drawStartY; p_syn->y < p_syn->drawEndY; (p_syn->y)++)
				{
					p_syn->d = (p_syn->y) * 256 - H * 128 + p_syn->spriteHeight * 128;
					p_syn->texY = ((p_syn->d * p_syn->tri.tex[4].height) / p_syn->spriteHeight) / 256;
					p_syn->color = p_syn->tri.tex[4].data[p_syn->tri.tex[4].width * p_syn->texY + p_syn->texX];
					if ((p_syn->color & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(&(p_syn->img), p_syn->stripe, p_syn->y, p_syn->color);
				}
			}
		}
	}
}
