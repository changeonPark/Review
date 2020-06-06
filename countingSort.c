/*계수 정렬*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 101

void main(){
    int counter;//입력할 수의 갯수 변수
    int number, arr[MAX] = {0}; //number: 입력받은 수의 갯수 확인 변수, arr[MAX]: 입력받은 수의 갯수를 담을 배열
    int* result;
    int input = 0;
    printf("입력할 수의 개수를 알려주세요: ");
    scanf("%d", &counter);
    
    //입력받은 수의 배열의 값을 하나씩 증가시켜 입력받은 수의 갯수를 저장한다.
    for(int i = 0; i < counter; i++){
        printf("1~100중 원하는 수 : ");
        scanf("%d", &number);
        arr[number]++;
    }
    //저장된 배열을 result 포인터 배열에 저장
    result = (int*)malloc(sizeof(int) * counter);//result 포인터 배열 메모리 할당
    for(int i = 0; i < MAX; i++){
        while(arr[i] != 0){
            result[input] = i;
            input++;
            arr[i]--;
        }   
    }
    //출력
    for(int i = 0; i < counter; i++){
        printf("%d ", result[i]);
    }
}