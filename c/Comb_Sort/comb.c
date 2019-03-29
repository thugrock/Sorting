#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int* inputFromUser(int size){
    int *arr,i;
    arr=(int *)malloc(sizeof(int)*size);
    printf("Enter the Array Elements to be Sorted:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    return arr;
}
void swap(int* pos1,int* pos2){
    int temp;
    temp=*pos1;
    *pos1=*pos2;
    *pos2=temp;
}
int getNextGap(int gap) 
{ 
    gap = (gap*10)/13;   
    if (gap < 1) 
        return 1; 
    return gap; 
}

void comb_Sort(int* arr,int size){
    int i,j;
    int gap=size;
    int did_swap;
    while( (gap!=1) || did_swap==1){
        gap=getNextGap(gap);
        did_swap=0;
        for(j=0;j<size-gap;j++){
            if(arr[j]>arr[j+gap]){
                swap(&arr[j],&arr[j+gap]);
                did_swap=1;
            }
        }
        if(did_swap=0){
            break;
        }
    }

}


void print_Array(int* arr,int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int size;
    int *arr;

    printf("Enter the Size of Array\n");
    scanf("%d",&size);
    arr=inputFromUser(size);

    comb_Sort(arr,size);

    print_Array(arr,size);
    return 0;
}