#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
}*first = NULL, *last = NULL, *temp, *temp1 = NULL, *temp2 = NULL, *ptr;

void create()
{
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d", &val);
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> prev = NULL;
    temp -> data = val;
    temp -> next = NULL;
    count++;
}

void insert_at_first()
{
    if(first == NULL)
    {
        create();
        first = temp;
        last = temp;
    }
    else
    {
        create();
        temp -> next = first;
        first -> prev = temp;
        first = temp;
    }
}

void insert_left()
{
    int val;
    printf("Enter the value of Node whose left the node has to be inserted: ");
    scanf("%d", &val);
    
    temp1 = first;
    while(temp1 != NULL && temp1 -> data != val)
    {
        temp2 = temp1;
        temp1 = temp1 -> next;
    }
    if(temp1 == NULL)
    {
        printf("The entered node is not present in the Linked List \n");
        return;
    }
    if(temp1 == first)
    {
        insert_at_first();
        return;
    }
    create();
    temp -> next = temp1;
    temp -> prev = temp2;
    temp2 -> next = temp;
    temp1 -> prev = temp;
}

void delete_node()
{
    int val;
    if(first == NULL)
    {
        printf("Linked List is empty ! \n");
        return;
    }
    printf("Enter the value of Node to be deleted: ");
    scanf("%d", &val);
    temp1 = first;
    while(temp1 != NULL && temp1 -> data != val)
    {
        temp = temp1;
        temp1 = temp1 -> next;
    }
    if(temp1 == NULL)
    {
        printf("The entered value Not Found in Linked List \n");
        return;
    }
    if(temp1 == first)
    {
        first = temp1 -> next;
        free(temp1);
        count--;
        return;
    }
    temp -> next = temp1 -> next;
    free(temp1);
    count--;
}

void display()
{
    ptr = first;
    if(first == NULL)
    {
        printf("Linked List is empty ! \n");
        return;
    }
    printf("The elements of the Linked List from the beginning are: \n");
    while(ptr != NULL)
    {
        printf("%d\t", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n\nThe number of nodes are: %d \n\n", count);
}

int main()
{
    int choice, n;
    while(1)
    {
        printf("\n------------Doubly Linked List----------\n");
        printf("Select any of the following choices: \n");
        printf("1. Insert at the front of the DLL \n");
        printf("2. Insert at left of the given value in DLL \n");
        printf("3. Delete the node with given value of the DLL \n");
        printf("4. Display the contents of the DLL \n");
        printf("5. Exit \n");
        printf("\n----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert_at_first();
                break;
            case 2:
                insert_left();
                break;
            case 3:
                delete_node();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Enter appropriate choice! \n");
                break;
        }
    }
    return 0;
}