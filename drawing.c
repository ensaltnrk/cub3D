#include "cub3D.h"

int	color_dark(int color, float dark)
{
	int	r;
	int	g;
	int	b;

	r = color & 0x000000FF;
	r *= dark;
	g = (color & 0x0000FF00) >> 8;
	g *= dark;
	b = (color & 0x00FF0000) >> 16;
	b *= dark;
	return (r | (g << 8) | (b << 16));
}

void	draw_wall(t_cub *data, float distance, float rate, int pixel)
{
	int		draw;
	float	rate_i;
	int		start;
	int		end;
	float	dark;

	dark = 2.0f / distance;
	if (dark >= 1)
		dark = 1;
	draw = (5 / distance) * (HEIGHT * 0.3f);
	rate_i = (float)data->imgs[data->active_img].height / draw;
	start = (HEIGHT - draw) / 2;
	end = 0;
	if (start < 0)
	{
		draw += start;
		end = -start;
	}
	while (draw-- > end)
		my_mlx_pixel_put(&data->screen, pixel, draw + start,
			color_dark(image_get_pixel(&data->imgs[data->active_img],
					data->imgs[data->active_img].width * rate,
					draw * rate_i), dark));
}
