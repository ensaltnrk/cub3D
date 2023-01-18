#include "cub3D.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	dst = data->addr + ((y * data->line_len) + x * (data->bbp / 8));
	*(int *)dst = color;
}

int	image_get_pixel(t_image *img, int x, int y)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	return (*((int *)(img->addr + (y * img->line_len) \
	+ (x * (img->bbp / 8)))));
}

int	float_approximately(float a, float b)
{
	return (a - b < 0.0001f && a - b > -0.0001f);
}

int	int_abs(int i)
{
	return (i * ((i > 0) * 2 - 1));
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\n' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
