

#ifndef HW2_USER_H
#define HW2_USER_H

typedef struct node{
    char* username;
    struct node* next;
}* Node;

typedef struct _list{
    char* list_name;
    struct node* head;
    int num_items;
}* LIST;


//TODO Omer
/**
 * gets new usersname and creates new struct
 * @return pointer to the new user or NULL if failed
 */
LIST User_Create(char* username);

//TODO Omer

/**
 * gets pointer to user and delete its friends list and user
 * @return
 */
void User_Delete(LIST pLIST);

//TODO Omer
/**
 * gets pointer to user1 and user2
 * adds user2 to user1's friends list and update his friends number.
 * adding the new user in the top of the friends list.
 * if this friend is already exists - nothing happens, returns FAILURE
 * no need to check that user2 is a real user
 * @return FAILURE (1) or SUCCESS(0)
 */
int User_addFriend(PUSER_NAME, Node);

//TODO Omer
/**
 * gets pointer to user1 and name of user2
 * removes user2 from user1's friends list and updates friends number.
 * if they weren't friends at all - do nothing return FAILURE
 * @return FAILURE (1) or SUCCESS(0)
 */
int User_removeFriend();

//TODO Daniel
/**
 * gets pointer to user and prints his name.
 *
 * @return 1 for error 0 for success.
 */
int User_getName();

//TODO Daniel
/**
 * gets pointer to user
 * @return pointer to first friend in friends list
 */
char* User_getFriendsList();

//TODO Daniel
/**
 * gets pointer to user
 * @return number of friends in friends list
 */
char* User_getFriendsNum();

//TODO Daniel
/**
 * gets poiner to user and prints his name and all of his friends
 * prints line to sum "The user has X friends: (X>1)"
 * @return
 */
int User_print();






//general node, link of the list (user's friends or concatenated social network users.
typedef struct _node{
    char* username;
    struct node* next;
} Node, *PNode;


PDATA_BASE CreateDB();
BOOL AddDB(PDATA_BASE, PPERSON);
PPERSON GetDB(PDATA_BASE, int);
BOOL RemoveDB(PDATA_BASE, int);
void PrintDB(PDATA_BASE);
void DeleteDB(PDATA_BASE);




#endif //HW2_USER_H
