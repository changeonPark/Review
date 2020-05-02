#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct Stack
{
    Node *top;
}Stack;

void linkedPush(Stack *stack, int data);
void linkedPop(Stack *stack);
void linkedShow(Stack *stack);


void main(){
    Stack stack;
    stack.top = NULL;

    linkedPush(&stack, 5);
    linkedPush(&stack, 6);
    linkedPush(&stack, 7);
    linkedShow(&stack);
    linkedPop(&stack);
    linkedShow(&stack);

}

void linkedPush(Stack *stack, int data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = stack->top;
    stack->top = newnode;
}

void linkedPop(Stack *stack){
    if(stack->top == NULL){
        printf("Stack Underflow!\n");
        return;
    }
    Node *popnode = stack->top;
    printf("data of pop = %d\n", popnode->data);
    stack->top = popnode->next;
    free(popnode);
}

void linkedShow(Stack *stack){
    Node *shownode = stack->top;
    while(shownode != NULL){
        printf("%d\n", shownode->data);
        shownode = shownode->next;
    }
}
