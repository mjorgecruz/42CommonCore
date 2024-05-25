/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:45:46 by masoares          #+#    #+#             */
/*   Updated: 2024/03/05 11:29:41 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	bresenham_points(t_point map, double u1, double v1, t_data *img)
{
	rot_calculator2(img, &map, &u1, &v1);
	map.u *= img->zoom;
	map.v *= img->zoom;
	u1 *= img->zoom;
	v1 *= img->zoom;
	map.u += ((1980 / 2) - (img->map_w / 2)) + img->trans_u * sqrt(img->zoom);
	map.v += ((1080 / 2) - (img->map_l / 2)) + img->trans_v * sqrt(img->zoom);
	u1 += ((1980 / 2) - (img->map_w / 2)) + img->trans_u * sqrt(img->zoom);
	v1 += ((1080 / 2) - (img->map_l / 2)) + img->trans_v * sqrt(img->zoom);
	pixel_put(img, map.u, map.v, map.color);
	return (1);
}

int	max_finder(double varu, double varv)
{
	if (varu < 0)
		varu *= (-1);
	if (varv < 0)
		varv *= (-1);
	if (varu < varv) 
		return (varv);
	else
		return (varu);
}

int	bresenham_x(t_point map, double u1, double v1, t_data *img)
{
	// (void) u1;
	// (void) v1;
	
	double 	du;
	double	dv;
	double 	dz;
	double	pu;
	double	pv;
	double	pz;
	int		u;
	int		v;
	du = (u1 - map.u)/(1000);
	dv = (v1- map.v)*(img->map_l/img->map_w)/(100);
	dz = (map.zz - map.z)/(100);
	pu = map.u;
	pv = map.v;
	pz = map.z;
	while ( (int) pu - u1 < 0)
	{
		rot_calculator2(img, &map, &pu, &pv);
		u = map.u * img->zoom;
		v = map.v * img->zoom;
		u = u + ((1980 / 2) - (img->map_w / 2)) + img->trans_u * sqrt(img->zoom);
		v = v + ((1080 / 2) - (img->map_l / 2)) + img->trans_v * sqrt(img->zoom);
		pixel_put(img, u, v, map.color);
		pu += du;
		pv += dv;
		pz += dz;
	}
	return (1);
}

int	bresenham_y(t_point map, double u1, double v1, t_data *img)
{
	(void) u1;
	double 	du;
	double	dv;
	double 	dz;
	double	pu;
	double	pv;
	double	pz;
	double	u;
	double	v;
	du = 0;
	dv = (v1 - map.v)/(10 * img->zoom);
	dz = (map.zz -map.z)/(10 * img->zoom);
	pu = map.u;
	pv = map.v;
	pz = map.z;
	while ((int) pv < (int) v1)
	{
		rot_calculator_mega(img, &map, &pu, &pv, &pz);
		u = map.u * img->zoom;
		v = map.v * img->zoom;
		u = u + ((1980 / 2) - (img->map_w / 2)) + img->trans_u * sqrt(img->zoom);
		v = v + ((1080 / 2) - (img->map_l / 2)) + img->trans_v * sqrt(img->zoom);
		pixel_put(img, u, v, map.color);
		pu += du;
		pv += dv;
		pz += dz;
	}
	return (0);
}

int	bresenham_original(t_point map, double u1, double v1, t_data *img)
{
	double	varu;
	double	varv;
	int		max;

	rot_calculator(img, &map, &u1, &v1);
	map.u *= img->zoom;
	map.v *= img->zoom;
	u1 *= img->zoom;
	v1 *= img->zoom;
	map.u += ((1980 / 2) - (img->map_w / 2)) + img->trans_u * sqrt(img->zoom);
	map.v += ((1080 / 2) - (img->map_l / 2)) + img->trans_v * sqrt(img->zoom);
	u1 += ((1980 / 2) - (img->map_w / 2)) + img->trans_u * sqrt(img->zoom);
	v1 += ((1080 / 2) - (img->map_l / 2)) + img->trans_v * sqrt(img->zoom);
	varu = u1 - map.u;
	varv = v1 - map.v;
	max = max_finder(varu, varv);
	varu /= max;
	varv /= max;
	while ((int)(map.u - u1) || (int)(map.v - v1))
	{
		pixel_put(img, map.u, map.v, map.color);
		map.u += varu;
		map.v += varv;
	}
	return (1);
}
