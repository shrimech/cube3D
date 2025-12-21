/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:22:41 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/19 16:59:34 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "./minilibx-linux/mlx.h"
# include "parse.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

/*---***	Window	***---*/

# define WIDTH 1000
# define HEIGHT 1000

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




typedef struct s_ray
{
	// 1. The Angle
	double angle; // The angle of THIS specific ray (not the player)

	// 2. Horizontal Intersection Data
	double horz_x;    // The x position where the ray hits a horizontal line
	double horz_y;    // The y position where the ray hits a horizontal line
	double horz_dist; // Distance from player to this point
	int horz_content; // What is in the map at this hit? ('1', '0', etc.)

	// 3. Vertical Intersection Data
	double vert_x;    // The x position where the ray hits a vertical line
	double vert_y;    // The y position where the ray hits a vertical line
	double vert_dist; // Distance from player to this point
	int vert_content; // What is in the map at this hit?

	// 4. The Winner (The Shortest)
	double wall_hit_x; // The final x coordinate of the wall hit
	double wall_hit_y; // The final y coordinate of the wall hit
	double distance;   // The SHORTEST distance (min of horz and vert)
	int was_vertical;  // boolean: true if the vertical wall was closer
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

double			normalize_angle(double angle);
double	distance(double x1, double y1, double x2, double y2);

/*---------------*** Debug ***------------------*/
void			print_map(t_map map, t_camera camera);

#endif
