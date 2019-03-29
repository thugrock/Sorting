#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

# define RANGE 1000

int* inputFromUser(int size){
    int *arr,i;
    arr=(int *)malloc(sizeof(int)*size);
    printf("Enter the elements to be sorted:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    return arr;
}
void swap(int *pos1,int* pos2){
    int temp;
    temp=*pos1;
    *pos1=*pos2;
    *pos2=temp;
}


void make_heap(int *arr, int size, int i) 
{ 
    int largest = i;  
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
      if (l < size && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < size && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 
  
        make_heap(arr, size, largest); 
    } 
} 

void heap_Sort(int *arr,int size){
    int i,j;
    for(i=size/2-1;i>=0;i--){
        make_heap(arr,size,i);
    }
    for (int i=size-1; i>=0; i--) 
    { 
        swap(&arr[0], &arr[i]); 
        make_heap(arr, i, 0); 
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

    heap_Sort(arr,size);

    print_Array(arr,size);
    return 0;
}