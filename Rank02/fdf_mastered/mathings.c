/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:10:35 by masoares          #+#    #+#             */
/*   Updated: 2024/03/05 11:29:24 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	 coordinate_converter(t_data *img, t_point **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->map_w)
	{
		x = 0;
		while (x < img->map_l)
		{
			map[y][x].u = x - img->map_l / 2;
			map[y][x].v = y - img->map_w / 2;
			if (y < img->map_w - 1)
			{
				map[y][x].zz = map[y + 1][x].z;
				bresenham_points(map[y][x], x, y + 1, img);
			}
			if (x < img->map_l - 1)
			{
				map[y][x].zz = map[y][x + 1].z;
				bresenham_points(map[y][x], x + 1, y, img);
			}
			x++;
		}
		y++;
	}
}

int	rot_calculator(t_data *img, t_point *map, double *u1, double *v1)
{
	// float	changed_z;
	// float	changed_zz;

	// changed_z = map->z - img->z_changer;
	// changed_zz = map->zz - img->z_changer;
	
	mat_multiplier_z(img, &map->u, &map->v);
	mat_multiplier_z(img, u1, v1);
	mat_multiplier_y(img, &map->u, &(map->z));
	mat_multiplier_y(img, u1, &(map->zz));
	mat_multiplier_x(img, &map->v, &(map->z));
	mat_multiplier_x(img, v1, &(map->zz));
	return (0);
}

void	mat_multiplier_z(t_data *img, double *u, double *v)
{
	double		x;
	double		y;

	x = *u;
	y = *v;
	*u = cos(img->ang_z) * x - sin(img->ang_z) * y;
	*v = sin(img->ang_z) * x + cos(img->ang_z) * y;
}

void	mat_multiplier_y(t_data *img, double *u, double *z)
{
	double	x;

	x = *u;
	*u = cos(img->ang_y) * x + sin(img->ang_y) * (*z);
	*z = -sin(img->ang_y) * x + cos(img->ang_y) * (*z);
}

void	mat_multiplier_x(t_data *img, double *v, double *z)
{
	double	y;

	y = *v;
	if (*z != 0)
	{
		*v = cos(img->ang_x) * y - sin(img->ang_x) * (*z * img->z_changer);
		*z = sin(img->ang_x) * y + cos(img->ang_x) * (*z * img->z_changer);
	}
	else
	{
		*v = cos(img->ang_x) * y - sin(img->ang_x) * (*z);
		*z = sin(img->ang_x) * y + cos(img->ang_x) * (*z);
	}
}


int	rot_calculator2(t_data *img, t_point *map, double *u1, double *v1)
{
	double	latitude;
	double	longitude;
	double	latitude1;
	double	longitude1;
	double	R;
	double	xx;
	double	yy;
	double	zz;
	
	
	R = img->map_l/(6.28); 

	longitude = (map->u)/ R;
	latitude = 2 *atan(exp(map->v/(R))) - 3.14/2;
	longitude1 = (*u1)/ R;
	latitude1 = 2 *atan(exp(*v1/(R))) - 3.14/2;
	
	map->y = (R + map->z/5)* cos(latitude) *cos(longitude);
	map->x = (R + map->z/5) * cos(latitude) *sin(longitude);
	map->z = (R + map->z/5) * sin(latitude);
	map->u = map->x;
	map->v = map->y;
	yy = (R + map->zz/5)* cos(latitude1) *cos(longitude1);
	xx = (R + map->zz/5) * cos(latitude1) *sin(longitude1);
	zz = (R + map->zz/5)* sin(latitude1);
	*u1 = xx;
	*v1= yy;
	mat_multiplier_z(img, &map->u, &map->v);
	mat_multiplier_z(img, u1, v1);
	mat_multiplier_y(img, &map->u, &(map->z));
	mat_multiplier_y(img, u1, &(zz));
	mat_multiplier_x(img, &map->v, &(map->z));
	mat_multiplier_x(img, v1, &(zz));
	
	return (0);
}

int	rot_calculator_mega(t_data *img, t_point *map, double *u1, double *v1, double *z1)
{
	double	latitude;
	double	longitude;
	double	R;
	double	xx;
	double	yy;
	double	zz;
	
	R = img->map_l/(6.28); 
	longitude = (*u1)/ (R);
	latitude = 2 *atan(exp(*v1/(R))) - 3.14/2;
	yy = (R + *z1/5)* cos(latitude) *cos(longitude);
	xx = (R + *z1/5) * cos(latitude) *sin(longitude);
	zz = (R + *z1/5) * sin(latitude);
	map->u = xx;
	map->v = yy;
	map->z = zz;
	mat_multiplier_z(img, &map->u, &map->v);
	mat_multiplier_y(img, &map->u, &(map->z));
	mat_multiplier_x(img, &map->v, &(map->z));
	
	return (0);
}