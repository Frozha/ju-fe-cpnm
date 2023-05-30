#include<stdio.h>

int DIMENSION;

float xnth(int n,float *var,float (*coeff)[DIMENSION],float *constnt){
    float sum_eval = 0;
    int j;
    for(j=0;j<DIMENSION;j++){
        if(j!=n){
            sum_eval +=*(*(coeff+n) + j)*(*(var+j));
        } 
    }
    return  (*(constnt+n)-sum_eval)/(*(*(coeff+n)+n));
}


int exceptioncase(float (*coeff)[DIMENSION]){
    int i,j,exception=0;
    float diag,sum;

    for(i=0;i<DIMENSION&&exception==0;i++){
        diag = *(*(coeff+i)+i);
        sum=0;
        for(j=0;j<DIMENSION;j++){
            sum+=(j!=i)?(*(*(coeff+i)+j)):0;
        }
        exception = (diag<sum)?1:0;
    }
    return exception;
}

float abso(float a){
    return a>0?a:-a;
}

void gauss_sidl(float *var,float (*coeff)[DIMENSION],float *constnt){
    int i,j,iteration =0;
    
    while(abso(xnth(0,var,coeff,constnt)-var[0])>0.001){
        iteration++;
        for(i=0;i<DIMENSION;i++){
            *(var+i) = xnth(i,var,coeff,constnt);
        }
    }

    printf("\nTook %d iterations",iteration);
}

void jacob(float *var,float (*coeff)[DIMENSION],float *constnt){
    int i,j,iteration =0;
    float var_temp[DIMENSION];
    
    for(i=0;i<DIMENSION;i++){
            *(var_temp+i) = xnth(i,var,coeff,constnt);
    }

    while(abso(var_temp[0]-var[0])>0.001){
        iteration++;
        for (i=0;i<DIMENSION;i++){
            *(var+i) = *(var_temp+i);
        }
        for(i=0;i<DIMENSION;i++){
            *(var_temp+i) = xnth(i,var,coeff,constnt);
        }
    }

    for (i=0;i<DIMENSION;i++){
            *(var+i) = *(var_temp+i);
    }

    printf("\nTook %d iterations",iteration);
}


int main(){
    printf("Enter number of variables - ");
    scanf("%d",&DIMENSION);
    float lin_coeff[DIMENSION][DIMENSION], lin_const[DIMENSION];
    
    printf("Enter linear equations in form a1x1+a2x2 .... anxn = bn\n");
    int i,j;
    for(i=0;i<DIMENSION;i++){
        printf("Equation %d\n",i+1);
        for(j=0;j<DIMENSION;j++){
            printf("a%d - ",j+1);
            scanf("%f",&lin_coeff[i][j]);
        }    
        printf("b%d - ",i);
        scanf("%f",&lin_const[i]);    
        }
    
    float var_vals[DIMENSION];
    for(i=0;i<DIMENSION;i++){
        var_vals[i] = 0; 
    }

    int methord =1;
    printf("Enter iterative methord to  be used - \n1.jacobi methord\n2.Gauss-Seidel methord\nChoice(1/2) - ");
    scanf("%d",&methord);
    methord = (exceptioncase(lin_coeff)==1)?0:methord;
    switch (methord)
    {
    case 1:
        jacob(var_vals,lin_coeff,lin_const);
        break;
    
    case 2:
        gauss_sidl(var_vals,lin_coeff,lin_const);
        break;
    case 0:
        printf("The entered equations cannot be solved as it diverges");
    }
    
    printf("\n");
    for(i=0;i<DIMENSION;i++){
        printf("x%d = %f  ",i+1,*(var_vals+i));
    }
}