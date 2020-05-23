#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    int n;
    int check = 0;
    char* word;
    word = (char* )malloc(sizeof(char) * 1000);
    scanf("%d %s", &n, word);

    char** array;
    array = (char** )malloc(sizeof(char *) * n);

    for(int i = 0; i < n; i++){
        array[i] = (char *)malloc(sizeof(char) * 1000);
        scanf("%s", array[i]);
    }

    for(int i = 0; i < n; i++){
        if(!strcmp(array[i], word)){
            printf("%d`s element\n", i + 1);
            check = 1;
        }
    }
    if(!check) printf("not found element\n");
}