#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;
void insertion_begining();
void insertion_last();
void insertion_specified();
void deletion_begining();
void deletion_last();
void deletion_specified();
void display();
void search();
int main()
{
    int choice = 0;
    do
    {
        printf("\n*****************main menu*********");
        printf("\n choose one option from the following list...\n");
        printf("\n=====================================================\n");
printf("\n1.Insert in begining \n2.Insert at last\n3.Insert at any random location\n4.Delete from begining");
printf("\n5.delete from last\n6.Delete the node after the given data\n7.Search\n8.display\n9.Exit");
printf("\n Enter your choice?\n");
scanf("\n%d", &choice);
switch (choice)
{
        case 1:
            insertion_begining();
            break;
        case 2:
            insertion_last();
            break;
        case 3:
            insertion_specified();
            break;
        case 4:
            deletion_begining();
            break;
        case 5:
            deletion_last();
            break;
        case 6:
            deletion_specified();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Pleas enter the valied choice...");
}
    } while (choice != 9);
}
void insertion_begining()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
printf("\n OVERFLOW");
    }
    else
    {
printf("\nEnter Item value");
scanf("%d", &item);
if (head == NULL)
{
    ptr->next = NULL;
    ptr->prev = NULL;
    ptr->data = item;
    head = ptr;
}
else
{
    ptr->data = item;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
}
printf("\nNode inserted\n");
    }
}
void deletion_begining()
{
    struct node *ptr;
    if (head == NULL)
    {
printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
head = NULL;
free(head);
printf("\nnode deleted \n");
    }
    else
    {
ptr = head;
head = head->next;
head->prev = NULL;
free(ptr);
printf("\nnode deleted\n");
    }
}
void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
printf("\nEmpty list\n");
    }
    else
    {
printf("\n Enter the item which you want to search?\n");
scanf("%d", &item);
while (ptr != NULL)
{
    if (ptr->data == item)
    {
        printf("\nitem found at location %d", i + 1);
        flag = 0;
        break;
    }
    else
    {
        flag = 1;
    }
}
i++;
ptr = ptr->next;
    }
    if (flag == 1)
    {
printf("\n Item not found\n");
    }
}
