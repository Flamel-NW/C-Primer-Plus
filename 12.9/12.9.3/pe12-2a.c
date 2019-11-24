//°∂C Primer Plus°∑p409 12.9.3
//pe12-2a.c
//”Îpe12-2b.c“ª∆±‡“Î 
#include <stdio.h>
#include "pe12-2a.h"

void set_mode(int * mode)
{
	if (*mode > 1)
	{
		printf("Invalid mode specified. Mode 1(US) used.\n");
		*mode = 1;
	}
}

void get_info(int * mode, int * distance, float * fuel)
{
	switch (*mode)
	{
		case 0:
			printf("Enter distance traveled in kilometers:");
			scanf("%d", distance);
			printf("Enter fuel consumed in liters:");
			scanf("%f", fuel);
			break;
		case 1:
			printf("Enter distance traveled in miles:");
			scanf("%d", distance);
			printf("Enter fuel consumed in gallon:");
			scanf("%f", fuel);
			break;
	}
}

void show_info(int * mode, int * distance, float * fuel)
{
	switch (*mode)
	{
		case 0:
			printf("Fuel consumption is %.2f liters per 100 km.\n", *fuel / (*distance / 100));
			break;
		case 1:
			printf("Fuel consumption is %.2f miles per gallon.\n", *distance / *fuel);
			break;
	}
}
