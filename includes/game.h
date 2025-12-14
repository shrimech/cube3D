/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhaiba hamza <ehamza@student.1337.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:22:41 by elhaiba hamza     #+#    #+#             */
/*   Updated: 2025/12/14 02:43:05 by elhaiba hamza    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>

# define WIDTH 720.0
# define HEIGHT 720.0
# define PI 3.14159265359

# define KEY_W 119
# define KEY_S 97
# define KEY_A 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_camera
{
	double		pos_x;
	double		pos_y;
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
	t_camera	camera;
	char		**map;
}				t_game;



/*---------------***	Core	***------------------*/
void			init_game(t_game *game);

/*---------------***  phyisics  ***------------------*/
void			calibrate_optics(t_camera *cam);
int				assert_motion(int keycode, t_camera *cam);
int				stop_motion(int keycode, t_camera *cam);
void			apply_motion(t_camera *cam);

/*---------------*** Rasterizer ***------------------*/
void	put_pixel(int x, int y, int color, t_game *game);
void	draw_square(int x, int y, int size, int color, t_game *game);
#endif
