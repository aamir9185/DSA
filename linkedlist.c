#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
} *temp = NULL, *first = NULL, *temp2 = NULL, *prev = NULL, *current = NULL, *next = NULL, *temp3 = NULL;
int Count = 0;
void create()
{
    int Data;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data:");
    scanf("%d", &Data);
    temp->data = Data;
    temp->link = NULL;
    Count++;
}
void Insert_at_Head()
{
    if (first == NULL)
    {
        create();
        first = temp;
    }
    else
    {
        create();
        temp->link = first;
        first = temp;
    }
}
void Insert_at_Last()
{
    if (first == NULL)
    {
        create();
        first = temp;
    }
    else
    {
        create();
        temp2 = first;
        while (temp2->link != NULL)
        {
            temp2 = temp2->link;
        }
        temp2->link = temp;
    }
}
void Insert_at_Position()
{
    int Position, Counter = 1;
    temp2 = first;
    printf("Enter the Position:");
    scanf("%d", &Position);
    if (Position == 1)
    {
        Insert_at_Head();
    }
    else if (Position == Count)
    {
        Insert_at_Last();
    }
    else
    {
        create();
        while (Counter != Position)
        {
            temp3 = temp2;
            temp2 = temp2->link;
            Counter++;
        }
        temp->link = temp2;
        temp3->link = temp;
        Count++;
    }
}
void delete_at_Position()
{
    int Position, Counter = 1;
    printf("Enter the Position:");
    scanf("%d", &Position);
    if (Position == 1)
    {
        temp2 = first;
        first = temp2->link;
        temp2->link = NULL;
        free(temp2);
        temp2 = NULL;
        Count--;
    }
    else
    {
        temp2 = first;
        while (Position != Counter)
        {
            temp3 = temp2;
            temp2 = temp2->link;
            Counter++;
        }
        temp3->link = temp2->link;
        temp2->link = NULL;
        free(temp2);
        temp2 = NULL;
        Count--;
    }
}
void delete_at_Value()
{
    int Value;
    printf("Enter the Value:");
    scanf("%d", &Value);
    temp2 = first;
    while (temp2->link->data != Value)
    {
        temp2 = temp2->link;
        temp3 = temp2;
    }
}
void display()
{
    if (first == NULL)
        printf("Empty Linked List\n");
    else
    {
        temp2 = first;
        printf("Data:");
        while (temp2 != NULL)
        {
            printf("%d ", temp2->data);
            temp2 = temp2->link;
        }
    }
}
void reverse()
{
    current = first;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    first = prev;
}
int main()
{

    int Choice;
    printf("1. Press 1 For Inserting at First \n");
    printf("2. Press 2 For Inserting at Last \n");
    printf("3. Press 3 For Inserting at Position\n");
    printf("4. Press 4 For Delete At Value\n");
    printf("5. Press 5 For Delete At Position\n");
    printf("6. Press 6 For Reverse\n");
    printf("7. Press 7 For Display\n");
    printf("8. Press 8 For Exit\n");
    while (1)
    {
        printf("\nEnter the Choice:");
        scanf("%d", &Choice);
        switch (Choice)
        {
        case 1:
            Insert_at_Head();
            break;
        case 2:
            Insert_at_Last();
            break;
        case 3:
            Insert_at_Position();
            break;
        case 4:
            break;
        case 5:
            delete_at_Position();
            break;
        case 6:
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}