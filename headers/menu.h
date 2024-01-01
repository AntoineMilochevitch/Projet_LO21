#ifndef __MENU__H__
#define __MENU__H__

#include "../headers/facts.h"
#include "../headers/knowledge_base.h"
#include <stdlib.h>

#define R(str) "\e[91m" str "\e[39m"
#define G(str) "\e[92m" str "\e[39m"
#define B(str) "\e[94m" str "\e[39m"

long user_input_num();
char* user_input_char();
void userInputRule(BC* knowledge_basis);
void sys_expert_input(BC knowledge_basis);
void menu(BC knowledge_basis);

#endif