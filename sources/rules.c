#include "../headers/rules.h"

Rule createRule() {
    Rule rule;
    rule.premises = NULL;
    rule.conclusion = NULL;
    return rule;
}

bool isEmptyRule(Rule rule) {
    if(rule.premises == NULL && rule.conclusion == NULL) {
        return true;
    }
    return false;
}

bool isEmptyPremise(Premise p) {
    if(p == NULL) {
        return true;
    }
    return false;
}

bool isEmptyConclusion(Conclusion c) {
    if(c == NULL) {
        return true;
    }
    return false;
}

bool isProposition(Premise p, char *content) {
    if(isEmptyPremise(p)) {
        return false;
    }
    else {
        if(strcmp(p->content, content) == 0) {
            return true;
        }
        else {
            return isProposition(p->next, content);
        }
    }
}

Rule addProposition(Rule rule, char* content) {
    // if the rule is empty
    if(isEmptyRule(rule)) {
        rule.premises = (Premise) malloc(sizeof(Premise));
        rule.premises->content = malloc(strlen(content));
        strcpy(rule.premises->content, content);
        rule.premises->next = NULL;
    }
    // if the rule is not empty
    else {
        if(!isProposition(rule.premises, content)) {
            Rule tmp = rule;
            while(!isEmptyPremise(tmp.premises->next)) {
                tmp.premises = tmp.premises->next;
            }
            Premise new = (Premise) malloc(sizeof(Proposition));
            new->content = (char*)malloc(strlen(content) + 1);
            strcpy(new->content, content);
            new->next = NULL;
            tmp.premises->next = new;
           
        }
        else {
            printf("The proposition %s is already in the rule\n", content);
        }
    }
    return rule;
}

Rule createConclusion(Rule rule, char* content) {
    if(isEmptyPremise(rule.premises)) {
        printf("The premise is empty : impossible to create a conclusion\n");
    }
    else {
        if(isEmptyConclusion(rule.conclusion)) {
            rule.conclusion = (Conclusion) malloc(sizeof(Conclusion));
            rule.conclusion = malloc(strlen(content)+1);
            strcpy(rule.conclusion, content);
        }
        else {
            printf("The conclusion is already set\n");
        }
    }
    return rule;
}

Premise deleteProposition(Premise p, char* content) {
    if(isEmptyPremise(p)) {
        printf("The proposition %s is not in the rule\n", content);
        return NULL; 
    }
    else {
        if(strcmp(p->content, content) == 0) {
            Premise tmp = p;
            p = p->next;
            free(tmp);
        }
        else {
            p->next = deleteProposition(p->next, content);
        }
    }
    return p;
}

char *getHeadProposition(Rule r) {
    if(isEmptyPremise(r.premises)) {
        printf("The premise is empty\n");
        return NULL;
    }
    else {
        return r.premises->content;
    }
}

char *getConclusion(Rule r) {
    if(isEmptyConclusion(r.conclusion)) {
        printf("The conclusion is empty\n");
        return NULL;
    }
    else {
        return r.conclusion;
    }
}

void deleteRule(Rule r) {
    if(isEmptyRule(r)) {
        printf("The rule is empty\n");
        return;
    }
    else {
        while (!isEmptyPremise(r.premises)) {
            Premise tmp = r.premises;
            r.premises = r.premises->next;
            free(tmp->content);
            free(tmp);
        }
        if(r.conclusion != NULL) {
            free(r.conclusion);
        }
        r.conclusion = NULL;
        r.premises = NULL;
        
    }
}

void displayRule(Rule r) {
    if(isEmptyRule(r)) {
        printf("The rule is empty\n");
        return;
    }
    else {
        printf("Premises : ");
        Premise tmp = r.premises;
        while(!isEmptyPremise(tmp->next)) {
            printf("%s & ", tmp->content);
            tmp = tmp->next;
        }
        printf("%s\n", tmp->content);
        printf("Conclusion : %s\n\n", r.conclusion);
    }
}