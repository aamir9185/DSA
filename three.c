#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct Node
{
    int data;
    struct Node* next;
} *first = NULL,*last = NULL,*temp = NULL,*temp1;

void create()
{
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data for the Node: ");
    scanf("%d", &temp->data);
    temp -> next = NULL;
    count++;
}

void display()
{
    temp1 = first;
    if(temp1 == NULL)
    {
        printf("The Linked List is empty \n");
        return;
    }
    else
    {
        int cnt = 1;
        printf("The Linked List elements from the beginning are: \n");
        while(temp1 != NULL)
        {
            printf("%d ", temp1 -> data);
            temp1 = temp1 -> next;
            cnt++;
        }
        printf(" \nNumber of nodes are : %d \n", count);
    }
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
        first = temp;
    }
}

void insert_at_last()
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
        temp1 = first;
        while(temp1 -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp;
        last = temp;
    }
}

void insert_at_position()
{
    temp = first;
    int pos, cnt = 0, num;
    printf("Enter the position (0 based indexing): ");
    scanf("%d", &pos);
    if(pos > count)
    {
        printf("Index out of range! \n");
    }
    else if(pos == 0) insert_at_first();
    else if(pos == count) insert_at_last();
    else
    {
        while(pos != cnt)
        {
            temp1 = temp;
            cnt++;
            if(temp -> next != NULL) temp = temp -> next;
            else break;
        }
        printf("Enter data: ");
        scanf("%d", &num);
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        temp1 -> next = new_node;
        new_node -> data = num;
        new_node -> next = temp;
        count++;
    }
}

void delete_at_position()
{
    if(first == NULL)
    {
        printf("The Linked List is empty \n");
        return;
    }
    int val;
    printf("Enter the value to be deleted: ");
    scanf("%d", &val);
    temp = first;
    while(temp -> data != val)
    {
        temp1 = temp;
        temp = temp -> next;
    }
    if(temp == first)
    {
        first = temp -> next;
        free(temp);
        count--;
        return;
    }
    printf("Data to be deleted is %d \n", temp -> data);
    temp1 -> next = temp -> next;
    free(temp);
    count--;
}

void search_at_val()
{
    int val;
    printf("Enter the value to be searched in the Linked List: ");
    scanf("%d", &val);
    if(first == NULL)
    {
        printf("The Linked List is empty \n");
    }
    else
    {
        int cnt = 1;
        temp = first;
        while(temp != NULL && temp -> data != val)
        {
            temp = temp -> next;
            cnt++;
        }
        if(temp == NULL)
        {
            printf("The value %d is not in the list \n", val);
            return;
        }
        printf("The value %d is found at position %d \n", val, cnt);
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("Enter any of the following choices");
        printf("\n ---------------------------------------- \n");
        printf("1. Insert at front of the Linked List \n");
        printf("2. Insert at position of the Linked List \n");
        printf("3. Delete a node based on specific value of the Linked List \n");
        printf("4. Search a node based on specific value of the Linked List \n");
        printf("5. Display all nodes of the Linked List \n");
        printf("6. Exit");
        printf("\n ---------------------------------------- \n");
        printf("Enter any choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert_at_first();
                break;
            case 2:
                insert_at_position();
                break;
            case 3:
                delete_at_position();
                break;
            case 4:
                search_at_val();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(1);
                break;
            default:
                break;
        }
    }
    return 0;
}
