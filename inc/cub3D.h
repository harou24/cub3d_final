/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: haachtch <haachtch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/28 20:22:58 by haachtch      #+#    #+#                 */
/*   Updated: 2020/06/28 20:23:00 by haachtch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libx/mlx.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 32

# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define UP 13
# define C_LEFT 123
# define C_RIGHT 124
# define ESC 53
# define ROTATION_SPEED 0.1
# define MOVE_SPEED 0.2
# define WALL_LIMIT 0.3

# define U_DIV 1
# define V_DIV 1
# define V_MOVE 1.0

typedef struct		s_key {
	int		key_code[7];
	int		key_state[7];
}					t_key;

typedef struct		s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_data;

typedef struct		s_vec2 {
	double	x;
	double	y;
	double	dist;
}					t_vec2;

typedef struct		s_counter {
	int			x;
	int			y;
}					t_counter;

typedef struct		s_sprite {
	t_vec2	pos;
	t_vec2	transform;
	double	inv_det;
	int		width;
	int		sprite_screen_x;
	int		sprite_height;
	int		v_move_screen;
	int		draw_start_x;
	int		draw_start_y;
	int		draw_end_x;
	int		draw_end_y;
	int		stripe;
	int		x;
	int		y;
	int		d;
}					t_sprite;

typedef struct		s_config {
	int			is_set[8];
	int			max_line;
	int			nb_line;
	int			height;
	int			width;
	char		**map;
	int			rgb_ceiling[3];
	int			rgb_floor[3];
	double		pos_x;
	double		pos_y;
	char		direction;
	char		**textures;
	int			nb_sprite;
	t_vec2		*sprites_pos;
}					t_config;

typedef struct		s_texture_data {
	t_data		data;
	int			width;
	int			height;
}					t_texture_data;

typedef struct		s_texture{
	char			*path;
	int				x;
	int				y;
	double			step;
	double			pos;
	t_texture_data	tex;
}					t_texture;

typedef	struct		s_player{
	t_vec2	pos;
	t_vec2	dir;
}					t_player;

typedef struct		s_game {
	t_player	p;
	t_vec2		ray_dir;
	t_vec2		plane;
	t_vec2		side_dist;
	t_vec2		delta_dist;
	double		camera;
	double		perp_wall_dist;
	double		wall_hit;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
}					t_game;

typedef struct		s_window {
	t_key			k;
	void			*mlx;
	void			*win;
	t_game			game;
	t_data			*array;
	int				array_index;
	t_data			*active;
	t_data			*non_active;
	t_config		conf;
	t_texture		*textures;
	t_sprite		sprite;
}					t_window;

void				init_sprite(t_window *w, int index);
void				get_sprites_back(t_config *conf);
void				order_sprites(t_window *w);
unsigned int		get_color(t_window *w);
void				init_game(t_window *w, int current_width);
void				init_player_pos(t_window *w);
void				swap_img(t_window *w);
t_data				*make_more_images(t_window *w);
void				init_texture(t_window *w, t_texture *t, int draw_start);
t_texture			*get_textures(t_window *w);
void				init_each_of_textures_values(t_window *w, int draw_start);
void				game(t_window *w);
int					get_start(t_window *w);
int					get_end(t_window *w);
void				jumpt_to_next_map(t_window *w);
t_config			new_config(void);
void				get_config(char **file, t_config *conf);
int					flood_fill(char **str, int x, int y, int nb_line);
char				**cpy_cube_file(char *argv, t_config *conf, int space);
void				set_resolution(t_config *conf, char *str);
int					is_resolution_line_ok(char *line);
void				print(char **file, int nb_line);
void				set_color(t_config *conf, char *str);
int					is_color_ok(char *line);
int					is_position_in_line(char *line);
int					is_line_valid(char *line);
int					is_map_valid(t_config *conf);
void				print_error(char *s);
void				set_texture(t_config *conf, char *str);
void				set_position(t_config *conf, char *line, int y);
void				set_map(t_config *conf, char *str);
t_config			new_parser(char *argv);
void				get_sprites(t_config *conf);
char				get_line_id(char *line);
void				magic_free(char **file, int nb_line);
void				my_mlx_pixel_put_rgb(unsigned char *addr,
						t_counter write, int line_size,
							unsigned int color);

t_vec2				new_vec2(double x, double y);
int					get_next_line(int fd, char **line);
char				*ft_strnjoin(char *s1, char const *s2, size_t pos);
int					is_next_line(char *buffer);
size_t				pos_next_line(char *buffer);
unsigned int		my_mlx_pixel_read(t_data *data, int x, int y);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					create_trgb(int t, int r, int g, int b);

void				move_camera(t_window *w, double old_dir_x,
						double old_plane_x);
void				move_down(t_window *w);
void				move_up(t_window *w);
void				move_left(t_window *w);
void				move_right(t_window *w);
t_key				init_key();
int					update(t_window *w);
int					key_pressed(int keycode, void *param);
int					key_release(int keycode, void *param);

#endif
