#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#define MAX_USERS 100
#define MAX_CLAIMS 100

void printTab(){
	printf("\t\t\t\t\t");
}
typedef struct {
    int id;
    char Motif[100];
    char description[255];
    char categorie[50];
    char status[20];
    char date[20];
    char notes[100];
    char periorite[100];
    char username[60];
    char date_resolue[20];
    int index_resolue; //si il est 1 alors reclama est resolue
} reclamation;

typedef struct {
    char username[20];
    char password[20];
    char email[50];
    char role[10]; // "admin", "agent","client"
} User;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep function
#include <windows.h> // for system colors (only works on Windows)



void error404(){

	system("color 4");
	printf("\n\n\n\n\n\n\n");
printTab();	printf("  ______                                  _  _      ___    _  _   \n");
printTab();	printf(" |  ____|                                | || |    / _ \\  | || |  \n");
printTab();	printf(" | |__     _ __   _ __    ___    _ __    | || |_  | | | | | || |_ \n");
printTab();	printf(" |  __|   | '__| | '__|  / _ \\  | '__|   |__   _| | | | | |__   _|\n");
printTab();	printf(" | |____  | |    | |    | (_) | | |         | |   | |_| |    | |  \n");
printTab();	printf(" |______| |_|    |_|     \\___/  |_|         |_|    \\___/     |_|  \n");

	sleep(2);




    system("color 07"); // Default white text, black background
}


void effacer_console() {
    system("cls"); // Efface l'écran sous Windows
}


void effet_texte(const char* texte) {
    for (int i = 0; texte[i] != '\0'; i++) {
        printf("%c", texte[i]);
        fflush(stdout); // Force l'affichage immédiat du caractère
        Sleep(1); // Pause de 50 millisecondes entre chaque lettre
    }
}

