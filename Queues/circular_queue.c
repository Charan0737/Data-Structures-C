#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int cqueue[MAX];
int front = -1, rear = -1;

void enqueue(int item)
{
    if (front == (rear + 1) % MAX)
    {
        printf("Queue Overflow\n");
        return;
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    cqueue[rear] = item;
}

int dequeue()
{
    int item;
    if (front == -1)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item = cqueue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
    return item;
}

int peek()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return cqueue[front];
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    i = front;
    while (1)
    {
        printf("%d ", cqueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
void menu()
{
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Show Index\n");
    printf("6. Quit\n");
}

int main()
{
    int choice, item;
    menu();
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Input the element for insertion: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                printf("Element deleted is: %d\n", dequeue());
                break;
            case 3:
                printf("Element at the front is: %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                menu();
                break;
            case 6:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
}


