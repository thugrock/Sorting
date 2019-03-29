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
void merge(int* arr,int low,int mid,int high){
    
    int i, j, k; 
    int n1 = mid - low + 1; 
    int n2 =  high - mid; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[low + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
  
    i = 0;  
    j = 0;  
    k = low;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void merge_Sort(int *arr,int low,int high){
    if(low<=high){
        int mid=low+(high-low)/2;
        merge_Sort(arr,low,mid-1);
        merge_Sort(arr,mid+1,high);
        merge(arr,low,mid,high);
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

    merge_Sort(arr,0,size-1);

    print_Array(arr,size);
    return 0;
}