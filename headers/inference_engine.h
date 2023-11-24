#ifndef __INFERENCE_ENGINE__H__
#define __INFERENCE_ENGINE__H__


#include "../headers/rules.h"
#include "../headers/knowledge_base.h"
#include "../headers/facts.h"


/********************************
 * @brief function backward chaining algorithm 
 * 
 * @param bc knowledge base containing the rules
 * @param bf fact base containing the facts
 * @param goal goal to reach
 * @return true if the goal is reached, false otherwise
 */
void backwardChaining(BC bc, BF bf, char *goal);


/********************************
 * @brief function checking if all the premises of a rule are true
 * 
 * @param bf fact base containing the facts
 * @param rule rule to check
 * @return true if all the premises are true, false otherwise
 */
bool allPremisesAreTrue(BF bf, Rule rule);



#endif