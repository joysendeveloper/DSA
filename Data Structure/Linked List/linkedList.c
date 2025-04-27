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

// Create a new node and add to start
// Return the new Head Address
struct node* insertToBegin(struct node* head, int value){
    struct node* newNode = createNode(value);
    newNode->next = head;
    return head = newNode;
}

void deleteFromBegin(struct node *head){

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

    // printf("new Node -> %p \n", insertToBegin(HEAD, 5));
    printf("Head : %d \n", HEAD);
    
    printf("Head->value : %d \n", HEAD->value);
    printf("Head->next : %p \n", HEAD->next);

    printList(HEAD);
    return 0;
}
