#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

const
// границы интервала	
	double a = 0;
	double b = 1;
// начальное условие для ДУ
	double y_nu = 1;
// начальные условия для системы ДУ
	double ys_nu = 1;
	double zs_nu = 2;


double dy(double x1, double y1)
{
	return x1*pow(y1,3)-y1;
}

double f(double x1, double y1, double z1)
{
	return (z1-y1)*x1;
}

double g(double x1, double y1, double z1)
{
	return (z1+y1)*x1;
}


int main()
{
	setlocale(LC_ALL, "russian");
	int n;
	double h;
	int i;
	double k[4];
	double l[4];
	double ty, tz;
	
	printf(" Лабораторная работа №5 \n");
	printf(" Решение дифференциальных уравнений \n");
	printf(" Введите количество отрезков n: ");
	scanf("%d",&n);
	h = (b-a)/n;
	printf(" h = %lf \n",h);
	double *x = new double [n+1];
	double *y = new double [n+1];
	double *z = new double [n+1];
	double x_el, y_el;


	printf("\n Уравнение y' = xy^3-y   y(0)=1   [0, 1] \n");
	printf(" Первый улучшенный метод Эйлера \n\n");

	for(i=0;i<=n;i++)
	{
		x[i] = a +i*h;
	}
	
	y[0] = y_nu;
	for(i=1;i<=n;i++)
	{
		x_el = x[i-1]+h/2;
		y_el = y[i-1]+h/2*dy(x[i-1],y[i-1]);
		ty = dy(x_el,y_el);
		y[i] = y[i-1]+h*ty;
	}
	printf(" Решение дифференциального уравнения: \n");
	printf("     x         y    \n");
	for(i=0;i<=n;i++)
	{
		printf(" %-8.4lf  %-8.4lf \n",x[i],y[i]);
	}

	printf("\n\n Решение системы дифференциальных уравнений \n");
	printf(" y' = (z-y)x   \n");
	printf(" z' = (z+y)x   \n");
	printf(" y(0)=0   z(0)=1   [0, 1] \n");
	printf(" Метод Рунге-Кутты 4-го порядка \n\n");

	y[0] = ys_nu;
	z[0] = zs_nu;

    for (i=1;i<=n;i++)
    {
    	k[0] = f(x[i-1],y[i-1],z[i-1])*h;
    	l[0] = g(x[i-1],y[i-1],z[i-1])*h;

    	k[1] = f(x[i-1]+h/2,y[i-1]+k[0]/2,z[i-1]+l[0]/2)*h;
    	l[1] = g(x[i-1]+h/2,y[i-1]+k[0]/2,z[i-1]+l[0]/2)*h;

    	k[2] = f(x[i-1]+h/2,y[i-1]+k[1]/2,z[i-1]+l[1]/2)*h;
    	l[2] = g(x[i-1]+h/2,y[i-1]+k[1]/2,z[i-1]+l[1]/2)*h;

    	k[3] = f(x[i-1]+h,y[i-1]+k[2],z[i-1]+l[2])*h;
    	l[3] = g(x[i-1]+h,y[i-1]+k[2],z[i-1]+l[2])*h;

	    ty = (k[0]+2*k[1]+2*k[2]+k[3])/6;
	    tz = (k[0]+2*k[1]+2*k[2]+k[3])/6;

	    y[i] = y[i-1] + ty;
	    z[i] = z[i-1] + tz;
	}

	printf(" Решение системы дифференциальных уравнений: \n");
	printf("     x         y        z    \n");
	for(i=0;i<=n;i++)
	{
		printf(" %-8.4lf  %-8.4lf  %-8.4lf \n",x[i],y[i],z[i]);
	}

	delete [] x;
	delete [] y;
	delete [] z;
	getch();
	return 0;
}

