#include <stdio.h>

#define S 5

int Q[5]; int front=-1,rear=-1;
    
void enqueue(int x)
{
    if((front==0 && rear==S-1) || (rear==front-1))
    {
        printf("Queue is full!\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        Q[rear]=x;
    }
    else
    {
        rear=(rear+1)%S;
        Q[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty!\n");
    }
    else if(front==rear)
    {
        printf("%d is deleted!\n",Q[front]);
        front=rear=-1;
    }
    else
    {
        printf("%d is deleted!\n",Q[front]);
        front=(front+1)%S;
    }
}

void isfull()
{
    if((front==0 && rear==S-1) || (rear==front-1))
    {
        printf("Queue is full!\n");
    }
    else
    {
        printf("Queue is not full!\n");
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty!\n");
    }
    else{
    int i; printf("The Queue: ");
    for(i=front;i!=rear;i=(i+1)%S)
    {
        printf("%d ",Q[i]);
    }
    printf("%d\n",Q[rear]);
    }
}

int main()
{
    enqueue(1);enqueue(2);enqueue(3);enqueue(4);enqueue(5);
    isfull();
    display();
    dequeue();dequeue();
    display();
    isfull();

    return 0;
}
