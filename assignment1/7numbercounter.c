#include<stdio.h>
#include<stdlib.h>

struct numdict *HOME; 

struct numdict{
    int num;
    int count;
    struct numdict* next;
};

void print(struct numdict *home){
    struct numdict *p = home;
    printf("num -  count\n");
    while(p->next!=NULL){
        printf("%d   -  %d\n",p->num,p->count);
        p=p->next;
    }
}

void destroy(){
    struct numdict *p=HOME,*q;
    while(p->next!=NULL){
        q = p->next;
        free(p);
        p = q;
    }
}

void create(struct numdict *prev_addrs,int numb){
    prev_addrs->next =  (struct numdict *)malloc(sizeof(struct numdict));
    prev_addrs->next->num = numb;
    prev_addrs->next->count=1;
    prev_addrs->next->next=NULL;
}

int main(){
    int n,i,digbool=0;
    printf("Enter number to find number of digits - ");
    scanf("%d",&n);
    HOME = (struct numdict *)malloc(sizeof(struct numdict));
    HOME->num=n%10;
    HOME->count=1;
    HOME->next=NULL;
    struct numdict *traveller = HOME;
    for(i=10;(n*10/i)!=0;i*=10){
        while(digbool==0){
            if(traveller->num == (n/i)%10){
                traveller->count++;
                digbool=1;
            }
            else{
                if(traveller->next!=NULL)traveller = traveller->next;
                else break;
            }
        }
        if((digbool==0)&&(traveller->next==NULL))create(traveller,(n/i)%10);
        traveller=HOME;
        digbool=0;
    }
    print(HOME);
    destroy();
}
