#include <stdio.h>

int arr[8] = {3, 4, 6, 1, 8, 10, 2, 5};

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int left, int right){
    if(left < right){//left >= right일 경우 비교할 원소가 1개 이하란 뜻(비교 완료)
        int pivot = left, i = left + 1, j = right;

        while(i <= j){
            while(i <= right && arr[i] < arr[pivot]) i++;
            while(j > left && arr[j] > arr[pivot]) j--;

            if(i <= j) swap(&arr[i], &arr[j]);
            else swap(&arr[j], &arr[pivot]);
        }

        sort(left, j - 1);
        sort(j + 1, right);
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