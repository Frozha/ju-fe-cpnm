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
int AUGM_COL;
int EXEP_CASE =0;

void row_transform(float *a,int subject_row, int refrence_row, float coeff,float *aug){
    if(subject_row!=refrence_row){
        for(int j=0;j<AUGM_COL;j++){
            *(aug+subject_row*AUGM_COL+j)=*(aug+subject_row*AUGM_COL+j)+(*(aug+refrence_row*AUGM_COL+j))*(coeff);
        }
        for(int j=0;j<DIMENSION;j++){
            *(a+subject_row*DIMENSION+j)=*(a+subject_row*DIMENSION+j)+(*(a+refrence_row*DIMENSION+j))*(coeff);
        }
    }
    else{
        for(int j=0;j<AUGM_COL;j++){
            *(aug+subject_row*AUGM_COL+j)=*(aug+subject_row*AUGM_COL+j)*(coeff);
        }
        for(int j=0;j<DIMENSION;j++){
            *(a+subject_row*DIMENSION+j)=(*(a+subject_row*DIMENSION+j))*(coeff);
        }
    }
}

void var_elimination(float *a,int subject_row,int subject_col,float *aug){
    int solve_bool=(*(a+(subject_row*DIMENSION)+subject_col)==1)?1:0;
    EXEP_CASE=((EXEP_CASE==0)&&(*(a+(subject_row*DIMENSION)+subject_col)==0))?1:0;
    if((*(a+(subject_row*DIMENSION)+subject_col)!=1)&&(*(a+(subject_row*DIMENSION)+subject_col)!=0)){
        row_transform(a,subject_row,subject_row,1/(*(a+(subject_row*DIMENSION)+subject_col)),aug);
        solve_bool=1;
    }
    if(solve_bool){
        for(int i=0;i<DIMENSION;i++){
            if(i!=subject_row){
                row_transform(a,i,subject_row,(*(a+i*DIMENSION+subject_col))*-1,aug);
            }
        }
    }
}


void gauss_jordan(float *a,float *aug){
    for(int i=0;i<DIMENSION;i++){
        var_elimination(a,i,i,aug);
        printmatx(a,aug);
    }
}

void printmatx(float *a,float *aug){
    printf("\n");
    for(int i=0;i<DIMENSION;i++){
        printf("| ");
        for(int j=0;j<DIMENSION+AUGM_COL;j++){
            if(j<DIMENSION){
                printf("%f ",*(a+i*DIMENSION+j));
            }
            else{printf(" %f ",*(aug+i*AUGM_COL+j-DIMENSION));}
        }
        printf("| \n");
    }
}

void augresultprint(float *a,float *aug){
    if(EXEP_CASE==0){
        for(int i=0;i<DIMENSION;i++){
            printf("x%d = %f\n",i+1,*(aug+i*AUGM_COL));
        }
    }
    else{
        printf("given set of equations do not have a solution.\nhere is final calculated augmented matrix :-\n");
        printmatx(a,aug);
    }
}

int main(){
    int menu=0;
    printf("Select methord to solve system of linear equation :-\n");
    printf("1. gauss jordan methord\n2. gauss jordan inversion methord\n");
    printf("your choice - ");
    scanf("%d",&menu);
    
    printf("Enter number of variables of system of linear equations - ");
    scanf("%d",&DIMENSION);
    float matx[DIMENSION][DIMENSION];
    
    switch(menu){
        case 1:
            AUGM_COL=1;
            float augmatx[DIMENSION][AUGM_COL];
            printf("Enter coefficients of eqn in form a1x1+a2x2+a3x3 ..... =b1");
            int a_counter=1,b_counter =1;
            for(int i=0;i<DIMENSION;i++){
                printf("\nEquation %d\n",i+1);
                for(int j=0;j<DIMENSION+AUGM_COL;j++){
                    if(j<DIMENSION){
                        printf("a%d = ",a_counter);
                        a_counter++;
                        scanf("%f",&matx[i][j]);
                    }
                    else{
                        printf("b%d = ",b_counter);
                        b_counter++;
                        scanf("%f",&augmatx[i][j-DIMENSION]);
                    }
                }
                a_counter =1;
                b_counter =1;
            }

            printmatx(matx,augmatx);
            gauss_jordan(matx,augmatx);
            augresultprint(matx,augmatx);
            break;
    }
}