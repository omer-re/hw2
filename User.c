#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>


//general node, link of the list (user's friends or concatenated social network users.
typedef struct node{
    char* username;
    struct node* next;
}* Node;

//first link of the linked list (username for example)
typedef struct _list{
    char* list_name;
    struct node* head;
    int num_items;
}* LIST;

LIST User_Create(char* username) {

    LIST pLIST;

    // creates a -list struct and verifies allocation
    if (NULL != (pLIST = (LIST)malloc(sizeof(LIST*)))) {
        pLIST->list_name=((char)realloc(pLIST->list_name,sizeof(char)*MAX_INPUT)); //does it resets the whole LIST?
        pLIST->head=NULL;
        pLIST->num_items=0;
    }

    //naming it by the username
    while(*username){
        strcpy(pLIST->list_name, username);
    }


    return pLIST;
}

Node Node_create(char* add_friend) {

    Node pNode;

    // creates a plist struct and verifies allocation
    if (NULL != (pNode = (Node)malloc(sizeof(Node*)))) {
        pNode->username=((char)realloc(pNode->username,sizeof(char)*MAX_INPUT)); //does it resets the whole Node? the array only?
        pNode->next=NULL;
    }

    //naming it by the username
    while(*add_friend){
        strcpy(pNode->username, add_friend);

    }

    return pNode;
}



//void User_Delete(Node ptr);

int destroyList(LIST pLIST){

    if (pLIST==NULL)
        return FAILURE;  //if it's NULL or not exsits, is it a successful delete?



    if (pLIST->head==NULL || pLIST->num_items<1)
        return SUCCESS;

}


int destroyNodes(Node ptr){

    //validation
    int counter=0;
    //free nodes
    while (ptr){
        Node toDel = ptr;
        ptr = ptr->next;
        free(toDel);
        counter++;
    }

    return counter;

}

void User_Delete(LIST pLIST) {

    if (pLIST==NULL || pLIST->head==NULL || pLIST->num_items<1)
        return;
    int items_deleted=destroyNodes(pLIST->head);

    //if (pLIST->num_items!=items_deleted)
    //    printf("UNMATCHING NUMBER OF ITEMS\n");
    destroyList(pLIST);

}


int User_addFriend(LIST pLIST, char* new_friend){

    //rolling to the first NULL = last link
    Node ptr = pLIST->head;
    while (ptr) {
        if (!strcmp(ptr->username,new_friend))
            return FAILURE;
        Node tail = ptr;
        ptr = ptr->next;
    }
    ptr= Node_create(new_friend);

    pLIST->num_items=(pLIST->num_items+1);

    return SUCCESS;
}


