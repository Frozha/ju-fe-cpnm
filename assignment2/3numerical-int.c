#include<stdio.h>

double f(double x){return x*x+5;}
double trapezoidal(double startofrange, double endofrange){
    double h = 0.25;
    int n =(int)(endofrange - startofrange)/h;
    double sum=(h/2)*((f(startofrange))+(f(endofrange)));
    int i;
    for (i=1;i<n;i++){
        sum+=h*(f(startofrange+h*i));
    }
    return sum;
}
double simpsons(double startofrange, double endofrange){
    double h = 0.25;
    int n =(int)(endofrange - startofrange)/h;
    double sum=(h/3)*((f(startofrange))+(f(endofrange)));
    int i;
    for (i=1;i<n;i+=2){
        sum+=4*h*(f(startofrange+h*i))/3;
    }
    for (i=2;i<n;i+=2){
        sum+=2*h*(f(startofrange+h*i))/3;
    }

    return sum;
}
int main(){
    printf("Enter range to find area of x^2+5\nFrom - ");
    double start,finish;
    scanf("%lf",&start);
    printf("To - ");
    scanf("%lf",&finish);
    printf("AREA (trapezoidal)=  %lf\n",trapezoidal(start,finish));
    printf("AREA (simpsons)=  %lf",simpsons(start,finish));
}