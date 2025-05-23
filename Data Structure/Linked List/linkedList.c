#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *next;
};

int sizeOfList(struct node *head){
    int count = 0;
    struct node *temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

void printList(struct node *head){
    struct node *temp = head;
    while(temp){
        printf("[Current -> %p || Value -> %d || Next -> %p] \n",temp, temp->value, temp->next);
        temp = temp->next;
    }
}

struct node* createNode(int value){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};

// Create a new node and add to start
// Return the new Head Address
// Pass by Value, thats why we need to return new head.
struct node* insertToBegin(struct node* head, int value){
    struct node* newNode = createNode(value);
    newNode->next = head;
    return head = newNode;
}

// Insert to the end of the Linked list with Big (O)n time Complexity
struct node* insertToEnd_On(struct node *head, int value){

    struct node *lastNode = head;
    while(lastNode->next)
        lastNode = lastNode->next;

    return lastNode->next = createNode(value);
}
// Insert to the end of the Linked list with Big (O)1 time Complexity
struct node* insertToEnd_O1(struct node *lastNode, int value){
    return lastNode->next = createNode(value);
}

void insertIntoSpecificPoint(struct node* head, int position, int value){
    if(head == NULL) {
        printf("List Empty, You can't add the value in %d position\n", position);
        return;
    };
    if((position - 1) >= sizeOfList(head)) {
        printf("List's Size is %d, You can't add value in %d position \n", sizeOfList(head), position);
        return;
    };
    struct node* newNode = createNode(value);
    struct node* temp = head;

    int count = 1;
    while (temp)
    {
        count++;
        temp = temp->next;
        if(count == (position - 1)){
            break;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;

    // printf("Temp-> %p \n", temp);
    // printf("Temp->value -> %d \n", temp->value);
    // printf("Temp->next -> %p \n", temp->next);

}

void deleteFromBegin(struct node **head){
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    printf("Deleted %d from Begin \n", (*head)->value);
    *head = (*head)->next;
}

void deleteFromEnd(struct node *head){
    struct node *temp = head;
    struct node *prev = NULL;
    if(head == NULL) return;

    while(temp->next){
        prev = temp;
        temp = temp->next;
    }
    
    printf("Deleting node with value: %d\n", temp->value);
    prev->next = NULL;
    free(temp);
}


void deleteIntoSpecificPoint(struct node* head, int position){
    if(head == NULL) {
        printf("List Empty, You can't delete the value from %d position\n", position);
        return;
    };
    if((position - 1) >= sizeOfList(head)) {
        printf("List's Size is %d, You can't delete value from %d position \n", sizeOfList(head), position);
        return;
    };
    
    struct node* prev = head;
    struct node* next = NULL;

    int count = 1;
    while (prev)
    {
        count++;
        prev = prev->next;
        next = prev->next;
        if(count == (position - 1)){
            break;
        }
    }
    prev->next = next->next;
    

    // printf("prev-> %p \n", prev);
    // printf("prev->value -> %d \n", prev->value);
    // printf("prev->next -> %p \n\n\n", prev->next);

    // printf("next-> %p \n", next);
    // printf("next->value -> %d \n", next->value);
    // printf("next->next -> %p \n", next->next);

}


int main(){
    struct node *HEAD  = (struct node *) malloc(sizeof(struct node));
    struct node *lastNode = (struct node *) malloc(sizeof(struct node));
    HEAD = createNode(10);

    // When there is only one node, First node is also the last Node
    lastNode = HEAD;
    lastNode = insertToEnd_O1(lastNode, 20);
    lastNode = insertToEnd_O1(lastNode, 30);
    lastNode = insertToEnd_O1(lastNode, 40);
    lastNode = insertToEnd_O1(lastNode, 50);
    HEAD = insertToBegin(HEAD, 05);
    lastNode = insertToEnd_O1(lastNode, 60);
    HEAD = insertToBegin(HEAD, 01);
    

    insertIntoSpecificPoint(HEAD, 3, 100);
    insertIntoSpecificPoint(HEAD, 3, 200);

    deleteFromBegin(&HEAD);

    deleteFromEnd(HEAD);
    deleteFromEnd(HEAD);
    deleteIntoSpecificPoint(HEAD, 3);

    printList(HEAD);
    return 0;
}
