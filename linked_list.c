#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>

#define NUM_DEFAULT_NODES   5

struct node {
    int data;
    struct node* prev;
    struct node* next;  
};

struct node* default_list();
void print_list(struct node*);
int add_int(struct node*, int);
int add_node(struct node*, struct node*);
int remove_node(struct node*, int pos);

int main(int argc, char* argv[]) {
    printf("\ncreating default list\n");
    struct node* header = default_list();
    print_list(header);
    printf("\nadding node with data of 3\n");
    add_int(header, 3);
    print_list(header);
    printf("\nremoving node at position 4\n");
    remove_node(header, 4);
    print_list(header);
} 

//create default list with ndoes from 1 - NUM_DEFALT_NODES
struct node* default_list() {
    
    struct node* header = (struct node*) malloc(sizeof(struct node));

    header->prev = header;
    header->next = header;
       
    struct node* trail = header;

    for(int i = 0; i < NUM_DEFAULT_NODES; i++) {
        struct node* cur = (struct node*) malloc(sizeof(struct node));
        
        cur->prev = trail;
        cur->data = i + 1;
        cur->next = header;

        trail->next = cur;
        trail = cur;
    }

    return header;
}

//print list whose header node is node
void print_list(struct node* node){
    
    struct node* header = node;
    
    while(node->next != header) {
        printf("%i ", node->next->data);
        node = node->next;
    }
    
    printf("\n");
}

//create and add node with data new_data in sorted order
//duplicates added after existing node(s)
int add_int(struct node* head, int new_data) {
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = new_data;

    return add_node(head, new_node);
}

//add node new_node in sorted order
//duplicates added after existing node(s)
int add_node(struct node* head, struct node* new_node) {

    struct node* cur = head;
    bool added = false;
    int pos = 0;

    while(cur->next != head && !added){
        if(cur->data > new_node->data) {
            
            new_node->prev = cur->prev;
            new_node->next = cur;

            cur->prev->next = new_node;
            cur->prev = new_node;
            
            return pos;
        }

        ++pos;
        cur = cur->next; 
    }

    return -1;

}

//remove node at position pos
int remove_node(struct node* header, int pos){
    
    int cur_pos = 0;
    struct node* cur = header->next;

    while(cur_pos != pos && cur->next != header) {
        cur = cur->next;
        ++cur_pos;
    }

    if(cur->next == header) {
           return -1;
    }
   
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;

    free(cur);
    return 0;
}






