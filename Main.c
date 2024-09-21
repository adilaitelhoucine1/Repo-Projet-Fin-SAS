#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#define MAX_USERS 100
#define MAX_CLAIMS 100

typedef struct {
    int id;
    char Motif[100];
    char description[255];
    char categorie[50];
    char status[20];
    char date[20];
    char notes[100];
    char periorite[100];
    char username[60]
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


    printf("Veuillez patienter 10 secondes avant de r�essayer...\n");
    sleep(10);
}

void generer_role() {

    int i, modifie = 0;
    char nom[20];
    printf("Entrer le nom de Client � changer en agent: ");
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
        printf("Utilisateur %s non trouv�\n", nom);
    }
}

void Ajout_reclamation() {
    srand(time(NULL));
    reclamation newreclamation;
    newreclamation.id = rand() % 100 + 1;

    printf("Entrer Le Motif : \n");
    scanf(" %[^\n]", newreclamation.Motif);

    printf("Entrer Le Description : \n");
    scanf(" %[^\n]", newreclamation.description);

    printf("Entrer La Categorie : \n");
    scanf(" %[^\n]", newreclamation.categorie);

    strcpy(newreclamation.status, "en Attent");
    strcpy(newreclamation.notes, "Aucune Note A affiche \n");

    // Ajout de la date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strftime(newreclamation.date, sizeof(newreclamation.date), "%d-%m-%Y %H:%M:%S", &tm);

    // Assigner la priorit�
    attribuerPriorite(&newreclamation);

    // Ajouter la nouvelle r�clamation au tableau
    if (claimCount < MAX_CLAIMS) {
        claims[claimCount] = newreclamation;
        claimCount++;
        printf("R�clamation ajout�e avec succ�s.\n");
    } else {
        printf("Erreur : Limite de r�clamations atteinte.\n");
    }
}


void affiche_reclamations() {
    if (claimCount == 0) {
        printf("Aucune reclamation � afficher.\n");
        return;
    }

    printf("\n==================== Liste des R�clamations ====================\n");
    for (int i = 0; i < claimCount; i++) {
        printf("ID: %d\n", claims[i].id);
        printf("Motif: %s\n", claims[i].Motif);
        printf("Description: %s\n", claims[i].description);
        printf("Cat�gorie: %s\n", claims[i].categorie);
        printf("Statut: %s\n", claims[i].status);
        printf("Date: %s\n", claims[i].date);
        printf("Notes: %s\n",claims[i].notes);
        printf("---------------------------------------------------------------\n");
    }
}

