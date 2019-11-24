//¡¶C Primer Plus¡·p101 4.8.6
#include<stdio.h>
#include<string.h>

int main()
{
	char FirstName[40];
	char LastName[40];
	
	int FirstName_length = 0;
	int LastName_length = 0;
	
	printf("ÇëÊäÈëÄúµÄĞÕÃû£º");
	scanf("%s %s", &FirstName, &LastName);
	
	FirstName_length = strlen(FirstName);
	LastName_length = strlen(LastName);
	
	printf("%s %s\n", FirstName, LastName);
	printf("%*d %*d\n", FirstName_length, FirstName_length, LastName_length, LastName_length);
	printf("%s %s\n", FirstName, LastName);
	printf("%-*d %-*d", FirstName_length, FirstName_length, LastName_length, LastName_length);
	
	return 0;
 } 
