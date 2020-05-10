#include <stdio.h>

int arr[8] = {3, 4, 6, 1, 8, 10, 2, 5};

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void inserstion(int left, int right){
    for(int i = left; i < right - 1; i++){
        int j = i;
        while(j >= left && arr[j] > arr[j + 1]){
            swap(&arr[j], &arr[j + 1]);
            j--;
        }
        
    }
}

void main(){
    inserstion(0, 8);
    printf("inserstion Sort: ");
    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}