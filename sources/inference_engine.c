#include "../headers/facts.h"
#include "../headers/knowledge_base.h"
#include "../headers/rules.h"
/*
BC search_premisse(const BC knowledge_basis, const BF fact_basis) {
	BC knowledge_buffer = createBC();
	BC known_fact = createBC();
	BF fact_buffer = createBF();

	knowledge_buffer = knowledge_basis;
	fact_buffer = fact_basis;

	while (!isEmptyBF(fact_buffer)) {
		while (!isEmptyBC(knowledge_buffer)) {
			Premise premisse_buffer = knowledge_buffer->next->rules.premises;
			while (premisse_buffer != NULL) {
				if (strcmp(premisse_buffer->content, fact_buffer->content) == 0 )
					known_fact = addRuleBC(known_fact, knowledge_buffer->next->rules);
				premisse_buffer = premisse_buffer->next;
			}
			knowledge_buffer = knowledge_buffer->next;
    }
    fact_buffer = fact_buffer->next;
	}
	return known_fact;
}

void inference_engine(BC knowledge_basis, BF fact_basis) {
	if(isEmptyBC(knowledge_basis)) 
        printf("La base de connaissance est vide\n");
	else {
		BC knowledge_buffer = createBC();
		BF fact_buffer = createBF();
		knowledge_buffer = knowledge_basis;
		fact_buffer = fact_basis;

		while(fact_buffer != NULL) {
			knowledge_buffer = search_premisse(knowledge_buffer, fact_buffer);
			printf("%s",fact_buffer->content); //DEBUG
			fact_buffer = fact_buffer->next;
		}

		if (isEmptyBC(knowledge_buffer)) {
			printf("\nAucune Plante ne correspond.\n");
			displayBF(fact_basis); //Test
		}
		else {
			printf("\nPlante correspondante : %s\n\n",knowledge_buffer->next->rules.conclusion);
			displayBC(knowledge_buffer); //Test
			displayBF(fact_basis); //Test
		}
	}
}*/

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
}