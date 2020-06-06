#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
//���Ḯ��Ʈ ����ü
typedef struct Node{
    int index;
    struct Node* next;
}Node;
//ť ����ü
typedef struct Queue{
    Node* front;
    Node* rear;
    int count;
}Queue;
//������ ������ ������ ���� 2���� ������
Node** g_array;
//���Ḯ��Ʈ ���� �Լ�
void AddFront(Node* root, int index){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}
//ť ���� �Լ�
void Push(Queue* que, int index){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = NULL;
    //ť�� ���Ե� �����Ͱ� ���� ���
    if(que->count == 0){
        que->front = node;
    }
    //���Ե� �����Ͱ� ���� ���
    else{
        que->rear->next = node;
    }
    //rear ��ġ ����
    que->rear = node;
    que->count++;
}
//ť ���� �Լ�
int Pop(Queue* que){
    if(que->count == 0){
        printf("starck underflow\n");
        return false;
    }
    Node* node = que->front;
    //������ �� ����
    int index = node->index;
    //front ��ġ �̵� �� �޸� �Ҵ� ����
    que->front = node->next;
    free(node);
    //���������Ƿ� count�� ����
    que->count--;
    return index;
}
//�ʺ� �켱 Ž�� �Լ�
void BFS(int start, int bfsarray[]){
    //ť �ʱ�ȭ
    Queue que;
    que.front = que.rear = NULL;
    que.count = 0;
    //ť�� PUSH �� �湮 ó��
    Push(&que, start);
    bfsarray[start] = 1;
    //count�� ���� 0�� �� �� ���� �ݺ�
    while(que.count != 0){
        int buf = Pop(&que);
        printf("%d ", buf);
        Node* cur = g_array[buf]->next;
        while(cur != NULL){
            int next = cur->index;
            //�湮���� ���� ����Ͻ�
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
    printf("������ ������ ���� �Է��Ͻÿ�: ");
    scanf("%d %d", &vertex, &edge);
    //������ ������ ������ ���� �迭 �ʱ�ȭ
    g_array = (Node**)malloc(sizeof(Node*) * MAX);
    for(int i = 0; i < MAX; i++){
        g_array[i] = (Node*)malloc(sizeof(Node));
        g_array[i]->next = NULL;
    }
    //������ ���� ����
    for(int i = 0; i < edge; i++){
        int x, y;
        printf("������ �� ������ �Է��ϼ���: ");
        scanf("%d %d", &x, &y);
        //����� ����
        AddFront(g_array[x], y);
        AddFront(g_array[y], x);
    }
    BFS(1, bfsarray);
}