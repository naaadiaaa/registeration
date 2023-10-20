   #include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#ifndef __cplusplus
#include <stdbool.h>
#endif





#define MAXUSERS 100

 
 

 
    typedef struct {
    char username[100];
    char password[100];
    char indecator[100];
    
     } User;
    

User Users[MAXUSERS];
int num_of_users = 0;



void registeration() {
    if (num_of_users >= MAXUSERS) {
        printf("you will exceed the maximum capacity\n");
        return;
    }


    User NewUser;


    printf("Enter username: ");
    scanf("%s", NewUser.username);

    for (int i = 0; i < num_of_users; i++) {
        if (strcmp(Users[i].username, NewUser.username) == 0) {
            printf("..........Username already exists,Please choose a different username..........\n");
            return;
        }
    }


    

    printf("Enter password: ");
    scanf("%s", NewUser.password);


     printf("Enter indecator: ");
    scanf("%s", NewUser.indecator);


    Users[num_of_users] = NewUser;
    num_of_users++;

    printf("_____Registration successful______\n");
}

void Login() {
    char username[100];
    char password[100];
     
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < num_of_users; i++) {
        if (strcmp(Users[i].username, username) == 0 && strcmp(Users[i].password, password) == 0) {
            if(strcmp(Users[i].indecator,"1")==0 || strcmp(Users[i].indecator,"true")==0){
               
                printf("__________Login SUCCESS___________\n");
            }else{

           printf("________In active account_________\n");
            }

            return;
           
        }
    }

   printf("_________Invalid username or password_________\n");
}

int main() {
   int i;

   do {
       
       printf("To Reister type 1,To Login type 2 \n");
       scanf("%d", &i);

       switch(i) {
           case 1:
               registeration();
               break;
           case 2:
               Login();
               break;
               
           default:
               printf("............Exit.............\n");
       }
   } while(1);

   
   
   
   return 0;
}