void afficher_ascii_art() {
    const char* message =
    "$$$$$$$\\  $$\\                                                                                                                    $$\\ $$\\                   $$\\     $$\\                                 \n"
    "$$  __$$\\ \\__|                                                                                                                   $$ |\\__|                  $$ |    \\__|                                \n"
    "$$ |  $$ |$$\\  $$$$$$\\  $$$$$$$\\$$\\    $$\\  $$$$$$\\  $$$$$$$\\  $$\\   $$\\  $$$$$$\\                   $$$$$$\\   $$$$$$\\   $$$$$$\\  $$ |$$\\  $$$$$$$\\$$$$$$$\\$$$$$$$\\   $$\\  $$$$$$\\  $$$$$$$\\              \n"
    "$$$$$$$$ |$$ |$$  __$$\\ $$  __$$\\$$\\  $$  |$$  __$$\\ $$  __$$\\ $$ |  $$ |$$  __$$\\                  \\____$$\\ $$  __$$\\ $$  __$$\\ $$ |$$ |$$  _____\\____$$\\_$$  _|  $$ |$$  __$$\\ $$  __$$\\            \n"
    "$$  __$$\\ $$ |$$$$$$$$ |$$ |  $$ \\$$\\$$  / $$$$$$$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$ |                 $$$$$$$ |$$ /  $$ |$$ /  $$ |$$ |$$ |$$ /     $$$$$$$ |$$ |    $$ |$$ /  $$ |$$ |  $$ |           \n"
    "$$ |  $$ |$$ |$$   ____|$$ |  $$ |\\$$$  /  $$   ____|$$ |  $$ |$$ |  $$ |$$   ____|                $$  __$$ |$$ |  $$ |$$ |  $$ |$$ |$$ |$$ |    $$  __$$ |$$ |$$\\ $$ |$$ |  $$ |$$ |  $$ |           \n"
    "$$$$$$$  |$$ |\\$$$$$$$\\ $$ |  $$ | \\$  /   \\$$$$$$$\\ $$ |  $$ |\\$$$$$$  |\\$$$$$$$\\                 \\$$$$$$$ |$$$$$$$  |$$$$$$$  |$$ |$$ |\\$$$$$$$\\$$$$$$$ |\\$$$$  |$$ |\\$$$$$$  |$$ |  $$ |           \n"
    "\\_______/ \\__| \\_______|\\__|  \\__|  \\_/     \\_______|\\__|  \\__| \\______/  \\_______|                 \\_______|$$  ____/ $$  ____/ \\__|\\__| \\_______\\_______| \\____/ \\__| \\______/ \\__|  \\__|           \n"
    "                                                                                                             $$ |      $$ |                                                                            \n"
    "                                                                                                             $$ |      $$ |                                                                            \n"
    "                                                                                                             \\__|      \\__|                                                                            \n"
    "      $$\\                                               $$\\     $$\\                                                                                                                                    \n"
    "      $$ |                                              $$ |    \\__|                                                                                                                                  \n"
    " $$$$$$$ | $$$$$$\\         $$$$$$\\   $$$$$$\\  $$$$$$$\\$$$$$$\\   $$\\  $$$$$$\\  $$$$$$$\\                                                                                                                 \n"
    "$$  __$$ |$$  __$$\\       $$  __$$\\ $$  __$$\\$$  _____\\_$$  _|  $$ |$$  __$$\\ $$  __$$\\                                                                                                                \n"
    "$$ /  $$ |$$$$$$$$ |      $$ /  $$ |$$$$$$$$ \\$$$$$$\\   $$ |    $$ |$$ /  $$ |$$ |  $$ |                                                                                                               \n"
    "$$ |  $$ |$$   ____|      $$ |  $$ |$$   ____|\\____$$\\  $$ |$$\\ $$ |$$ |  $$ |$$ |  $$ |                                                                                                               \n"
    "\\$$$$$$$ |\\$$$$$$$\\       \\$$$$$$$ |\\$$$$$$$\\$$$$$$$  | \\$$$$  |$$ |\\$$$$$$  |$$ |  $$ |                                                                                                               \n"
    " \\_______| \\_______|       \\____$$ | \\_______\\_______/   \\____/ \\__| \\______/ \\__|  \\__|                                                                                                               \n"
    "                          $$\\   $$ |                                                                                                                                                                 \n"
    "                          \\$$$$$$  |                                                                                                                                                                 \n"
    "                           \\______/                                                                                                                                                                    \n"
    "      $$\\                                    $$$$$$$\\                      $$\\                                   $$\\     $$\\                                                                           \n"
    "      $$ |                                   $$  __$$\\                     $$ |                                  $$ |    \\__|                                                                          \n"
    " $$$$$$$ | $$$$$$\\  $$$$$$$\\                 $$ |  $$ | $$$$$$\\   $$$$$$$\\ $$ | $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\$$$$$$\\   $$\\  $$$$$$\\  $$$$$$$\\   $$$$$$$\\                                             \n"
    "$$  __$$ |$$  __$$\\$$  _____|                $$$$$$$  |$$  __$$\\ $$  _____|$$ | \\____$$\\ $$  _$$  _$$\\  \\____$$\\_$$  _|  $$ |$$  __$$\\ $$  __$$\\ $$  _____|                                            \n"
    "$$ /  $$ |$$$$$$$$ \\$$$$$$\\                  $$  __$$< $$$$$$$$ |$$ /      $$ | $$$$$$$ |$$ / $$ / $$ | $$$$$$$ |$$ |    $$ |$$ /  $$ |$$ |  $$ |\\$$$$$$\\                                              \n"
    "$$ |  $$ |$$   ____|\\____$$\\                 $$ |  $$ |$$   ____|$$ |      $$ |$$  __$$ |$$ | $$ | $$ |$$  __$$ |$$ |$$\\ $$ |$$ |  $$ |$$ |  $$ | \\____$$\\                                             \n"
    "\\$$$$$$$ |\\$$$$$$$\\$$$$$$$  |                $$ |  $$ |\\$$$$$$$\\ \\$$$$$$$\\ $$ |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$ |\\$$$$  |$$ |\\$$$$$$  |$$ |  $$ |$$$$$$$  |                                            \n"
    " \\_______| \\_______|\\_______/                 \\__|  \\__| \\_______| \\_______|\\__| \\_______|\\__| \\__| \\__| \\_______| \\____/ \\__| \\______/ \\__|  \\__|\\_______/                                             \n"
    "";

    effet_texte(message);
}

