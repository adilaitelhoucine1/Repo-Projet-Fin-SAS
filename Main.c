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
    char date_reject[20];
    int index_resolue; //si il est 1 alors reclama est resolue
    int index_rejecte; //si il est 1 alors reclama est rejected
} reclamation;

typedef struct {
    char username[20];
    char password[20];
    char email[50];
    char role[10]; // "admin", "agent","client"
} User;

User users[MAX_USERS];
int userCount = 0;
int nombre_reclama_resolue=0;
int nombre_reclama_rejected=0;
reclamation claims[MAX_CLAIMS];
int diff__reclama_resolu[MAX_CLAIMS];
int claimCount = 0;
int differences[MAX_CLAIMS]; // Pour stocker les diffrences
int differenceCount = 0; // Pour suivre le nombre de diffrences stockes

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

void topbar() {
    system("color 7");
    //system("cls");
    printf("\n\n");
    printTab();

    printf("\n");
    printf("                   _   _                      _            _____               _                         _   _                  \n");
    printf("                 | | (_)                    | |          |  __ \\             | |                       | | (_)                \n");
    printf("   __ _  ___  ___| |_ _  ___  _ __        __| | ___      | |__) |___    ___  | | __ _ _ __ ___   __ _  | |_ _  ___  _ __  ___ \n");
    printf("  / _` |/ _ \\/ __| __| |/ _ \\| '_ \\      / _` |/ _ \\     |  _  // _ \\  / __| | |/ _` | '_ ` _ \\ / _` | | __| |/ _ \\| '_ \\/ __|\n");
    printf(" | (_| |  __/\\__ \\ |_| | (_) | | | |    | (_| |  __/     | | \\ \\  __/ | (__  | | (_| | | | | | | (_| | | |_| | (_) | | | \\__ \\ \n");
    printf("  \\__, |\\___||___/\\__|_|\\___/|_| |_|     \\__,_|\\___|     |_|  \\_\\___|  \\___| |_|\__,_|_| |_| |_|\\__,_|  \\__|_|\\___/|_| |_|___/\n");
    printf("   __/ |                                                                                                                       \n");
    printf("  |___/                                                                                                                        \n");

    printf("\n\n\n\n");
}


void effacer_console() {
    system("cls"); // Efface l'�cran sous Windows
}


void effet_texte(const char* texte) {
    for (int i = 0; texte[i] != '\0'; i++) {
        printf("%c", texte[i]);
        fflush(stdout); // Force l'affichage imm�diat du caract�re
        Sleep(1);
    }
}

void afficher_ascii_art() {
     system("color 3");
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
     system("color 07");
}

void afficher_intro() {
    //system("cls"); // Effacer l'�cran
    afficher_ascii_art();
    //Sleep(50);
    effet_texte("Gestion de Reclamations\n");
   // Sleep(50);
    system("cls"); // Effacer l'�cran
}




char* obtenir_date_actuelle() {
    // Allouer de la m�moire pour la cha�ne de caract�res
    char* buffer = malloc(100 * sizeof(char));
    if (buffer == NULL) {
        return NULL; // V�rification de l'allocation
    }

    // Obtenir l'heure actuelle
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Formater la date et l'heure actuelles
    strftime(buffer, 100, "%d-%m-%Y %H:%M:%S", &tm);

    // Retourner la cha�ne de caract�res
    return buffer;
}


struct tm string_to_tm(const char* date_str) {
    struct tm tm = {0};

    sscanf(date_str, "%d-%d-%d %d:%d:%d",
           &tm.tm_mday, &tm.tm_mon, &tm.tm_year,
           &tm.tm_hour, &tm.tm_min, &tm.tm_sec);

    tm.tm_year -= 1900;
    tm.tm_mon -= 1;

    return tm;
}



