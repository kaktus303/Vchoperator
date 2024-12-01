#include<stdio.h>
#include<stdlib.h>
#define n 1000
#define start 0
#define finish 10
double Ai(int i)
{
    return 0;
}
double Bi(int i)
{
    return 0;
}
double Ci(int i)
{
    return 0;
}
double Fi(int i)
{
    return 0;
}
double utoch(double x)
{
    return 0;
}
void x_filling(double *x_points)
{
    double step = (finish - start)/(n-1), x = start;
    x_points[0] = start;
    printf("%.15lf", step);
    for(int i = 1;i < n;++i)
    {
        x+=step;
        x_points[i] = x;
    }
}
int main()
{
    double *k_points = malloc(sizeof(double) * n), *v_points = malloc(sizeof(double)* n), *x_points = malloc(sizeof(double)* n),
        *y_points = malloc(sizeof(double)* n);
    k_points[0] = 0;
    v_points[0] = 0;
    y_points[n-1] = 0;
    for(int i = 1; i < n;++i)
    {
        k_points[i] = - (Bi(i)/(Ci(i) + A(i)* k_points[i-1]));
    }
    for(int i = 1;i<n;++i)
    {
        v_points[i] = -((Ai(i) * v_points[i-1] - Fi(i))/(Ci(i) + Ai(i) * k_points[i-1]));
    }
    for(int i = n-2;i >= 0; --i)
    {
        y_points[i] = k_points[i] * y_points[i+1] + v_points[i];
    }

    return 0;
}