#include <stdio.h>

int arr[8] = {3, 4, 6, 1, 8, 10, 2, 5};

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int left, int mid, int right){
    int i = left, j = mid + 1;//left~mid와 mid+1~right비교하여 오름차 정렬을 위함
    int result[8], key = left;

    while(i <= mid && j <= right){//i가 mid를 넘어가거나 j가 right를 넘어가면 한 쪽의 모든 원소가 다른쪽의 제일 작은 값보다 전부 작다는 것을 의미.
        // result배열에 기록
        if(arr[i] < arr[j]){//i의 원소가 j의 원소보다 작을 경우
            result[key] = arr[i];//i의 원소를 기록
            i++;
        }
        else{//j의 원소가 i보다 작을 경우
            result[key] = arr[j];//j의 원소를 기록
            j++;
        }
        key++;
    }

    if(i > mid){//i~mid의 기록이 끝난 경우
        for(int m = j; m <= right; m++){//남아있는 j~right의 수가 i~mid의 최댓값보다 크다는 의미.
            result[key] = arr[m];//순차적으로 기록한다.
            key++;
        }
    }
    else{//j~right의 기록이 끝난 경우
        for(int m = i; m <= mid; m++){//남아있는 i~mid의 수가 j~right의 최대값보다 크다는 의미
            result[key] = arr[m];//순차적으로 기록한다
            key++;
        }
    }

    for(int m = left; m <= right; m++){//정렬이 끝난 배열들을 기존 배열에 삽입한다.
        arr[m] = result[m];

    }
}

void sort(int left, int right){
    if(left < right){//element가 1이 될 때까지 반복
        int mid = (left + right)/2;

        sort(left, mid);//left~mid 분할
        sort(mid + 1, right);//mid+1 ~ right 분할
        merge(left, mid, right);//정복
    }
}

void main(){
    sort(0, 7);
    printf("Merge Sort: ");
    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}