int difference_entre_dates(const char* date1_str, const char* date2_str) {
    // Conversion des cha�nes en struct tm
    struct tm tm_date1 = string_to_tm(date1_str);
    struct tm tm_date2 = string_to_tm(date2_str);

    // Conversion en time_t (nombre de secondes depuis Epoch)
    time_t time1 = mktime(&tm_date1);
    time_t time2 = mktime(&tm_date2);

    // Calcul de la diff�rence en secondes
    return difftime(time2, time1);
}




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

   printTab();printf("-----------Creation de compte-----------\n");
    printTab();printf("Entrez votre nom d'utilisateur: ");
    scanf(" %[^\n]", newuser.username);

    if (!ValiderNom(newuser.username)) {
        printTab();printf("Erreur : Le nom doit contenir des alphabets uniquement.\n");
        return;
    }

  printTab();  printf("Entrez votre email : ");
    scanf("%s", newuser.email);

    if (!ValiderMail(newuser.email)) {
       printTab(); printf("Erreur : L'email n'est pas valide (doit contenir @ et .).\n");
        return;
    }

  printTab();  printf("Entrez votre mot de passe: ");
    scanf("%s", newuser.password);

    if (!validatePassword(newuser.username, newuser.password)) {
      printTab();  printf("Erreur : Le mot de passe ne repond pas aux criteres requis.\n");
        return;
    }

    // Ajouter l  utilisateur au tableau
    if (userCount < MAX_USERS) {
        users[userCount] = newuser;
      printTab();  printf("\n Vous avez cree votre compte avec succes.\n");
        userCount++;
    } else {
       printTab(); printf("\n -!- Erreur : Limite d'utilisateurs atteinte -!-.\n");
    }
}
int signinAsAdmin() {
    char username[20], password[20];
    printTab();printf("Veuillez entrer le nom d'utilisateur Admin: ");
    scanf("%s", username);

    printTab();printf("Veuillez entrer le mot de passe Admin: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin@123") == 0) {
        printTab();printf("Connexion admin reussie\n");
        return 1;
    } else {
        return 0;
    }
}
void connexion() {
    int trouve = 0, count = 1;
    char username[20], password[20];

   printTab(); printf("-----------Connexion-----------\n");
    while (count <= 3) {
      printTab();  printf("Veuillez entrer le nom d'utilisateur : ");
        scanf(" %[^\n]", username);

      printTab();  printf("Veuillez entrer le mot de passe : ");
        scanf("%s", password);

        for (int i = 0; i < userCount; i++) {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0 && strcmp(users[i].role, "agent") == 0) {
                trouve = 1;
                clientMenu(users[i].username); // Passe le nom d'utilisateur
                return;
            }
        }

        if (trouve == 1) {
            return;
        } else {
          printTab();  printf("Connexion echouee\n");
        }

        count++;
      printTab();  printf("\n Attention il vous reste %d tentative(s)\n", (3 - count) + 1);
    }

   printTab(); printf("\nErreur !! Mot de passe incorrect 3 fois\n");
  printTab();  printf("Veuillez patienter 10 secondes avant de r�essayer...\n");
    sleep(10);
}

