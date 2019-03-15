// linked list processing functions from list.c - recursive versions
// written by andrewt@unsw.edu.au for COMP1511 04/18

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int         data;
};

struct node *create_node(int data, struct node *next);
struct node *last(struct node *head);
struct node *append(struct node *head, int value);
int sum(struct node *head);
void print_list(struct node *head);
void print_list_items(struct node *head);
int length(struct node *head);
struct node *find_node(struct node *head, int data);

int
main(int argc, char *argv[]) {
    struct node *head = NULL;

    while (1) {
        int number;
        printf("Enter a number: ");
        if (scanf("%d", &number) != 1) {
            break;
        }
        head = append(head, number);
    }

    if (head == NULL) {
        printf("List is empty.\n");
        return 0;
    }
    printf("\nList entered was: ");
    print_list(head);

    printf("\nFirst element in list is: %d.\n", head->data);
    printf("Last element in list is: %d.\n", last(head)->data);
    printf("Length of list is: %d.\n", length(head));
    printf("Sum of the list is: %d.\n", sum(head));

    if (find_node(head, 42) != NULL) {
        printf("42 is in the list.\n");
    } else {
        printf("42 is not in the list.\n");
    }
    return 0;
}


// Create a new struct node containing the specified data,
// and next fields, return a pointer to the new struct node.

struct node *create_node(int data, struct node *next) {
    struct node *n = malloc(sizeof (struct node));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    n->data = data;
    n->next = next;
    return n;
}

// return pointer to last node in list
// NULL is returned if list is empty

struct node *last(struct node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    return last(head->next);
}


// create a new list node containing value
// and append it to end of list

struct node *append(struct node *head, int value) {
    if (head == NULL) {
        return create_node(value, NULL);
    }
    head->next = append(head->next, value);
    return head;
}

// return sum of list data fields: using recursive call

int sum(struct node *head) {
    if (head == NULL) {
        return 0;
    }
    return head->data + sum(head->next);
}

// print contents of list in Python syntax

void print_list(struct node *head) {
    printf("[");
    if (head != NULL) {
        print_list_items(head);
    }
    printf("]");
}

void print_list_items(struct node *head) {
    printf("%d", head->data);
    if (head->next != NULL) {
        printf(", ");
        print_list_items(head->next);
    }
}

// return count of nodes in list

int length(struct node *head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + length(head->next);
}


// return pointer to first node with specified data value
// return NULL if no such node

struct node *find_node(struct node *head, int data) {
    if (head == NULL || head->data == data) {
        return head;
    }
    return find_node(head->next, data);
}


// Delete a Node from a List: Recursive
struct node *deleteR(struct node *head, struct node *node) {
   if (head == NULL) {
      fprintf(stderr, "warning: node not in list\n");
      
   } else if (node == head) {
      head = head->next;        // remove first item
      free(node);
      
   } else {
      head->next = deleteR(head->, node)
   }
   return head;
}

// Insert a Node into an Ordered List: recursive
struct node *insertR(struct node *head, struct node *node) {
   if (head == NULL || head->data >= node->data) {
   
      node->next = head;
      return node;
   }
   
   head->next = insertR(head->next, node);	
   
   return head;
}



