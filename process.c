#include "cub3D.h"

void	fill_screen(t_cub *data)
{
	int		x;
	int		y;
	int		middle;

	middle = data->screen.height / 2;
	y = -1;
	while (++y < middle)
	{
		x = -1;
		while (++x < data->screen.width)
			my_mlx_pixel_put(&data->screen, x, y, data->ceil_color);
	}
	while (++y < data->screen.height)
	{
		x = -1;
		while (++x < data->screen.width)
			my_mlx_pixel_put(&data->screen, x, y, data->floor_color);
	}
}

void	render(t_cub *data)
{
	float	view_angle;
	float	add;
	float	angle;
	int		pixels;

	view_angle = 0.6f;
	add = view_angle / WIDTH;
	fill_screen(data);
	pixels = WIDTH;
	angle = -(view_angle / 2);
	while (pixels--)
	{
		raycast(data, angle, pixels);
		angle += add;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.img, 0, 0);
}

void	init_game(t_cub *data, t_map *map)
{
	data->pos.x = map->posx + 0.5f;
	data->pos.y = map->posy + 0.5f;
	data->look = (map->ang + 180) * ANGLE_TO_RADIAN;
	render(data);
}
