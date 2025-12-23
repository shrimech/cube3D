/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:22:41 by elhaiba ham       #+#    #+#             */
/*   Updated: 2025/12/23 23:08:46 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "./minilibx-linux/mlx.h"
# include "parse.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

/*---***	Window	***---*/

# define WIDTH 1920
# define HEIGHT 1010

/*---***	Math	***---*/
# define PI 3.14159265359
# define FOV 1.047197551
# define STEP_ANGLE 5.45415391e-04
# define MOVE_SPEED 0.5
# define ROT_SPEED 0.03

/*---***	Keys	***---*/
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define KEY_ESC 65307
# define ON_DESTROY 17

/*---***		***---*/
# define BLOCK 30

typedef struct s_wall
{
	double	ray_angle;
	double	corrected_dist;
	double	proj_plane_dist;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	int		x;

}	t_wall;

typedef struct s_ray_step
{
	double		px;
	double		py;
	double		x_step;
	double		y_step;
	double		x_intercept;
	double		y_intercept;
	bool		is_facing_right;
	bool		is_facing_down;
	double		next_x;
	double		next_y;
	double		check;
}				t_ray_step;

typedef struct s_ray
{
	double		angle;
	double		horz_x;
	double		horz_y;
	double		horz_dist;
	double		vert_x;
	double		vert_y;
	double		vert_dist;
	double		wall_hit_x;
	double		wall_hit_y;
	double		distance;
	bool		is_facing_down;
	bool		is_facing_right;
	bool		was_vertical;
}				t_ray;

typedef struct s_image
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_camera
{
	double		pos_x;
	double		pos_y;
	t_tile		player;
	double		view_angle;
	bool		move_fwd;
	bool		move_back;
	bool		truck_left;
	bool		truck_right;
	bool		rotate_left;
	bool		rotate_right;
}				t_camera;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			line_lengh;
	int			endian;
	t_camera	*camera;
	t_map		*map_data;
	char		**map;
	t_image		images[4];
}				t_game;

typedef enum e_texture
{
	T_NORTH,
	T_SOUTH,
	T_WEST,
	T_EAST,
}				t_texture;

typedef struct s_tex_info
{
	double		tex_pos;
	double		step;
	int			tex_x;
}				t_tex_info;

/*---------------***	Core	***------------------*/
t_game			*create_game(void);
t_camera		*init_camera(void);
void			init_graphics(t_game *game);

/*---------------***  phyisics  ***------------------*/
void			calibrate_optics(t_camera *cam);
int				assert_motion(int keycode, t_camera *cam);
int				stop_motion(int keycode, t_camera *cam);
void			apply_motion(t_game *game, t_camera *cam);
void			apply_translation(t_game *game, t_camera *cam,
					double dx, double dy);
int				is_valid_move(t_game *game, double x, double y);
void			compute_motion(t_camera *cam, double *dx, double *dy);
void			update_rotation(t_camera *cam);

/*---------------*** Rasterizer ***------------------*/
void			put_pixel(int x, int y, int color, t_game *game);
int				draw_loop(t_game *game);
void			clear_image(t_game *game);
void			draw_ceiling_floor(t_game *game);
void			render_wall(t_game *game, t_wall wall, t_ray ray);
void			draw_text_y(t_game *game, t_wall wall,
					t_tex_info info, t_texture tex);
t_texture		which_tex(t_ray ray);
t_tex_info		info_tex(t_game *game, t_wall wall, t_ray ray, t_texture tex);
unsigned int	get_tex_color(t_image tex, int x, int y);

/*---------------*** Raycast ***------------------*/
void			cast_ray(t_game *game, double ray_angle, t_ray *ray);
void			check_horizontal(t_game *game, t_ray *ray);
void			check_vertical(t_game *game, t_ray *ray);

/*---------------*** Geometry ***------------------*/
double			normalize_angle(double angle);
int				is_wall(t_game *game, double x, double y);
double			distance(double x1, double y1, double x2, double y2);

void			render_wall(t_game *game, t_wall wall, t_ray ray);
/*---------------*** Debug ***------------------*/
void			print_map(t_map map, t_camera camera);
void			load_images(t_game *game);

#endif
