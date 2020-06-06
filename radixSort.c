/*��� ����*/
#include <stdio.h>
#include <stdlib.h>

//������� �Լ�
void RadixSort(int*arr, int count){
    int* buff = (int*)malloc(sizeof(int) * count);//������ ���� �ӽ������� ���� ������ �迭
    int max = 0;//�ִ밪�� ���� ����
    int exp = 1;//LSD->���� ���� �ڸ������� ��
    //�ִ밪 ���ϱ�
    for(int i = 0; i < count; i++){
        if(arr[i] > max) max = arr[i];
    }
    //���� ����
    while(max / exp > 0){
        int bucket[10] = {0};//0~9�� ���� ������ ���� �迭
        //���� �� / exp �ڸ� ���� ������ ����
        for(int i = 0; i < count; i++){
            bucket[arr[i] / exp % 10]++;
        }
        //0~9 ������ �������� ���������� ����(������ ����)
        for(int i = 1; i < 10; i++){
            bucket[i] += bucket[i - 1];
        }
        //�� �� ���� ������ - 1�� ��ġ�� ���� �����Ѵ�.
        for(int i = count - 1; i > -1; i--){
            buff[--bucket[arr[i] / exp % 10]] = arr[i]; 
        }
        //buff���� ���ĵ� ������ arr�� �����Ų��
        for(int i = 0; i < count; i++){
            arr[i] = buff[i];
        }

        exp *= 10;
    }

}

void main(){
    int* arr;
    int count;//�Է¹��� ���� ���� ����

    printf("�Է��� ���� ��Դϱ�? ");
    scanf("%d", &count);
    //�迭 �޸� �Ҵ�
    arr = (int*)malloc(sizeof(int) * count);
    //0~count������ �ݺ��Ͽ� ���� �Է¹޾� arr�� �����Ѵ�
    for(int i = 0; i < count; i++){
        int number;//���� �Է¹��� ����
        printf("���� �Է��ϼ���: ");
        scanf("%d", &number);
        arr[i] = number;
    }
    
    RadixSort(arr, count);

    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
}