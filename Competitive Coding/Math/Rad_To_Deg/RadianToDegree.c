#include <stdio.h>

double ConvertDegToRad(double radian)
{
	double pi = 3.14159;
	return(radian * (180/pi));
}

int main()
{
	double radian;
	scanf("%lf",&radian);
	double degree = ConvertDegToRad(radian);
	printf("%.5lf\n", degree);
	return 0;
}
