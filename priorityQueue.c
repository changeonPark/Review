#include <stdio.h>

//x와 y값 변경을 위한 함수
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

typedef struct priorityQueue
{
    int heap[100]; //값을 저장할 배열
    int count; //저장된 값들의 수를 세어줄 변수
}priorityQueue;


void push(priorityQueue* pq, int data){
    //입력할 수 있는 최대 수보다 count가 커질 경우 stackoverflow
    if(pq->count >= 1000){
        printf("stack overflow\n");
        return;
    }

    pq->heap[pq->count] = data; //heap배열의 count번째 배열에 값 대입
    int now = pq->count;
    int parent = (now - 1) / 2;
    //count가 1이상일 때부터, 현재 값이 부모 값보다 클 경우
    //상향식으로 정렬
    while (now > 0 && pq->heap[now] > pq->heap[parent])
    {
        swap(&pq->heap[now], &pq->heap[parent]);//현재 값과 부모 값을 바꾸어준다
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;
}

int pop(priorityQueue* pq){
    //아무 값도 없을 때 pop할 경우 -> stack underflow
    if(pq->count <= 0){
        printf("stack underflow\n");
        return -33;
    }

    int result = pq->heap[0];//결과를 저장하기 위한 변수->root node값 저장
    pq->count--;//1. 배열은 0부터 시작이므로 2. 큐에서 데이터를 뽑아내기 시작하므로 --> count를 줄여준다.
    pq->heap[0] = pq->heap[pq->count]; //root node에 leaf node의 마지막 값 저장.
    int now = 0, leftchild = 1, rightchild = 2;//fifo이므로 root노드 부터 하향식으로 타고 내려가기 위한 사전 준비.
    int target = now;//target -> 비교하기 위한 변수

    //하향식으로 정렬하기 위한 while
    while(leftchild < pq->count){//pq->count보다 leftchild가 커질 경우 값이 null이거나 우측 node로 넘어가므로
        if(pq->heap[target] < pq->heap[leftchild]) target = leftchild;//target이 leftchild보다 작을 경우 하향식으로 타고 내려가기 위해 값을 바꾸어주기 위함.
        if(pq->heap[target] < pq->heap[rightchild] && rightchild < pq->count) target = rightchild;//leftchild < rightchild일 경우와 동일. 
        //rightchild < pq->count가 필요한 이유: index가 2개일 경우 heap[0], heap[1]만 있는 경우, rightchild = 2가 되므로 if문 실행시 오류가 발생할 수 있음!
        
        if(target == now) break;
        else{
            swap(&pq->heap[now], &pq->heap[target]);
            now = target;
            leftchild = now * 2 + 1;
            rightchild = now * 2 + 2;
        }
    }
    return result;    
}

void main(){
    int n, data;
    printf("입력할 수 : ");
    scanf("%d", &n);
    priorityQueue pq;
    pq.count = 0;
    printf("수를 입력하세요 : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        push(&pq, data);
    }

    printf("출력 값: ");
    for(int i = 0;i < n;i++){
        int printdata = pop(&pq);
        printf("%d ", printdata);
    }
}
