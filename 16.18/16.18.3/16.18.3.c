//¡¶C Primer Plus¡·p563 16.18.3
#include <stdio.h>
#include <math.h>
#define PI acos(-1)

struct polar
{
	double angle;
	double length;
};

struct rect
{
	double x;
	double y;
};

struct rect polar_to_rect(const struct polar * p);

int main(void)
{
	struct polar point1 = { PI / 3, 2 };
	struct rect point2 = polar_to_rect(&point1);
	printf("%.2f, %.2f", point2.x, point2.y);
	
	return 0;
}

struct rect polar_to_rect(const struct polar * p)
{
	struct rect ret;
	ret.x = p->length * cos(p->angle);
	ret.y = p->length * sin(p->angle);
	
	return ret;
}
