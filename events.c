#include "cub3D.h"

int	quit(void)
{
	exit(0);
}

int	collision_detect(t_cub *data, t_vector2f pos)
{
	float	size;

	size = 0.2f;
	return (data->map[(int)(pos.y + size)][(int)(pos.x + size)] != '1'
		&& data->map[(int)(pos.y - size)][(int)(pos.x + size)] != '1'
		&& data->map[(int)(pos.y - size)][(int)(pos.x - size)] != '1'
		&& data->map[(int)(pos.y + size)][(int)(pos.x - size)] != '1');
}

void	move(t_cub *data, t_vector2f move)
{
	if (collision_detect(data,
			(t_vector2f){data->pos.x + move.x, data->pos.y}))
		data->pos.x += move.x;
	if (collision_detect(data,
			(t_vector2f){data->pos.x, data->pos.y + move.y}))
		data->pos.y += move.y;
}

int	update(t_cub *data)
{
	float		speed;
	float		look_speed;
	t_vector2f	movement;

	speed = 0.05f;
	look_speed = 0.02f;
	movement = (t_vector2f){0, 0};
	movement.x += cosf(data->look) * speed
		* (data->keys->w - data->keys->s);
	movement.y += sinf(data->look) * speed
		* (data->keys->w - data->keys->s);
	movement.x += cosf(data->look + (PI / 2)) * speed
		* (data->keys->a - data->keys->d);
	movement.y += sinf(data->look + (PI / 2)) * speed
		* (data->keys->a - data->keys->d);
	if (data->keys->left)
		data->look += look_speed;
	if (data->keys->right)
		data->look -= look_speed;
	move(data, movement);
	render(data);
	return (0);
}
