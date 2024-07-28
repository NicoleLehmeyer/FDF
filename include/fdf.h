/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:47:00 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/04/10 12:47:01 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "LIBFT/include/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include "minilibx_macos/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef WIN_X
#  define WIN_X 1000
# endif

# ifndef WIN_Y
#  define WIN_Y 1000
# endif

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**data_img;			//Holds parsed map - 2D array of integers
	int		data_width;			//Width of **data_img
	int		data_height;		//Height of **data_img
	int		zoom;				//Data for projection
	int		colour;				
	t_image	pointer_to_image;	//Pointer to t_image
	void	*param;
}				t_fdf;

typedef struct s_vector
{
	float	x;
	float	y;
	float	x_steps;
	float	y_steps;
	int		max;				//Max of x_steps and y_steps (determines which direction for next pixel)
	int		z1;
	int		z2;
}				t_vector;

int		main(int argc, char **argv);
void	free_data_img(int **data_img, int height);
int		destroy_window(void *fdf);
int		esc(int keycode, void *fdf);

void	my_pp(t_fdf *fdf, int x, int y, int colour);
void	set_p3(t_vector p1, t_vector p2, t_vector *p3);
void	bresenham(t_vector p1, t_vector pix2, t_fdf *fdf);
void	iso_project(float *x, float *y, int z, t_fdf *fdf);
void	draw_line(t_fdf *fdf);

void	parse_assist(t_fdf *fdf, int y, int x, char **char_value);
int		find_height(const char *file);
int		find_width(const char *file);
void	parse_input(const char *file, t_fdf *fdf);
int		**malloc_data_img(t_fdf *fdf);

int		totalwordindest_fdf(char const *s, char c);
int		pos_conv(int a);
int		find_max(int a, int b);
int		colour(int a, int b);
void	ft_error(char *error_msg);

#endif