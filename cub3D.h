#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH				1024
# define HEIGHT				720
# define ANGLE_TO_RADIAN	0.0174532f
# define PI					3.14159f

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_image
{
	int		height;
	int		width;
	void	*img;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_vector2f
{
	float	x;
	float	y;
}	t_vector2f;

typedef struct s_hit
{
	float	distance;
	float	rate;
}	t_hit;

typedef struct s_pl
{
	int		x;
	int		y;
	float	angle;
}	t_pl;

typedef struct s_pixel
{
	int	o;
	int	r;
	int	g;
	int	b;
	int	check;
}	t_pixel;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
}	t_keys;

typedef struct s_map
{
	char	**content;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		posx;
	int		posy;
	float	ang;
	t_pixel	f;
	t_pixel	c;
}	t_map;

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_win;
	int			**map;
	int			y_size;
	int			x_size;
	int			floor_color;
	int			ceil_color;
	float		look;
	int			active_img;
	t_image		imgs[4];
	t_vector2f	pos;
	t_image		screen;
	t_keys		*keys;
}	t_cub;

int		check_file(char *filename, char *format);
int		clear_map(t_map *map);
int		check_wall(t_map *map, char ch);
int		check_map(t_map *map, char *s, char *s2);
int		image_get_pixel(t_image *img, int x, int y);
int		float_approximately(float a, float b);
int		int_abs(int i);
int		ft_isspace(int c);
int		get_clear_line(char **str, int fd, int mode);
int		key_press(int key, t_cub *data);
int		key_release(int key, t_cub *data);
int		update(t_cub *data);
int		quit(void);
int		clear_pixel(char *s);
char	*join_and_free(char *s1, char *s2);
char	*real_dir(char *cmp, char *line);
void	init_mlx(t_cub *data);
void	mlx_events(t_cub *data);
void	render(t_cub *data);
void	draw_wall(t_cub *data, float distance, float rate, int pixel);
void	init_process(t_cub *data, t_map *map);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	raycast(t_cub *data, float angle, int pixels);
void	init_game(t_cub *data, t_map *map);
t_map	*get_map(int fd);

#endif