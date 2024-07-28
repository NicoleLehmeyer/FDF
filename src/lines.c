/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:52:59 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/04/19 11:53:01 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Put pixel to image
void	my_pp(t_fdf *fdf, int x, int y, int colour)
{
	char	*dst;

	dst = NULL;
	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y)
		return ;
	dst = fdf->pointer_to_image.addr + (y * fdf->pointer_to_image.line_length
			+ x * (fdf->pointer_to_image.bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

// SET P3 - Calculates direction of line, to get p3.x&y_steps
void	set_p3(t_vector p1, t_vector p2, t_vector *p3)
{
	p3->x_steps = p2.x - p1.x;
	p3->y_steps = p2.y - p1.y;
	p3->max = find_max(pos_conv(p3->x_steps), pos_conv(p3->y_steps));
	p3->x_steps = p3->x_steps / p3->max;
	p3->y_steps = p3->y_steps / p3->max;
}

void	iso_project(float *x, float *y, int z, t_fdf *fdf)
{
	int	converted_x;

	converted_x = *x;
	*x = (*x * 0.5 * fdf->zoom) - (*y * 0.5 * fdf->zoom);
	*y = ((converted_x * 0.25 * fdf->zoom)
			+ (*y * 0.25 * fdf->zoom)) - z;
}

//BRESENHAM:
// Bresenham's line algorithm is used to draw lines on a raster
	// grid (pixel grid), intaking two points, and determining
	// the placement of each pixel between them
// p3 is the line we are drawing. p1 and p2 are the points
	// according to data in t_data *fdf struct
// These two points are assigned to p3.z1&z2
// We scale the coordinates of p1&p2 by the zoom. Otherwise,
	// they will be a pixel apart
	// and we would just see a small concentrated cluster of pixels
// COLOUR - NON-ESSENTIAL AS PER SUBJECT GUIDELINES
// We call the iso_project function which converts the 2D coordinates to a
// 3D isometric projection, as per subject guidelines
// This uses trigonometry - once I understood it, but no, I can't and won't now.
	// Google it - there's a formula :)
// We offset the image by 500 pixels so it's not just
	// chilling in the top left corner
// Set p3
// While loop - calling my_pp (my pixel put) function to put
	// each pixel down, incrementing
	// the coordinates until we hit the end of the line
void	bresenham(t_vector p1, t_vector p2, t_fdf *fdf)
{
	t_vector	p3;

	p3.x_steps = 0.0;
	p3.y_steps = 0.0;
	p3.z1 = fdf->data_img[(int)p1.y][(int)p1.x];
	p3.z2 = fdf->data_img[(int)p2.y][(int)p2.x];
	p1.x = p1.x * fdf->zoom;
	p1.y = p1.y * fdf->zoom;
	p2.x = p2.x * fdf->zoom;
	p2.y = p2.y * fdf->zoom;
	fdf->colour = colour(p3.z1, p3.z2);
	iso_project(&p1.x, &p1.y, p3.z1, fdf);
	iso_project(&p2.x, &p2.y, p3.z2, fdf);
	p1.x = p1.x + 500;
	p1.y = p1.y + 500;
	p2.x = p2.x + 500;
	p2.y = p2.y + 500;
	set_p3(p1, p2, &p3);
	while ((int)(p1.x - p2.x) != 0 || (int)(p1.y - p2.y) != 0)
	{
		my_pp(fdf, p1.x, p1.y, fdf->colour);
		p1.x = p1.x + p3.x_steps;
		p1.y = p1.y + p3.y_steps;
	}
}

// Draw lines between all points in array
void	draw_line(t_fdf *fdf)
{
	t_vector	p1;
	t_vector	p2;

	p1 = (t_vector){0.0, 0.0, 0.0, 0.0, 0, 0, 0};
	p1.y = 0;
	while (p1.y < fdf->data_height)
	{
		p1.x = 0;
		while (p1.x < fdf->data_width)
		{
			p2 = p1;
			if (p1.x + 1 < fdf->data_width)
				p2.x++;
			bresenham(p1, p2, fdf);
			if (p1.y + 1 < fdf->data_height)
			{
				p2.x = p1.x;
				p2.y++;
			}
			bresenham(p1, p2, fdf);
			p1.x++;
		}
		p1.y++;
	}
}
