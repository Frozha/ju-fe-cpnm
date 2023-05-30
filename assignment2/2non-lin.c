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
void c(double *a, double *b){
        if(f((*a+*b)/2)*f(*a)<0){
                *b=(*a+*b)/2;
        }
        else{
                *a=((*a+*b)/2);
        }
        printf("a - %lf\tb - %lf\n",*a,*b);
}
double bisection(double *a,double *b){
        double prev_a = *a,prev_b = *b;
        c(a,b);
        for(;abslt(prev_a-*a)>0.001||abslt(prev_b-*b)>0.001;){
                prev_a = *a;
                prev_b = *b;
                c(a,b);
        }
        return (prev_a-*a>0.001)?*b:*a;
}

int main(){
        int methord = 0;
        printf("Enter methord to solve f(x) = x^3-x^2+1\n");
        printf("1. Newton Ralphson\n2.Bisection\nYour choice (1/2) - ");
        scanf("%d",&methord);
        double root;
        switch(methord){
                case 1:
                        printf("Enter starting x0 for eqn - ");
                        double x = 0;
                        scanf("%lf",&x);
                        root = nwt_rphson(x,0.001);
                        printf("root is  = %lf\n",root);
                        break;
                case 2:
                        printf("Enter range\n From - ");
                        double a,b;
                        scanf("%lf",&a);
                        printf(" To - ");
                        scanf("%lf",&b);
                        if (f(a)*f(b)<0){
                                root = bisection(&a,&b);
                                printf("root is  = %lf\n",root);
                        }
                        else{printf("no root in range");}
                        


        }
        
}