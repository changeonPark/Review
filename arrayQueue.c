#include <stdio.h>

#define SIZE 4
int arr[SIZE];
int rear = 0, front = 0;

void push(int data){
    if(rear == SIZE){
        printf("It`s stack overflow\n");
        return;
    }
    arr[rear++] = data;
}

void pop(){
    if(front == rear){
        printf("It`s stack underflow\n");
        return;
    }
    front++;
}

void show(){
    for(int i = front; i < rear; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}



void main(){
    pop();
    push(3);
    show();
    push(2);
    show();
    pop();
    show();

}