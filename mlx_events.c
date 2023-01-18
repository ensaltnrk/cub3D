#include "cub3D.h"

int	key_press(int key, t_cub *data)
{
	if (key == 13)
		data->keys->w = 1;
	else if (key == 1)
		data->keys->s = 1;
	else if (key == 0)
		data->keys->a = 1;
	else if (key == 2)
		data->keys->d = 1;
	else if (key == 123)
		data->keys->left = 1;
	else if (key == 124)
		data->keys->right = 1;
	else if (key == 53)
		quit();
	return (0);
}

int	key_release(int key, t_cub *data)
{
	if (key == 13)
		data->keys->w = 0;
	else if (key == 1)
		data->keys->s = 0;
	else if (key == 0)
		data->keys->a = 0;
	else if (key == 2)
		data->keys->d = 0;
	else if (key == 123)
		data->keys->left = 0;
	else if (key == 124)
		data->keys->right = 0;
	return (0);
}

void	init_mlx(t_cub *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx,
			WIDTH, HEIGHT, "CUB3D");
	data->screen.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->screen.height = HEIGHT;
	data->screen.width = WIDTH;
	data->screen.addr = mlx_get_data_addr(data->screen.img,
			&data->screen.bbp, &data->screen.line_len, &data->screen.endian);
}

void	mlx_events(t_cub *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_press, data);
	mlx_hook(data->mlx_win, 3, 0, key_release, data);
	mlx_loop_hook(data->mlx, update, data);
	mlx_hook(data->mlx_win, 17, 0, quit, 0);
}
