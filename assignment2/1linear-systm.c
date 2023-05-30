/*
program to take input of system of linear equations and find
solution using gauss jordan methord
<A|B> --> reduced row echelon form
|a  b  c|   |1 b/a     c/a   |     |1 0 ...|
|d  e  f|-> |0 e-db/a  f-dc/a| ->  |0 1 ...|
|g  h  i|   |0 h-gb/a  i-gc/a|     |0 0 ...|
or gauss jordan inversion methord
*/

#include<stdio.h>

int DIMENSION;
int AUGM_COL=1;
int EXEP_CASE =0;

void id_matx_init(float (*id_matx)[DIMENSION]){
    int i,j;
    for(i=0;i<DIMENSION;i++){
        for(j=0;j<DIMENSION;j++){
            *(*(id_matx+i)+j) = (i==j)?1:0;
        }
    }
}

void row_transform(float (*coeff_matx)[DIMENSION],int subject_row, int refrence_row, float multiplier,float (*augm_matx)[AUGM_COL]){
    int j;
    if(subject_row!=refrence_row){
        for(j=0;j<AUGM_COL;j++){
            *(*(augm_matx+subject_row)+j)+=*(*(augm_matx+refrence_row)+j)*(multiplier);
        }
        for(j=0;j<DIMENSION;j++){
            *(*(coeff_matx+subject_row)+j)+=*(*(coeff_matx+refrence_row)+j)*(multiplier);
        }
    }
    else{
        for(j=0;j<AUGM_COL;j++){
            *(*(augm_matx+subject_row)+j)*=multiplier;
        }
        for(j=0;j<DIMENSION;j++){
            *(*(coeff_matx+subject_row)+j)*=multiplier;
        }
    }
}

void var_elimination(float (*coeff_matx)[DIMENSION],int subject_row,int subject_col,float (*augm_matx)[AUGM_COL]){
    int solve_bool=*(*(coeff_matx+subject_row)+subject_col)==1?1:0;
    int i;
    EXEP_CASE=((EXEP_CASE==0)&&(*(*(coeff_matx+subject_row)+subject_col)==0))?1:0;
    if((solve_bool!=1)&&(*(*(coeff_matx+subject_row)+subject_col)!=0)){
        row_transform(coeff_matx,subject_row,subject_row,1/(*(*(coeff_matx+subject_row)+subject_col)),augm_matx);
        solve_bool=1;
    }
    if(solve_bool==1&&EXEP_CASE==0){
        for(i=0;i<DIMENSION;i++){
            if(i!=subject_row){
                row_transform(coeff_matx,i,subject_row,*(*(coeff_matx+i)+subject_col)*-1,augm_matx);
            }
        }
    }
}


void gauss_jordan(float (*coeff_matx)[DIMENSION],float (*const_matx)[AUGM_COL]){
    int i;
    for(i=0;i<DIMENSION;i++){
        var_elimination(coeff_matx,i,i,const_matx);
        printmatx(coeff_matx,const_matx);
    }
}

int inverse_matx(float (*coeff_matx)[DIMENSION],float (*id_matx)[DIMENSION]){
    int i;
    for( i=0;i<DIMENSION;i++){
        var_elimination(coeff_matx,i,i,id_matx);
        printmatx(coeff_matx,id_matx);
    }
    return (EXEP_CASE==0)?1:0;
}

void printmatx(float (*coeff_matx)[DIMENSION],float (*augm_matx)[AUGM_COL]){
    printf("\n");
    int i,j;
    for(i=0;i<DIMENSION;i++){
        printf("| ");
        for(j=0;j<DIMENSION+AUGM_COL;j++){
            if(j<DIMENSION){
                printf("%f ",*(*(coeff_matx+i)+j));
            }
            else{printf(" %f ",*(*(augm_matx+i)+j-DIMENSION));}
        }
        printf("| \n");
    }
}

void jord_inv_res(float (*coeff_matx)[DIMENSION],float (*const_matx)[1]){
    float sum=0;
    printf("\n");
    int i,k;
    for(i=0;i<DIMENSION;i++){
        sum =0;
        for(k=0;k<DIMENSION;k++){
            sum+=*(*(coeff_matx+i)+k)*(*(*(const_matx+k)));
        }
        printf("x%d - %f\n",i,sum);
    }
}

void gjresultprint(float (*coeff_matx)[DIMENSION],float (*augm_matx)[AUGM_COL]){
    if(EXEP_CASE==0){
        int i;
        for(i=0;i<DIMENSION;i++){
            printf("x%d = %f\n",i+1,**(augm_matx+i));
        }
    }
    else{
        printf("given set of equations do not have a solution.\nhere is final calculated augmented matrix :-\n");
        printmatx(coeff_matx,augm_matx);
    }
}

int main(){
    int menu=0,i,j;
    printf("Select methord to solve system of linear equation :-\n");
    printf("1. gauss jordan methord\n2. gauss jordan inversion methord\n");
    printf("your choice - ");
    scanf("%d",&menu);
    
    printf("Enter number of variables of system of linear equations - ");
    scanf("%d",&DIMENSION);
    float coeffmatx[DIMENSION][DIMENSION];
    int a_counter=1,b_counter =1;            
    float constmatx[DIMENSION][1];

    printf("Enter coefficients of eqn in form a1x1+a2x2+a3x3 ..... =b1");
    for(i=0;i<DIMENSION;i++){
        printf("\nEquation %d\n",i+1);
        for(j=0;j<DIMENSION;j++){
            printf("a%d = ",a_counter);
            a_counter++;
            scanf("%f",&coeffmatx[i][j]);
        }
        printf("b%d = ",b_counter);
        b_counter++;
        scanf("%f",&constmatx[i][0]);
        a_counter =1;
    }
    switch(menu){
        case 1:
            AUGM_COL=1;
            printmatx(coeffmatx,constmatx);
            gauss_jordan(coeffmatx,constmatx);
            gjresultprint(coeffmatx,constmatx);
            break;
        
        case 2:
            AUGM_COL = DIMENSION;
            float id_matx[DIMENSION][DIMENSION];
            id_matx_init(id_matx);
            printmatx(coeffmatx,id_matx);
            inverse_matx(coeffmatx,id_matx);
            jord_inv_res(id_matx,constmatx);
    }
}