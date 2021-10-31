#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
}*head;

void insertAtBeg(int data);
void insertAtEnd(int data);
void insertAtPos(int data , int pos);
void deleteAtBeg();
void deleteAtEnd();
void deleteAtPos(int pos);
void display();

void main(){
    head = NULL;
    int data , choice , pos;

    printf("\n1.Insert at beginning \n2.Insert at end \n3.Insert at any position");
    printf("\n4.Delete at beginning \n5.Delete at end \n6.Delete at any position");
    printf("\n7.Display elements \n8.Exit");

    while(1){
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        
        switch(choice){
        case 1 :
            printf("\nEnter the data : ");
            scanf("%d",&data);
            insertAtBeg(data);
            break;
        case 2 :
            printf("\nEnter the data : ");
            scanf("%d",&data);
            insertAtEnd(data);
            break;
        case 3 :
            printf("\nEnter the data : ");
            scanf("%d",&data);
            printf("\nEnter the position where you want to insert : ");
            scanf("%d",&pos);
            if(pos<1)
                printf("Position starts from 1. Please try again!");
            else
                insertAtPos(data, pos);
            break;
        case 4 : 
            if(head==NULL)
                printf("List is already empty!");
            else
                deleteAtBeg();
            break;
        case 5 :
            if(head==NULL)
                printf("List is already empty!");
            else
                deleteAtEnd();
            break;
        case 6 : 
            if(head==NULL)
                printf("List is already empty!");
            else{
                printf("\nEnter the position where you want to delete : ");
                scanf("%d", &pos);
                if(pos<1)
                printf("Position starts from 1. Please try again!");
                else deleteAtPos(pos);
            }
            break;
        case 7 :
            display();
            break;
        case 8 :
            exit(0);
        }
    }
}

void insertAtBeg(int data){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = head;
    head = newNode;
    printf("\n%d is inserted at the beginning",data);
}

void insertAtEnd(int data){
    struct node* ptr = head;
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    if(head==NULL){
        head = newNode;
        printf("\n%d is inserted at the end",data);
        return;
    }

    while(ptr->link != NULL){
        ptr = ptr->link;
    }
        ptr->link = newNode;
    printf("\n%d is inserted at the end",data);
}

void insertAtPos(int data , int pos){
    struct node *ptr = head;
    int count = 0 ;

    while(ptr != NULL){
        ptr = ptr->link;
        count++;
    }

    if(pos>count+1){
        printf("Positon %d is free. Please fill it first.",count+1);
        return;
    }

    struct node* newNode = malloc(sizeof(struct node));
    if(pos==1){
        newNode->data = data;
        newNode->link = head;
        head = newNode;
        printf("\n%d is inserted at position %d", data, pos);
        return;
    }
    
    int i = 0;
    ptr = head;
    while (ptr!=NULL){
        i++;
        if(i==pos-1){
            newNode->data = data;
            newNode->link = ptr->link;
            ptr->link = newNode;
            return;
        }
        ptr = ptr->link;
    }
    printf("\n%d is inserted at position %d", data, pos);
}

void deleteAtBeg(){
    if(head->link == NULL){
        printf("\n%d is deleted.", head->data);
        free(head);
        head = NULL;
        return;
    } else {
        struct node* temp = head;
        printf("\n%d is deleted.", head->data);
        head = head->link;
        free(temp);
    }
}

void deleteAtEnd(){
    struct node *ptr=head;
    struct node *prev;

    while(ptr->link!=NULL){
        prev = ptr;
        ptr = ptr->link;
    }
    if(ptr==head){
        printf("\n%d is deleted.", head->data);
        free(head);
        head = NULL;
    }else{
        printf("\n%d is deleted.", ptr->data);
        prev->link = NULL;
        free(ptr);
    }
}

void deleteAtPos(int pos){
    struct node *ptr = head;
    struct node *prev=head, *del;
    int i = 1;

    if(pos==1){
        deleteAtBeg();
        return;
    }
    while(ptr->link!=NULL){
        i++;
        ptr = ptr->link;
        del = ptr;
        if(i==pos){
            printf("\n%d is deleted.", del->data);
            prev->link = del->link;
            free(del);
            return;
        }
        prev = prev->link;
    }
    if(ptr->link==NULL)
    printf("No data at specified position!");
}

void display(){
    struct node* ptr = head;
    if(head==NULL){
        printf("The list is empty");
    } else{
        printf("The list is : [ ");
        while(ptr != NULL){
            printf("%d , ",ptr->data);
            ptr = ptr->link;
        }
        printf("\b\b]");
    }
}
