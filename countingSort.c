/*��� ����*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 101

void main(){
    int counter;//�Է��� ���� ���� ����
    int number, arr[MAX] = {0}; //number: �Է¹��� ���� ���� Ȯ�� ����, arr[MAX]: �Է¹��� ���� ������ ���� �迭
    int* result;
    int input = 0;
    printf("�Է��� ���� ������ �˷��ּ���: ");
    scanf("%d", &counter);
    
    //�Է¹��� ���� �迭�� ���� �ϳ��� �������� �Է¹��� ���� ������ �����Ѵ�.
    for(int i = 0; i < counter; i++){
        printf("1~100�� ���ϴ� �� : ");
        scanf("%d", &number);
        arr[number]++;
    }
    //����� �迭�� result ������ �迭�� ����
    result = (int*)malloc(sizeof(int) * counter);//result ������ �迭 �޸� �Ҵ�
    for(int i = 0; i < MAX; i++){
        while(arr[i] != 0){
            result[input] = i;
            input++;
            arr[i]--;
        }   
    }
    //���
    for(int i = 0; i < counter; i++){
        printf("%d ", result[i]);
    }
}