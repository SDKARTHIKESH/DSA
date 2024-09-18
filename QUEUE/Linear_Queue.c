#include <stdio.h>

#define S 5
int queue[S];
int front=-1,rear=-1;

void enqueue(int x)
{
    if(front==0 && rear==S-1)
    {
        printf("Queue is Full!\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
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
        printf("The deleted element is %d\n",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("The deleted element is %d\n",queue[front]);
        front++;
    }
}

void Peek()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Topmost element: %d\n",queue[front]);
    }
}

void isempty()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue is not empty!\n");
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    Peek();
    isempty();
    return 0;
}
