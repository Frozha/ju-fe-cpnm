#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int size;

float sine(float degrees){
    degrees *=atan(1)*4/180;
    return sin(degrees);
}

float nthcoeff(float n,float p){
    float fact=1,prod=p;
    if(n>0){
        for(n;n>1;n--){
            fact*=n;
            prod*=(p-(n-1));
        }
    }
    else{
        n=-n;
        for(n;n>1;n--){
            fact*=n;
            prod*=(p+(n-1));
        }
    }
    return prod/fact;
}

float* diff_arr(float *target_arr,int sizeoftarget){
    float* resultant_arr = (float*)malloc(sizeof(float)*(sizeoftarget-1));
    int i;
    for(i=0;i<sizeoftarget -1;i++){
        *(resultant_arr+i) = target_arr[i+1]-target_arr[i];
    }
    return resultant_arr;
}

void destroy(void* a[size]){
    int i;
    for(i=1;i<size;i++){
        free(a[i]);
    }
}

float newt(float *x, float *y,float value){
    int i = 0;
    float h = *(x+1)-*x;
    void* y_arr_index[size];
    y_arr_index[0] =y;
    int j;

    for (j=1;j<size;j++){
        y_arr_index[j] = (void*)diff_arr(y_arr_index[j-1],size+1-j);
    }

    while (value > *(x+i)){i++;}

    float result = 0;

    if(i<=(size/2)){
        float p = (value-*(x+i-1))/h;
        result = *(y+i-1);
        for(j=1;j<size-(i-1);j++){
            result += *((float*)y_arr_index[j]+i-1)*nthcoeff(j,p);
        }
    }
    else if (i>size/2){
        float p = (*(x+i)-value)/h;
        result = *(y+i);
        for(j=1;i!=0;i--){
            result +=*((float*)y_arr_index[j]+i-1)*nthcoeff(-j,-p);
            j++;
        }
    }
    destroy(y_arr_index);
    return result;
}

int main(){
    float h = 5;
    size = 37;
    float *x = (float*)malloc(sizeof(float)*size);
    float *y = (float*)malloc(sizeof(float)*size);
    int i;
    for(i=0;i<size;i++){
        *(x+i) = h*i;
        *(y+i) = sine(*(x+i));
    }
    printf("Enter <value> between %0.f and %0.f degrees to find sin<value> \n",*x,*(x+size-1));
    printf("value - ");
    float value;
    scanf("%f",&value);
    printf("sin(%0.1f)(degrees)- %f",value,newt(x,y,value));
    free(x);
    free(y);
}