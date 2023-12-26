#ifndef __MENU__H__
#define __MENU__H__

#include "../headers/facts.h"
#include "../headers/knowledge_base.h"
#include <stdlib.h>

long user_input_num();
char* user_input_char();
void userInputRule(BC* knowledge_basis);
void sys_expert_input(BC knowledge_basis);
void menu(BC knowledge_basis);

#endif