#ifndef __KNOWLEDGE_BASE__H__
#define __KNOWLEDGE_BASE__H__

#include "../headers/rules.h"

typedef struct knowledge_base {
    Rule rules;
    struct knowledge_base *next;
} KnowledgeBase;

typedef KnowledgeBase *BC;


/********************************
 * @brief function creating an empty knowledge base
 * 
 * @param new_bc variable accepting the new knowledge base
 * @return knowledge base created
 */
BC createBC();


/********************************
 * @brief function adding a rule to the knowledge base
 * 
 * @param bc knowledge base to which the rule will be added
 * @param r rule to add
 * @return knowledge base with the rule added
 */
BC addRuleBC(BC bc, Rule r);


/********************************
 * @brief function taking the head of the knowledge bas
 * 
 * @param bc knowledge base to check
 * @return head of the knowledge base (rule)
 */
Rule getHeadRule(BC bc);



/********************************
 * @brief function checking if the knowledge base is empty
 * 
 * @param bc knowledge base to check
 * @return true if the knowledge base is empty, false otherwise
 */
bool isEmptyBC(BC bc);

/********************************
 * @brief function deleting the knowledge base
 * 
 * @param bc knowledge base to delete
 * @return knowledge base deleted (NULL)
 */
void deleteBC(BC bc);

/********************************
 * @brief function displaying the knowledge base
 * 
 * @param bc knowledge base to display
 */
void displayBC(BC bc);


#endif