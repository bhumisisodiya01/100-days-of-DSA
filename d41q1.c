/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if(rear == NULL){
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

int dequeue(){
    if(front == NULL)
        return -1;

    struct Node* temp = front;
    int val = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

int main(){
    int n,x;
    char op[20];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",op);

        if(strcmp(op,"enqueue")==0){
            scanf("%d",&x);
            enqueue(x);
        }
        else if(strcmp(op,"dequeue")==0){
            printf("%d\n",dequeue());
        }
    }

    return 0;
}