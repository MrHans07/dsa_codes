#include <stdio.h> //Header file
void push();       // function declaration
void pop();        // function declaration
void display();    // function declaration
int stack[100], i, item, n, ch, top;
int main()
{
    top = -1;
    printf("\nEnter the size of the stack: ");
    scanf("%d", &n);
    do
    {
        printf("\nEnter Choice : ");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.display");
        printf("\n4.exit");
        printf("\n Enter your choice = ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(); // function call
            break;
        case 2:
            pop(); // function call
            break;
        case 3:
            display(); // function call
            break;
        case 4:
            break;
        default:
            printf("\nEnter valid choice");
            break;
        }
    } while (ch != 4);
}
void push() // function defination
{
    if (top >= n - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        printf("\nEnter the element you want to insert: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
    }
}
void pop() // function defination
{
    if (top >= 0)
    {
        printf("\nDeleted element is %d ", stack[top]);
        top--;
    }
    else
    {
        printf("\nStack Underflow");
    }
}
void display() // function defination
{
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}