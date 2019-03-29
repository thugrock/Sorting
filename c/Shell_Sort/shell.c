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

int* getGaps(int* gap_size){
    int temp,option;
    while(1){
    printf("Enter the following options to select sequrnce og Gaps:\n");
    printf("press 1 for 2^k-1\n");
    printf("Press 2 for 2^p3^q\n");
    scanf("%d",&option);
    if(option==1){
        int *gaps;
        *gap_size=5; //Could be changed acc to your wish.
        gaps=(int *)malloc(sizeof(int)*(*gap_size));
        gaps[0]=31;gaps[1]=15;gaps[2]=7;gaps[3]=3,gaps[4]=1;
        return gaps;
    }
    else if(option==2){
        int *gaps;
        *gap_size=6;  //Could be changed acc to your wish
        gaps=(int *)malloc(sizeof(int)*(*gap_size));
        gaps[0]=9;gaps[1]=6;gaps[2]=4;gaps[3]=3;gaps[4]=2,gaps[5]=1;
        return gaps;
    }
    else{
        printf("Wrong input.Enter Follow Above Instructions\n");
    }

    }
}
void swap(int* pos1,int* pos2){
    int temp;
    temp=*pos1;
    *pos1=*pos2;
    *pos2=temp;
}
 
void print_Array(int* arr,int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void shell_Sort(int *gaps,int gap_size,int* arr,int size){
    int i,j,curr_ele,gap_index;
    for(gap_index=0;gap_index<gap_size;gap_index++){
    int gap=gaps[gap_index];
    for(i=gap;i<size;i++){
        curr_ele=arr[i];
        j=i;
        while(j>=gap && arr[j-gap]>curr_ele){
            arr[j]=arr[j-gap];
            j-=gap;
        }
        arr[j]=curr_ele;
    }
    }
}


int main(){
    int size,gap_size=1;
    int *arr,*gaps;

    printf("Enter the Size of Array\n");
    scanf("%d",&size);
    arr=inputFromUser(size);
    gaps=getGaps(&gap_size);
    shell_Sort(gaps,gap_size,arr,size);

    print_Array(arr,size);
    return 0;
}