void afficher_intro() {
    system("cls"); // Effacer l'écran
    afficher_ascii_art();
    Sleep(50);
    effet_texte("Gestion de Reclamations\n");
    Sleep(50);
    system("cls"); // Effacer l'écran
}




char* obtenir_date_actuelle() {
    // Allouer de la mémoire pour la chaîne de caractères
    char* buffer = malloc(100 * sizeof(char));
    if (buffer == NULL) {
        return NULL; // Vérification de l'allocation
    }

    // Obtenir l'heure actuelle
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Formater la date et l'heure actuelles
    strftime(buffer, 100, "%d-%m-%Y %H:%M:%S", &tm);

    // Retourner la chaîne de caractères
    return buffer;
}


struct tm string_to_tm(const char* date_str) {
    struct tm tm = {0};

    // Extraire les valeurs de la chaîne et les stocker dans la structure tm
    sscanf(date_str, "%d-%d-%d %d:%d:%d",
           &tm.tm_mday, &tm.tm_mon, &tm.tm_year,
           &tm.tm_hour, &tm.tm_min, &tm.tm_sec);

    // Ajuster les valeurs pour la structure tm
    tm.tm_year -= 1900;  // tm_year est l'année depuis 1900
    tm.tm_mon -= 1;      // Les mois vont de 0 (janvier) à 11 (décembre)

    return tm;
}



int difference_entre_dates(const char* date1_str, const char* date2_str) {
    // Conversion des chaînes en struct tm
    struct tm tm_date1 = string_to_tm(date1_str);
    struct tm tm_date2 = string_to_tm(date2_str);

    // Conversion en time_t (nombre de secondes depuis Epoch)
    time_t time1 = mktime(&tm_date1);
    time_t time2 = mktime(&tm_date2);

    // Calcul de la différence en secondes
    return difftime(time2, time1);
}


User users[MAX_USERS];
int userCount = 0;
int nombre_reclama_resolue=0;
reclamation claims[MAX_CLAIMS];
int diff__reclama_resolu[MAX_CLAIMS];
int claimCount = 0;
int differences[MAX_CLAIMS]; // Pour stocker les différences
int differenceCount = 0; // Pour suivre le nombre de différences stockées

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
        printf("\n Vous avez cree votre compte avec succes.\n");
        userCount++;
    } else {
        printf("\n -!- Erreur : Limite d'utilisateurs atteinte -!-.\n");
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
                clientMenu(users[i].username); // Passe le nom d'utilisateur
                return;
            }
        }

        if (trouve == 1) {
            return;
        } else {
            printf("Connexion echouee\n");
        }

        count++;
        printf("\n Attention il vous reste %d tentative(s)\n", (3 - count) + 1);
    }

    printf("\nErreur !! Mot de passe incorrect 3 fois\n");
    printf("Veuillez patienter 10 secondes avant de réessayer...\n");
    sleep(10);
}

