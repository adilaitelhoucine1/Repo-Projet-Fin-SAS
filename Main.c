#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int id;
    char clientName[50];
    char reason[100];
    char description[255];
    char category[50];
    char status[20];
    char date[20];
} recla;

recla claims[MAX];
int claimCount = 0;

int validatePassword(char *username, char *password) {
    int upper = 0, lower = 0, digit = 0, special = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) upper = 1;
        else if (islower(password[i])) lower = 1;
        else if (isdigit(password[i])) digit = 1;
        else if (ispunct(password[i])) special = 1;
    }

    if (strlen(password) >= 8 && upper && lower && digit && special && !strstr(password, username)) {
        return 1;
    } else {
        return 0;
    }
}

void signup() {
    char username[20], password[20];
    printf("enter votre username: ");
    gets(username);

    printf("enter mot de pass: ");
    gets(password);

    if (validatePassword(username, password)) {
        //saveUser(username, password);
        printf("compte a est cree\n");
    } else {
        printf("mot de passe ne contient pas les requises\n");
    }
}
int signinAsAdmin() {
    char username[20], password[20];
    printf("veuillez entrer Admin username: ");
    scanf(" %[^\n]",username);

    printf("veuillez entrer Admin password: ");
    scanf(" %[^\n]",password);


    if (strcmp(username, "admin") == 0 && strcmp(password, "admin@123") == 0) {
        printf("Connexion admin reussie\n");
        return 1;
    } else {
        return 0;
    }
}
int signinAsClient() {
    char username[20], password[20];
    printf("veuillez entrer Client username : ");
    gets(username);
    printf("veuillez entrer Client mot de pass : ");
    gets(password);


        printf("connexion Client reussie\n");
        return 1;

}
int main() {
    int choice;

    do {
        printf("\n============================MENU============================\n");
        printf("1. Connectez-vous en tant qu'admin\n");
        printf("2. Connectez-vous en tant qu'agent\n");
        printf("3. Connectez-vous en tant qu'clien\n");
        printf("0. Exit ...\n");
        printf("veuillez entrer votre choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                if (signinAsAdmin()) {
                    //adminMenu();
                } else {
                    printf("echec de la connexion en tant qu'admin\n");
                }
                break;
            case 2:
                /*if (signinAsAgent()) {
                   // agentMenu();
                } else {
                printf("echec de la connexion en tant qu'agent\n");
                }
                break;*/
            case 3:
                /*if (signinAsClient()) {
                    char clientName[20];
                    printf("veuillez entrer votre username: ");
                    gets(clientName);
                  //  clientMenu(clientName);
                } else {
                    printf("echec de la connexion en tant qu'clien\n");
                }
                break;*/
            case 0:
               /* printf("Exiting program ...\n");
                brea*/;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
