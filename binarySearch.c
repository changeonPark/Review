#include <stdio.h>

int binarySearch(int start, int end, int target, int arr[]){
    printf("test\n");
    if(start > end) return -99; //탐색 종료
    int mid = (start + end) / 2; //중간값
    
    if(arr[mid] == target) return mid;
    //찾으려는 값이 중간값보다 큰 경우
    else if(target > arr[mid]) binarySearch(mid + 1, end, target, arr);
    //찾으려는 값이 중간값보다 작은 경우
    else binarySearch(start, mid - 1, target, arr);
}

void main(){
    int n, target;
    scanf("%d %d", &n, &target);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int result = binarySearch(0, n - 1, target, a);
    if(result != - 99) printf("%d element", result + 1);
    else printf("not found\n");

}