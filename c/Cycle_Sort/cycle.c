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

void cycle_Sort(int arr[], int n) 
{ 
    int writes = 0; 
   
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) { 
        int item = arr[cycle_start]; 
   
        int pos = cycle_start; 
        for (int i = cycle_start + 1; i < n; i++) 
            if (arr[i] < item) 
                pos++; 
  
        if (pos == cycle_start) 
            continue; 
  
        while (item == arr[pos]) 
            pos += 1; 
  
        if (pos != cycle_start) { 
            swap(&item, &arr[pos]); 
            writes++; 
        } 
  
        while (pos != cycle_start) { 
            pos = cycle_start; 
  
            for (int i = cycle_start + 1; i < n; i++) 
                if (arr[i] < item) 
                    pos += 1; 
  
            while (item == arr[pos]) 
                pos += 1; 
  
            if (item != arr[pos]) { 
                swap(&item, &arr[pos]); 
                writes++; 
            } 
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

    cycle_Sort(arr,size);

    print_Array(arr,size);
    return 0;
}