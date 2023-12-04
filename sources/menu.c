#include "../headers/facts.h"
#include "../headers/inference_engine.h"
#include "../headers/knowledge_base.h"
#include "../headers/menu.h"
#include "../headers/rules.h"

#define MAX_LENGHT 200

long user_input_num() {
	char input[MAX_LENGHT];
	// get a user entry & return 0 if NaN
	fgets(input, MAX_LENGHT+1, stdin);
	return strtol(input, NULL, 10);
}

char* user_input_char() {
	char input[MAX_LENGHT];
	fgets(input, MAX_LENGHT+1, stdin);
	input[strlen(input) - 1] = 0;
    // adjust the size of the string to fit perfectly in memory
	char* result = (char*)malloc(strlen(input)+1);
	strcpy(result, input);
	return result;
}

void userInputRule(){
    printf("Ajoute théoriquement une règle (tkt)\n");
}

void menu(BC knowledge_basis){
	unsigned short choice;
	printf("\n");
    printf("0 - Trouver une plante\n");
    printf("1 - Liste des plantes enregistrées\n");
    printf("2 - Ajouter une règle \n");
    printf("3 - Supprimer la base de connaissance\n");
    printf("4 - Quitter\n\n");
    do {
	    printf(">>> ");
		choice = user_input_num();
    } while (choice > 4 || choice < 0);

    switch (choice)
    {
    case 0:
        break;
    case 1:
        displayBC(knowledge_basis);
        break;
    case 2:
        userInputRule();
        break;
    case 3:
        deleteBC(knowledge_basis);
        break;
    case 4:
        printf("Salud");
        exit(0);
        break;
    default:
        break;
    }
}