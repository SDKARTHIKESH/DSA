#include <stdio.h>

#define SIZE 5

void enqueue(int x, int s[], int *t) {
    if (*t >= SIZE - 1) {
        printf("Queue is Full!\n");
    } else {
        s[++(*t)] = x;
    }
}

void dequeue(int s1[], int s2[], int *t1, int *t2) {
    if (*t1 == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    // Transfer elements from s1 to s2
    while (*t1 != -1) {
        s2[++(*t2)] = s1[(*t1)--];
    }

    // Remove the element from s2 (front of the queue)
    printf("The Deleted Element is %d\n", s2[(*t2)--]);

    // Transfer elements back to s1
    while (*t2 != -1) {
        s1[++(*t1)] = s2[(*t2)--];
    }
}

void peek(int s[], int *t) {
    if (*t == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("The Topmost Element is: %d\n", s[0]);
    }
}

void isempty(int s[], int *t) {
    if (*t == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue is not empty!\n");
    }
}

int main() {
    int stack1[SIZE], stack2[SIZE];
    int top1 = -1, top2 = -1;

    // Enqueue elements
    for (int i = 1; i <= SIZE; i++) {
        enqueue(i, stack1, &top1);
    }

    // Dequeue elements
    dequeue(stack1, stack2, &top1, &top2);
    dequeue(stack1, stack2, &top1, &top2);

    // Peek and check if empty
    peek(stack1, &top1);
    isempty(stack1, &top1);

    return 0;
}
