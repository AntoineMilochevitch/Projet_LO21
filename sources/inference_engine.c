#include "../headers/facts.h"
#include "../headers/knowledge_base.h"
#include "../headers/rules.h"

BC filterKnowledge(BC knowledge_basis, BF fact_basis) {
    BC filtered_kb = createBC();
    BC current_rule = knowledge_basis;
    if (current_rule != NULL) {
        current_rule = current_rule->next;
    }

    while (current_rule != NULL) {
        Rule current_rule_content = getHeadRule(current_rule);
        printf("\nCurrent rule: \n");
        displayRule(current_rule_content);  // suppose que displayRule affiche le contenu de la règle
        bool all_premises_match = true;
        Premise current_premise = current_rule_content.premises;

        while (current_premise != NULL) {
            bool is_fact = isFact(fact_basis, current_premise);
            printf("Premise: %s, isFact: %d\n", current_premise->content, is_fact);
            if (!is_fact) {
                all_premises_match = false;
                break;
            }
            current_premise = current_premise->next;
        }

        if (all_premises_match) {
            filtered_kb = addRuleBC(filtered_kb, current_rule_content);
            displayBC(filtered_kb);  // suppose que displayBC affiche le contenu de la base de connaissances7
            printf("\n");
        }
        current_rule = current_rule->next;
    }
    return filtered_kb;
}
void inference_engine(BC knowledge_basis, BF fact_basis){
	if(isEmptyBC(knowledge_basis)) 
        printf("BC est vide\n");
	else {
		BC filtered_basis = filterKnowledge(knowledge_basis, fact_basis);
        filtered_basis = filtered_basis->next;
		if (isEmptyBC(filtered_basis)) {
    		printf("\nAucune Plante ne correspond.\n");
		} else {
			displayBC(filtered_basis);
			printf("\nPlante correspondante : %s.\n", getConclusion(filtered_basis->rules));
		}
	}
}
