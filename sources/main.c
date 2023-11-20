#include "../headers/rules.h"
#include "../headers/knowledge_base.h"

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
    printf("createRule\n");
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

    printf("deleteRule\n");
    deleteRule(Rule1);

    if(isEmptyRule(Rule1)) {
        printf("Rule1 is empty\n");
    }
    else {
        printf("Rule1 is not empty\n");
    }
    printf("displayRule\n");
    displayRule(Rule1);
    displayBC(bc);
    //fclose(file);

    return 0;
}