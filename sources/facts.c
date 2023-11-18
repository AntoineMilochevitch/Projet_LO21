#include "../headers/facts.h"

bool isEmptyFact(BF bf) {
    if(bf == NULL) {
        return true;
    }
    return false;
}

BF createBF() {
    BF bf = (BF)malloc(sizeof(Facts));
    bf->facts = NULL;
    bf->next = NULL;
    return bf;
}

BF addFactBF(BF bf,char *content) {
    Proposition *p = (Proposition*)malloc(sizeof(Proposition));
    p->content = (char*)malloc(strlen(content) + 1);
    strcpy(p->content, content);
    p->next = NULL;

    BF new = (BF)malloc(sizeof(Facts));
    new->facts = p;
    new->next = NULL;
    if (isEmptyBF(bf)) {
        bf->facts = p;
        bf->next = NULL;
    }
    else {
        BF tmp = bf;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
    return bf;
}

void deleteBF(BF bf) {
    if(bf == NULL) {
        return;
    }

    deleteBF(bf->next);
    free(bf->facts->content);
    free(bf->facts);
    free(bf);
}