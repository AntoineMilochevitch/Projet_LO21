#include "../headers/rules.h"
#include "../headers/knowledge_base.h"
#include "../headers/CreateWindw.h"
#include "../headers/facts.h"

#define MAX_LINE_SIZE 1024
#define MAX_PROP_SIZE 256

int main() {
    /*FILE *file = fopen("../car_evaluation.csv", "r");
    if(file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    BC bc = createBC();
    while(fgets(line, sizeof(line), file)) {
        Rule r = createRule(); 

        char *prop = strtok(line, ",");
        int count = 0;
        while(prop != NULL) {
            if(count < 6) { // the first six columns are premises
                r = addProposition(r, prop); 
            } else { // the last column is the conclusion
                r = createConclusion(r, prop);
            }
            prop = strtok(NULL, ",");
            count++;
        }
        displayRule(r);
        bc = addRuleBC(bc, r);
    }*/
    //createWindow();

    /*printf("createRule\n");
    Rule Rule1 = createRule();
    printf("addProposition A\n");
    Rule1 = addProposition(Rule1, "A");
    printf("addProposition B\n");
    Rule1 = addProposition(Rule1, "B");
    printf("addProposition C\n");
    Rule1 = addProposition(Rule1, "C");
    printf("createConclusion D\n");
    Rule1 = createConclusion(Rule1, "D");

    printf("displayRule\n");
    displayRule(Rule1);

    printf("createRule\n");
    Rule Rule2 = createRule();
    printf("addProposition E\n");
    Rule2 = addProposition(Rule2, "E");
    printf("addProposition F\n");
    Rule2 = addProposition(Rule2, "F");
    printf("createConclusion G\n");
    Rule2 = createConclusion(Rule2, "G");

    printf("displayRule\n");
    displayRule(Rule2);

    printf("createBC\n");
    BC bc = createBC();
    printf("addRuleBC\n");
    bc = addRuleBC(bc, Rule1);
    printf("addRuleBC\n");
    bc = addRuleBC(bc, Rule2);
    printf("displayBC\n");
    displayBC(bc);

    printf("getHeadRule\n");
    char *headProposition = getHeadProposition(Rule1);
    printf("Head proposition : %s\n", headProposition);

    printf("getConclusion\n");
    char *conclusion = getConclusion(Rule1);
    printf("Conclusion : %s\n", conclusion);

    printf("deleteProposition\n");
    Rule1.premises = deleteProposition(Rule1.premises, "A");
    displayRule(Rule1);

    printf("deleteRule\n");
    deleteRule(Rule1);
    Rule = NULL;

    //printf("deleteBC\n");
    //deleteBC(bc);

    if(isEmptyRule(Rule1)) {
        printf("Rule1 is empty\n");
    }
    else {
        printf("Rule1 is not empty\n");
    }
    printf("displayRule\n");
    displayRule(Rule1);
    //displayBC(bc);
    //fclose(file);*/

	// Création des règles et de leurs prémisses & conclusion
	Rule Regle1 = createRule();
	Regle1 = addProposition(Regle1, "Circulaire");
	Regle1 = addProposition(Regle1, "Crevassée");
	Regle1 = addProposition(Regle1, "Persistant");
	Regle1 = addProposition(Regle1, "Gland");
	Regle1 = createConclusion(Regle1, "Chêne");

	Rule Regle2 = createRule();
	Regle2 = addProposition(Regle2, "Ovale");
	Regle2 = addProposition(Regle2, "Fissurée");
	Regle2 = addProposition(Regle2, "Marcescent");
	Regle2 = addProposition(Regle2, "Boule");
	Regle2 = createConclusion(Regle2, "Hêtre");

	Rule Regle3 = createRule();
	Regle3 = addProposition(Regle3, "Circulaire");
	Regle3 = addProposition(Regle3, "Lisse");
	Regle3 = addProposition(Regle3, "Caduc");
	Regle3 = addProposition(Regle3, "Samare");
	Regle3 = createConclusion(Regle3, "Erable");

	Rule Regle4 = createRule();
	Regle4 = addProposition(Regle4, "Circulaire");
	Regle4 = addProposition(Regle4, "Rugueuse");
	Regle4 = addProposition(Regle4, "Persistant");
	Regle4 = addProposition(Regle4, "Samare");
	Regle4 = createConclusion(Regle4, "Frêne");

	Rule Regle5 = createRule();
	Regle5 = addProposition(Regle5, "Triangulaire");
	Regle5 = addProposition(Regle5, "Lisse");
	Regle5 = addProposition(Regle5, "Marcescent");
	Regle5 = addProposition(Regle5, "Baie");
	Regle5 = createConclusion(Regle5, "If");

	Rule Regle6 = createRule();
	Regle6 = addProposition(Regle6, "Ovale");
	Regle6 = addProposition(Regle6, "Fissurée");
	Regle6 = addProposition(Regle6, "Caduc");
	Regle6 = addProposition(Regle6, "Gland");
	Regle6 = createConclusion(Regle6, "Noyer");

	// Création de la base de connaissance & ajout des règles dedans
	BC knowledge_basis = createBC();
	knowledge_basis = addRuleBC(knowledge_basis, Regle1);
	knowledge_basis = addRuleBC(knowledge_basis, Regle2);
	knowledge_basis = addRuleBC(knowledge_basis, Regle3);
	knowledge_basis = addRuleBC(knowledge_basis, Regle4);
	knowledge_basis = addRuleBC(knowledge_basis, Regle5);
	knowledge_basis = addRuleBC(knowledge_basis, Regle6);
/*
    BC knowledge_basis = createBC();

    printf("createBF\n");
    BF bf = createBF();

    printf("addFactBF\n");
    bf = addFactBF(bf, "A");
    printf("addFactBF\n");
    bf = addFactBF(bf, "B");

    printf("displayBF\n");
    displayBF(bf);*/

    menu(knowledge_basis);

    return 0;
}