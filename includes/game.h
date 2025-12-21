/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:22:41 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/21 20:14:48 by elhaiba hamza    ###   ########.fr       */
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
# define FOV 1.0471975512
# define MOVE_SPEED 0.05
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

typedef struct s_ray_step
{
    double  px;
    double  py;
    double  x_step;
    double  y_step;
    double  x_intercept;
    double  y_intercept;
    bool    is_facing_right;
    bool    is_facing_down;
    double  next_x;
    double  next_y;
    double  check;
}   t_ray_step;

typedef struct s_ray
{
	double		angle;
	double		horz_x;
	double		horz_y;
	double		horz_dist;
	int			horz_content;
	double		vert_x;
	double		vert_y;
	double		vert_dist;
	bool		vert_content;
	double		wall_hit_x;
	double		wall_hit_y;
	double		distance;
	bool		was_vertical;
}				t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			line_lengh;
	int			endian;
	t_camera	camera;
	t_map		hole_map;
	char		**map;
}				t_game;

/*---------------***	Core	***------------------*/
void			init_game(t_game *game);

/*---------------***  phyisics  ***------------------*/
void			calibrate_optics(t_camera *cam);
int				assert_motion(int keycode, t_camera *cam);
int				stop_motion(int keycode, t_camera *cam);
void			apply_motion(t_game *game, t_camera *cam);

/*---------------*** Rasterizer ***------------------*/
void			put_pixel(int x, int y, int color, t_game *game);
void			draw_square(int x, int y, int size, int color, t_game *game);
int				draw_loop(t_game *game);
void			clear_image(t_game *game);
void			draw_line(int x0, int y0, int x1, int y1, int color,
					t_game *game);

/*---------------*** Geometry ***------------------*/
double			normalize_angle(double angle);
double			distance(double x1, double y1, double x2, double y2);

/*---------------*** Debug ***------------------*/
void			print_map(t_map map, t_camera camera);

#endif
