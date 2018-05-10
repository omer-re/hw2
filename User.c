#include "defs.h"
#include "User.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

void print_top(Node first_friend);



LIST User_Create(char* username) {

    LIST pLIST;

    // creates a -list struct and verifies allocation
    if (NULL != (pLIST = (LIST)malloc(sizeof(LIST*)))) {
        pLIST->list_name=((char*)realloc(pLIST->list_name,sizeof(char)*MAX_INPUT)); //does it resets the whole LIST?
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
    if ((pNode = (Node)malloc(sizeof(Node*))) != NULL) {
        pNode->username=((char*)realloc(pNode->username,sizeof(char)*MAX_INPUT)); //does it resets the whole Node? the array only?
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
    Node pNode = pLIST->head;
    //Null will symbol the last link
    while (pNode->username) {
        if (strcmp(pNode->username,new_friend)) {
            return FAILURE;
        }
        pNode = pNode->next;
    }

    pNode->next = Node_create(new_friend);

    pLIST->num_items=(pLIST->num_items+1);

    return SUCCESS;
}


int User_removeFriend(LIST pUSER, char* pFRIEND){

    int counter=0;
    Node ptr1 = pUSER->head;
    Node ptr_minus1=NULL;
    //looking for a friend with the matching name
    while (ptr1->username&&counter==0) {
        //when it's a match
        if (!strcmp(ptr1->username,pFRIEND)) {
            ptr_minus1->next = ptr1->next;
            ptr1->next = NULL; //will stop the while loop as well
            counter++;
            break;
        }
        ptr_minus1=ptr1;
        ptr1 = ptr1->next;
    }

    if (counter){
        pUSER->num_items=(pUSER->num_items-1);
        return SUCCESS;

    }

    return FAILURE;
}


char* User_getName(LIST pUSER){

    if (pUSER==NULL){
        return "FAILURE";
    }

    return pUSER->list_name;
}


Node User_getFriendsList(LIST pUSER){

    if (pUSER==NULL){
        return NULL;
    }

    return pUSER->head;
}


int User_getFriendsNum(LIST pUSER){

    if (pUSER==NULL){
        return FAILURE;
    }

    return pUSER->num_items;
}

int User_print(LIST pUSER){

    if (pUSER==NULL) {
        return FAILURE;
    }

    printf("User's name: %s\n", pUSER->list_name);
    printf("The user has %d friends: \n",pUSER->num_items );
    print_top(User_getFriendsList(pUSER));

    return SUCCESS;
}

void print_top(Node first_friend){
    if (!first_friend){
        return;
    }
    print_top(first_friend->next);
    printf("%s\n", first_friend->username);

}