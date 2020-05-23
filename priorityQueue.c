#include <stdio.h>

//x�� y�� ������ ���� �Լ�
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

typedef struct priorityQueue
{
    int heap[100]; //���� ������ �迭
    int count; //����� ������ ���� ������ ����
}priorityQueue;


void push(priorityQueue* pq, int data){
    //�Է��� �� �ִ� �ִ� ������ count�� Ŀ�� ��� stackoverflow
    if(pq->count >= 1000){
        printf("stack overflow\n");
        return;
    }

    pq->heap[pq->count] = data; //heap�迭�� count��° �迭�� �� ����
    int now = pq->count;
    int parent = (now - 1) / 2;
    //count�� 1�̻��� ������, ���� ���� �θ� ������ Ŭ ���
    //��������� ����
    while (now > 0 && pq->heap[now] > pq->heap[parent])
    {
        swap(&pq->heap[now], &pq->heap[parent]);//���� ���� �θ� ���� �ٲپ��ش�
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;
}

int pop(priorityQueue* pq){
    //�ƹ� ���� ���� �� pop�� ��� -> stack underflow
    if(pq->count <= 0){
        printf("stack underflow\n");
        return -33;
    }

    int result = pq->heap[0];//����� �����ϱ� ���� ����->root node�� ����
    pq->count--;//1. �迭�� 0���� �����̹Ƿ� 2. ť���� �����͸� �̾Ƴ��� �����ϹǷ� --> count�� �ٿ��ش�.
    pq->heap[0] = pq->heap[pq->count]; //root node�� leaf node�� ������ �� ����.
    int now = 0, leftchild = 1, rightchild = 2;//fifo�̹Ƿ� root��� ���� ��������� Ÿ�� �������� ���� ���� �غ�.
    int target = now;//target -> ���ϱ� ���� ����

    //��������� �����ϱ� ���� while
    while(leftchild < pq->count){//pq->count���� leftchild�� Ŀ�� ��� ���� null�̰ų� ���� node�� �Ѿ�Ƿ�
        if(pq->heap[target] < pq->heap[leftchild]) target = leftchild;//target�� leftchild���� ���� ��� ��������� Ÿ�� �������� ���� ���� �ٲپ��ֱ� ����.
        if(pq->heap[target] < pq->heap[rightchild] && rightchild < pq->count) target = rightchild;//leftchild < rightchild�� ���� ����. 
        //rightchild < pq->count�� �ʿ��� ����: index�� 2���� ��� heap[0], heap[1]�� �ִ� ���, rightchild = 2�� �ǹǷ� if�� ����� ������ �߻��� �� ����!
        
        if(target == now) break;
        else{
            swap(&pq->heap[now], &pq->heap[target]);
            now = target;
            leftchild = now * 2 + 1;
            rightchild = now * 2 + 2;
        }
    }
    return result;    
}

void main(){
    int n, data;
    printf("�Է��� �� : ");
    scanf("%d", &n);
    priorityQueue pq;
    pq.count = 0;
    printf("���� �Է��ϼ��� : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        push(&pq, data);
    }

    printf("��� ��: ");
    for(int i = 0;i < n;i++){
        int printdata = pop(&pq);
        printf("%d ", printdata);
    }
}
