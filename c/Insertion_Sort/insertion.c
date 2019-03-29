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

void insertion_Sort(int* arr,int size){
    int i,j,curr_ele;
    for(i=1;i<size;i++){
        curr_ele=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>curr_ele){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr_ele;
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

    insertion_Sort(arr,size);

    print_Array(arr,size);
    return 0;
}