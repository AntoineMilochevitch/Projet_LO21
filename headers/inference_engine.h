#ifndef __INFERENCE_ENGINE__H__
#define __INFERENCE_ENGINE__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/rules.h"
#include "../headers/knowledge_base.h"
#include "../headers/facts.h"

BC search_premisse(BC knowledge_basis, BF fact_basis);
void inference_engine(BC knowledge_basis, BF fact_basis);

#endif