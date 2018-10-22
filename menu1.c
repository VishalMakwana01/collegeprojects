#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

typedef struct
{
    char *name;
    //can add as much profile details as we want
} user;

user users[MAX]; //user list
int relationMat[MAX][MAX];
int visited[MAX];
int stack[MAX];

int numbOfUsers = 0;
int stackTop = -1, usersIndex = -1;

void push(int item)
{
    if (stackTop == MAX)
        printf("Stack overflow");
    else
        stack[++stackTop] = item;
}

int pop()
{
    if (stackTop == -1)
    {
        printf("Stack underflow");
        return 0;
    }
    else
        return (stack[stackTop--]);
}

void addUser(char *_name) //add user to Users' database.
{
    int i = 0;
    usersIndex++;
    numbOfUsers++;
    users[usersIndex].name = strdup(_name);
}

void displayFriends()
{
    int i = 0, j = 0;

    for (i = 0; i < numbOfUsers; i++)
    {
        printf("\n%s: ", users[i].name);
        for (j = 0; j < numbOfUsers; j++)
        {
            if (relationMat[i][j] == 1)
                printf("%s, ", users[j].name);
        }
    }
}

void listAllUsers() //DFS traversal in order to display friends list
{
    int u, i;
    int initial_node = 0;
    stackTop = -1;
    push(initial_node);
    while (stackTop >= 0)
    {
        u = pop();
        if (visited[u] == 0)
        {
            printf("%s, ", users[u].name);
            visited[u] = 1;
        }
        for (i = 1; i <= numbOfUsers; i++)
        {
            if ((relationMat[u][i] == 1) && (visited[i] == 0))
            {
                push(u);
                visited[i] = 1;
                printf("%s, ", users[u].name);
                u = i;
            }
        }
    }
}

void addFriend(int user, int friend) //create relations graph.
{
    if (user > 0 && friend > 0 && user <= MAX && friend <= MAX)
        relationMat[user - 1][friend - 1] = 1;
    else
        printf("Invalid input!");
}

void unfriend(int user, int friend) //create relations graph.
{
    if (user > 0 && friend > 0 && user <= MAX && friend <= MAX)
        relationMat[user - 1][friend - 1] = 0;
    else
        printf("Invalid input!");
}



void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void menu()
{   int choice,user1,friend1,c=1;
    char *name;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\t\tFRIEND MANAGEMENT");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.ADD USER\n\t\t2.ADD A FRIEND FOR A USER\n\t\t3.UNFRIEND\n\t\t4.SEE FRIENDS OF A USER\n\t\t5.CHECK MUTUAL FRIENDS\n\t\t6.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    if(choice==6)
        system("color 7");
    system("cls");
    switch(choice)
    {
        case 1:printf("Enter name %d: ", numbOfUsers+1);
               gets(name);
               addUser(name);
        break;
        case 2:for(int i=0;i<numbOfUsers;i++){
            printf("\t\t%d.%s\n",i+1,users[i].name);
        }
        printf("\t\tEnter the user you want to add friends for:");
        scanf("%d",user1);
        system("cls");
        for(int i=0;i<numbOfUsers;i++){
            if(i==user1-1)
                break;
            else{
            printf("\t\t%d.%s\n",i+1,users[i].name);
        }
        }
        do{
        printf("\t\tEnter the friends:");
        scanf("%d",friend1);
        addFriend(user1,friend1);
        printf("\t\tDo you want to add more friends ? (1/0)");
        scanf("%d",&c);
        }while(c!=0);
        break;
        case 3:c=1;
        for(int i=0;i<numbOfUsers;i++){
            printf("\t\t%d.%s\n",i+1,users[i].name);
        }
        printf("\t\tEnter the user you want to remove friends for:");
        scanf("%d",user1);
        system("cls");
        printf("\t\tBelow are the friends of %s\n\n",users[user1-1].name);
        for(int j=0;j<numbOfUsers;j++)
        {
            if(relationMat[user1-1][j]==1)
            {
                printf("\t\t%d.%s",j+1,users[j].name);
            }
        }
         do{
        printf("\t\tEnter the friends:");
        scanf("%d",friend1);
        unfriend(user1,friend1);
        printf("\t\tDo you want to remove more friends ? (1/0)");
        scanf("%d",&c);
        }while(c!=0);
        break;
        case 4:displayFriends();
        break;
        case 5:close();
        break;

    }
}

void main(){ int n;
char *name;
    int i = 0, j = 0, k = 0;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
            relationMat[i][j] = 0;
    }
  system("cls");
    system("color 9");
    printf("\n\n\t\t\t\tWELCOME");
    for(int i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
printf("\n\n\t\tENTER THE NUMBER OF USERS: ");
scanf("%d",&n);
numbOfUsers=n;
usersIndex=n-1;
for (i = 0; i < n; i++)
    {
        printf("Enter name %d: ", i + 1);
        gets(name);
        addUser(name);
    }

    
}
        

        