void modifier_reclamation() {
    int id;
    printf("Entrez l'ID de la reclamation � modifier: ");
    scanf("%d", &id);


    for (int i = 0; i < claimCount; i++) {
        if (claims[i].id == id) {
            printf("R�clamation trouv�e:\n");
            printf("Motif: %s\n", claims[i].Motif);
            printf("Description: %s\n", claims[i].description);
            printf("Cat�gorie: %s\n", claims[i].categorie);
            printf("Statut: %s\n", claims[i].status);
            printf("Date: %s\n", claims[i].date);

            // Demander les nouvelles infos
            char nouveauMotif[100];
            printf("Entrez le nouveau motif: ");
            scanf(" %[^\n]", nouveauMotif);
            strcpy(claims[i].Motif, nouveauMotif);

            char nouvelleDescription[255];
            printf("Entrez la nouvelle description: ");
            scanf(" %[^\n]", nouvelleDescription);
            strcpy(claims[i].description, nouvelleDescription);

            char nouvelleCategorie[50];
            printf("Entrez la nouvelle cat�gorie: ");
            scanf(" %[^\n]", nouvelleCategorie);
            strcpy(claims[i].categorie, nouvelleCategorie);

            printf("R�clamation modifi�e avec succ�s.\n");
            return;
        }
    }

    printf("Erreur : R�clamation avec l'ID %d non trouv�e.\n", id);
}
void supprimer_reclamation() {

    int id;
    if(claimCount==0){
        printf("Aucune Reclamation a Supprimer\n");
        return ;
    }
    printf("Entrez l'ID de la r�clamation � supprimer: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].id == id) {
            found = 1;
            for (int j = i; j < claimCount - 1; j++) {
                claims[j] = claims[j + 1];
            }
            claimCount--;
            printf("Reclamation avec ID %d supprimee avec succes.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Erreur : Reclamation avec l'ID %d non trouvee.\n", id);
    }
}
void modifer_status(int choix){
    int id;
    printf("Entrez l'ID de la reclamation � modifier: ");
    scanf("%d", &id);


    for (int i = 0; i < claimCount; i++) {
        if (claims[i].id == id){
            if(choix==1){
                  strcpy(claims[i].status,"en cours");
            }else if(choix==2){
                     strcpy(claims[i].status,"resolue");
            }else{
                     strcpy(claims[i].status,"fermee");
            }
        }
    }
}
void clientMenu() {
    int choice;
    do {
        printf("\n========== Client Menu ==========\n");
        printf("1. Ajouter reclamation\n");
        printf("2. Lister My Claims\n");
        printf("3. Modify My Claim\n");
        printf("4. Delete My Claim\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                 Ajout_reclamation();
                break;
            case 2:
                affiche_reclamations();
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
void traiter_reclamation(){
  int ID;
  int choix;
  printf("entrer l'ID de la reclamation � traiter :");
  scanf("%d",&ID);
   for(int i =0;i<claimCount;i++){
    if(ID==claims[i].id){
        printf("\n1.reclamation en cours de traitement.\n");
        printf("2.reclamation resolue.\n");
        printf("3.reclamation rejet�e.\n");
        printf("votre choix :");
        scanf("%d",&choix);
        switch(choix){
        case 1:
            strcpy(claims[i].status,"en cours");
            break;
        case 2:
            strcpy(claims[i].status,"resole");
            break;
        case 3:
            strcpy(claims[i].status,"rejet�e");
            break;
        default:
            printf("choix invalide.\n");
        }
        printf("ajouter une note concernant le traitement:");
        scanf(" %[^\n]",&claims[i].notes);
    }
   }
}
int prioriteIndex(char *priorite) {
    if (strcmp(priorite, "haute") == 0) return 1;
    if (strcmp(priorite, "moyenne") == 0) return 2;
    return 3; // "basse"
}

void attribuerPriorite(reclamation *claim) {
    if (strstr(claim->description, "urgent") != NULL || strstr(claim->description, "immediat") != NULL) {
        strcpy(claim->periorite, "haute");
    } else if (strstr(claim->description, "important") != NULL) {
        strcpy(claim->periorite, "moyenne");
    } else {
        strcpy(claim->periorite, "basse");
    }
}

void trierReclamationsParPriorite() {
    int i, j, minIndex;
    reclamation temp;

    for (i = 0; i < claimCount - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < claimCount; j++) {
            // Comparer les priorit�s par index
            if (prioriteIndex(claims[j].periorite) < prioriteIndex(claims[minIndex].periorite)) {
                minIndex = j;
            }
        }

        // �changer les r�clamations si n�cessaire
        if (minIndex != i) {
            temp = claims[i];
            claims[i] = claims[minIndex];
            claims[minIndex] = temp;
        }
    }

    printf("Reclamations triees par priorite avec succes.\n");
}

void afficherReclamationsTriees() {
    trierReclamationsParPriorite();
    affiche_reclamations(); // Appelle la fonction existante pour afficher les r�clamations
}
void rechercher_reclamation() {
    int id;
    char motif[100];
    int choix;

    printf("Voulez-vous rechercher par:\n");
    printf("1. ID\n");
    printf("2. Motif\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    getchar();

    if (choix == 1) {
        printf("Entrez l'ID de la reclamation: ");
        scanf("%d", &id);
        int idfound = 0;

        for (int i = 0; i < claimCount; i++) {
            if (claims[i].id == id) {
                printf("\n--Reclamation trouvee--:\n");
                printf("ID: %d\n", claims[i].id);
                printf("Motif: %s\n", claims[i].Motif);
                printf("Description: %s\n", claims[i].description);
                printf("Categorie: %s\n", claims[i].categorie);
                printf("Statut: %s\n", claims[i].status);
                printf("Date: %s\n", claims[i].date);
                printf("Notes: %s\n", claims[i].notes);
                idfound = 1;
                break;
            }
        }

        if (!idfound) {
            printf("-!- Aucune reclamation trouvee cet ID -!- .\n");
        }

    } else if (choix == 2) {
        printf("Entrez le motif de la reclamation: ");
        scanf(" %[^\n]", motif);
        int motiffound = 0;

        for (int i = 0; i < claimCount; i++) {
            if (strcmp(claims[i].Motif, motif) == 0) {
                printf("\n--Reclamation trouvee--:\n");
                printf("ID: %d\n", claims[i].id);
                printf("Motif: %s\n", claims[i].Motif);
                printf("Description: %s\n", claims[i].description);
                printf("Cat�gorie: %s\n", claims[i].categorie);
                printf("Statut: %s\n", claims[i].status);
                printf("Date: %s\n", claims[i].date);
                printf("Notes: %s\n", claims[i].notes);
                motiffound = 1;
            }
        }

        if (!motiffound) {
            printf("-!- Aucune reclamation trouvee avec ce Motif -!-\n");
        }

    } else {
        printf("-!- Choix invalide -!- \n");
    }
}

void adminMenu() {
    int choice;
    do {
        printf("\n========== Admin Menu ==========\n");
        printf("1. Gerer les roles des utilisateurs\n");
        printf("2. Ajouter une reclamations\n");
        printf("3. Afficher la liste des reclamations\n");
        printf("4. Modifier une reclamation\n");
        printf("5. Supprimer une reclamation\n");
        printf("6. Traiter une reclamation\n");
        printf("7. Rechercher une reclamation\n");
        printf("8. Afficher les reclamations ordonnees par priorite\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                generer_role();
                break;
            case 2:
                Ajout_reclamation();
                break;
            case 3:
                affiche_reclamations();
                break;
            case 4:
                modifier_reclamation();
                break;
            case 5:
                supprimer_reclamation();
                break;
            case 6:
                traiter_reclamation();
                break;
            case 7:
                rechercher_reclamation();
                break;
            case 8:
                afficherReclamationsTriees();
                break;
            case 9:
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


    printf("Veuillez patienter 10 secondes avant de r�essayer...\n");
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
    int validunput=scanf("%d", &choice);
    getchar();

        if(validunput){
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
                printf("Merci d utuliser notre application \n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
        }

    } while (choice != 0 );

    return 0;
}
