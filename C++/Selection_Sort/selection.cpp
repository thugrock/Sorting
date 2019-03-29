#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


using namespace std;

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

void selection_Sort(int* arr,int size){
    int i,j,curr_min;

    for(i=0;i<size-1;i++){

        curr_min=i;

        for(j=i+1;j<size;j++){
            if(arr[j]<arr[curr_min]){
                curr_min=j;
            }
        }

        if(curr_min!=i)
            swap(&arr[i],&arr[curr_min]);
        
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

    selection_Sort(arr,size);

    print_Array(arr,size);
    return 0;
}