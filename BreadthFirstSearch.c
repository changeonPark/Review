#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
//연결리스트 구조체
typedef struct Node{
    int index;
    struct Node* next;
}Node;
//큐 구조체
typedef struct Queue{
    Node* front;
    Node* rear;
    int count;
}Queue;
//정점과 간선의 정보를 담을 2차원 포인터
Node** g_array;
//연결리스트 삽입 함수
void AddFront(Node* root, int index){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}
//큐 삽입 함수
void Push(Queue* que, int index){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = NULL;
    //큐에 삽입된 데이터가 없을 경우
    if(que->count == 0){
        que->front = node;
    }
    //삽입된 데이터가 있을 경우
    else{
        que->rear->next = node;
    }
    //rear 위치 변경
    que->rear = node;
    que->count++;
}
//큐 추출 함수
int Pop(Queue* que){
    if(que->count == 0){
        printf("starck underflow\n");
        return false;
    }
    Node* node = que->front;
    //추출할 값 저장
    int index = node->index;
    //front 위치 이동 후 메모리 할당 해제
    que->front = node->next;
    free(node);
    //추출했으므로 count값 감소
    que->count--;
    return index;
}
//너비 우선 탐색 함수
void BFS(int start, int bfsarray[]){
    //큐 초기화
    Queue que;
    que.front = que.rear = NULL;
    que.count = 0;
    //큐에 PUSH 후 방문 처리
    Push(&que, start);
    bfsarray[start] = 1;
    //count의 값이 0이 될 때 까지 반복
    while(que.count != 0){
        int buf = Pop(&que);
        printf("%d ", buf);
        Node* cur = g_array[buf]->next;
        while(cur != NULL){
            int next = cur->index;
            //방문하지 않은 노드일시
            if(!bfsarray[next]){
                Push(&que, next);
                bfsarray[next] = 1;
            }
            cur = cur->next;
        }
    }
}

void main(){
    int vertex, edge;
    int bfsarray[MAX] = {0, };
    printf("정점과 간선의 수를 입력하시오: ");
    scanf("%d %d", &vertex, &edge);
    //정점과 간선의 정보를 담을 배열 초기화
    g_array = (Node**)malloc(sizeof(Node*) * MAX);
    for(int i = 0; i < MAX; i++){
        g_array[i] = (Node*)malloc(sizeof(Node));
        g_array[i]->next = NULL;
    }
    //정점간 간선 연결
    for(int i = 0; i < edge; i++){
        int x, y;
        printf("연결할 두 정점을 입력하세요: ");
        scanf("%d %d", &x, &y);
        //양방향 연결
        AddFront(g_array[x], y);
        AddFront(g_array[y], x);
    }
    BFS(1, bfsarray);
}