void generer_role() {


    int i, modifie = 0;
    char nom[20];
    printf("Entrer le nom de Client a changer en agent: ");
    scanf(" %[^\n]", nom);

    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, nom) == 0) {
            strcpy(users[i].role,"agent");
            modifie = 1;
            break;
        }
    }
    if (modifie == 1) {
        printf("\n Utilisateur %s est maintenant agent\n", nom);
    } else {
        printf("Utilisateur %s non trouve\n", nom);
    }
}
void Ajout_reclamation_client(char *username) {

    srand(time(NULL));
    reclamation newreclamation;
    newreclamation.id = rand() % 100 + 1;
    newreclamation.index_resolue=0;

    printf("Entrer Le Motif : \n");
    scanf(" %[^\n]", newreclamation.Motif);

    printf("Entrer La Description : \n");
    scanf(" %[^\n]", newreclamation.description);

    printf("Entrer La Categorie : \n");
    scanf(" %[^\n]", newreclamation.categorie);

    strcpy(newreclamation.status, "en Attent");
    strcpy(newreclamation.notes, "Aucune Note A affiche");


    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strftime(newreclamation.date, sizeof(newreclamation.date), "%d-%m-%Y %H:%M:%S", &tm);


    attribuerPriorite(&newreclamation);
    strcpy(newreclamation.username, username);

    if (claimCount < MAX_CLAIMS) {
        claims[claimCount] = newreclamation;
        claimCount++;
        printf("Reclamation ajoutee avec succes.\n");
    } else {
        printf("Erreur : Limite de reclamations atteinte.\n");
    }
}
void Ajout_reclamation_All() {


    srand(time(NULL));
    reclamation newreclamation;
    newreclamation.id = rand() % 100 + 1;

    printf("Entrer Le Motif : \n");
    scanf(" %[^\n]", newreclamation.Motif);

    printf("Entrer La Description : \n");
    scanf(" %[^\n]", newreclamation.description);

    printf("Entrer La Categorie : \n");
    scanf(" %[^\n]", newreclamation.categorie);

    strcpy(newreclamation.status, "en Attent");
    strcpy(newreclamation.notes, "Aucune Note A affiche \n");


    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strftime(newreclamation.date, sizeof(newreclamation.date), "%d-%m-%Y %H:%M:%S", &tm);


    attribuerPriorite(&newreclamation);
    if (claimCount < MAX_CLAIMS) {
        claims[claimCount] = newreclamation;
        claimCount++;
        printf("Réclamation ajoutee avec succes.\n");
    } else {
        printf("Erreur : Limite de reclamations atteinte.\n");
    }
}
void affiche_reclamations_client(char *username) {

    if (claimCount == 0) {
        printf("Aucune reclamation a afficher.\n");
        return 0;
    }

    printf("\n==================== Liste des Réclamations ====================\n");
    for (int i = 0; i < claimCount; i++) {
        if (strcmp(claims[i].username, username) == 0) { // Affiche  les réclamations  dya  client bohdo
            printf("ID: %d\n", claims[i].id);
            printf("Motif: %s\n", claims[i].Motif);
            printf("Description: %s\n", claims[i].description);
            printf("Catégorie: %s\n", claims[i].categorie);
            printf("Statut: %s\n", claims[i].status);
            printf("Date: %s\n", claims[i].date);
            printf("Notes: %s\n", claims[i].notes);
            printf("---------------------------------------------------------------\n");
        }
    }
}
void affiche_reclamations_All() {


    if (claimCount == 0) {
        printf("Aucune reclamation a afficher.\n");
        return 0;
    }

    printf("\n==================== Liste des Réclamations ====================\n");
    for (int i = 0; i < claimCount; i++) {
            printf("ID: %d\n", claims[i].id);
            printf("Motif: %s\n", claims[i].Motif);
            printf("Description: %s\n", claims[i].description);
            printf("Categorie: %s\n", claims[i].categorie);
            printf("Statut: %s\n", claims[i].status);
            printf("Date: %s\n", claims[i].date);
            printf("Notes: %s\n", claims[i].notes);
            printf("Fait par : %s\n", claims[i].username);
            printf("---------------------------------------------------------------\n");
        }

}
void modifier_reclamation_client(char *username) {

    int id;
    printf("Entrez l'ID de la reclamation a modifier: ");
    scanf("%d", &id);

    for (int i = 0; i < claimCount; i++) {
        if (claims[i].id == id && strcmp(claims[i].username, username) == 0) { // Vérifie que l'utilisateur est le propriétaire
        if(difference_entre_dates(claims[i].date,obtenir_date_actuelle())<10){ // jai tester 10 second
            printf("Reclamation trouvée:\n");
            printf("Motif: %s\n", claims[i].Motif);
            printf("Description: %s\n", claims[i].description);
            printf("Categorie: %s\n", claims[i].categorie);
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
            printf("Entrez la nouvelle categorie: ");
            scanf(" %[^\n]", nouvelleCategorie);
            strcpy(claims[i].categorie, nouvelleCategorie);

            printf("Reclamation modifiee avec succes.\n");
            return;
        }else{
                printf("Vous avez passer le delai de modification ( 24 h)\n");
                return;
        }
    }

    printf("Reclamation non trouvee ou vous n'etes pas le proprietaire.\n");
}
}
void modifier_reclamation_All() {

    int id;
    printf("Entrez l'ID de la reclamation à modifier: ");
    scanf("%d", &id);

    for (int i = 0; i < claimCount; i++) {
        if(claims[i].id==id){

            printf("Reclamation trouvee:\n");
            printf("Motif: %s\n", claims[i].Motif);
            printf("Description: %s\n", claims[i].description);
            printf("Catégorie: %s\n", claims[i].categorie);
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
            printf("Entrez la nouvelle categorie: ");
            scanf(" %[^\n]", nouvelleCategorie);
            strcpy(claims[i].categorie, nouvelleCategorie);

            printf("Reclamation modifiee avec succes.\n");
            return;

    }else{
            printf("Erreur : Reclamation avec l'ID %d non trouvee.\n", id);
         }
    }
}

