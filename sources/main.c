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

    BC knowledge_basis = createBC();

    printf("createBF\n");
    BF bf = createBF();

    printf("addFactBF\n");
    bf = addFactBF(bf, "A");
    printf("addFactBF\n");
    bf = addFactBF(bf, "B");

    printf("displayBF\n");
    displayBF(bf);

    menu(knowledge_basis);

    return 0;
}