#include "../headers/facts.h"
#include "../headers/knowledge_base.h"
#include "../headers/rules.h"

BC filterKnowledge(BC knowledge_basis, BF fact_basis) {
    BC filtered_kb = createBC();
    BC current_rule = knowledge_basis;

    while (current_rule != NULL) {
        Rule current_rule_content = getHeadRule(current_rule);
        bool all_premises_match = true;
        Premise current_premise = current_rule_content.premises;

        while (current_premise != NULL) {
            if (!isFact(fact_basis, current_premise)) {
                all_premises_match = false;
                break;
            }
            current_premise = current_premise->next;
        }

        if (all_premises_match) {
            filtered_kb = addRuleBC(filtered_kb, current_rule_content);
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
		if (isEmptyBC(filtered_basis)) {
    		printf("\nAucune Plante ne correspond.\n");
		} else {
			displayBC(filtered_basis);
			printf("\nPlante correspondante : %s.\n", getConclusion(filtered_basis->rules));
		}
	}
}
/*
bool allPremisesAreTrue(BF bf, Rule rule) {
    Premise currentPremise = rule.premises;
    while (currentPremise != NULL) {
        if (!isFact(bf, currentPremise->content)) {
            return false;
        }
        currentPremise = currentPremise->next;
    }
    return true;
}

void backwardInference(BF bf, BC bc, Proposition goal) {
    if (isFact(bf, &(goal.content))) {
        return;
    }

    KnowledgeBase *currentBC = bc;
    while (currentBC != NULL) {
        if (strcmp(currentBC->rules.conclusion, goal.content) == 0) {
            if (allPremisesAreTrue(bf, currentBC->rules)) {
                addFact(bf, currentBC->rules.conclusion);
                return;
            }
        }
        currentBC = currentBC->next;
    }
}*/