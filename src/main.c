/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:45:49 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/04/14 21:09:52 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
	{
		ft_printf("Incorrect Number of Arguments");
		exit(1);
	}
	parse_input(argv[1], &fdf);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIN_X, WIN_Y, "FdF");
	fdf.pointer_to_image.img = mlx_new_image(fdf.mlx_ptr, WIN_X, WIN_Y);
	fdf.pointer_to_image.addr = mlx_get_data_addr
		(fdf.pointer_to_image.img,
			&fdf.pointer_to_image.bits_per_pixel,
			&fdf.pointer_to_image.line_length,
			&fdf.pointer_to_image.endian);
	fdf.zoom = (int)(30.0 / (sqrt(fdf.data_width) + 1)) + 1;
	draw_line(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr,
		fdf.pointer_to_image.img, 0, 0);
	free_data_img(fdf.data_img, fdf.data_height);
	mlx_hook(fdf.win_ptr, 17, 0, destroy_window, &fdf);
	mlx_key_hook(fdf.win_ptr, esc, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}

void	free_data_img(int **data_img, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(data_img[i]);
		i++;
	}
	free(data_img);
}

int	destroy_window(void *fdf)
{
	t_fdf	*fdf2;

	fdf2 = (t_fdf *)fdf;
	mlx_destroy_image(fdf2->mlx_ptr, fdf2->pointer_to_image.img);
	mlx_destroy_window(fdf2->mlx_ptr, fdf2->win_ptr);
	exit(0);
}

int	esc(int keycode, void *fdf)
{
	(void)fdf;
	if (keycode == 53)
	{
		destroy_window(fdf);
	}
	return (0);
}
