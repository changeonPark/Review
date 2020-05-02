#include <Stdio.h>

#define SIZE 10000
int arraystack[SIZE];
int arrtop = -1;

void arrPush(int data);
void arrPop();
void arrShow();

void main(){
    arrPush(1);
    arrPush(2);
    arrPush(3);
    arrShow();
    arrPop();
    arrShow();
}

void arrPush(int data){
    if(arrtop == SIZE - 1){
        printf("Stack Overflow!\n");
        return;
    }
    arraystack[++arrtop] = data;
}

void arrPop(){
    if(arrtop == -1){
        printf("Stack Underflow!\n");
        return;
    }
    --arrtop;
}

void arrShow(){
    for(int i = arrtop; i > -1; i--){
        printf("%d\n", arraystack[i]);
    }
}
