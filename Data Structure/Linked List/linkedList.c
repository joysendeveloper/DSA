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
// Pass by Value, thats why we need to return new head.
struct node* insertToBegin(struct node* head, int value){
    struct node* newNode = createNode(value);
    newNode->next = head;
    return head = newNode;
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

    printf("Temp-> %p \n", temp);
    printf("Temp->value -> %d \n", temp->value);
    printf("Temp->next -> %p \n", temp->next);

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
    printf("Size -> %d \n", sizeOfList(HEAD));
    insertIntoSpecificPoint(HEAD, 3, 100);
    insertIntoSpecificPoint(HEAD, 3, 200);
    printList(HEAD);
    return 0;
}
