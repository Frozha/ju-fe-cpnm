#include <stdio.h>

double f(double x, double y) {
    return x + y;
}

void eulerMethod(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    int count=1;
    printf("x0 = %lf y0 = %lf\n",x,y);

    while (x < xn) {
        y += h * f(x, y);
        x += h;
        printf("x%d = %lf y%d = %lf\n",count,x,count,y);
        count++;
    }
}
void rungeKuttaMethod(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    int count = 1;
    printf("x0 = %lf y0 = %lf\n",x,y);

    while (x < xn) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += h;

        printf("x%d = %lf y%d = %lf\n",count,x,count,y);
        count++;
    }
}
int main() {
    double x0 = 0,y0 = 1,h = 0.02,xn = 0.1;
    printf("finding solutions of dy/dx = x+y in x = %lf to x =%lf",x0,xn);
    printf("\n\n Using eulers methord \n");
    eulerMethod(x0, y0, h, xn);
    printf("\n\n Using range-kutta methord \n");
    rungeKuttaMethod(x0,y0,h,xn);
}