#include<stdio.h>

double f(double x){
        //f(x) = x^3-x^2+1
        return (x*x*x) -(x*x) +1;
}

double derivf(double x){
        //f'(x)=3*x^2-2*x
        return (3*x*x)-(2*x);
}

double x1(double x0){
        return (x0-(f(x0)/derivf(x0)));
}

double abslt(double a){
        return (a>0)?a:(-1*a);
}

double nwt_rphson(double x0,double accur){
        //X1 = X0 -(F(X0)/F'(X0))
        double prev=x0,next=x1(x0);
        int i=0;
        printf("x%d = %lf ,x%d = %lf \n",i,prev,i+1,next);
        while((abslt(next-prev))>(abslt(accur))){
                prev = next;
                i++;
                next = x1(prev);
                printf("x%d = %lf ,x%d = %lf \n",i,prev,i+1,next);
        }
           return next;
}

int main(){
        printf("Enter starting x0 for eqn f(x)=x^3-x^2+1\nx0 - ");
        double acc,x = 0,root=69;
        scanf("%lf",&x);
        printf("Enter the accuracy of root - ");
        scanf("%lf",&acc);
        root = nwt_rphson(x,acc);
        printf("root is  = %lf\n",root);
}