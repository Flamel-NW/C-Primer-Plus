//��C Primer Plus��p101 4.8.8
#include<stdio.h>
#define KM_PER_MILE 1.609
#define LITRE_PER_GALLON 3.785

int main(void)
{
	float driven_distance = 0.0;
	float gas_consumption = 0.0;
	float litre_per_hundred_km = 0.0;
	float mile_per_gallon = 0.0;
	
	printf("�����������е���̣�");
	scanf("%f", &driven_distance);
	printf("�����������������ĵ���������");
	scanf("%f", &gas_consumption);
	
	mile_per_gallon = driven_distance / gas_consumption;
	litre_per_hundred_km = (gas_consumption * LITRE_PER_GALLON) / (driven_distance * KM_PER_MILE / 100); 
	
	printf("��������������Ϊ%.1fӢ��/���أ���%.1f��/100����", mile_per_gallon, litre_per_hundred_km); 
	return 0; 
 } 
