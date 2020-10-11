#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void Create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int)); 
}
void Enqueue(struct Queue *q, int data)
{
    if (q->rear == q-> size -1)
    {
        printf("Queue is full");
        exit -1;
    }
    else
    {
        q->Q[++q->rear] = data;
    }
}
int Dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
    {
        printf("Queue is Empty");
        exit -1;
    }
    else
    {
        x = q->Q[++q->front];
    }
    return x;
}
void display(struct Queue q)
{
    int i;

    for ( i = q.front+1; i <= q.rear; i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}
int main()
{
    struct Queue q;
    Create(&q,5);

    Enqueue(&q,10);
    Enqueue(&q,20);
    Enqueue(&q,30);

    display(q);

    printf("%d ",Dequeue(&q));

    return 0;
}
