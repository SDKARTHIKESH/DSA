#include <stdio.h>

#define SIZE 5

void push(int x, int s[], int *t) {
    if (*t == SIZE - 1) {
        printf("Stack is full!\n");
    } else {
        s[++(*t)] = x; // Increment top and then assign value
    }
}

int pop(int s[], int *t) {
    if (*t == -1) {
        printf("Stack is empty!\n");
        return -1; // Return an invalid value
    } else {
        return s[(*t)--]; // Return value and decrement top
    }
}

void enqueue(int x, int arr[], int *f, int *r) {
    if (*r == SIZE - 1) {
        printf("Queue is Full!\n");
    } else if (*f == -1 && *r == -1) {
        *f = *r = 0;
        arr[*r] = x;
    } else {
        arr[++(*r)] = x; // Increment rear and then assign value
    }
}

int dequeue(int arr[], int *f, int *r) {
    if (*f == -1 && *r == -1) {
        printf("Queue is empty!\n");
        return -1; // Return an invalid value
    } else if (*f == *r) {
        int temp = arr[*f];
        *f = *r = -1; // Queue is now empty
        return temp;
    } else {
        return arr[(*f)++]; // Return front value and increment front
    }
}

void Peek(int arr[], int *f, int *r) {
    if (*f == -1 && *r == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Topmost element: %d\n", arr[*f]);
    }
}

void isempty(int arr[], int *f, int *r) {
    if (*f == -1 && *r == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue is not empty!\n");
    }
}

void display(int arr[], int *f, int *r) {
    if (*f == -1 && *r == -1) {
        printf("Queue is empty!\n");
    } else {
        for (int i = *f; i <= *r; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int stack[SIZE]; 
    int top = -1; // Stack is initially empty

    // Enqueue elements into the original queue
    for (int i = 1; i <= SIZE; i++) {
        enqueue(i, queue, &front, &rear);
    }

    // Dequeue elements from the original queue and push to the stack
    for (int i = 1; i <= SIZE; i++) {
        int p = dequeue(queue, &front, &rear);
        push(p, stack, &top);
    }

    // Pop elements from the stack and enqueue to the new queue
    for (int i = 1; i <= SIZE; i++) {
        int p = pop(stack, &top);
        enqueue(p, queue, &front, &rear);
    }

    // Display the reversed queue
    printf("The reversed queue: ");
    display(queue, &front, &rear);

    return 0;
}
