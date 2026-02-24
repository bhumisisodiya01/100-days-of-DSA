/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {

    int n, key, i;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    
    // Input number of nodes
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Input key to delete
    scanf("%d", &key);

    struct node *curr = head;
    struct node *prev = NULL;

    // If head node contains key
    if(curr != NULL && curr->data == key) {
        head = curr->next;
        free(curr);
    } else {
        // Traverse list
        while(curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        // If key found
        if(curr != NULL) {
            prev->next = curr->next;
            free(curr);
        }
    }

    // Print updated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}