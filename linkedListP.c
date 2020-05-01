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
//create node
void newNode(Node *head, int data){
    Node *newnode = (Node*)malloc(sizeof(Node)); //initialization struct Node
    newnode->data = data; //put value of data in data of Node
    newnode->next = head->next;//next of Node link to next of head
    head->next = newnode; //next of head link to Node
    printf("%d ", newnode->data);//test code
}
//delete first node
void delNode(Node *head){
    Node *delnode = head->next;//initialization struct Node and Node link to next of head
    head->next = delnode->next;//next of head link to next of Node
    free(delnode);//free memory of Node
}

void delNodeValue(Node *head, int data){
    Node *delcurr = head->next;//initialization struct Node1(delete value) and link to next of head
    Node *curr = head;//initialization struct Node2(temp) and link to head
    while(delcurr != NULL){
        if(delcurr->data == data){
            curr->next = delcurr->next;//next of Node2 link to next of Node1
            free(delcurr);//free data of Node1
            return;//close function
        }
        //move to next Node;
        curr = delcurr;//Node2 link to Node1
        delcurr = delcurr->next;//Node1 link to next of Node1
    }
    printf("Can`t find Node you want.\n");//No match value of input data and data of Node1 
    
}

void allDelNode(Node *head){//reset Node;
    Node *target = head->next;//initialization struct Node1(delete value) and link to next of head
    Node *temp = target; //initialization struct Node2(temp) ande link to target
    while(target != NULL){
        temp = target->next;//Node2 link to next of target
        free(target);
        target = temp;//Node1 link to Node2
    }
    head->next = NULL;//next of head link to NULL
}
/*
void cleanMemory(Node *head){//Delete with head;
    Node *target = head;//need to delete head;
    Node *temp = target; //need to next point;
    while(target != NULL){
        temp = temp->next;//input head->next <> input Node->next;
        free(target);//free head <> free Node;
        target = temp;//input head->next <> input Node->next;
    }
}
*/
//allprint
void showNode(Node *head){
    Node *shownode = head->next;//initialization struct Node
    int cnt = 1; //initialization check false
    printf("show to values = ");
    while(shownode != NULL){
        printf("%d ", shownode->data);
        shownode = shownode->next;//Node link to next of Node
        cnt = 0; //check change true
    }
    if(cnt == 1){//if check is false
        printf("none Node\n");
        return;//close function
    }
    printf("\n");

}
//search
void searchNode(Node *head, int data){
    Node *searchnode = head->next;//initialization struct Node
    while(searchnode != NULL){
            if(searchnode->data == data){
            printf("Finding Node! = %d\n", searchnode->data);
            return;//close function
        }
        searchnode = searchnode->next; //Node link to next of Node
    }
    printf("I can`t find Node\n");//not find;
}