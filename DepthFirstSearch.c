/* 깊이 우선 탐색 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node{
    int index;
    struct Node* next;
}Node;

Node** g_array;
//연결리스트 생성 함수
void AddFront(Node* root, int index){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}
//깊이 우선 탐색 함수
void DFS(int x, int* dfsarray){
    //이미 방문한 경우
    if(dfsarray[x]) return;
    //방문하지 않은 경우
    dfsarray[x] = 1;//방문 처리
    printf("%d ", x);
    Node* cur = g_array[x]->next;//현재 노드가 가리키는 노드의 정보 저장
    //모든 노드를 방문할 때 까지 반복
    while(cur != NULL){
        int next = cur->index;
        DFS(next, dfsarray);
        cur = cur->next;
    }
}
void main(){
    int vertex, edge;
    int dfsarray[MAX] = {0, };
    printf("정점과 간선의 수를 입력하시오: ");
    scanf("%d %d", &vertex, &edge);
    //정점과 간선의 정보를 담을 배열 초기화
    g_array = (Node**)malloc(sizeof(Node*) * vertex);
    for(int i = 0; i < vertex; i++){
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
    DFS(0, dfsarray);

    
}