void supprimer_reclamation_client(char *username) {
    int id;
    if(claimCount==0){
        printf("Aucune Reclamation a Supprimer\n");
        return ;
    }
    printf("Entrez l'ID de la reclamation à supprimer: ");
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
void supprimer_reclamation_All() {
    int id;
    if(claimCount==0){
        printf("Aucune Reclamation a Supprimer\n");
        return ;
    }
    printf("Entrez l'ID de la reclamation a supprimer: ");
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
    printf("Entrez l'ID de la reclamation à modifier: ");
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
void clientMenu(char *username) {

    int choice;
    do {
        printf("\n----------- Menu Client -----------\n");
        printf("1. Ajouter une reclamation\n");
        printf("2. Afficher mes reclamations\n");
        printf("3. Modifier une reclamation\n");
        printf("4. Supprimer une reclamation\n");
        printf("0. Deconnexion\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Ajout_reclamation_client(username);
                break;
            case 2:
                affiche_reclamations_client(username);
                break;
            case 3:
                modifier_reclamation_client(username);
                break;
            case 4:
                supprimer_reclamation_client(username);
                break;
            case 0:
                printf("Deconnexion reussie.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choice != 0);
}

void traiter_reclamation() {
    int ID;
    int choix;
    printf("Entrez l'ID de la reclamation a traiter : ");
    scanf("%d", &ID);

    for (int i = 0; i < claimCount; i++) {
        if (ID == claims[i].id) {
            printf("\n1. En cours.\n");
            printf("2. Resolue.\n");
            printf("3. Rejetee.\n");
            printf("Votre choix : ");
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    strcpy(claims[i].status, "en cours");
                    break;
                case 2:
                    strcpy(claims[i].status, "resolue");
                    nombre_reclama_resolue++;
                    time_t t = time(NULL);
                    struct tm tm = *localtime(&t);
                    strftime(claims[i].date_resolue, sizeof(claims[i].date_resolue), "%d-%m-%Y %H:%M:%S", &tm);
                    claims[i].index_resolue = 1;

                    // Calcul de la différence et le stocker dans tab
                    differences[differenceCount] = difference_entre_dates(claims[i].date, claims[i].date_resolue);
                    differenceCount++;
                    break;
                case 3:
                    strcpy(claims[i].status, "rejetee");
                    break;
                default:
                    printf("Choix invalide.\n");
            }

            printf("Ajouter une note concernant le traitement : ");
            scanf(" %[^\n]", claims[i].notes);
            return;
        }
    }
    printf("Reclamation avec l'ID %d non trouvee.\n", ID);
}

int prioriteIndex(char *priorite) {

    if (strcmp(priorite, "haute") == 0) return 1;
    if (strcmp(priorite, "moyenne") == 0) return 2;
    return 3;
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
            if (prioriteIndex(claims[j].periorite) < prioriteIndex(claims[minIndex].periorite)) {
                minIndex = j;
            }
        }

        // lakan tbdl minindex hya ils sont pas trie alors on fait permutation
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
    affiche_reclamations_All();
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
                printf("Catégorie: %s\n", claims[i].categorie);
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


void Statistiques_Rapports() {
    int somme = 0;
    float moyenne;

    printf("\n========== Statistiques & Rapports ==========\n");

    // En-tête du tableau
    printf("+-------------------------------------------+\n");
    printf("|               Statistiques               |\n");
    printf("+----------------+-------------------------+\n");
    printf("| Nombre total   | %-23d |\n", claimCount);
    printf("| Reclamations   |                         |\n");
    printf("+----------------+-------------------------+\n");
    printf("| Taux de        | %d / %d                    |\n", nombre_reclama_resolue, claimCount);
    printf("| Resolution     |                          |\n");
    printf("+----------------+-------------------------+\n");

    // Calcul de la somme des différences
    for (int i = 0; i < differenceCount; i++) {
        somme += differences[i];
    }

    if (nombre_reclama_resolue != 0) {
        moyenne = (float)somme / nombre_reclama_resolue; // Calcul de la moyenne
        printf("| Delai moyen    | %.2f secondes            |\n", moyenne);
    } else {
        printf("| Delai moyen    | Aucune reclamation       |\n");
        printf("|                | resolue                  |\n");
    }

    // Pied de tableau
    printf("+----------------+-------------------------+\n");
    printf("=============================================\n");
}


int Diff_time(char *date1, char *date2) {
    struct tm tm1 = {0}, tm2 = {0};

    // Utilisation de sscanf pour parser les dates
    sscanf(date1, "%d-%d-%d %d:%d:%d", &tm1.tm_mday, &tm1.tm_mon, &tm1.tm_year,
           &tm1.tm_hour, &tm1.tm_min, &tm1.tm_sec);
    sscanf(date2, "%d-%d-%d %d:%d:%d", &tm2.tm_mday, &tm2.tm_mon, &tm2.tm_year,
           &tm2.tm_hour, &tm2.tm_min, &tm2.tm_sec);

    // Ajustement de l'année et du mois
    tm1.tm_year -= 1900; // l'année commence à 1900
    tm1.tm_mon -= 1;     // le mois commence à 0
    tm2.tm_year -= 1900;
    tm2.tm_mon -= 1;

    // Conversion en time_t
    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);

    // Calcul de la différence en secondes
    return difftime(time2, time1);
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
        printf("9. Statistiques et Rapports\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                generer_role();
                break;
            case 2:
                Ajout_reclamation_All("admin");
                break;
            case 3:
                affiche_reclamations_All("admin");
                break;
            case 4:
                modifier_reclamation_All("admin");
                break;
            case 5:
                supprimer_reclamation_All("admin");
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
                Statistiques_Rapports();
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
           agentMenu();
            return;
        } else {
            printf("Connexion echouee\n");
        }

        count++;
        printf("\nAttention il vous reste %d tentative(s)\n", (3 - count) + 1);
    }

    printf("\nErreur !! Mot de passe incorrect 3 fois\n");


    printf("Veuillez patienter 10 secondes avant de reessayer...\n");
    sleep(10);
}

void agentMenu() {
    int choice;
    do {
        printf("\n========== Agent Menu ==========\n");
        printf("1. Ajouter une reclamations\n");
        printf("2. Afficher la liste des reclamations\n");
        printf("3. Modifier une reclamation\n");
        printf("4. Supprimer une reclamation\n");
        printf("5. Traiter une reclamation\n");
        printf("6. Rechercher une reclamation\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                Ajout_reclamation_All("agent");
                break;
            case 2:
                affiche_reclamations_All("agent");
                break;
            case 3:
                modifier_reclamation_All("agent");
                break;
            case 4:
                supprimer_reclamation_All("agent");
                break;
            case 5:
                traiter_reclamation();
                break;
            case 6:
                rechercher_reclamation();
                break;
            case 0:
                printf("Deconnexon comme agent...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}
int main() {
     //afficher_intro();
//again :
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
                error404();

                system("cls");
                //goto again;
        }
        }

    } while (choice != 0 );

    return 0;
}
