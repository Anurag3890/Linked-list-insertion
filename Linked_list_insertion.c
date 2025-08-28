#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

void insert_begin(int val){
    struct Node* newnode=malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

void insert_end(int val){
    struct Node* newnode=malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    if(!head){head=newnode;return;}
    struct Node* temp=head;
    while(temp->next)temp=temp->next;
    temp->next=newnode;
}

void insert_pos(int val,int pos){
    if(pos==0){insert_begin(val);return;}
    struct Node* temp=head;
    for(int i=0;i<pos-1 && temp;i++)temp=temp->next;
    if(!temp)return;
    struct Node* newnode=malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=temp->next;
    temp->next=newnode;
}

void display(){
    struct Node* temp=head;
    while(temp){printf("%d ",temp->data);temp=temp->next;}
    printf("\n");
}

int main(){
    insert_end(10);insert_begin(5);insert_end(20);insert_pos(15,2);
    display();
    return 0;
}
