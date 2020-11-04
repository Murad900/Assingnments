#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>


struct Node {

    char data[256];
    struct Node *next;
};

void luckyCustomer(struct Node ** head, char *key){
    struct Node *temp = *head, *prev = NULL;

    if(temp != NULL && strcmp(temp->data, key) == 0){
        *head = temp->next;
    }
    else {
        while (temp != NULL && strcmp(temp->data, key) != 0) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL) {
            printf("No such customer\n");
            return;
        }
        prev->next = temp->next;
    }


    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;
    strcpy(new_Node->data, temp->data);
    new_Node->next = NULL;

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_Node;
    free(temp);
    temp = NULL;

}
void admit(struct Node ** head){
    if (*head == NULL) {
        printf("The queues is empty.\n");
        return;
    }
    struct Node *next_node = NULL;
    next_node = (*head)->next;
    printf("%s was admitted\n", (*head)->data);
    free(*head);
    *head = next_node;

}

void pushToEnd(struct Node ** head, char *new_data) {
    struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;
    strcpy(new_Node->data, new_data);
    new_Node->next = NULL;

    if (*head == NULL){
        *head = new_Node;
    }

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_Node;
}
void printList(struct Node * head) {
    printf("Queue: ");
    while (head != NULL) {
        if(head->next == NULL)
            printf("%s", head->data);
        else
            printf("%s, ", head->data);
        head = head->next;
    }
    printf("\n");
}



void freeMemory(struct Node **head){
    struct Node *new_node = *head;
    struct Node *next;

    while(new_node != NULL){
        next = new_node->next;
        free(new_node);
        new_node = next;
    }
    *head = NULL;
}



int main(){
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));

    strcpy(head->data,"Turgut");
    head->next = NULL;
    pushToEnd(&head, "Nazrin");
    pushToEnd(&head, "Nigar");
    pushToEnd(&head, "Kamran");
    pushToEnd(&head, "Eljan");
    printList(head);


    char input[256];
    bool quit = 0;

    while(!quit)
    {
        printf("\nEnter a name or a special keyword: ");
        scanf( "%s" , input);
        if (strcmp(input,"quit") == 0)
        {
            quit = 1;
        }
        else if (strcmp(input,"admit") == 0)
        {
            admit(&head);
        }
        else{
            luckyCustomer(&head, input);
        }
        printList(head);
    }
    freeMemory(&head);

    return 0;
}
