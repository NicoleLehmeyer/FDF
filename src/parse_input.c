/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:27:57 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/05/26 17:12:36 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Read file, check if it exists, open file
// Find size and malloc for 2D array of ints
// Convert char to ints & assign to array
void	parse_input(const char *file, t_fdf *fdf)
{
	int		fd;
	int		y;
	int		x;
	char	**char_value;
	char	*line;

	y = 0;
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		ft_error("Open file error");
	fdf->data_height = find_height(file);
	fdf->data_width = find_width(file);
	fdf->data_img = malloc_data_img(fdf);
	while (y < fdf->data_height)
	{
		x = 0;
		line = get_next_line(fd);
		char_value = ft_split(line, ' ');
		parse_assist(fdf, y, x, char_value);
		free(line);
		free(char_value);
		y++;
	}
}

int	**malloc_data_img(t_fdf *fdf)
{
	int	i;
	int	**data_img;

	i = 0;
	data_img = (int **)malloc(sizeof(int **) * (fdf->data_height + 1));
	if (data_img == NULL)
	{
		ft_error("Malloc err - malloc_data_img");
		return (NULL);
	}
	while (i < fdf->data_height)
	{
		data_img[i] = (int *)malloc(sizeof(int *) * (fdf->data_width + 1));
		i++;
	}
	data_img[fdf->data_height] = NULL;
	return (data_img);
}

int	find_height(const char *file)
{
	int		height;
	int		fd;
	char	*gnl_return;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	height = 1;
	gnl_return = get_next_line(fd);
	if (!gnl_return)
		return (0);
	while (gnl_return)
	{
		free(gnl_return);
		height++;
		gnl_return = get_next_line(fd);
	}
	close(fd);
	free(gnl_return);
	return (height - 1);
}

int	find_width(const char *file)
{
	int		width;
	int		fd;
	char	*gnl_return;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	width = 0;
	gnl_return = get_next_line(fd);
	width = totalwordindest_fdf(gnl_return, ' ');
	close(fd);
	free(gnl_return);
	return (width);
}

void	parse_assist(t_fdf *fdf, int y, int x, char **char_value)
{
	while (x < fdf->data_width)
	{
		fdf->data_img[y][x] = ft_atoi(char_value[x]);
		free(char_value[x]);
		x++;
	}
}
