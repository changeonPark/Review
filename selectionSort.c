#include <stdio.h>

int arr[8] = {3, 4, 6, 1, 8, 10, 2, 5};

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void selection(int left, int right){
    for(int i = left; i < right; i++){
        int min = arr[i], idx = i;
        for(int j = i; j < right; j++){
            if(arr[j] < min){
                min = arr[j];
                idx = j;
            }
        }
        swap(&arr[i], &arr[idx]);
    }
}

void main(){
    selection(0, 8);
    printf("selection Sort: ");
    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}