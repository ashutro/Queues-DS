#include<stdio.h>
#include<stdlib.h>
struct CircularQ
{
    int size;
    int rear; 
    int front;
    int *Q;
};
void Create(struct CircularQ *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size*sizeof(int));

}
void Enqueue(struct CircularQ *q, int data)
{
    if ((q->rear+1)% q->size == q->front)
    {
        printf("Queue is Full");
        exit -1;
    }
    else
    {
        q->rear = (q->rear+1) % q->size;
        q->Q[q->rear] = data;
    }
}
int Dequeue(struct CircularQ *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is Empty");
        exit -1;
    }
    else
    {
        q->front = (q->front +1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
void Display(struct CircularQ q)
{
    int i = q.front+1;
    do
    {   printf("%d ",q.Q[i]);
        i = (i+1) % q.size;
    } while (i != (q.rear+1) % q.size) ;
    printf("\n");
}
int main()
{
    struct CircularQ q;

    Create(&q,7);

    Enqueue(&q,10);
    Enqueue(&q,20);
    Enqueue(&q,30);
    Enqueue(&q,40);
    Enqueue(&q,50);

    Display(q);

    printf("%d ",Dequeue(&q));
    printf("\n");
    Display(q);
}