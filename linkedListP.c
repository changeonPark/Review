#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void newNode(Node *head, int data);
void delNode(Node *head);
void delNodeValue(Node *head, int data);
void allDelNode(Node *head);
void showNode(Node *head);
void searchNode(Node *head, int data);

void main(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    newNode(head, 1);
    newNode(head, 2);
    newNode(head, 3);
    newNode(head, 4);
    showNode(head);
    delNode(head);
    showNode(head);
    newNode(head, 6);
    showNode(head);
    delNodeValue(head, 2);
    showNode(head);
    searchNode(head, 1);
    searchNode(head, 99);
    allDelNode(head);
    showNode(head);
}

void newNode(Node *head, int data){
    Node *newnode = (Node*)malloc(sizeof(Node)); //create newnode;
    newnode->data = data; //input data in newnode;
    newnode->next = head->next;//newnode pointing to head;
    head->next = newnode; //head pointing to newnode`s value;
    printf("%d ", newnode->data);
}

void delNode(Node *head){
    Node *delnode = head->next;
    head->next = delnode->next;
    free(delnode);
}

void delNodeValue(Node *head, int data){
    Node *delcurr = head->next;//delete Node;
    Node *curr = head;//before delete Node;
    while(delcurr != NULL){//if delcurr is NULL -> END or none Node;
        if(delcurr->data == data){
            curr->next = delcurr->next;//before Node pointing next Node;
            free(delcurr);//free current Node;
            return;//end function;
        }
        //move to next Node;
        curr = delcurr;//before Node pointing current Node;
        delcurr = delcurr->next;//current Node pointing next Node;
    }
    printf("Can`t find Node you want.\n");
    
}

void allDelNode(Node *head){//reset to Node;
    Node *target = head->next;//target == node1 or NULL;
    Node *temp = target; //temp == target == node1 or NULL;
    while(temp != NULL){//if temp == NULL is none node;
        temp = temp->next;//input currentNode->next;
        free(target); //delete currentNode;
        target = temp;//target == node->next;
    }
    head->next = NULL;//pointing head->next;
}

void cleanMemory(Node *head){//Delete with head;
    Node *target = head;//need to delete head;
    Node *temp = target; //need to next point;
    while(target != NULL){
        temp = temp->next;//input head->next <> input Node->next;
        free(target);//free head <> free Node;
        target = temp;//input head->next <> input Node->next;
    }
}

void showNode(Node *head){
    Node *shownode = head->next;//printing nodes;
    int cnt = 1;
    printf("show to values = ");
    while(shownode != NULL){//if shownode is NULL -> END or noneData;
        printf("%d ", shownode->data);//print;
        shownode = shownode->next;//shift to next Node;
        cnt = 0;
    }
    if(cnt == 1){
        printf("none Node\n");
        return;
    }
    printf("\n");

}

void searchNode(Node *head, int data){
    Node *searchnode = head->next;//don`t need head;
    while(searchnode != NULL){//if searchnode is NULL -> END or noneData;
        if(searchnode->data == data){//finding;
            printf("Finding Node! = %d\n", searchnode->data);
            return;//end to function;
        }
        searchnode = searchnode->next;
    }
    printf("I can`t find Node\n");//not find;
}