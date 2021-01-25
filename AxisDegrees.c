/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AxisDegrees.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 10:38:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/01/25 12:32:11 by pspijkst      ########   odam.nl         */
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

t_vector3	v3_abs(t_vector3 vector3)
{
	if (vector3.x < 0)
		vector3.x *= -1;
	if (vector3.y < 0)
		vector3.y *= -1;
	if (vector3.z < 0)
		vector3.z *= -1;
	return (vector3);
}

double	v3_scalar(t_vector3 vect)
{
	return (vect.x + vect.y + vect.z);
}

double	v3_magnitude(t_vector3 vector3)
{
	vector3 = v3_abs(vector3);
	return (sqrt(pow(vector3.x, 2) + pow(vector3.y, 2) + pow(vector3.z, 2)));
}

double	rad_to_deg(double rad)
{
	return (rad * (180 / PI));
}

double	v3_angle_axis(t_vector3 vector3, t_axis axis)
{
	return (rad_to_deg(acos(((double*)&vector3)[axis] / v3_magnitude(vector3))));
}

double	v3_angle(t_vector3 vect)
{
	return (rad_to_deg(acos(v3_scalar(vect) / v3_magnitude(vect))));
}

t_vector3	v3_multiply(t_vector3 vect1, t_vector3 vect2)
{
	vect1.x *= vect2.x;
	vect1.y *= vect2.y;
	vect1.z *= vect2.z;
	return (vect1);
}

double	v3_angle_v3(t_vector3 vect1, t_vector3 vect2)
{
	double	scalarmult;
	double	magnmult;

	scalarmult = v3_scalar(v3_multiply(vect1, vect2));
	magnmult = v3_magnitude(vect1) * v3_magnitude(vect2);
	return (rad_to_deg(acos(scalarmult / magnmult)));
}

void	printv3(t_vector3 vect)
{
	printf("Vector3: %f, %f, %f\n", vect.x, vect.y, vect.z);
}

t_vector3	v3_init(double x, double y, double z)
{
	t_vector3	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

int		main(void)
{
	t_vector3	vect1;
	t_vector3	vect2;
	t_vector3	vectres;

	vect1 = v3_init(1, -2, 3);
	vect2 = v3_init(4, -2, 3);
	printf("Vect1 > vect2 angle: %f\n", v3_angle_v3(vect1, vect2));
	printf("Vect1 local angle: %f\n", v3_angle(vect1));
	printf("X<: %f\n", v3_angle_axis(vect1, axis_x));
	printf("Y<: %f\n", v3_angle_axis(vect1, axis_y));
	printf("Z<: %f\n", v3_angle_axis(vect1, axis_z));
	vectres = v3_multiply(vect1, vect2);
	printv3(vectres);
}
