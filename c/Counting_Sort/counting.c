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

void counting_Sort(int *arr,int size) 
{ 
    int *output;
    output=(int *)malloc(sizeof(int)*size); 
  
    int *count, i; 
    count=(int *)malloc(sizeof(int)*RANGE); 
    for(i=0;i<RANGE;i++){
        count[i]=0;
    }
    
    for(i = 0; i<size; ++i) 
        ++count[arr[i]]; 
  
    for (i = 1; i <= RANGE; ++i) 
        count[i] += count[i-1]; 
  
     
     for (i = size-1; i>=0; --i) 
    { 
        output[count[arr[i]]-1] = arr[i]; 
        --count[arr[i]]; 
    } 
    
    for (i = 0; arr[i]; ++i) 
        arr[i] = output[i]; 
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

    counting_Sort(arr,size);

    print_Array(arr,size);
    return 0;
}