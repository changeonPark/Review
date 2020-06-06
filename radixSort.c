/*계수 정렬*/
#include <stdio.h>
#include <stdlib.h>

//계수정렬 함수
void RadixSort(int*arr, int count){
    int* buff = (int*)malloc(sizeof(int) * count);//정렬할 값을 임시적으로 담을 포인터 배열
    int max = 0;//최대값을 담을 변수
    int exp = 1;//LSD->가장 작은 자릿수부터 비교
    //최대값 구하기
    for(int i = 0; i < count; i++){
        if(arr[i] > max) max = arr[i];
    }
    //정렬 시작
    while(max / exp > 0){
        int bucket[10] = {0};//0~9의 수의 갯수를 담을 배열
        //현재 값 / exp 자리 수의 갯수를 저장
        for(int i = 0; i < count; i++){
            bucket[arr[i] / exp % 10]++;
        }
        //0~9 까지의 누적합을 순차적으로 저장(정렬을 위함)
        for(int i = 1; i < 10; i++){
            bucket[i] += bucket[i - 1];
        }
        //맨 끝 부터 누적합 - 1의 위치에 수를 저장한다.
        for(int i = count - 1; i > -1; i--){
            buff[--bucket[arr[i] / exp % 10]] = arr[i]; 
        }
        //buff에서 정렬된 값들을 arr에 저장시킨다
        for(int i = 0; i < count; i++){
            arr[i] = buff[i];
        }

        exp *= 10;
    }

}

void main(){
    int* arr;
    int count;//입력받을 수를 담을 변수

    printf("입력할 수는 몇개입니까? ");
    scanf("%d", &count);
    //배열 메모리 할당
    arr = (int*)malloc(sizeof(int) * count);
    //0~count전까지 반복하여 수를 입력받아 arr에 저장한다
    for(int i = 0; i < count; i++){
        int number;//수를 입력받을 변수
        printf("수를 입력하세요: ");
        scanf("%d", &number);
        arr[i] = number;
    }
    
    RadixSort(arr, count);

    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
}