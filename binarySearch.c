#include <stdio.h>

int binarySearch(int start, int end, int target, int arr[]){
    printf("test\n");
    if(start > end) return -99; //Ž�� ����
    int mid = (start + end) / 2; //�߰���
    
    if(arr[mid] == target) return mid;
    //ã������ ���� �߰������� ū ���
    else if(target > arr[mid]) binarySearch(mid + 1, end, target, arr);
    //ã������ ���� �߰������� ���� ���
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