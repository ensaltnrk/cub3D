#include "cub3D.h"

static float	get_distance(t_vector2f a, t_vector2f b)
{
	float	x;
	float	y;

	if (float_approximately(a.x, b.x))
		return (fabs(a.y - b.y));
	if (float_approximately(a.y, b.y))
		return (fabs(a.x - b.x));
	x = a.x - b.x;
	y = a.y - b.y;
	return (sqrt(x * x + y * y));
}

t_hit	look_horizontal(t_cub *data, float f_slope, int add)
{
	float	f_add;
	int		i;
	float	y;

	i = data->pos.x;
	i += add;
	f_add = data->pos.y - (f_slope * data->pos.x);
	while (1)
	{
		y = f_slope * (i + (add < 0)) + f_add;
		if (y < 0 || (int)y >= data->y_size || i < 0 || i >= data->x_size)
			return ((t_hit){0x7FFFFFFF, 0});
		if (data->map[(int)y][i] == '1')
		{
			return ((t_hit){get_distance((t_vector2f){i + (add < 0), y},
				data->pos), y - (int)y});
		}
		i += add;
	}
}

t_hit	look_vertical(t_cub *data, float f_slope, int add)
{
	float	f_add;
	int		i;
	float	x;

	i = data->pos.y;
	i += add;
	f_add = data->pos.x - (f_slope * data->pos.y);
	while (1)
	{
		x = f_slope * (i + (add < 0)) + f_add;
		if (x < 0 || (int)x >= data->x_size || i < 0 || i >= data->y_size)
			return ((t_hit){0x7FFFFFFF, 0});
		if (data->map[i][(int)x] == '1')
		{
			return ((t_hit){get_distance((t_vector2f){x, i + (add < 0)},
				data->pos), x - (int)x});
		}
		i += add;
	}
}

void	look_slope(t_cub *data, float slope, t_pl *dir, int index)
{
	t_hit	vertical;
	t_hit	horizontal;

	horizontal = look_horizontal(data, slope, dir->x);
	vertical = look_vertical(data, 1 / slope, dir->y);
	if (horizontal.distance > vertical.distance)
	{
		data->active_img = dir->y > 0;
		if (dir->y < 0)
			vertical.rate = 1 - vertical.rate;
		draw_wall(data, vertical.distance * cos(dir->angle),
			vertical.rate, index);
	}
	else
	{
		data->active_img = 2 + (dir->x > 0);
		if (dir->x > 0)
			horizontal.rate = 1 - horizontal.rate;
		draw_wall(data, horizontal.distance * cos(dir->angle),
			horizontal.rate, index);
	}
}

void	raycast(t_cub *data, float angle, int pixels)
{
	float	cos_value;
	float	sin_value;
	t_pl	dir;

	cos_value = cosf(angle + data->look);
	sin_value = sinf(angle + data->look);
	dir.x = (cos_value > 0) * 2 - 1;
	dir.y = (sin_value > 0) * 2 - 1;
	dir.angle = angle;
	look_slope(data, sin_value / cos_value, &dir, pixels);
}