void generer_role() {


    int i, modifie = 0;
    char nom[20];
  printTab();  printf("Entrer le nom de Client a changer en agent: ");
    scanf(" %[^\n]", nom);

    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, nom) == 0) {
            strcpy(users[i].role,"agent");
            modifie = 1;
            break;
        }
    }
    if (modifie == 1) {
       printTab(); printf("\n Utilisateur %s est maintenant agent\n", nom);
    } else {
      printTab();  printf("Utilisateur %s non trouve\n", nom);
    }
}
void Ajout_reclamation_client(char *username) {

    srand(time(NULL));
    reclamation newreclamation;
    newreclamation.id = rand() % 100 + 1;
    newreclamation.index_resolue=0;

   printTab(); printf("Entrer Le Motif : \n");
    scanf(" %[^\n]", newreclamation.Motif);

   printTab(); printf("Entrer La Description : \n");
    scanf(" %[^\n]", newreclamation.description);

 printTab();  printf("Entrer La Categorie : \n");
    scanf(" %[^\n]", newreclamation.categorie);

    strcpy(newreclamation.status, "en Attent");
    strcpy(newreclamation.notes, "Aucune Note A affiche");


    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strftime(newreclamation.date, sizeof(newreclamation.date), "%d-%m-%Y", &tm);


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

    printTab();printf("Entrer Le Motif : \n");
    printTab();scanf(" %[^\n]", newreclamation.Motif);

 printTab();printf("Entrer La Description : \n");
   printTab(); scanf(" %[^\n]", newreclamation.description);

 printTab();printf("Entrer La Categorie : \n");
   printTab(); scanf(" %[^\n]", newreclamation.categorie);

    strcpy(newreclamation.status, "en Attent");
    strcpy(newreclamation.notes, "Aucune Note A affiche \n");


    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strftime(newreclamation.date, sizeof(newreclamation.date), "%d-%m-%Y ", &tm);


    attribuerPriorite(&newreclamation);
    if (claimCount < MAX_CLAIMS) {
        claims[claimCount] = newreclamation;
        claimCount++;
        printTab();printf("R�clamation ajoutee avec succes.\n");
    } else {
       printTab(); printf("Erreur : Limite de reclamations atteinte.\n");
    }
    //effacer_console();
    //topbar();
    adminMenu();
}
void affiche_reclamations_client(char *username) {

    if (claimCount == 0) {
        printf("Aucune reclamation a afficher.\n");
        return 0;
    }

  printTab();  printf("==================== Liste des Reclamations ====================\n");
    for (int i = 0; i < claimCount; i++) {
        if (strcmp(claims[i].username, username) == 0) { // Affiche  les reclamations  dya  client bohdo
            printf("ID: %d\n", claims[i].id);
            printf("Motif: %s\n", claims[i].Motif);
            printf("Description: %s\n", claims[i].description);
            printf("Cat�gorie: %s\n", claims[i].categorie);
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

   printTab(); printf("==================== Liste des Reclamations ====================\n");
    for (int i = 0; i < claimCount; i++) {
           printTab(); printf("ID: %d\n", claims[i].id);
           printTab(); printf("Motif: %s\n", claims[i].Motif);
           printTab(); printf("Description: %s\n", claims[i].description);
          printTab();  printf("Categorie: %s\n", claims[i].categorie);
          printTab();  printf("Statut: %s\n", claims[i].status);
          printTab();  printf("Date: %s\n", claims[i].date);
          printTab();  printf("Notes: %s\n", claims[i].notes);
          printTab();  printf("Fait par : %s\n", claims[i].username);
          printTab();  printf("---------------------------------------------------------------\n");
        }

}
void modifier_reclamation_client(char *username) {

    int id;
  printTab();  printf("Entrez l'ID de la reclamation a modifier: ");
    scanf("%d", &id);

    for (int i = 0; i < claimCount; i++) {
        if (claims[i].id == id && strcmp(claims[i].username, username) == 0) { // V�rifie que l'utilisateur est le propri�taire
        if(difference_entre_dates(claims[i].date,obtenir_date_actuelle())<10){ // jai tester 10 second
          printTab();  printf("Reclamation trouv�e:\n");
          printTab();  printf("Motif: %s\n", claims[i].Motif);
          printTab();  printf("Description: %s\n", claims[i].description);
          printTab();  printf("Categorie: %s\n", claims[i].categorie);
          printTab();  printf("Statut: %s\n", claims[i].status);
          printTab();  printf("Date: %s\n", claims[i].date);

            // Demander les nouvelles infos
            char nouveauMotif[100];
           printTab(); printf("Entrez le nouveau motif: ");
            printTab();scanf(" %[^\n]", nouveauMotif);
            strcpy(claims[i].Motif, nouveauMotif);

            char nouvelleDescription[255];
           printTab(); printf("Entrez la nouvelle description: ");
            scanf(" %[^\n]", nouvelleDescription);
            strcpy(claims[i].description, nouvelleDescription);

            char nouvelleCategorie[50];
           printTab(); printf("Entrez la nouvelle categorie: ");
           printTab(); scanf(" %[^\n]", nouvelleCategorie);
            strcpy(claims[i].categorie, nouvelleCategorie);

           printTab(); printf("Reclamation modifiee avec succes.\n");
            return;
        }else{
               printTab(); printf("Vous avez passer le delai de modification ( 24 h)\n");
                return;
        }
    }

   printTab(); printf("Reclamation non trouvee ou vous n'etes pas le proprietaire.\n");
}
}
void modifier_reclamation_All() {

    int id;
   printTab(); printf("Entrez l'ID de la reclamation � modifier: ");
    scanf("%d", &id);

    for (int i = 0; i < claimCount; i++) {
        if(claims[i].id==id){

           printTab(); printf("Reclamation trouvee:\n");
          printTab();  printf("Motif: %s\n", claims[i].Motif);
          printTab();  printf("Description: %s\n", claims[i].description);
          printTab();  printf("Cat�gorie: %s\n", claims[i].categorie);
          printTab();  printf("Statut: %s\n", claims[i].status);
          printTab();  printf("Date: %s\n", claims[i].date);

            // Demander les nouvelles infos
            char nouveauMotif[100];
           printTab(); printf("Entrez le nouveau motif: ");
            scanf(" %[^\n]", nouveauMotif);
            strcpy(claims[i].Motif, nouveauMotif);

            char nouvelleDescription[255];
          printTab();  printf("Entrez la nouvelle description: ");
            scanf(" %[^\n]", nouvelleDescription);
            strcpy(claims[i].description, nouvelleDescription);

            char nouvelleCategorie[50];
         printTab();   printf("Entrez la nouvelle categorie: ");
            scanf(" %[^\n]", nouvelleCategorie);
            strcpy(claims[i].categorie, nouvelleCategorie);

            printTab();printf("Reclamation modifiee avec succes.\n");
            return;

    }else{
           printTab(); printf("Erreur : Reclamation avec l'ID %d non trouvee.\n", id);
         }
    }
}

void supprimer_reclamation_client(char *username) {
    int id;
    if(claimCount==0){
        printf("Aucune Reclamation a Supprimer\n");
        return ;
    }
   printTab(); printf("Entrez l'ID de la reclamation � supprimer: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].id == id) {
            found = 1;
            for (int j = i; j < claimCount - 1; j++) {
                claims[j] = claims[j + 1];
            }
            claimCount--;
            printTab();printf("Reclamation avec ID %d supprimee avec succes.\n", id);
            break;
        }
    }

    if (!found) {
       printTab(); printf("Erreur : Reclamation avec l'ID %d non trouvee.\n", id);
    }
}
void supprimer_reclamation_All() {
    int id;
    if(claimCount==0){
       printTab(); printf("Aucune Reclamation a Supprimer\n");
        return ;
    }
   printTab(); printf("Entrez l'ID de la reclamation a supprimer: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].id == id) {
            found = 1;
            for (int j = i; j < claimCount - 1; j++) {
                claims[j] = claims[j + 1];
            }
            claimCount--;
          printTab();  printf("Reclamation avec ID %d supprimee avec succes.\n", id);
            break;
        }
    }

    if (!found) {
        printTab();printf("Erreur : Reclamation avec l'ID %d non trouvee.\n", id);
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
void clientMenu(char *username) {

    int choice;
    do {
      printTab();printf("\n----------- Menu Client -----------\n");
      printTab(); printf("1. Ajouter une reclamation\n");
      printTab(); printf("2. Afficher mes reclamations\n");
      printTab();  printf("3. Modifier une reclamation\n");
      printTab();  printf("4. Supprimer une reclamation\n");
      printTab();  printf("0. Deconnexion\n");
      printTab();  printf("Entrez votre choix: ");
      printTab();  scanf("%d", &choice);

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
                printTab();printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choice != 0);
}

void traiter_reclamation() {
    int ID;
    int choix;
    time_t t = time(NULL);
   printTab(); printf("Entrez l'ID de la reclamation a traiter : ");
    scanf("%d", &ID);

    for (int i = 0; i < claimCount; i++) {
        if (ID == claims[i].id) {
           printTab(); printf("1. En cours.\n");
           printTab(); printf("2. Resolue.\n");
           printTab(); printf("3. Rejetee.\n");
           printTab(); printf("Votre choix : ");
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    strcpy(claims[i].status, "en cours");
                    break;
                case 2:
                    strcpy(claims[i].status, "resolue");
                    nombre_reclama_resolue++;
                    struct tm tm = *localtime(&t);
                    strftime(claims[i].date_resolue, sizeof(claims[i].date_resolue), "%d-%m-%Y %H:%M:%S", &tm);
                    claims[i].index_resolue = 1;

                    // Calcul de la diff et le stocker dans tab
                    differences[differenceCount] = difference_entre_dates(claims[i].date, claims[i].date_resolue);
                    differenceCount++;
                    break;
                case 3:
                    strcpy(claims[i].status, "rejetee");
                    nombre_reclama_rejected++;
                    struct tm tm2 = *localtime(&t);
                    strftime(claims[i].date_reject, sizeof(claims[i].date_reject), "%d-%m-%Y %H:%M:%S", &tm2);
                    claims[i].index_resolue = 1;

                    // Calcul de la diff et le stocker dans tab
                    differences[differenceCount] = difference_entre_dates(claims[i].date, claims[i].date_reject);
                    differenceCount++;
                    break;
                default:
                   printTab(); printf("Choix invalide.\n");
            }

          printTab();  printf("Ajouter une note concernant le traitement : ");
            scanf(" %[^\n]", claims[i].notes);
            return;
        }
    }
    printTab();printf("Reclamation avec l'ID %d non trouvee.\n", ID);
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

    printTab();printf("Reclamations triees par priorite avec succes.\n");
}
void afficherReclamationsTriees() {

    trierReclamationsParPriorite();
    affiche_reclamations_All();
}/*
void afficherReclamation(claim Claim* claim) {
    printTab(); printf("\n--Reclamation trouvee--:\n");
    printTab(); printf("ID: %d\n", claim->id);
    printTab(); printf("Motif: %s\n", claim->Motif);
    printTab(); printf("Description: %s\n", claim->description);
    printTab(); printf("Categorie: %s\n", claim->categorie);
    printTab(); printf("Statut: %s\n", claim->status);
    printTab(); printf("Date: %s\n", claim->date);
    printTab(); printf("Notes: %s\n", claim->notes);
}

*/
void rechercher_reclamation() {
    int id;
    char motif[100];
    char nomClient[100];
    char date[11]; // Format date: "YYYY-MM-DD"
    char statut[20];
    char categorie[50];
    int choix;

    printTab();
    printf("Voulez-vous rechercher par:\n");
    printTab();
    printf("1. ID\n");
    printTab();
    printf("2. Motif\n");
    printTab();
    printf("3. Nom du client\n");
    printTab();
    printf("4. Date de soumission\n");
    printTab();
    printf("5. Statut\n");
    printTab();
    printf("6. Catégorie de réclamation\n");
    printTab();
    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    getchar();

    switch (choix) {
        case 1: // Recherche par ID
            printTab();
            printf("Entrez l'ID de la reclamation: ");
            scanf("%d", &id);
            int idfound = 0;

            for (int i = 0; i < claimCount; i++) {
                if (claims[i].id == id) {
                printTab();printf("Reclamation est bien trouve\n");
                    idfound = 1;
                    break;
                }
            }

            if (!idfound) {
                printTab(); printf("-!- Aucune reclamation trouvee avec cet ID -!- .\n");
            }
            break;

        case 2: // Recherche par Motif
            printTab();
            printf("Entrez le motif de la reclamation: ");
            scanf(" %[^\n]", motif);
            int motiffound = 0;

            for (int i = 0; i < claimCount; i++) {
                if (strcmp(claims[i].Motif, motif) == 0) {
                  printTab();printf("Reclamation est bien trouve\n");
                    motiffound = 1;
                }
            }

            if (!motiffound) {
                printTab(); printf("-!- Aucune reclamation trouvee avec ce Motif -!-\n");
            }
            break;

        case 3: // Recherche par Nom du client
            printTab();
            printf("Entrez le nom du client: ");
            scanf(" %[^\n]", nomClient);
            int clientFound = 0;

            for (int i = 0; i < claimCount; i++) {
                if (strcmp(claims[i].username, nomClient) == 0) {
                  printTab();printf("Reclamation est bien trouve \n");
                    clientFound = 1;
                }
            }

            if (!clientFound) {
                printTab(); printf("-!- Aucune reclamation trouvee pour ce client -!-\n");
            }
            break;

        case 4: // Recherche par Date
            printTab();
            printf("Entrez la date de soumission (YYYY-MM-DD): ");
            scanf(" %[^\n]", date);
            int dateFound = 0;

            for (int i = 0; i < claimCount; i++) {
                if (strcmp(claims[i].date, date) == 0) {
                   printTab();printf("Reclamation est bien trouve\n");
                    dateFound = 1;
                }
            }

            if (!dateFound) {
                printTab(); printf("-!- Aucune reclamation trouvee pour cette date -!-\n");
            }
            break;

        case 5: // Recherche par Statut
            printTab();
            printf("Entrez le statut (en cours, rejeté, résolu): ");
            scanf(" %[^\n]", statut);
            int statutFound = 0;

            for (int i = 0; i < claimCount; i++) {
                if (strcmp(claims[i].status, statut) == 0) {
                   printTab();printf("Reclamation est bien trouve\n");
                    statutFound = 1;
                }
            }

            if (!statutFound) {
                printTab(); printf("-!- Aucune reclamation trouvee avec ce statut -!-\n");
            }
            break;

        case 6: // Recherche par Catégorie
            printTab();
            printf("Entrez la catégorie de réclamation: ");
            scanf(" %[^\n]", categorie);
            int categorieFound = 0;

            for (int i = 0; i < claimCount; i++) {
                if (strcmp(claims[i].categorie, categorie) == 0) {
                   printTab();printf("Reclamation est bien trouve \n");
                    categorieFound = 1;
                }
            }

            if (!categorieFound) {
                printTab(); printf("-!- Aucune reclamation trouvee dans cette categorie -!-\n");
            }
            break;

        default:
            printTab(); printf("-!- Choix invalide -!- \n");
            break;
    }
}



void Statistiques_Rapports() {
    int somme = 0;
    float moyenne;

    printTab();printf("\n========== Statistiques & Rapports ==========\n");


   printTab(); printf("+-------------------------------------------+\n");
   printTab(); printf("|               Statistiques               |\n");
  printTab();  printf("+----------------+-------------------------+\n");
   printTab(); printf("| Nombre total   | %-23d |\n", claimCount);
  printTab();  printf("| Reclamations   |                         |\n");
  printTab();  printf("+----------------+-------------------------+\n");
  printTab();  printf("| Taux de        | %d / %d                    |\n", nombre_reclama_resolue, claimCount);
  printTab();  printf("| Resolution     |                          |\n");
  printTab();  printf("+----------------+-------------------------+\n");

    // Calcul de la somme des diff
    for (int i = 0; i < differenceCount; i++) {
        somme += differences[i];
    }

    if (nombre_reclama_resolue != 0 || nombre_reclama_rejected !=0) {
        moyenne = (float)somme / (nombre_reclama_resolue+nombre_reclama_rejected); // Calcul de la moyenne
        printf("| Delai moyen    | %.2f secondes            |\n", moyenne);
    } else {
                printf("| Delai moyen    | Aucune reclamation       |\n");
                printf("|                | Traite                  |\n");
    }

    printTab();printf("+----------------+-------------------------+\n");
    printTab();printf("=============================================\n");
}


int Diff_time(char *date1, char *date2) {
    struct tm tm1 = {0}, tm2 = {0};

    // Utilisation de sscanf pour parser les dates
    sscanf(date1, "%d-%d-%d %d:%d:%d", &tm1.tm_mday, &tm1.tm_mon, &tm1.tm_year,
           &tm1.tm_hour, &tm1.tm_min, &tm1.tm_sec);
    sscanf(date2, "%d-%d-%d %d:%d:%d", &tm2.tm_mday, &tm2.tm_mon, &tm2.tm_year,
           &tm2.tm_hour, &tm2.tm_min, &tm2.tm_sec);


    tm1.tm_year -= 1900;
    tm1.tm_mon -= 1;
    tm2.tm_year -= 1900;
    tm2.tm_mon -= 1;

    // Conversion en time_t
    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);

    return difftime(time2, time1); //en seconds
}

