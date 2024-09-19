#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define MAX_USERS 100
#define MAX_CLAIMS 100

typedef struct {
    int id;
    char clientName[50];
    char reason[100];
    char description[255];
    char category[50];
    char status[20];
    char date[20];
} reclamation;

typedef struct {
    char username[20];
    char password[20];
    char email[50];
    char role[10]; // "admin", "agent" ou "client"
} User;

User users[MAX_USERS];
int userCount = 0;
reclamation claims[MAX_CLAIMS];
int claimCount = 0;

int ValiderNom(char *nom) {
    for (int i = 0; i < strlen(nom); i++) {
        if (!isalpha(nom[i]) && nom[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

int ValiderMail(char *mail) {
    const char *texte = mail;
    char *ars = strchr(texte, '@');
    if (ars != NULL) {
        char *dot = strchr(ars, '.');
        if (dot != NULL) {
            return 1;
        }
    }
    return 0;
}

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

void formulaireInscription() {
    User newuser;

    printf("\n-----------Creation de compte-----------\n");
    printf("Entrez votre nom d'utilisateur: ");
    scanf(" %[^\n]", newuser.username);

    if (!ValiderNom(newuser.username)) {
        printf("Erreur : Le nom doit contenir des alphabets uniquement.\n");
        return;
    }

    printf("Entrez votre email : ");
    scanf("%s", newuser.email);

    if (!ValiderMail(newuser.email)) {
        printf("Erreur : L'email n'est pas valide (doit contenir @ et .).\n");
        return;
    }

    printf("Entrez votre mot de passe: ");
    scanf("%s", newuser.password);

    if (!validatePassword(newuser.username, newuser.password)) {
        printf("Erreur : Le mot de passe ne repond pas aux criteres requis.\n");
        return;
    }

    // Ajouter l  utilisateur au tableau
    if (userCount < MAX_USERS) {
        users[userCount] = newuser;
        printf("Vous avez cree votre compte avec succes.\n");
        userCount++;
    } else {
        printf("Erreur : Limite d'utilisateurs atteinte.\n");
    }
}

int signinAsAdmin() {
    char username[20], password[20];
    printf("Veuillez entrer le nom d'utilisateur Admin: ");
    scanf("%s", username);

    printf("Veuillez entrer le mot de passe Admin: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin@123") == 0) {
        printf("Connexion admin reussie\n");
        return 1;
    } else {
        return 0;
    }
}

void connexion() {
    int trouve = 0, count = 1;
    char username[20], password[20];

    printf("\n-----------Connexion-----------\n");
    while (count <= 3) {
        printf("Veuillez entrer le nom d'utilisateur : ");
        scanf(" %[^\n]", username);

        printf("Veuillez entrer le mot de passe : ");
        scanf("%s", password);

        for (int i = 0; i < userCount; i++) {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                trouve = 1;
                break;
            }
        }

        if (trouve == 1) {
            clientMenu();
            return;
        } else {
            printf("Connexion echouee\n");
        }

        count++;
        printf("\nAttention il vous reste %d tentative(s)\n", (3 - count) + 1);
    }

    printf("\nErreur !! Mot de passe incorrect 3 fois\n");


    printf("Veuillez patienter 10 secondes avant de réessayer...\n");
    sleep(10);
}

void generer_role() {
    int i, modifie = 0;
    char nom[20];
    printf("Entrer le nom de Client à changer en agent: ");
    scanf(" %[^\n]", nom);

    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, nom) == 0) {
            strcpy(users[i].role,"agent");
            modifie = 1;
            break;
        }
    }
    if (modifie == 1) {
        printf("Utilisateur %s est maintenant agent\n", nom);
    } else {
        printf("Utilisateur %s non trouvé\n", nom);
    }
}

void clientMenu() {
    int choice;
    do {
        printf("\n========== Client Menu ==========\n");
        printf("1. Ajoutter recl\n");
        printf("2. View My Claims\n");
        printf("3. Modify My Claim\n");
        printf("4. Delete My Claim\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                // addClaim(clientName);
                break;
            case 2:
                // viewMyClaims(clientName);
                break;
            case 3:
                // modifyMyClaim(clientName);
                break;
            case 4:
                // deleteMyClaim(clientName);
                break;
            case 0:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

void adminMenu() {
    int choice;
    do {
        printf("\n========== Admin Menu ==========\n");
        printf("1. Gerer les roles des utilisateurs\n");
        printf("2. Afficher la liste des réclamations\n");
        printf("3. Modifier une réclamation\n");
        printf("4. Supprimer une réclamation\n");
        printf("5. Traiter une réclamation\n");
        printf("6. Rechercher une réclamation\n");
        printf("7. Afficher les réclamations ordonnées par priorité\n");
        printf("8. Traiter une réclamation\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                generer_role();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                printf("Logging out as Admin...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

void connexion_agent(){
    int trouve = 0, count = 1;
    char username[20], password[20];

    printf("\n-----------Connexion-----------\n");
    while (count <= 3) {
        printf("Veuillez entrer le nom d'utilisateur : ");
        scanf(" %[^\n]", username);

        printf("Veuillez entrer le mot de passe : ");
        scanf("%s", password);

        for (int i = 0; i < userCount; i++) {

               if(strcmp(users[i].role,"agent")==0 && strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0){
                    trouve = 1;
                    break;
                }
        }

        if (trouve == 1) {
           // AgentMenu();
           printf("good");
            return;
        } else {
            printf("Connexion echouee\n");
        }

        count++;
        printf("\nAttention il vous reste %d tentative(s)\n", (3 - count) + 1);
    }

    printf("\nErreur !! Mot de passe incorrect 3 fois\n");


    printf("Veuillez patienter 10 secondes avant de réessayer...\n");
    sleep(10);
}



int main() {
    int choice;
    int i;
    do {
    printf("\n");
    printf("\n============================MENU==============================\n");
    printf("||                                                          ||\n");
    printf("||                      1. Espace admin                     ||\n");
    printf("||                      2. Inscription Client               ||\n");
    printf("||                      3. Connexion Client                 ||\n");
    printf("||                      4. Connexion Agent                  ||\n");
    printf("||                      0. Exit ...                         ||\n");
    printf("||                                                          ||\n");
    printf("==============================================================\n");
    printf("Veuillez entrer votre choix: ");
    scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (signinAsAdmin()) {
                    adminMenu();
                } else {
                    printf("Echec de la connexion en tant qu'admin\n");
                }
                break;
            case 2:
                formulaireInscription();
                break;
            case 3:
                connexion();
                break;
            case 4:
                connexion_agent();
                break;
            case 0:
                printf("Merci d'utiliser notre App !!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choice != 0);

    return 0;
}
