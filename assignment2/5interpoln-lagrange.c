#include<stdio.h>

int sample_size;

float lagrng_nth_term(float *x,float *y,int n_index,float x_target){
    float product_numerator =1,product_denominator=1;
    int i;
    for(i=0;i<sample_size;i++){
        if(i!=n_index){
            product_numerator*=(x_target-x[i]);
            product_denominator*=(x[n_index]-x[i]);
        }
    }
    return ((product_numerator/product_denominator)*(y[n_index]));
}

float lagrange(float *x,float *y,float x_target){
    int  i;
    float sum =0;
    for(i=0;i<sample_size;i++){
        sum+=lagrng_nth_term(x,y,i,x_target);
        }
    return sum;
}

int main(){
    //lagranges methord for f(x) = y = x^2+5

    float x[]= {5,6,9,11};
    float y[]= {30,41,86,126};
    sample_size = sizeof(x)/sizeof(float);
    printf("Enter value of x to find interpolated value for given data \n");
    int i;
    for(i=0;i<sample_size;i++){
        printf("x%d = %f, y%d = %f\n",i+1,x[i],i+1,y[i]);
    }
    printf("find value at x = ");
    float x_target;
    scanf("%f",&x_target);
    printf("value at %f is %f",x_target,lagrange(x,y,x_target));

}