void Generer_rapport(reclamation claims[], int claimCount) {
    FILE *fichier = fopen("rapport.txt", "w");

    if (fichier == NULL) {
        printf("Erreur de l'ouverture du fichier.\n");
        return;
    }

    fprintf(fichier, "\n==================== Liste des Réclamations Resolue ====================\n");

    for (int i = 0; i < claimCount; i++) {
       if(strcmp(claims[i].status,"resolue")==0){
        fprintf(fichier, "ID: %d\n", claims[i].id);
        fprintf(fichier, "Motif: %s\n", claims[i].Motif);
        fprintf(fichier, "Description: %s\n", claims[i].description);
        fprintf(fichier, "Categorie: %s\n", claims[i].categorie);
        fprintf(fichier, "Statut: %s\n", claims[i].status);
        fprintf(fichier, "Date: %s\n", claims[i].date);
        fprintf(fichier, "Notes: %s\n", claims[i].notes);
        fprintf(fichier, "---------------------------------------------------------------\n");
       }

    }

    fprintf(fichier, "\n==================== Liste des Réclamations Daujourd'hui====================\n");
    char dates[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strftime(dates, sizeof(dates), "%d-%m-%Y", &tm);
    for (int i = 0; i < claimCount; i++) {
            if(difference_entre_dates(claims[i].date,dates) == 0){
                fprintf(fichier, "ID: %d\n", claims[i].id);
                fprintf(fichier, "Motif: %s\n", claims[i].Motif);
                fprintf(fichier, "Description: %s\n", claims[i].description);
                fprintf(fichier, "Catégorie: %s\n", claims[i].categorie);
                fprintf(fichier, "Statut: %s\n", claims[i].status);
                fprintf(fichier, "Date: %s\n", claims[i].date);
                fprintf(fichier, "Notes: %s\n", claims[i].notes);
                fprintf(fichier, "---------------------------------------------------------------\n");
            }

    }
    fclose(fichier);


   printTab(); printf("Donnees enregistrées avec succes dans rapport.txt\n"); // Corrigé le nom du fichier ici
}


void adminMenu() {

    int choice;
    do {
       printTab();    printf("============================ADMIN MENU======================================= \n");
printTab();    printf("||                                                                           ||\n");
printTab();    printf("||                      1. Gerer Role                                        ||\n");
printTab();    printf("||                      2. Ajouter Une Reclamation                           ||\n");
printTab();    printf("||                      3. Afficher la liste des reclamations                ||\n");
printTab();    printf("||                      4. Connexion Agent                                   ||\n");
printTab();    printf("||                      5. Modifier une reclamation                          ||\n");
printTab();    printf("||                      6. Supprimer une reclamation                         ||\n");
printTab();    printf("||                      7. Traiter une reclamation                           ||\n");
printTab();    printf("||                      8. Rechercher une reclamation                        ||\n");
printTab();    printf("||                      9. Afficher les reclamations ordonnees par priorite  ||\n");
printTab();    printf("||                      10. Statistiques et Rapports                         ||\n");
printTab();    printf("||                      11. Generer un Rapport journalier                    ||\n");
printTab();    printf("||                      0. Deconnexion                                       ||\n");
printTab();    printf("=============================================================================\n");
       printTab(); printf("Enter your choice: ");

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
            case 10:
                Generer_rapport(claims,claimCount);
                break;
            case 0:
                printTab();printf("Logging out as Admin...\n");
                break;
            default:
                printTab();printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}
void connexion_agent(){
    int trouve = 0, count = 1;
    char username[20], password[20];

   printTab(); printf("-----------Connexion-----------\n");
    while (count <= 3) {
       printTab(); printf("Veuillez entrer le nom d'utilisateur : ");
        scanf(" %[^\n]", username);

       printTab(); printf("Veuillez entrer le mot de passe : ");
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
            printTab();printf("Connexion echouee\n");
        }

        count++;
       printTab(); printf("\nAttention il vous reste %d tentative(s)\n", (3 - count) + 1);
    }

   printTab(); printf("\nErreur !! Mot de passe incorrect 3 fois\n");


   printTab() ;printf("Veuillez patienter 10 secondes avant de reessayer...\n");
    sleep(10);
}

void agentMenu() {
    int choice;
    do {
        printTab();printf("\n========== Agent Menu ==========\n");
        printTab();printf("1. Ajouter une reclamations\n");
        printTab();printf("2. Afficher la liste des reclamations\n");
       printTab(); printf("3. Modifier une reclamation\n");
        printTab();printf("4. Supprimer une reclamation\n");
        printTab();printf("5. Traiter une reclamation\n");
       printTab(); printf("6. Rechercher une reclamation\n");
       printTab(); printf("0. Logout\n");
        printTab();printf("Enter your choice: ");
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
               printTab(); printf("Deconnexon comme agent...\n");
                break;
            default:
               printTab(); printf("Invalid choice. Please try again.\n");
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
    printTab();
    topbar();
printTab();    printf("============================MENU==============================\n");
printTab();    printf("||                                                          ||\n");
printTab();    printf("||                      1. Espace admin                     ||\n");
printTab();    printf("||                      2. Inscription Client               ||\n");
printTab();    printf("||                      3. Connexion Client                 ||\n");
printTab();    printf("||                      4. Connexion Agent                  ||\n");
printTab();    printf("||                      0. Exit ...                         ||\n");
printTab();    printf("||                                                          ||\n");
printTab();    printf("==============================================================\n");
printTab();    printf("Veuillez entrer votre choix: ");
    int validunput=scanf("%d", &choice);
    while(getchar() != '\n');



        if(validunput){
             switch (choice) {
            case 1:
                if (signinAsAdmin()) {
                    adminMenu();
                } else {
                    //printTab();printf("Echec de la connexion en tant qu'admin\n");
                error404();
                //system("cls");

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
               printTab(); printf("Merci d utuliser notre application \n");
                break;
            default:
                error404();

              //  system("cls");
                //goto again;
        }
        }else{
            error404();
            effacer_console();
        }

    } while (choice != 0 );

    return 0;
}
