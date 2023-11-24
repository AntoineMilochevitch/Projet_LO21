#include "inference_engine.h"


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