/* ���� �켱 Ž�� */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node{
    int index;
    struct Node* next;
}Node;

Node** g_array;
//���Ḯ��Ʈ ���� �Լ�
void AddFront(Node* root, int index){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}
//���� �켱 Ž�� �Լ�
void DFS(int x, int* dfsarray){
    //�̹� �湮�� ���
    if(dfsarray[x]) return;
    //�湮���� ���� ���
    dfsarray[x] = 1;//�湮 ó��
    printf("%d ", x);
    Node* cur = g_array[x]->next;//���� ��尡 ����Ű�� ����� ���� ����
    //��� ��带 �湮�� �� ���� �ݺ�
    while(cur != NULL){
        int next = cur->index;
        DFS(next, dfsarray);
        cur = cur->next;
    }
}
void main(){
    int vertex, edge;
    int dfsarray[MAX] = {0, };
    printf("������ ������ ���� �Է��Ͻÿ�: ");
    scanf("%d %d", &vertex, &edge);
    //������ ������ ������ ���� �迭 �ʱ�ȭ
    g_array = (Node**)malloc(sizeof(Node*) * vertex);
    for(int i = 0; i < vertex; i++){
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
    DFS(0, dfsarray);

    
}