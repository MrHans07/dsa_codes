#include <stdio.h>
#include <stdlib.h>
#define size 10
int count = 0;
struct hashTable
{
    int data;
    int delStatus; // 0 means valid data present, 1 means valid data not present
   // in the data field
};
struct hashTable ht[size];
void initHT()
{
    int i;
    for (i = 0; i < size; i++)
        ht[i].delStatus = 1;
}
int isFull()
{
    if (count == size)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (count == 0)
        return 1;
    else
        return 0;
}
void addData()
{
    int data, key, i;
    if (!isFull())
    {
        printf("\nEnter data : ");
        scanf("%d", &data);
        key = data % size; // Applying hash function
        if (ht[key].delStatus == 1)
        {
            ht[key].data = data;
            ht[key].delStatus = 0;
            printf("\nData Added to table\n");
            count++;
        }
        else
        {
            for (i = 0; i < size; i++)
            {
                key = (key + 1) % size;
                if (ht[key].delStatus == 1)
                {
                    ht[key].data = data;
                    ht[key].delStatus = 0;
                    printf("\nData Added to table\n");
                    count++;
                    break;
                }
            }
        }
    }
    else
        printf("\nHash Table FULL\n");
}
void delData()
{
    int data, key, i, flag = 0;
    if (!isEmpty())
    {
        printf("\nEnter data to delete : ");
        scanf("%d", &data);
        key = data % size; // Applying hash function
        if (ht[key].delStatus == 0 && ht[key].data == data)
        {
            ht[key].delStatus = 1;
            printf("\nData deleted from table\n");
            count--;
        }
        else
        {
            for (i = 0; i < size; i++)
            {
                key = (key + 1) % size;
                if (ht[key].data == data)
                {
                    ht[key].delStatus = 1;
                    printf("\nData deleted from table\n");
                    count--;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                printf("\nData to be deleted not found in table\n");
        }
    }
    else
        printf("\nHash Table EMPTY\n");
}
void display()
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (ht[i].delStatus == 0)
        {
            printf("| %d |", ht[i].data);
        }
        else
            printf("| |");
    }
}
int main()
{
    int ch;
    initHT();
    do
    {
        printf("\nMain menu :\n");
printf("\n1) Add data \n2) Delete data \n3) Display table \n4) Exit\n\nEnter choice :");
scanf("%d", &ch);
switch(ch)
{
        case 1:
            addData();
            break;
        case 2:
            delData();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice!!");
}
    } while (ch != 4);
    return 0;
}
