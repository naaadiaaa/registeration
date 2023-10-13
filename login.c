 #include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_USERS 100

typedef struct {
    char username[100];
    char password[100];
} User;

User users[MAX_USERS];
int numUsers = 0;

void registeration() {
    if (numUsers >= MAX_USERS) {
        printf("you will exceed the maximum.\n");
        return;
    }

    User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[numUsers] = newUser;
    numUsers++;

    printf("Registration successful.\n");
}

void Login() {
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

   printf("Invalid username or password.\n");
}

int main() {
   int i;

   do {
       
       printf("for register type 1,   for Login type 2,   for exit type 3 \n");
       scanf("%d", &i);

       switch(i) {
           case 1:
               registeration();
               break;
           case 2:
               Login();
               break;
               
           default:
               printf("Invalid...\n");
       }
   } while(1);

   return 0;
}
