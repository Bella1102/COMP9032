
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

struct node *insert_ordered(struct node *head, struct node *node);
struct node *delete(struct node *head, struct node *node);

int
main(int argc, char *argv[]) {

    struct node *head = create_node(97, NULL);
    head = create_node(68, head);
    head = create_node(42, head);    
    head = create_node(25, head);
    head = create_node(10, head);

    struct node *new_node = create_node(30, NULL);
    insert_ordered(head, new_node);
  
    print_list(head); 
    printf("\n");
    
    struct node *n1 = find_node(head, 68);
    delete(head, n1);
    print_list(head); 
    printf("\n");
        
    n1 = find_node(head, 10);
    head = delete(head, n1);
    print_list(head); 
    printf("\n");        
        
    return 0;
}


// Delete a Node from a List
//
struct node *delete(struct node *head, struct node *node) {
   if (node == head) {
      printf("remove first item \n"); 
      head = head->next;        // remove first item
      free(node);
      return head;
   } else {
      struct node *previous = head;
      while (previous != NULL && previous->next != node) {
         previous = previous->next;
      }
      if (previous != NULL) { // node found in list
         previous->next = node->next;
         free(node);
      } else {
         fprintf(stderr, "warning: node not in list\n");
      }
   }
   return head;
}


//Insert a Node into an Ordered List
//
struct node *insert_ordered(struct node *head, struct node *node) {
   struct node *previous;
   struct node *n = head;
   // find correct position
   while (n != NULL && node->data > n->data) {
       previous = n;
       n = n->next;
   }
   
   // link new node into list
   if (previous == NULL) {
       head = node;
       node->next = n;
   } else {
       previous->next = node;
       node->next = n;
   }
   
   return head;
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



