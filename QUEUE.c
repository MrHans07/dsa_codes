#include <stdio.h>  //header file
#include <stdlib.h> //header file
#define MAX 4
void insert();  // Function decleration
void delete();  // Function decleration
void display(); // Function decleration
int queue[MAX], i, item, ch;
int rear = -1;
int front = -1;
int main()
{
    do
    {
        printf("\nEnter Choice : ");
        printf("\n1.Insert element to queue ");
        printf("\n2.Delete elements of queue ");
        printf("\n3.Display all elements of queue ");
        printf("\n4.Quit ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(); // function call
            break;
        case 2:
            delet(); // function call
            break;
        case 3:
            display(); // function call
            break;
        case 4:
            break;
        default:
            printf("Wrong choice ");
            break;
        }
    } while (ch != 4);
}
void insert() // Function defination
{
    if (rear == MAX - 1) // Queue Full conditin
        printf("\nQueue Overflow ");
    else
    {
        if (front == -1) // insert frist element
            front = 0;
        printf("\nInsert the element in queue: ");
        scanf("%d", &item);
        rear = rear + 1;
        queue[rear] = item;
    }
}
void delete() // Function defination
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow ");
        return;
    }
    else
    {
        printf("\nElement deleted from queue is:%d", queue[front]);
        front = front + 1;
    }
}
void display() // Function defination
{
    if (front == -1)
        printf("\nQueue is empty ");
    else
    {
        printf("\nQueue is: ");
        for (i = front; i <= rear; i++)
            printf("\n%d", queue[i]);
    }
}
