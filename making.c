#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to print the elements of the linked list
void printLinkedList(struct Node *head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating nodes for the linked list
    struct Node *head = NULL; // Initializing an empty linked list

    // Adding elements to the linked list
    for (int i = 1; i <= 5; i++) {
        // Creating a new node
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        // Assigning data to the new node
        newNode->data = i;
        newNode->next = NULL;

        // If the list is empty, set the new node as the head
        if (head == NULL) {
            head = newNode;
        } else {
            // Traverse to the end of the list and append the new node
            struct Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Print the linked list
    printLinkedList(head);

    // Free memory allocated for the linked list
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
