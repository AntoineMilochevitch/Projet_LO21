#ifndef __RULES__H__
#define __RULES__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*
 Definition proposition
*/
typedef struct proposition {
    char *content;
    struct proposition *next;
} Proposition;

typedef Proposition *Premise;
typedef char *Conclusion;


/*
 Definition rule
*/
typedef struct rule {
    Premise  premises;
    Conclusion conclusion;
} Rule;


/********************************
 * @brief function creation empty rule
 * 
 * @param new_rule variable accepting the new rule
 * @return rule created
 */
Rule createRule();


/********************************
 * @brief function adding a proposition to the rule
 * 
 * @param rule rule to which the proposition will be added
 * @param content proposition to add
 * @return rule with the proposition added
 */
Rule addProposition(Rule r, char *content);


/********************************
 * @brief function adding a conclusion to the rule
 * 
 * @param rule rule to which the conclusion will be added
 * @param content conclusion to add
 * @return rule with the conclusion added
 */
Rule createConclusion(Rule r, char *content);


/********************************
 * @brief function checking if a proposition is in the rule
 * 
 * @param p proposition to check
 * @param content proposition to check with premises
 * @return true if the proposition is in the rule, false otherwise
 */
bool isProposition(Premise p,char *content);  


/********************************
 * @brief function deleting a proposition from the rule
 * 
 * @param p proposition to delete
 * @param content proposition to delete with premises
 * @return rule with the proposition deleted
 */
Premise deleteProposition(Premise p, char *content);


/********************************
 * @brief function checking if premise is empty
 * 
 * @param p premise to check
 * @return true if the premise is empty, false otherwise
 */
bool isEmptyPremise(Premise p);


/********************************
 * @brief function checking if conclusion is empty
 * 
 * @param c conclusion to check
 * @return true if the conclusion is empty, false otherwise
 */
bool isEmptyConclusion(Conclusion c);


/********************************
 * @brief function checking if rule is empty
 * 
 * @param r rule to check
 * @return true if the rule is empty, false otherwise
 */
bool isEmptyRule(Rule r);


/********************************
 * @brief function taking the proposition on the head of a premise
 * 
 * @param r rule to check
 * @return proposition on the head of the premise
 */
char *getHeadProposition(Rule r);


/********************************
 * @brief function taking the conclusion of a rule
 * 
 * @param r rule to check
 * @return conclusion of the rule
 */
char *getConclusion(Rule r);


/********************************
 * @brief function deleting a rule
 * 
 * @param r rule to delete
 */
void deleteRule(Rule r);


/********************************
 * @brief function displaying a rule
 * 
 * @param r rule to display
 */
void displayRule(Rule r);

#endif