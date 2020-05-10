#include <stdio.h>

int arr[8] = {3, 4, 6, 1, 8, 10, 2, 5};

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int left, int mid, int right){
    int i = left, j = mid + 1;//left~mid�� mid+1~right���Ͽ� ������ ������ ����
    int result[8], key = left;

    while(i <= mid && j <= right){//i�� mid�� �Ѿ�ų� j�� right�� �Ѿ�� �� ���� ��� ���Ұ� �ٸ����� ���� ���� ������ ���� �۴ٴ� ���� �ǹ�.
        // result�迭�� ���
        if(arr[i] < arr[j]){//i�� ���Ұ� j�� ���Һ��� ���� ���
            result[key] = arr[i];//i�� ���Ҹ� ���
            i++;
        }
        else{//j�� ���Ұ� i���� ���� ���
            result[key] = arr[j];//j�� ���Ҹ� ���
            j++;
        }
        key++;
    }

    if(i > mid){//i~mid�� ����� ���� ���
        for(int m = j; m <= right; m++){//�����ִ� j~right�� ���� i~mid�� �ִ񰪺��� ũ�ٴ� �ǹ�.
            result[key] = arr[m];//���������� ����Ѵ�.
            key++;
        }
    }
    else{//j~right�� ����� ���� ���
        for(int m = i; m <= mid; m++){//�����ִ� i~mid�� ���� j~right�� �ִ밪���� ũ�ٴ� �ǹ�
            result[key] = arr[m];//���������� ����Ѵ�
            key++;
        }
    }

    for(int m = left; m <= right; m++){//������ ���� �迭���� ���� �迭�� �����Ѵ�.
        arr[m] = result[m];

    }
}

void sort(int left, int right){
    if(left < right){//element�� 1�� �� ������ �ݺ�
        int mid = (left + right)/2;

        sort(left, mid);//left~mid ����
        sort(mid + 1, right);//mid+1 ~ right ����
        merge(left, mid, right);//����
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