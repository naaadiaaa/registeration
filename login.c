 #include <stdio.h>
#include <stdlib.h>
#include <string.h> 


#define MAXUSERS 100



typedef struct {
    char username[100];
    char password[100];
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

    Users[num_of_users] = NewUser;
    num_of_users++;

    printf("Registration successful.\n");
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
            printf("Login successful.\n");
            return;
        }
    }

   printf("Invalid username or password.\n");
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
