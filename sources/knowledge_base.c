#include "../headers/knowledge_base.h"

bool isEmptyBC(BC bc) {
    if(bc == NULL) {
        return true;
    }
    return false;
}

BC createBC() {
    BC bc = (BC)malloc(sizeof(KnowledgeBase));
    if(bc == NULL){
        printf("Memory allocation for a now Knowlegde Base failed");
        exit(-1);
    }
    bc->rules.premises = NULL;
    bc->next = NULL;
    return bc;
}

BC addRuleBC(BC bc, Rule r) {
    if (isEmptyBC(bc)) {
        bc->rules = r;
        bc->next = NULL;
    }
    else {
        BC tmp = bc;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        BC new = (BC)malloc(sizeof(KnowledgeBase));
        new->rules = r;
        tmp->next = new;
    }
    return bc;
}

Rule getHeadRule(BC bc) {
    if (isEmptyBC(bc)) {
        printf("Knowledge base is empty\n");
        exit(-1);
    }
    return bc->rules;

}

void deleteBC(BC bc) {
    if(isEmptyBC(bc)) {
        return NULL;
    }
    else { 
        deleteRule(bc->rules);
        deleteBC(bc->next);
        free(bc);
    }
    printf("Knowledge base deleted\n");
}

void displayBC(BC bc) {
    if(isEmptyBC(bc)) {
        printf("Empty knowledge base\n");
    }
    else {
        printf("Knowledge base : \n");
        BC tmp = bc;
        while (tmp != NULL) {
            displayRule(getHeadRule(tmp));
            tmp = tmp->next;
        }  
    }
}