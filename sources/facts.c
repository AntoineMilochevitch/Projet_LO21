#include "../headers/facts.h"

bool isEmptyBF(BF bf) {
    if(bf == NULL)
        return true;
    return false;
}

BF createBF() {
    BF bf = NULL;
    return bf;
}

BF addFactBF(BF bf,char *content) {
    if (isEmptyBF(bf)) {
        printf("Input of the first element in the BF...\n");
        bf = (BF)malloc(sizeof(Proposition));
        bf->content = (char*)malloc(strlen(content));
        strcpy(bf->content, content);
        bf->next = NULL;
    }
    else {
        BF tmp = bf;
        while(!isEmptyBF(tmp->next)) {
            tmp = tmp->next;
        }
        BF new = (BF)malloc(sizeof(Proposition));
        new->content = (char*)malloc(strlen(content));
        strcpy(new->content, content);
        new->next = NULL;
        tmp->next = new;
    }
    return bf;
}

void deleteBF(BF bf) {
    if(bf == NULL) {
        return;
    }
    deleteBF(bf->next);
    free(bf->content);
    free(bf);
}

void displayBF(BF bf) {
    if(isEmptyBF(bf)) {
        printf("Empty facts base\n");
    }
    else {
        printf("Facts base : \n");
        BF tmp = bf; 
        while (tmp != NULL) {
            printf("Fact : %s\n", tmp->content);
            tmp = tmp->next;
        }
    }
}

bool isFact(BF bf, Premise p) {
    Proposition *currentFact = bf;
    while (currentFact != NULL) {
        if (strcmp(currentFact->content, p->content) == 0) {
            return true;
        }
        currentFact = currentFact->next;
    }
    return false;
}