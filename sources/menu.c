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
	char* result = (char*)malloc(strlen(input)+1);
	strcpy(result, input);
	return result;
}

void userInputRule(BC* knowledge_basis){
  Rule UserRule = createRule();    
  bool IsConclu = false;
  while(!IsConclu){
    printf("Ajouter une proposition (Si conclusion tapper 0) : ");
    char* input = user_input_char();
    if(strcmp(input, "0") == 0){
      IsConclu = true;
    }
    else{
      UserRule = addProposition(UserRule, input);
      printf("Proposition %s ajoutée à la nouvelle règle.\n", input);
    }
  }
  printf("Ecrire la conclusion : ");
  char* conclusion = user_input_char();
  UserRule = createConclusion(UserRule, conclusion);
  *knowledge_basis = addRuleBC(*knowledge_basis, UserRule);
  printf("Nouvelle règle %s ajoutée à la base de connaissance. \n",conclusion);
}

void sys_expert_input(BC knowledge_basis){
  unsigned short num;
  BF base_faits = createBF();
  if (isEmptyBC(knowledge_basis)) {
		printf(R("Base de connaissance vide\n"));
		menu(knowledge_basis);
	}

  printf("\nQuelle silouette a l'arbre ?\n");
  printf("1 : Circulaire\n");
  printf("2 : Triangulaire\n");
  printf("3 : Ovale\n");

  do {
		printf("Choisissez : ");
		num = user_input_num();
	} while (num > 3 || num < 1);
  switch(num){
      case 1 : 
        base_faits = addFactBF(base_faits, "Circulaire");
        break;
      case 2 : 
        base_faits = addFactBF(base_faits, "Triangulaire");
        break;
      case 3 : 
        base_faits = addFactBF(base_faits, "Ovale");
        break;
    }

  printf("\nQuelle écorce a l'arbre ?\n");
  printf("1 : Lisse\n");
  printf("2 : Rugueuse\n");
  printf("3 : Fissurée\n");
  printf("4 : Crevassée\n");

  do {
		printf("Choisissez : ");
		num = user_input_num();
	} while (num > 4 || num < 1);
  switch(num){
      case 1 : 
        base_faits = addFactBF(base_faits, "Lisse");
        break;
      case 2 : 
        base_faits = addFactBF(base_faits, "Rugueuse");
        break;
      case 3 : 
        base_faits = addFactBF(base_faits, "Fissurée");
        break;
      case 4 : 
        base_faits = addFactBF(base_faits, "Crevassée");
        break;
  }

  printf("\nType de Feuillage de l'arbre ?\n");
  printf("1 : Caduc\n");
  printf("2 : Persistant\n");
  printf("3 : Marcescent\n");

  do {
		printf("Choisissez : ");
		num = user_input_num();
	} while (num > 3 || num < 1);
  switch(num){
      case 1 : 
        base_faits = addFactBF(base_faits, "Caduc");
        break;
      case 2 : 
        base_faits = addFactBF(base_faits, "Persistant");
        break;
      case 3 : 
        base_faits = addFactBF(base_faits, "Marcescent");
        break;
    }

  printf("\nLe Fruit de l'arbre ?\n");
  printf("1 : Baies\n");
  printf("2 : Glands\n");
  printf("3 : Boules\n");
  printf("4 : Samares\n");

  do {
		printf("Choisissez : ");
		num = user_input_num();
	} while (num > 4 || num < 1);
  switch(num){
      case 1 : 
        base_faits = addFactBF(base_faits, "Baie");
        break;
      case 2 : 
        base_faits = addFactBF(base_faits, "Gland");
        break;
      case 3 : 
        base_faits = addFactBF(base_faits, "Boule");
        break;
      case 4 : 
        base_faits = addFactBF(base_faits, "Samare");
        break;
  }
  displayBF(base_faits);
  inference_engine(knowledge_basis, base_faits);
  menu(knowledge_basis);
}

void menu(BC knowledge_basis){
  bool isUp = true;
  while(isUp){
    unsigned short choice;
    printf("\n");
    printf(B("0 - Trouver une plante\n"));
    printf(B("1 - Liste des plantes enregistrées\n"));
    printf(B("2 - Ajouter une règle \n"));
    printf(B("3 - Supprimer la base de connaissance\n"));
    printf(B("4 - Quitter\n\n"));

    do {
      printf(B(">>> "));
      choice = user_input_num();
    } while (choice > 4 || choice < 0);

    switch (choice){
      case 0:
        sys_expert_input(knowledge_basis);
        break;
      case 1:
        displayBC(knowledge_basis);
        break;
      case 2:
        userInputRule(&knowledge_basis);
        break;
      case 3:
        deleteBC(knowledge_basis);
        printf(R("Base de connaissances supprimée... \n"));
        isUp = false;
        break;
      case 4:
        deleteBC(knowledge_basis);
        printf(R("Programme Fermé. \n"));
        isUp = false;
        break;
      default:
          break;
    }
  }
  exit(0);
}