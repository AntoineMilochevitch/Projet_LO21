#include "../headers/rules.h"
#include "../headers/knowledge_base.h"

#define MAX_LINE_SIZE 1024
#define MAX_PROP_SIZE 256

int main() {
    FILE *file = fopen("../car_evaluation.csv", "r");
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
        Proposition *last = NULL;
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
    }
    displayBC(bc);
    fclose(file);

    return 0;
}