//°∂C Primer Plus°∑p409 12.9.2
//pe12-2a.c
//”Îpe12-2b.c“ª∆±‡“Î 
#include <stdio.h>
#include "pe12-2a.h"

static int last_mode = 0;
static int distance = 0;
static float fuel = 0;

void set_mode(int mode)
{
	if (mode > 1)
	{
		printf("Invalid mode specified. Mode 1(US) used.\n");
		last_mode = 1;
	}
	else
	{
		last_mode = mode;
	}
}

void get_info(void)
{
	switch (last_mode)
	{
		case 0:
			printf("Enter distance traveled in kilometers:");
			scanf("%d", &distance);
			printf("Enter fuel consumed in liters:");
			scanf("%f", &fuel);
			break;
		case 1:
			printf("Enter distance traveled in miles:");
			scanf("%d", &distance);
			printf("Enter fuel consumed in gallon:");
			scanf("%f", &fuel);
			break;
	}
}

void show_info(void)
{
	switch (last_mode)
	{
		case 0:
			printf("Fuel consumption is %.2f liters per 100 km.\n", fuel / (distance / 100));
			break;
		case 1:
			printf("Fuel consumption is %.2f miles per gallon.\n", distance / fuel);
			break;
	}
}
