#include <stdio.h>
#include <string.h>

#define MAX_CHARACTER_FOR_DESTINATIONS 12

typedef struct Station_list {
    char Station_name;
    int Destination;
    struct Station_list *next;
} Station_list;



char searchDestinationByName(struct Station_list destination[], int searchWay, char userEntry[]) {
    int i;
    for(i = 0; i < searchWay; i++) {
        printf("Enter name: ");
        scanf("%s", userEntry);
        if(strcmp(destination[i].Destination, userEntry) == 0) {
            return destination[i].station_name;
        }else {
            printf("Unable to find destination !\n");
        }
    }
    printf("Train is full\n");
}



char iscorresp(int arrets, int correspondence){
 if(arrets == 3){
     correspondence=1;
 }else {
     correspondence=0;
 }
 return correspondence;
};

//mets en relations searchdestination et iscorresp et sort à l'utilisateur son trajet.(Affiche toutes les gares par lesquelles il passe)
//CalculateWay(){};

void CalculateWay(struct Station_list way[], int terminus ){
    printf("Enter destination");
    scanf("%d",terminus);
    searchDestinationByName(terminus);

    if( terminus == "Paris"){
        printf("Your train's destination is Paris\n");
        printf("That Train route is a Direct-Way, it means theres not any stops between your station and Paris's station\n");
        printf("The only station that will be used is 'Station A'");

    }else if(terminus == "Bordeaux"){
        printf("Your train's destination is Bordeaux\n");
        printf("That Train route is serving the following stops");
        printf("Station A\nStation 1\nStation 2\nStation 3\nand\n Station B which your arrival.");
    }
    else if(terminus == "Death"){
        printf("Your train's destination is Bordeaux\n");
        printf("That Train route is serving the following stops");
        printf("Station A\nStation 1\nStation 2\nStation 3\nand\n Station B which your arrival.");
    }


}

int main() {
    struct Station_list destination[MAX_CHARACTER_FOR_DESTINATIONS];
    int user_destination = 0;
    char choice;
    do {
        printf("\n What is your destination ?\n");
        printf("1. Paris \n");
        printf("2. Bordeaux\n");
        printf("3. Death :P\n");
        printf("4. Nowhere\n");
        printf("Choice: \n  ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                CalculateWay(user_destination);
                break;
            case '2':
                CalculateWay();
                break;
            case '3':
                CalculateWay();
                break;
            case '4':
                printf("Ciao");
            default:
                printf("Try again little noobs\n");
        }
    } while(choice != '4');
    return 0;
}


//Struct : arrets
//
//
//Fonctions :
//Trajets(){} : prend en entrée les "Arrêts" et calcul la destination
//
//IsCorresp(){} : prend également les arrets en entrée et vérifie si il y a correspondance possible.
//
//CalculateWay(){} : mets en relations searchdestination ; trajets et iscorresp et sors à l'utilisateur son trajet.(Affiche toutes les gares par lesquelles il passe)
//
//Searchdestination(){} : prend les entrées utilisateurs convertit en un char  exemple : PARIS = A; Bordeaux= B …etc