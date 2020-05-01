#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

void createNode(Node *head, Node *tail, int data);
void deleteNode(Node *head, Node *tail, int data);
void showNode(Node *head, Node *tail);

void main(){
    Node *head = (Node*)malloc(sizeof(Node));
    Node *tail = (Node*)malloc(sizeof(Node));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
    createNode(head, tail, 5);
    showNode(head, tail);
    createNode(head, tail, 6);
    showNode(head, tail);
    createNode(head, tail, 7);
    showNode(head, tail);
    deleteNode(head, tail, 10);
    showNode(head, tail);
    deleteNode(head, tail, 6);
    showNode(head, tail);
}

void createNode(Node *head, Node *tail, int data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    
    Node *nextnode = head->next;

    while(nextnode->data <= data && nextnode != tail){
        if(nextnode->data == data){
            printf("Duplicate values!!\n");
            return;
        }
        nextnode = nextnode->next;
    }
    Node *previousnode = nextnode->prev;
    previousnode->next = newnode;
    newnode->prev = previousnode;
    nextnode->prev = newnode;
    newnode->next = nextnode;
}

void deleteNode(Node *head, Node *tail, int data){
    Node *deletenode = head->next;
    while(deletenode != tail){
        if(data == deletenode->data){
            Node *previousnode = deletenode->prev;
            Node *nextnode = deletenode->next;
            previousnode->next = deletenode->next;
            nextnode->prev = deletenode->prev;
            free(deletenode);
            printf("Success\n");
            return;
        }
        deletenode = deletenode->next;
    }
    printf("Fail!\n");
}
void showNode(Node *head, Node *tail){
    Node *node = head->next;
    printf("start -> ");
    while(node != tail){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("END \n");
}