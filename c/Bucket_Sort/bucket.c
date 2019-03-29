#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

# define MIN -10000.00
float* inputFromUser(int size){
    float *arr;
    int i;
    arr=(float *)malloc(sizeof(float)*size);
    printf("Enter the Array Elements to be Sorted:(in between 0 to 1)\n");
    for(i=0;i<size;i++){
        scanf("%f",&arr[i]);
    }

    return arr;
}

void print_Array(float** arr,int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(arr[i][j]==MIN)
                continue;
            else
            {
                printf("%f ",arr[i][j]);
            }
            
        }
        
    }
}
void insertion_Sort(float* arr,int size){
    int i,j;
    float curr_ele;
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

void bucket_Sort(float* arr,int size){
    float **buckets;
    int i,j;
    buckets=(float **)malloc(sizeof(float *)*size);
    for(i=0;i<size;i++)
        buckets[i]=(float *)malloc(sizeof(float)*size);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            buckets[i][j]=MIN;
        }
    }

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(buckets[(int)arr[i]*size][j]==MIN){
                buckets[(int)arr[i]*size][j]=arr[i];
                break;
            }
        } 
    }
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(buckets[(int)arr[i]*size][j]==MIN){
                break;
            }
        }
        insertion_Sort(buckets[i],j);
        
    }


    print_Array(buckets,size);

}



int main(){
    int size;
    float *arr;

    printf("Enter the Size of Array\n");
    scanf("%d",&size);
    arr=inputFromUser(size);

    bucket_Sort(arr,size);

    return 0;
}