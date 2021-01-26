/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vectors.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 10:38:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/01/26 11:35:38 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

typedef enum	e_axis
{
	axis_x,
	axis_y,
	axis_z
}				t_axis;

typedef struct	s_vector3
{
	double	x;
	double	y;
	double	z;
}				t_vector3;

/*
**	Returns an absolute duplicate of vect.
*/
t_vector3	v3_abs(t_vector3 vect)
{
	if (vect.x < 0)
		vect.x *= -1;
	if (vect.y < 0)
		vect.y *= -1;
	if (vect.z < 0)
		vect.z *= -1;
	return (vect);
}

/*
**	Returns the scalar of vect. (i.e. coordinates combined)
*/
double	v3_scalar(t_vector3 vect)
{
	return (vect.x + vect.y + vect.z);
}

/*
**	Returns the magnitude of vect.
*/
double	v3_magnitude(t_vector3 vect)
{
	vect = v3_abs(vect);
	return (sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2)));
}

/*
**	Returns rad converted to degrees.
*/
double	rad_to_deg(double rad)
{
	return (rad * (180 / PI));
}

/*
**	Returns the angle of a single axis of vect, compared to origin (0,0,0).
*/
double	v3_angle_axis(t_vector3 vect, t_axis axis)
{
	return (rad_to_deg(acos(((double*)&vect)[axis] / v3_magnitude(vect))));
}

/*
**	Returns the angle (degrees) of vect compared to origin (0,0,0).
*/
double	v3_angle(t_vector3 vect)
{
	return (rad_to_deg(acos(v3_scalar(vect) / v3_magnitude(vect))));
}

/*
**	Returns the scaled value (multiply a by b) of 2 vectors.
*/
t_vector3	v3_scale(t_vector3 vect_a, t_vector3 vect_b)
{
	vect_a.x *= vect_b.x;
	vect_a.y *= vect_b.y;
	vect_a.z *= vect_b.z;
	return (vect_a);
}

/*
**	Returns the dot product of vect_a and vect_b
**	The dot product represents the angle between the 2 vectors.
*/
double		v3_dot(t_vector3 vect_a, t_vector3 vect_b)
{
	double	scalarmult;
	double	magnmult;

	scalarmult = v3_scalar(v3_scale(vect_a, vect_b));
	magnmult = v3_magnitude(vect_a) * v3_magnitude(vect_b);
	return (rad_to_deg(acos(scalarmult / magnmult)));
}

/*
**	<--- Not implemented yet! --->
**	Returns a vector representing 3 angles, over x,y,z axis respectively.
*/
t_vector3	v3_angles_v3(t_vector3 vect_a, t_vector3 vect_b)
{
}

/*
**	Returns the cross product of 2 vectors.
*/
t_vector3	v3_cross(t_vector3 vect_a, t_vector3 vect_b)
{
	t_vector3	cross;

	cross.x = (vect_a.y * vect_b.z) - (vect_a.z * vect_b.y);
	cross.y = -((vect_a.x * vect_b.z) - vect_a.z * vect_b.x);
	cross.z = (vect_a.x * vect_b.y) - (vect_a.y * vect_b.x);
	return (cross);
}

/*
**	Returns a t_vector3 with doubles x, y, z values.
*/
t_vector3	v3_init(double x, double y, double z)
{
	t_vector3	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

void	printv3(t_vector3 vect)
{
	printf("Vector3: %f, %f, %f\n", vect.x, vect.y, vect.z);
}

int		main(void)
{
	t_vector3	vect_a;
	t_vector3	vect_b;
	t_vector3	vectres;

	vect_a = v3_init(1, 2, 3);
	vect_b = v3_init(4, 5, 6);
	vectres = v3_cross(vect_a, vect_b);
	printv3(vectres);
	printf("vecta vectb dot: %f\n", v3_dot(vect_a, vect_b));
	printf("vecta angle: %f\n", v3_angle(vect_a));
	printf("X<: %f\n", v3_angle_axis(vect_a, axis_x));
	printf("Y<: %f\n", v3_angle_axis(vect_a, axis_y));
	printf("Z<: %f\n", v3_angle_axis(vect_a, axis_z));
	vectres = v3_scale(vect_a, vect_b);
	printv3(vectres);
}
