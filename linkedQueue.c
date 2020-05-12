#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct Queue
{
    Node *rear;
    Node *front;
    int count;
}Queue;

void push(Queue *que, int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if(que->count == 0) que->front = node; //첫 노드 생성
    else que->rear->next = node; //2~N번째까지 노드 생성

    que->rear = node;
    que->count++;
}

void pop(Queue *que){
    if(que->count == 0){
        printf("stack underflow\n");
        return;
    }
    Node *node = que->front;
    que->front = node->next;
    free(node);
    que->count--;

}

void show(Queue *que){
    Node *node = que->front;
    while(node != NULL){
        printf("%d\n", node->data);
        node = node->next;
    }
    printf("---\n");
}

void main(){
    Queue que;
    que.front = que.rear = NULL;
    que.count = 0;
    printf("rear : %d front : %d\n", que.rear, que.front);
    pop(&que);
    push(&que, 3);
    printf("rear : %d front : %d\n", que.rear, que.front);
    push(&que, 2);
    printf("rear : %d front : %d\n", que.rear, que.front);
    show(&que);
    pop(&que);
    printf("rear : %d front : %d\n", que.rear, que.front);
    show(&que);
}