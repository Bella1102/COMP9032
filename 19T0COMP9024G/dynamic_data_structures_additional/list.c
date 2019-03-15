/*
$ dcc list.c
$ a.out
Enter a number: 1
Enter a number: 2
Enter a number: 3
Enter a number: 4
Enter a number: 5
Enter a number:
List entered was: [1, 2, 3, 4, 5]
First element in list is: 1.
Last element in list is: 5.
Length of list is: 5.
Sum of the list is: 15.
42 is not in the list.
*/

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
        head =  append(head, number);
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
    if (head == NULL) {
        return NULL;
    }

    struct node *n = head;
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}


// create a new list node containing value
// and append it to end of list

struct node *append(struct node *head, int value) {
    // new node will be last in list, so next field is NULL
    struct node *n = create_node(value, NULL);
    if (head == NULL) {
        // new node is now  head of the list
        return n;
    } else {
        // change next field of last list node
        // from NULL to new node
        last(head)->next = n;  /* append node to list */
        return head;
    }
}

// return sum of list data fields

int sum(struct node *head) {
    int sum = 0;
    struct node *n = head;
    // execute until end of list
    while (n != NULL) {
        sum += n->data;
        // make n point to next item
        n = n->next;
    }
    return sum;
}

// return sum of list data fields: using for loop

int sum1(struct node *head) {
    int sum = 0;
    
    for (struct node *n = head; n != NULL; n = n->next) {
    
        sum += n->data;
        
    }
    
    return sum;
}


// print contents of list in Python syntax

void print_list(struct node *head) {
    printf("[");
    for (struct node *n = head; n != NULL; n = n->next) {
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]");
}


// return count of nodes in list

int length(struct node *head) {
    int len = 0;
    for (struct node *n = head; n != NULL; n = n->next) {
        len = len + 1;
    }
    return len;
}


// return pointer to first node with specified data value
// return NULL if no such node

struct node *find_node(struct node *head, int data) {
    struct node *n = head;

    // search until end of list reached
    while (n != NULL) {
        // if matching item found return it
        if (n->data == data) {
            return n;
        }

        // make node point to next item
        n = n->next;
    }

    // item not in list
    return NULL;
}

// previous function written as for loop

struct node *find_node1(struct node *head, int data) {
    for (struct node *n = head; n != NULL; n = n->next) {
        if (n->data == data) {
            return n;
        }
    }
    return NULL;
}

// previous function written as a more concise while loop

struct node *find_node2(struct node *head, int data) {
    struct node *n = head;
    
    while (n != NULL && n->data != data) {
    
       n = n->next;
    }
    
    return n;
}



