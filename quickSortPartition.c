#include <stdio.h>

int arr[8] = {3, 4, 6, 1, 8, 10, 2, 5};

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int left, int right){
    int pivot = left;
    int cnt = left;

    for(int i = left + 1; i <= right; i++){
        if(arr[i] < arr[pivot]){
            cnt++;
            swap(&arr[cnt], &arr[i]);
        }
    }
    swap(&arr[cnt], &arr[pivot]);
    return cnt;
}

void sort(int left, int right){
    if(left < right){
        int pivot = partition(left, right);

        sort(left, pivot - 1);
        sort(pivot + 1, right);
    }
}

void main(){
    sort(0, 7);
    printf("Quick Sort: ");
    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}