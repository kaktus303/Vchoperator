#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define n 1000
#define start 2.0
#define finish 5.0
double Ai(int i, double *x_points, double step)
{
    return ((x_points[i])/(step*step) - (1/(x_points[i])));
}
double Bi(int i, double *x_points, double step)
{
    return ((x_points[i])/(step*step) + (1/(x_points[i])));
}
double Ci(int i, double *x_points, double step)
{
    return (-(2*(x_points[i])/(step*step)) - (x_points[i]));
}
double Fi(int i, double *x_points, double step)
{
    return 0;
}
double utoch(double x)
{
    return (1.0/x) * exp(x);
}
double utoch_der(double x)
{
    return (1.0/x)*exp(x) - (1.0/(x*x))*exp(x);
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
void file_write(FILE *file_graph, double *points_x, double *points_y)
{
    for (int i = 0; i < n; ++i)
    {
        fprintf(file_graph, "%.15lf %.15lf\n", points_x[i], points_y[i]);
    }
}
int main()
{
    FILE *f = fopen("test.txt", "w");
    // FILE *answer = fopen("answer.txt", "w");
    double *k_points = malloc(sizeof(double) * n), *v_points = malloc(sizeof(double)* n), *x_points = malloc(sizeof(double)* n),
        *y_points = malloc(sizeof(double)* n);
    double step = (finish - start)/(n-1);
    x_filling(x_points);
    k_points[0] = 1;
    v_points[0] = step * utoch_der(x_points[1]);
    y_points[n-1] = utoch(x_points[n-1]);
    for(int i = 1; i < n;++i)
    {
        k_points[i] = - (Bi(i, x_points, step)/(Ci(i, x_points, step) + Ai(i, x_points, step)* k_points[i-1]));
    }
    for(int i = 1;i<n;++i)
    {
        v_points[i] = -((Ai(i, x_points, step) * v_points[i-1] - Fi(i, x_points, step))/(Ci(i, x_points, step) + Ai(i, x_points, step) * k_points[i-1]));
    }
    for(int i = n-2;i >= 0; --i)
    {
        y_points[i] = k_points[i] * y_points[i+1] + v_points[i];
    }
    file_write(f, x_points, y_points);
    return 0;
}